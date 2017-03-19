#include <avr/pgmspace.h>
#include "pitches.h"
#include "songs.h"

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

const int buttonPin = 3;    // the number of the pushbutton pin
int buttonState = 0;             // the current reading from the input pin

const int upButtonPin = 4;    // the number of the pushbutton pin
int upButtonState;             // the current reading from the input pin
int lastUpButtonState = LOW;             // the current reading from the input pin

long upButtonDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

int currentSong = 0;
int currentPosition = 0;
int readyTone = 1;
int nowNote;

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

  digitalWrite(PowerLedPin, HIGH);

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
        currentPosition = 0;
        currentSong++;
        if(currentSong >= songNum) currentSong = 0;
      }
    }
  }

  if(currentSong == 0){
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
  } else if(currentSong == 1){
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
  } else if(currentSong == 2){
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
  if(buttonState == 1 && readyTone == 1){
    digitalWrite(ledPin, HIGH);
    nowNote = pgm_read_word(&melody[currentSong][currentPosition]);
    // 最後の音まで来たらリセット
    if(nowNote == 0){
      // Serial.print("if melody_size: ");
      // Serial.println(melody_size);
      Serial.print("if currentPosition: ");
      Serial.println(currentPosition);
      currentPosition = 0;
      nowNote = pgm_read_word(&melody[currentSong][currentPosition]);
    }

    tone(14, nowNote);
    Serial.print("tone: ");
    Serial.println(nowNote);
    Serial.print("currentPosition: ");
    Serial.println(currentPosition);

    // ifを何度も実行しないようにフラグを立てる
    readyTone = 0;

  }

  // OFFされて一回だけ実行
  if (buttonState == 0 && readyTone == 0) {
    digitalWrite(ledPin, LOW);
    currentPosition++;
    noTone(14);
    delay(50);
    readyTone = 1;
  }

}
