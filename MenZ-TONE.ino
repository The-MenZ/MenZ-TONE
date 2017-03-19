
#include "pitches.h"

const int PowerLedPin = 13;      // the number of the LED pin
const int ledPin = 2;      // the number of the LED pin

const int seg1Pin = 9;      // the number of the LED pin
const int seg2Pin = 10;      // the number of the LED pin
const int seg4Pin = 11;      // the number of the LED pin
const int seg5Pin = 12;      // the number of the LED pin x
const int seg6Pin = 5;      // the number of the LED pin
const int seg7Pin = 6;      // the number of the LED pin
const int seg9Pin = 7;      // the number of the LED pin
const int seg10Pin = 8;      // the number of the LED pin
int melodyNo = 0;

const int buttonPin = 3;    // the number of the pushbutton pin
int buttonState = 0;             // the current reading from the input pin

const int upButtonPin = 4;    // the number of the pushbutton pin
int upButtonState;             // the current reading from the input pin
int lastUpButtonState = LOW;             // the current reading from the input pin

long upButtonDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

int thisNote = 0;
int ready_tone = 1;

// notes in the melody:

int melody[] = {
    // パーパパパーパーパーパー
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, NOTE_B3, NOTE_C4
};

    // キラキラ星
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
//int melody[] = {
//    NOTE_C4, NOTE_C4,NOTE_G4, NOTE_G4, NOTE_A4,NOTE_A4, NOTE_G4, 
//    NOTE_F4, NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4, 
//    NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,
//    NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,
//    NOTE_C4, NOTE_C4,NOTE_G4, NOTE_G4, NOTE_A4,NOTE_A4, NOTE_G4,
//    NOTE_F4, NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4
//};

//int melody[] = {
//  // ナウシカレクイエム
//  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
//  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_GS4, 
//  NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_E4, 
//  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, 
//  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
//  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, 
//  NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
//  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_B4, 
//  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
//  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, 
//  NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_E4, 
//  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, 
//  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, 
//  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C5, NOTE_C5, 
//  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D4, NOTE_A4, NOTE_D4, 
//  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_B4, 
//  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
//  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, 
//  NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_E4, 
//  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4
//};

int melody_size = sizeof(melody) / sizeof(melody[0]);

//int melody[] = {
//  // ナウシカレクイエム
//  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
//  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_GS4, 
//  NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_E4, 
//  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, 
//  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
//  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, 
//  NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
//  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_B4, 
//  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
//  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, 
//  NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_E4, 
//  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, 
//  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, 
//  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C5, NOTE_C5, 
//  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D4, NOTE_A4, NOTE_D4, 
//  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_B4, 
//  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
//  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, 
//  NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_E4, 
//  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4
//};

int melody2[3][143] = {
  {
    // パーパパパーパーパーパー
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, NOTE_B3, NOTE_C4,
    0
  },
  {
    NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
    NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,
    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
    NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
    NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,
    0
  },
  {
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
    NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4,
    0
  }
};

void setup() {
  pinMode(PowerLedPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(seg1Pin, OUTPUT);
  pinMode(seg2Pin, OUTPUT);
  pinMode(seg4Pin, OUTPUT);
  pinMode(seg5Pin, OUTPUT);
  pinMode(seg6Pin, OUTPUT);
  pinMode(seg7Pin, OUTPUT);
  pinMode(seg9Pin, OUTPUT);
  pinMode(seg10Pin, OUTPUT);
//  digitalWrite(seg1Pin, LOW);
//  digitalWrite(seg2Pin, HIGH);
//  digitalWrite(seg3Pin, LOW);
  PORTD = B11100000;

  digitalWrite(PowerLedPin, HIGH);

  pinMode(buttonPin, INPUT);
  pinMode(upButtonPin, INPUT);

  Serial.begin(9600);
  Serial.println("DEBUG DEBUG DEBUG");
  Serial.print("melody_size: ");
  Serial.println(melody_size);

}

void loop() {
  int buttonState = digitalRead(buttonPin);

  int reading = digitalRead(upButtonPin);
  if (reading != lastUpButtonState) {
    upButtonDebounceTime = millis();
  }

  if ((millis() - upButtonDebounceTime) > debounceDelay) {
    if (reading != upButtonState) {
      upButtonState = reading;

      if (upButtonState == HIGH) {
        //曲の頭出し
        thisNote = 0;
        melodyNo = melodyNo + 1;
        if(melodyNo >= 3) melodyNo = 0;
      }
    }
  }

  if(melodyNo == 0){
//    digitalWrite(seg1Pin, LOW);
//    digitalWrite(seg2Pin, LOW);
//    digitalWrite(seg4Pin, LOW);
//    digitalWrite(seg5Pin, HIGH);
//    digitalWrite(seg6Pin, LOW);
//    digitalWrite(seg7Pin, LOW);
//    digitalWrite(seg9Pin, LOW);
//    digitalWrite(seg10Pin, HIGH);
    digitalWrite(seg1Pin, HIGH);
    digitalWrite(seg2Pin, HIGH);
    digitalWrite(seg4Pin, HIGH);
    digitalWrite(seg5Pin, LOW);
    digitalWrite(seg6Pin, HIGH);
    digitalWrite(seg7Pin, HIGH);
    digitalWrite(seg9Pin, HIGH);
    digitalWrite(seg10Pin, LOW);
  } else if(melodyNo == 1){
//    digitalWrite(seg1Pin, HIGH);
//    digitalWrite(seg2Pin, HIGH);
//    digitalWrite(seg4Pin, LOW);
//    digitalWrite(seg5Pin, HIGH);
//    digitalWrite(seg6Pin, LOW);
//    digitalWrite(seg7Pin, HIGH);
//    digitalWrite(seg9Pin, HIGH);
//    digitalWrite(seg10Pin, HIGH);
    digitalWrite(seg1Pin, LOW);
    digitalWrite(seg2Pin, LOW);
    digitalWrite(seg4Pin, HIGH);
    digitalWrite(seg5Pin, LOW);
    digitalWrite(seg6Pin, HIGH);
    digitalWrite(seg7Pin, LOW);
    digitalWrite(seg9Pin, LOW);
    digitalWrite(seg10Pin, LOW);
  } else if(melodyNo == 2){
//    digitalWrite(seg1Pin, LOW);
//    digitalWrite(seg2Pin, LOW);
//    digitalWrite(seg4Pin, HIGH);
//    digitalWrite(seg5Pin, HIGH);
//    digitalWrite(seg6Pin, LOW);
//    digitalWrite(seg7Pin, LOW);
//    digitalWrite(seg9Pin, HIGH);
//    digitalWrite(seg10Pin, LOW);
    digitalWrite(seg1Pin, HIGH);
    digitalWrite(seg2Pin, HIGH);
    digitalWrite(seg4Pin, LOW);
    digitalWrite(seg5Pin, LOW);
    digitalWrite(seg6Pin, HIGH);
    digitalWrite(seg7Pin, HIGH);
    digitalWrite(seg9Pin, LOW);
    digitalWrite(seg10Pin, HIGH);
  }

  lastUpButtonState = reading;


  // ONされて一回だけ実行
  if(buttonState == 1 && ready_tone == 1){
    digitalWrite(ledPin, HIGH);

    // 最後の音まで来たらリセット
    if(melody2[melodyNo][thisNote] == 0){
      Serial.print("if melody_size: ");
      Serial.println(melody_size);
      Serial.print("if thisNote: ");
      Serial.println(thisNote);
      thisNote = 0;
    }

      int noteDuration = 1000 / 8;
      tone(14, melody2[melodyNo][thisNote]);
      Serial.print("tone: ");
      Serial.println(melody2[melodyNo][thisNote]);
      Serial.print("thisNote: ");
      Serial.println(thisNote);

    // ifを何度も実行しないようにフラグを立てる
      ready_tone = 0;

  }

  // OFFされて一回だけ実行
  if (buttonState == 0 && ready_tone == 0) {
    digitalWrite(ledPin, LOW);
    thisNote++;
    noTone(14);
    delay(50);
    ready_tone = 1;
  }

}
