#include "mml.h"
#include <stdlib.h>
#include <math.h>
#include <Arduino.h>

int currentCur, mmlSize, tmpCursol;
char mmlNotes[512];

int note;
int noteSendFlag = 0;

int duration;
int baseDuration = 4;

int octave, baseOctave = 4;

int tempo = 120;

void mml_initialize(char* mml) {
  mmlSize = sizeof(mml) / sizeof(mml[0]);
  currentCur = 0;

  for (int i; i < mmlSize; i++) {
    mmlNotes[i] = mml[i];
  }
}

void reset_cursol() {
  currentCur = 0;
}

int getDuration(char number1, char number2, char dot, int baseDuration) {
  int convNumber1, convNumber2;
  float relativeDuration;

  if(is_digit(number1) == 1) {
    if(is_digit(number2) == 1) {
      convNumber1 = atoi(&number1);
      convNumber2 = atoi(&number2);
      relativeDuration = (convNumber1 * 10) + convNumber2;
      if (dot == '.')
        relativeDuration = 1 / ((1 / relativeDuration) * 1.5);
    }
    else if(number2 == '.')
      relativeDuration = 1 / ((1 / convNumber1) * 1.5);
    else
      relativeDuration = convNumber1;
  }
  else if (number1 == '.')
    relativeDuration = 1 / ((1 / baseDuration) * 1.5);
  else
    relativeDuration = baseDuration;

  return (int)(((60000 / tempo) * 4) / relativeDuration);
}

int is_digit(char checkChar) {
  if (checkChar >= '0' && checkChar <= '9') {
    return 1;
  } else {
    return 0;
  }
}

int get_note() {
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

  return frequencies[octave][key];
}

int char_to_keynumber(char key) {
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
    // // 半音の取得
    // // Note:音楽的にはEの半音上げとかはないが、MMLは全音上げとして認識するのでFになる
    // // 同じく、Bの半音上げCの半音下げはオクターブが変わって全音上げ下げになる
    // function getSemitone(note, up_or_down = "") {
    //   var notes = ["C","CS","D","DS","E","F","FS","G","GS","A","AS","B"];
    //   array_index = notes.indexOf(note.toUpperCase());
    //   if (up_or_down == "+") {
    //     // オクターブ上がるやつ
    //     if (array_index == 11) {
    //       return [notes[0], "+"];
    //     }
    //     return [notes[array_index + 1], 0];
    //   } else if (up_or_down == "-") {
    //     // オクターブ下がるやつ
    //     if (array_index == 0) {
    //       return [notes[11], "-"];
    //     }
    //     return [notes[array_index - 1], 0];
    //   }
    // }

Score fetch_mml() {
  //［テンポt］［オクターブ_~］［音階cdefgabr］［半音-+］［音の長さ1〜64］
  if (currentCur >= mmlSize) return (Score){NOTE_END, 0};

  switch (mmlNotes[currentCur]){
    // テンポ
    case 't':
//      char tempoArray[5];
      tempo = 0;
      // 数字の間は読み込む
      for (tmpCursol = 1;
            is_digit(mmlNotes[currentCur + tmpCursol]) == 1;
            tmpCursol++) {
          // tempoArray[tmpCursol - 1] = mmlNotes[i + tmpCursol];
        tempo = (tempo * pow(10, tmpCursol - 1)) + atoi(&mmlNotes[currentCur + tmpCursol]);
      }
      // tempo = atoi(tempoArray);
      break;

    // 音階
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'a':
    case 'b':
      tmpCursol = 1;

      note = get_note();

      // TODO:タイに対応させたほうがよさそう(スラーはMenZ-TONEの仕様上不要)
      // タイの例：c+16.&c+8→&の次もc+か判定する必要がある。結構面倒くさい。
      duration = getDuration(mmlNotes[currentCur + tmpCursol],
                              mmlNotes[currentCur + tmpCursol+1],
                              mmlNotes[currentCur + tmpCursol+2],
                              baseDuration);
      noteSendFlag = 1;
      break;

    // 休符
    case 'r':
      note = REST;
      duration = getDuration(mmlNotes[currentCur + tmpCursol],
                              mmlNotes[currentCur + tmpCursol + 1],
                              mmlNotes[currentCur + tmpCursol + 2],
                              baseDuration);
      noteSendFlag = 1;
      break;

    // スペースは何もしない
    case ' ':
      break;

    // Base duration
    case 'l':
      baseDuration = getDuration(mmlNotes[currentCur + 1], mmlNotes[currentCur + 2], '-', baseDuration);
      break;

    // Octave
    case 'o':
//      baseOctave = getDuration(mmlNotes[currentCur + 1], mmlNotes[currentCur + 2], baseDuration);
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
    octave = baseOctave;
    return (Score){note, duration};
  }

  currentCur++;
}
