//const int songNum = 10;

// MMLは320文字以内で
const static char mml0[] PROGMEM = "t120 c4<g8g8a4g4r4b4>c4";
const static char mml1[] PROGMEM = "t100 g8a8b2. a8g8r4g8a8b8 a8g8a1";
const static char mml2[] PROGMEM = "t100 r4c4c4g4 g4a4a4g2 f4f4e4 e4d4d4c2 g4g4f4 f4e4e4d2 g4g4f4 f4e4e4d2 c4c4g4 g4a4a4g2 f4f4e4 e4d4d4c2";
const static char mml3[] PROGMEM = "t98 a4.>c8c2 <a4.g8f2 g4.a8>c4. <a8g1 a4.>c8c2 <a4.g8f2 g4a4g4. f8f1";
const static char mml4[] PROGMEM = "t100 c8d8d+8f8g2 g4g+8f8g2 g4>c4d+4 c4d1 c4c4<g+4 g+4g4g4f4 g+4g4g+4g4 g4c1";
const static char mml5[] PROGMEM = "t120 d2d4a2 a4e4.f8 e4d2. <d>a>cd2 c4<a4b4 g4a2. >d2d4c2 <a4a4g4 f4e2. d2a4g2 f4e4d4 c4d2&d8";
const static char mml6[] PROGMEM = "t60 d4c4d4e4 g4e4d2 e4g4a4g8a8 >d4<b4a4g4 e4g4a2 >d4c4d2 <e4g4a4g4 e4.g8d2 a4>c4d2 c4d4<a4g4 a4g8e8d2";
const static char mml7[] PROGMEM = "t100 >c4c8d8c8c8 c4c8c16c16c8<a+16a+16>c8c16<a+16 g4>c8<a+8>c8<a+8>c8c16<a+16 g4>c8c8c8d8c8c8 c4c8<a+16a+16>c8<a+16a+16>c8c16<a+16 g4>c16c16c16c16c8d8c8.<a+16 >c8";
const static char mml8[] PROGMEM = "t100 a2a4 g4a4a8g8e2 a+4a+8a+8>d4 <a+8a8a+8a8g8g8a2 a+4a+4a+8>d8 <a+8a8a+8a8g8g8a2 f4.f8a4 f8e8f8e8d8d8e2 f8f4f8a8a8 f8e8f8e8d8d8e2 a+8a+8a+8a+8>d8d8 <a+8a8a+8a8g8g8a4. f8f8f8f8f8f8a8 f8e8f8e8d8d8e2& e8a8a8a8a8a8 a8g8a8a8a8g8d8d8 e4.d8e8f8g8a8 a+8a8a+4>d4e8d8 <a+4a4a8g8a2";
const static char mml9[] PROGMEM = "t80 d4g4.g8g4 b4a4.g8a4 b4g4g4><b4 >d4e2. e4d4.<b8><b4 g4a4.g8a4 b4g4.e8e4 d4g2. >e4d4.<b8b4 g4a4.g8a4 >e4d4.<b8><b4 >d4e2. e4d4.<b8b4 g4a4.g8a4 b4g4.e8e4 d4g2";

// Then set up a table to refer to your strings.

const char* const mml_list[] PROGMEM = {
  mml0,
  mml1,
  mml2,
  mml3,
  mml4,
  mml5,
  mml6,
  mml7,
  mml8,
  mml9
};

//
//const PROGMEM uint16_t melody[songNum][256] =
//{
//  // ようこそなんとかパークへ
//  {
//    NOTE_F4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4,
//    NOTE_AS4, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_F4,
//    NOTE_F4, NOTE_D5, NOTE_C5, NOTE_F4, NOTE_AS4, NOTE_A4,
//    NOTE_G4, NOTE_F4, NOTE_G4,
//    0
//  },
//  // なんとかなんとかミッション
//  { NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_DS4, NOTE_C5,
//    NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_DS4,
//    NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_G4,
//    NOTE_D5, NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_DS4,
//    NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_GS5, NOTE_G5,
//    NOTE_AS4, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_C5, NOTE_AS4,
//    0
//  },
//  // yryr
//  {
//    NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4,
//    NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_G4, NOTE_F4,
//    NOTE_G4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4,
//    NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_G4,
//    NOTE_F4, NOTE_G4, NOTE_DS4, NOTE_DS4, NOTE_DS4,
//    NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4,
//    NOTE_G4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_D4, NOTE_D4, NOTE_DS4,
//    0
//  },
//  // なん本桜
//  {
//    NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, REST, NOTE_A4,
//    NOTE_C5, NOTE_D5, NOTE_G4, NOTE_F4, NOTE_A4,
//    NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, REST, NOTE_A4,
//    NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4,
//    NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, REST, NOTE_A4,
//    NOTE_C5, NOTE_D5, NOTE_G4, NOTE_F4, NOTE_A4,
//    NOTE_D4, NOTE_F4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4,
//    NOTE_A4, NOTE_E4, NOTE_C4, NOTE_D4,
//    0
//  },
//  // なんとかのなんとかリオン
//  {
//    NOTE_E4, NOTE_E4, NOTE_B4, NOTE_B4,
//    NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_GS4, NOTE_FS4,
//    NOTE_E4, NOTE_E5, NOTE_DS5, NOTE_B4, NOTE_CS5, REST,
//    NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_CS5,
//    NOTE_B4, NOTE_GS4, NOTE_FS4, NOTE_E4, NOTE_FS4, NOTE_GS4,
//    NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_B4, NOTE_GS4, REST,
//    NOTE_A4, NOTE_GS4, NOTE_FS4,
//    0
//  },
//  // 鳥のなんとか
//  {
//    NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_A5,
//    NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_FS5, REST,
//    NOTE_E5, NOTE_FS5, NOTE_A5, NOTE_E5, NOTE_CS5, NOTE_D5,
//    NOTE_CS5, NOTE_CS5, NOTE_B4, NOTE_FS4, REST,
//    NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_A5,
//    NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_FS5, REST,
//    NOTE_E5, NOTE_FS5, NOTE_A5, NOTE_FS5, NOTE_A5, NOTE_D6,
//    NOTE_CS6, NOTE_B5, NOTE_FS5, NOTE_E5,
//    NOTE_FS5, NOTE_A5, NOTE_B5, NOTE_CS6,
//    NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_FS5, REST,
//    NOTE_E5, NOTE_FS5, NOTE_A5, NOTE_E5, NOTE_CS5, NOTE_D5,
//    NOTE_CS5, NOTE_CS5, NOTE_B4, NOTE_FS4, REST,
//    
//    NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_A5,
//    NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_FS5, REST,
//    NOTE_E5, NOTE_FS5, NOTE_A5, NOTE_FS5, NOTE_A5, NOTE_D6,
//    NOTE_CS6, NOTE_B5,
//    NOTE_B5, NOTE_B5,
//    NOTE_CS6, NOTE_B5,
//    NOTE_B5,
//    0
//  },
//  // 残酷なやつ
//  {
//    NOTE_C5, NOTE_DS5, NOTE_F5, NOTE_DS5, NOTE_F5,
//    NOTE_F5, NOTE_F5, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_F5, NOTE_G5,
//    NOTE_G5, NOTE_AS5, NOTE_C6, NOTE_F5, NOTE_DS5,
//    NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_F5, NOTE_DS5, NOTE_DS5,
//
//    NOTE_C5, NOTE_DS5, NOTE_F5, NOTE_DS5, NOTE_F5,
//    NOTE_F5, NOTE_F5, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_F5, NOTE_G5,
//    NOTE_G5, NOTE_AS5, NOTE_C6, NOTE_F5, NOTE_DS5,
//    NOTE_AS5, NOTE_AS5, NOTE_G5, NOTE_AS5, NOTE_AS5, NOTE_C6,
//
//    NOTE_C5, NOTE_DS5, NOTE_F5, NOTE_DS5, NOTE_F5,
//    NOTE_F5, NOTE_F5, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_F5, NOTE_G5,
//    NOTE_G5, NOTE_AS5, NOTE_C6, NOTE_F5, NOTE_DS5,
//    NOTE_AS5, NOTE_AS5, NOTE_G5, NOTE_AS5, NOTE_AS5, NOTE_C6,
//    0
//  },
//  // 翔べなにダム
//  {
//    NOTE_E4, NOTE_G4, NOTE_C5, NOTE_C5, NOTE_C5,
//    NOTE_E4, NOTE_G4, NOTE_C5, NOTE_C5, NOTE_C5,
//    NOTE_E4, NOTE_G4, NOTE_C5, NOTE_C5, NOTE_C5,
//    NOTE_B4, NOTE_A4, NOTE_B4, NOTE_B4, REST,
//    NOTE_G4, NOTE_G4, NOTE_A4, REST,
//    NOTE_A4, NOTE_G4, NOTE_A4, REST,
//
//    NOTE_E4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C5, NOTE_A4, REST,
//    NOTE_E4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C5, NOTE_A4, REST,
//    NOTE_A4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_C5, REST,
//    NOTE_C5, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_F5, NOTE_E5, NOTE_D5, REST,
//    NOTE_G4, NOTE_G4, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4, REST,
//    NOTE_B4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_G4, REST,
//    NOTE_G4, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_E5, REST,
//    NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, REST,
//    NOTE_D5, NOTE_C5, NOTE_C5, NOTE_C5,
//    0
//  },
//  // Godなんとか
//  {
//    NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4,
//    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4,
//    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_C5,
//    NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_D5,
//    NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
//
//    NOTE_D4, NOTE_D4, NOTE_A4, REST, NOTE_A4,
//    NOTE_G4, NOTE_A4, NOTE_C5, NOTE_G4,
//    NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4,
//    NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4,
//
//    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4,
//    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_C5,
//    NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_D5,
//
//    NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
//    NOTE_D4, NOTE_A4, NOTE_A4,
//    NOTE_G4, NOTE_A4, NOTE_C5, NOTE_G4,
//    NOTE_G4, NOTE_F4,
//
//    REST, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
//    0
//  },
//  // Auld Lang Syne
//  {
//    NOTE_C4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_A4, NOTE_G4, NOTE_F4,
//    NOTE_G4, NOTE_A4, NOTE_F4, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_D5, REST,
//
//    NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4,
//    NOTE_G4, NOTE_A4, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_F4, REST,
//
//    NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4,
//    NOTE_G4, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, REST,
//
//    NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4,
//    NOTE_G4, NOTE_A4, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_F4,
//    0
//  }
//
//};
//
//const PROGMEM uint16_t defaultSongs[songNum][256] =
//{
//  // パーパパパーパーパーパー
//  {
//     NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, NOTE_B3, NOTE_C4,
//     0
//  },
//  // キラキラ星
//  {
//    NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
//    NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,
//    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
//    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
//    NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
//    NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,
//    0
//  },
//  // ナウシカレクイエム
//  {
//    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4,
//    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_GS4,
//    NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_E4,
//    NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4,
//    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4,
//    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4,
//    NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4,
//    NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_B4,
//    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4,
//    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4,
//    NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_E4,
//    NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4,
//    NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4,
//    NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C5, NOTE_C5,
//    NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D4, NOTE_A4, NOTE_D4,
//    NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_B4,
//    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4,
//    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4,
//    NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_E4,
//    NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4,
//    0
//  },
//  // ようこそなんとかパークへ
//  {
//    NOTE_F4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4,
//    NOTE_AS4, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_F4,
//    NOTE_F4, NOTE_D5, NOTE_C5, NOTE_F4, NOTE_AS4, NOTE_A4,
//    NOTE_G4, NOTE_F4, NOTE_G4,
//    0
//  },
//  // 君が代
//  {
//    NOTE_D4,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_G4,NOTE_E4,NOTE_D4,NOTE_E4,
//    NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_D5,NOTE_B4,NOTE_A4,NOTE_G4,
//    NOTE_E4,NOTE_G4,NOTE_A4,NOTE_D5,NOTE_C5,NOTE_D5,NOTE_E4,NOTE_G4,
//    NOTE_A4,NOTE_G4,NOTE_E4,NOTE_G4,NOTE_D4,NOTE_A4,NOTE_C5,NOTE_D5,
//    NOTE_C5,NOTE_D5,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_E4,NOTE_D4,
//    0
//  }
//};
//
//const PROGMEM uint16_t tempoList[songNum] = {
//  170, // ようこそなんとかパークへ
//  80,  // なんとかなんとかミッション
//  173, // yryr
//  154, // 何本桜
//  151, // なんとかのなんとかリオン
//  120, // 鳥のなんとか
//  150, // 残酷なやつ
//  143, // 翔べなにダム
//  150, // Godなんとか
//  90, // Auld Lang Syne
//};
//
//const PROGMEM float noteDurations[songNum][256] =
//{
//  // ようこそなんとかパークへ
//  {
//    8, 8, 8, 4, 8, 8, 4,
//    8, 8, 4, 8, 8, 8, 
//    4, 4, 4, 4, 8, 8,
//    8, 8, 2,
//    0
//  },
//  // なんとかなんとかミッション
//  { 5.33, 5.33, 5.33, 5.33,
//    8, 2, 16, 16, 8, 16, 16,
//    16, 8, 8, 5.33, 5.33, 5.33,
//    16, 8, 16, 16, 16, 2.67, 16,
//    16, 8, 16, 16, 16, 8, 8,
//    0
//  },
//  // yryr
//  { 4, 8, 4, 4, 4, 4, 8, 8,
//    8, 8, 8, 4, 8, 4, 4, 4,
//    4, 8, 8, 8, 8, 8, 4, 8,
//    4, 4, 4, 4, 8, 8, 8, 8,
//    8, 4, 4, 8, 4, 4,
//    0
//  },
//  // 何本桜
//  {
//    8, 8, 6, 6, 8, 4, 8, 8,
//    8, 8, 8, 8, 4,
//    8, 8, 6, 6, 8, 4, 8, 8,
//    8, 8, 8, 8, 4,
//    8, 8, 6, 6, 8, 4, 8, 8,
//    8, 8, 8, 8, 4,
//    8, 8, 4, 4, 4, 4, 8,
//    8, 8, 8, 4,
//    0
//  },
//  // なんとかのなんとかリオン
//  {
//    4, 4, 4, 4,
//    4, 8, 8, 4, 8, 8,
//    4, 4, 4, 4, 2, 4,
//    4, 4, 4, 8, 8,
//    4, 8, 8, 4, 8, 8,
//    8, 8, 8, 8, 4, 8, 4, 8,
//    16, 16, 4,
//    0
//  },
//  // 鳥のなんとか
//  {
//    4, 8, 8, 8,
//    4, 8, 16, 2, 4,
//    8, 8, 8, 8, 8, 8,
//    4, 8, 16, 2, 4, 
//    4, 8, 8, 8,
//    4, 8, 16, 2, 4,
//    8, 8, 8, 8, 8, 8,
//    
//    6, 6, 3, 6,
//    4, 4, 4, 4,
//    
//    4, 8, 16, 2, 4,
//    8, 8, 8, 8, 8, 8,
//    4, 8, 16, 2, 4,
//    
//    4, 8, 8, 8,
//    4, 8, 16, 2, 4,
//    8, 8, 8, 8, 8, 8,
//    1, 8,
//    2, 4,
//    1, 8,
//    2,
//    0
//  },
//  // 残酷なやつ
//  {
//    4, 4, 6, 6, 8,
//    8, 8, 8, 8, 16, 8, 3,
//    4, 4, 6, 6, 8,
//    8, 8, 8, 8, 16, 8, 3,
//    
//    4, 4, 6, 6, 8,
//    8, 8, 8, 8, 16, 8, 3,
//    4, 4, 6, 6, 8,
//    8, 8, 8, 8, 6, 3,
//    
//    4, 4, 6, 4, 8,
//    8, 8, 8, 8, 16, 8, 3,
//    4, 4, 6, 4, 8,
//    8, 8, 8, 8, 6, 4,
//    0
//  },
//  // 翔べなにダム
//  {
//    8, 8, 8, 4, 3,
//    8, 8, 8, 4, 3,
//    8, 8, 8, 4, 3,
//    8, 8, 8, 3, 4,
//    8, 8, 1, 4,
//    8, 8, 1, 2,
//
//    8, 8, 8, 8, 8, 4, 4, 8, 4, 4,
//    8, 8, 8, 3, 8, 4, 8, 4, 4,
//    8, 8, 8, 3, 8, 8, 4, 4,
//    8, 8, 4, 8, 8, 4, 8, 8, 4, 4,
//    8, 8, 8, 3, 8, 8, 8, 3, 4,
//    8, 8, 8, 3, 8, 8, 3, 8, 4,
//    8, 8, 2, 4, 8, 4, 4,
//    8, 4, 8, 4, 4,
//    8, 8, 8, 8,
//    0
//  },
//  // Godなんとか
//  {
//    4, 8, 4,
//    4, 8, 8, 16, 6, 4,
//    4, 8, 8, 16, 6, 4,
//    4, 8, 8, 4, 8, 8,
//    4, 4, 4, 8, 8, 8,
//
//    4, 8, 3, 8,
//    8, 4, 4, 4, 4,
//    2, 8, 8, 3,
//    4, 8, 4,
//    4, 8, 8, 16, 6, 4,
//    4, 8, 8, 16, 6, 4,
//
//    4, 8, 8, 4, 8, 8, 4, 4,
//    4, 8, 8, 8, 3, 2,
//    8, 4, 4, 4, 4, 3, 2,
//
//    4, 4, 8, 4, 8, 2, 2,
//
//    0
//  },
//  // Auld Lang Syne
//  {
//    4, 3, 8, 4, 4, 3, 8, 4,
//    4, 4, 4, 4, 4, 2, 4,
//    4, 3, 8, 4, 4, 3, 8, 4,
//    4, 3, 8, 4, 4, 2, 4,
//    4, 3, 8, 4, 4, 3, 8, 4,
//    4, 3, 8, 4, 4, 2, 4,
//    4, 3, 8, 4, 4, 3, 8, 4,
//    4, 3, 8, 4, 4, 2,
//    0 
//  }
//};

