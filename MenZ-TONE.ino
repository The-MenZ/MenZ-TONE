#include <TimerOne.h>
#include <avr/pgmspace.h>
// #include "mml.h"
// #include "pitches.h"
#include "songs.h"
// #include "songs2.h"
#include <avr/sleep.h>
#include "menzmml.h"

const int PowerLedPin = 15;      // the number of the LED pin
const int ledPin = 2;      // the number of the LED pin
const int anode_pins[] = {9, 10, 11, 5, 6, 7, 8, 12};    // アノードに接続するArduinoのピン
//const int digits[] = {
volatile int digits[] = {
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

volatile int bootDigits[] = {
//  0b11111011, // 4
//  0b11111101, // 5
//  0b11111110, // 6
//  0b10111111, // 0
//  0b11110111, // 3
//  0b11101111, // 2
//  0b11011111, // 1
//  0b10111111, // 0
//  0b11111011, // 4

  0b11111101, // 5
  0b11111100, // 6
  0b10111110, // 0
  0b10110111, // 3
  0b11100111, // 2
  0b11001111, // 1
  0b10011111, // 0
  0b10111011, // 4
  0b11111001, // 5
  0b11111101, // 5
};

const int buttonPin = 3;    // the number of the pushbutton pin
int buttonState = 0;             // the current reading from the input pin

const int upButtonPin = 13;    // the number of the pushbutton pin
int upButtonState;             // the current reading from the input pin
int lastUpButtonState = LOW;             // the current reading from the input pin

unsigned long upButtonDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

const int downButtonPin = 4;    // the number of the pushbutton pin
int downButtonState;             // the current reading from the input pin
int lastDownButtonState = LOW;             // the current reading from the input pin
unsigned long downButtonDebounceTime = 0;  // the last time the output pin was toggled
unsigned long downDebounceDelay = 50;    // the debounce time; increase if the output flickers
int autoPlay = 0;

volatile int currentSong = 0;

//int currentPosition = 0;
int readyTone = 1;

int nowNoteDuration;

unsigned long sleepTime = 300000;
unsigned long sleepTimeCount = millis();

const int songNum = 10;

char mmlBuffer[320];

MenzMML menz_mml;

void ledBlink() {
  static boolean output = LOW;  // プログラム起動前に１回だけHIGH(1)で初期化される
  digitalWrite(PowerLedPin, output);      // 13番ピン(LED)に出力する(HIGH>ON LOW>OFF)
  if(output){
    for (int i = 0; i < (sizeof(anode_pins) / sizeof(anode_pins[0])); i++) {
      digitalWrite(anode_pins[i], digits[currentSong] & (1 << i) ? HIGH : LOW);
    }
  } else {
    for (int i = 0; i < (sizeof(anode_pins) / sizeof(anode_pins[0])); i++) {
      digitalWrite(anode_pins[i], HIGH);
    }
  }
  output = !output;              // 現在のoutput内容を反転(HIGH→LOW/LOW→HIGH)させoutputにセットする
}

void setup() {
  pinMode(PowerLedPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  PORTD = B11100000;

  for(int n = 0; n < 3; n++){
    for(int j = 0; j < (sizeof(bootDigits) / sizeof(bootDigits[0])); j++){
      for (int i = 0; i < (sizeof(anode_pins) / sizeof(anode_pins[0])); i++) {
        digitalWrite(anode_pins[i], bootDigits[j] & (1 << i) ? HIGH : LOW);
      }
      delay(30);
    }
  }
//  digitalWrite(PowerLedPin, HIGH);
//  Timer1.initialize(1000000); //マイクロ秒単位で設定
  Timer1.initialize(13000); //マイクロ秒単位で設定
  Timer1.attachInterrupt(ledBlink);

  pinMode(buttonPin, INPUT);
  pinMode(upButtonPin, INPUT);
  pinMode(downButtonPin, INPUT);
  
  Serial.begin(9600);
  Serial.println("Hello!! We are The-MenZ!!");
  strcpy_P(mmlBuffer, (char*)pgm_read_word(&(mml_list[currentSong])));
  menz_mml.mml_initialize(mmlBuffer);
}

void loop() {
//  delay(1000);
//  menz_mml.fetch_mml();
//  Serial.print("tempo:");
//  Serial.println(menz_mml.tempo);
//  Serial.print("note:");
//  Serial.println(menz_mml.note);
//  Serial.print("duration(relative):");
//  Serial.println(menz_mml.duration);
//  Serial.print("duration(absolute):");
//  Serial.println((int)(((60000 / menz_mml.tempo) * 4) / menz_mml.duration));
  
  int buttonState = digitalRead(buttonPin);

  int reading = digitalRead(upButtonPin);
  if (reading != lastUpButtonState) {
    upButtonDebounceTime = millis();
    // スリープカウントリセット
    sleepTimeCount = millis();
  }

  int downButtonReading = digitalRead(downButtonPin);
  if (downButtonReading != lastDownButtonState) {
    downButtonDebounceTime = millis();
    // スリープカウントリセット
    sleepTimeCount = millis();
  }

  // ボタンプッシュで曲選択
  if ((millis() - upButtonDebounceTime) > debounceDelay) {
    if (reading != upButtonState) {
      upButtonState = reading;

      if (upButtonState == HIGH) {
        //曲の頭出し
        currentSong++;
        if(currentSong >= songNum) currentSong = 0;
        strcpy_P(mmlBuffer, (char*)pgm_read_word(&(mml_list[currentSong])));
        menz_mml.mml_initialize(mmlBuffer);
      }
    }
  }

  // ボタンプッシュで自動演奏
  if ((millis() - downButtonDebounceTime) > downDebounceDelay) {
    if (downButtonReading != downButtonState) {
      downButtonState = downButtonReading;
      autoPlay = 1;
    }
  }

  // 自動演奏モード
  if(autoPlay == 1){
    menz_mml.fetch_mml();
    // 最後の音まで来たらリセット
    if(menz_mml.note == MenzMML::NOTE_END) {
      menz_mml.reset_cursol();
      autoPlay = 0;
    } else {
      if (menz_mml.note > MenzMML::REST) {
        tone(14, menz_mml.note);
      }
      // TODO:MenzMMLでgetAbsoluteDuration()とかやってもいい気がする
      nowNoteDuration = (int)(((60000 / menz_mml.tempo) * 4) / menz_mml.duration);
      delay(nowNoteDuration);

      noTone(14);
    }

  }

  // ONされて一回だけ実行
  if(buttonState == 1 && readyTone == 1){
    digitalWrite(ledPin, HIGH);
    menz_mml.fetch_mml();
    autoPlay = 0;
    // 1はスキップ
    if(menz_mml.note == MenzMML::REST){
      menz_mml.fetch_mml();
    }
    // 最後の音まで来たらリセット
    if(menz_mml.note == MenzMML::NOTE_END){
      menz_mml.reset_cursol();
      menz_mml.fetch_mml();
    }

    tone(14, menz_mml.note);

    // ifを何度も実行しないようにフラグを立てる
    readyTone = 0;

    // スリープカウントリセット
    sleepTimeCount = millis();
  }

  // OFFされて一回だけ実行
  if (buttonState == 0 && readyTone == 0) {
    digitalWrite(ledPin, LOW);
    noTone(14);
    delay(50);
    readyTone = 1;
  }

  lastUpButtonState = reading;
  lastDownButtonState = downButtonReading;

  // スリープチェック
  if ((millis() - sleepTimeCount) > sleepTime) {
    for (int i = 0; i < (sizeof(anode_pins) / sizeof(anode_pins[0])); i++) {
      digitalWrite(anode_pins[i], HIGH);
    }
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_mode();
  }
}
