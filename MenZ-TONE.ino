
#include "pitches.h"

const int buttonPin = 2;    // the number of the pushbutton pin

int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

int thisNote = 0;
int ready_tone = 1;

// notes in the melody:
int melody[] = {
  // パーパパパーパーパーパー
//  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, NOTE_B3, NOTE_C4
  // ナウシカレクイエム
NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_GS4, 
NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_E4, 
NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, 
NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, 
NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_B4, 
NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, 
NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_E4, 
NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, 
NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, 
NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C5, NOTE_C5, 
NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D4, NOTE_A4, NOTE_D4, 
NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_B4, 
NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, 
NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_E4, 
NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4



//らどしらしみみ
//らどしらそ＃
//みらどしらしみみみ
//ふぁそらしどしら
//らどしらしみみ
//らどしらそ＃
//みらどしらしみみ
//ふぁそらしどらし
//らどしらしみみ
//らどしらそ＃
//みらどしらしみみみ
//ふぁそらしどしら
//みみみみふぁみみれれ
//れれれれみれれどど
//どどどどれられ
//どしらそみし
//らどしらしみみ
//らどしらそ＃
//みらどしらしみみみ
//ふぁそらしどしら

  // キラキラ星
//  NOTE_C4, NOTE_C4,NOTE_G4, NOTE_G4, NOTE_A4,NOTE_A4, NOTE_G4, 
//  NOTE_F4, NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4, 
//  NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,
//  NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,
//  NOTE_C4, NOTE_C4,NOTE_G4, NOTE_G4, NOTE_A4,NOTE_A4, NOTE_G4,
//  NOTE_F4, NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4
};

int melody_size = sizeof(melody) / sizeof(melody[0]);

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  Serial.println("DEBUG DEBUG DEBUG");
  Serial.print("melody_size: ");
  Serial.println(melody_size);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // ONされて一回だけ実行
  if(buttonState == 1 && ready_tone == 1){
//  if(buttonState == 1){

  // 最後の音まで来たらリセット
  if(thisNote >= (melody_size)){
    Serial.print("if melody_size: ");
    Serial.println(melody_size);
    Serial.print("if thisNote: ");
    Serial.println(thisNote);
    thisNote = 0;
  }
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
//    int noteDuration = 1000 / noteDurations[thisNote];
    int noteDuration = 1000 / 8;
//    tone(8, melody[thisNote], noteDuration);
    tone(8, melody[thisNote]);
    Serial.print("tone: ");
    Serial.println(melody[thisNote]);
    Serial.print("thisNote: ");
    Serial.println(thisNote);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
//    int pauseBetweenNotes = noteDuration * 1.30;
//    delay(pauseBetweenNotes);
    // stop the tone playing:
//    noTone(8);

//    thisNote++;

    // ifを何度も実行しないようにフラグを立てる
    ready_tone = 0;

  }

  // OFFされて一回だけ実行
  if (buttonState == 0 && ready_tone == 0) {
    thisNote++;
    noTone(8);
    ready_tone = 1;
  }

}
