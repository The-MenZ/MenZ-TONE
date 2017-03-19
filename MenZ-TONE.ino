#include <TimerOne.h>
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
const int anode_pins[] = {9, 10, 11, 5, 6, 7, 8};    // アノードに接続するArduinoのピン
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
int melody[5][143] = {
  {
     // パーパパパーパーパーパー
     NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, NOTE_B3, NOTE_C4,
     0
  },
  {
    // キラキラ星
    NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
    NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,
    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
    NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
    NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,
    0
  },
  {
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
    NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4,
    0
  },
  // ようこそなんとかパークへ
  {
    NOTE_F4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4,
    NOTE_AS4, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_F4,
    NOTE_F4, NOTE_D5, NOTE_C5, NOTE_F4, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_F4, NOTE_G4,
    0
  },
  // 君が代
  {
    NOTE_D4,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_G4,NOTE_E4,NOTE_D4,NOTE_E4,
    NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_D5,NOTE_B4,NOTE_A4,NOTE_G4,
    NOTE_E4,NOTE_G4,NOTE_A4,NOTE_D5,NOTE_C5,NOTE_D5,NOTE_E4,NOTE_G4,
    NOTE_A4,NOTE_G4,NOTE_E4,NOTE_G4,NOTE_D4,NOTE_A4,NOTE_C5,NOTE_D5,
    NOTE_C5,NOTE_D5,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_E4,NOTE_D4,
    0
  },
};

void ledBlink() {
  static boolean output = LOW;  // プログラム起動前に１回だけHIGH(1)で初期化される
  digitalWrite(PowerLedPin, output);      // 13番ピン(LED)に出力する(HIGH>ON LOW>OFF)
  output = !output;              // 現在のoutput内容を反転(HIGH→LOW/LOW→HIGH)させoutputにセットする
}

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
  PORTD = B11100000;

//  digitalWrite(PowerLedPin, HIGH);
  Timer1.initialize(1000000); //マイクロ秒単位で設定
  Timer1.attachInterrupt(ledBlink);

  pinMode(buttonPin, INPUT);
  pinMode(upButtonPin, INPUT);

  Serial.begin(9600);
  Serial.println("DEBUG DEBUG DEBUG");
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

const int digits[] = {
  0b01000000, // 0
  0b01110011, // 1
  0b00100100, // 2
  0b00100001, // 3
  0b00010011, // 4
  0b00001001, // 5
  0b00001000, // 6
  0b01000011, // 7
  0b00000000, // 8
  0b00000001, // 9
};

  if(melodyNo == 0){
    for (int i = 0; i < (sizeof(anode_pins) / sizeof(anode_pins[0])); i++) {
      digitalWrite(anode_pins[i], digits[1] & (1 << i) ? HIGH : LOW);
    }
  } else if(melodyNo == 1){
    for (int i = 0; i < (sizeof(anode_pins) / sizeof(anode_pins[0])); i++) {
      digitalWrite(anode_pins[i], digits[8] & (1 << i) ? HIGH : LOW);
    }
  } else if(melodyNo == 2){
    for (int i = 0; i < (sizeof(anode_pins) / sizeof(anode_pins[0])); i++) {
      digitalWrite(anode_pins[i], digits[9] & (1 << i) ? HIGH : LOW);
    }
  } else if(melodyNo == 3){
    for (int i = 0; i < (sizeof(anode_pins) / sizeof(anode_pins[0])); i++) {
      digitalWrite(anode_pins[i], digits[melodyNo] & (1 << i) ? HIGH : LOW);
    }
  }

  lastUpButtonState = reading;

  // ONされて一回だけ実行
  if(buttonState == 1 && ready_tone == 1){
    digitalWrite(ledPin, HIGH);

    // 最後の音まで来たらリセット
    if(melody[melodyNo][thisNote] == 0){
      // Serial.print("if melody_size: ");
      // Serial.println(melody_size);
      Serial.print("if thisNote: ");
      Serial.println(thisNote);
      thisNote = 0;
    }

      int noteDuration = 1000 / 8;
      tone(14, melody[melodyNo][thisNote]);
      Serial.print("tone: ");
      Serial.println(melody[melodyNo][thisNote]);
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
