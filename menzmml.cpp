#include "menzmml.h"
#include <stdlib.h>
#include <math.h>
#include <Arduino.h>

int currentCur, mmlSize, tmpCursol;
char mmlNotes[512];

// int note;
// int noteSendFlag = 0;
// noteSendFlag = 0;

// int duration;
// baseDuration = 4;

// octave, baseOctave = 4;

// tempo = 120;

const int frequencies[7][12] = {
  {33,35,37,39,41,44,46,49,52,55,58,62},
  {65,69,73,78,82,87,93,98,104,110,117,123},
  {131,139,147,156,165,175,185,196,208,220,233,247},
  {262,277,294,311,330,349,370,392,415,440,466,494},
  {523,554,587,622,659,698,740,784,831,880,932,988},
  {1047,1109,1175,1245,1319,1397,1480,1568,1661,1760,1865,1976},
  {2093,2217,2349,2489,2637,2794,2960,3136,3322,3520,3729,3951}
};

MenzMML::MenzMML() {
  noteSendFlag = 0;
  baseDuration = 4;
  octave, baseOctave = 4;
  tempo = 120;
}

void MenzMML::mml_initialize(char* mml) {
  Serial.println("init");
  mmlSize = strlen(mml);
  currentCur = 0;
  for (int u = 0; u < mmlSize; u++) {
    mmlNotes[u] = mml[u];
  }
  Serial.println("init end");
}

void MenzMML::reset_cursol() {
  currentCur = 0;
}

int MenzMML::get_duration(char number1, char number2, char dot, float baseDuration) {
//  Serial.println("duration");
  float convNumber1, convNumber2, relativeDuration;

  if(is_digit(number1) == 1) {
    convNumber1 = char_to_int(number1);
//    Serial.println(convNumber1);
    if(is_digit(number2) == 1) {
      convNumber2 = char_to_int(number2);
//      Serial.println(convNumber2);
      relativeDuration = (convNumber1 * 10) + convNumber2;
      if (dot == '.') {
//        Serial.println("2 digits and dot");
        relativeDuration = 1 / ((1 / relativeDuration) * 1.5);
      }
//      relativeDuration = convNumber1;
//      Serial.println("2digits");
    }
    else if(number2 == '.') {
//      Serial.println("1digit and dot");
//      Serial.println(convNumber1);
      relativeDuration = 1 / ((1 / convNumber1) * 1.5);
    }
    else {
//      Serial.println("1 digit");
      relativeDuration = convNumber1;
    }
  }
  else if (number1 == '.') {
//    Serial.println("dot only");
    relativeDuration = 1 / ((1 / baseDuration) * 1.5);
  }
  else {
//    Serial.println("not specified");
    relativeDuration = baseDuration;
  }
//  Serial.println(baseDuration);
//  Serial.println(relativeDuration);
//  Serial.println("duration end");
  return relativeDuration;
}

int MenzMML::is_digit(char checkChar) {
  if (checkChar >= '0' && checkChar <= '9') {
    return 1;
  } else {
    return 0;
  }
}

int MenzMML::get_note() {
  int key = char_to_keynumber(mmlNotes[currentCur]);

  // 半音の判定
  if (mmlNotes[currentCur + tmpCursol] == '+') {
    key++;
  } else if(mmlNotes[currentCur + tmpCursol] == '-') {
    key--;
  }

  if (key > 11) {
    octave++;
    key = 0;
  } else if (key < 0) {
    octave--;
    key = 11;
  }
//  Serial.println("note");
//  Serial.println(mmlNotes[currentCur]);
//  Serial.println(octave);
//  Serial.println(key);
  return frequencies[octave - 1][key];
}

int MenzMML::char_to_keynumber(char key) {
  switch (key) {
      case 'c': return 0;
      case 'd': return 2;
      case 'e': return 4;
      case 'f': return 5;
      case 'g': return 7;
      case 'a': return 9;
      case 'b': return 11;
  }
}

int MenzMML::char_to_int(char number) {
  switch (number) {
      case '0': return 0;
      case '1': return 1;
      case '2': return 2;
      case '3': return 3;
      case '4': return 4;
      case '5': return 5;
      case '6': return 6;
      case '7': return 7;
      case '8': return 8;
      case '9': return 9;
  }
}

void MenzMML::fetch_mml() {
  //［テンポt］［オクターブ_~］［音階cdefgabr］［半音-+］［音の長さ1〜64］
  octave = baseOctave;
  noteSendFlag = 0;
  
  while(1) {
    if (currentCur >= mmlSize) {
      note = NOTE_END;
      duration = 0;
      return;
    }
//    Serial.println(mmlNotes[currentCur]);
    switch (mmlNotes[currentCur]){
      // テンポ
      case 't':
        tempo = 0;
        tempo = atoi(&mmlNotes[currentCur + 1]);
//        Serial.println("tempo");
//        Serial.println(tempo);
        break;
      // 音階
      case 'c':
      case 'd':
      case 'e':
      case 'f':
      case 'g':
      case 'a':
      case 'b':
//        Serial.println("note");
  
        tmpCursol = 1;
  
        note = get_note();
//        Serial.println(note);
        // TODO:タイに対応させたほうがよさそう(スラーはMenZ-TONEの仕様上不要)
        // タイの例：c+16.&c+8→&の次もc+か判定する必要がある。結構面倒くさい。
        duration = get_duration(mmlNotes[currentCur + tmpCursol],
                                mmlNotes[currentCur + tmpCursol+1],
                                mmlNotes[currentCur + tmpCursol+2],
                                baseDuration);
        noteSendFlag = 1;
        break;
  
      // 休符
      case 'r':
//        Serial.println("rest");
        note = REST;
        duration = get_duration(mmlNotes[currentCur + tmpCursol],
                                mmlNotes[currentCur + tmpCursol + 1],
                                mmlNotes[currentCur + tmpCursol + 2],
                                baseDuration);
        noteSendFlag = 1;
//        Serial.println(duration);
        break;
  
      // スペースは何もしない
      case ' ':
        break;
  
      // Base duration
      case 'l':
//        Serial.println("l");
        baseDuration = get_duration(mmlNotes[currentCur + 1], mmlNotes[currentCur + 2], '-', baseDuration);
        break;
  
      // Octave
      case 'o':
//        Serial.println("o");
        if (is_digit(mmlNotes[currentCur + 1]) == 1) {
          baseOctave = atoi(&mmlNotes[currentCur + 1]);
        }
//        Serial.println(baseOctave);
  //      baseOctave = get_duration(mmlNotes[currentCur + 1], mmlNotes[currentCur + 2], baseDuration);
        break;
  
      // baseOctave up
      case '>':
        baseOctave++;
        break;
  
      // baseOctave down
      case '<':
        baseOctave--;
        break;
  
      // Relative octave up
      case '~':
        octave++;
        break;
  
      // Relative octave down
      case '_':
        octave--;
        break;
  
    }
  
    if(noteSendFlag == 1){
      currentCur++;
      return;
    }
  
    currentCur++;
  }
}
