const int songNum = 10;

const PROGMEM uint16_t melody[songNum][256] =
{
  // パーパパパッパパッパ
  {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3,
    NOTE_G3, REST, NOTE_B3, NOTE_C4, 0
  },
  // チャルメラ
  {
    NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4,
    NOTE_G4, REST, NOTE_G4, NOTE_A4, NOTE_B4,
    NOTE_A4, NOTE_G4, NOTE_A4,
    0
  },
  // きらきら星
  {
    NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4,
    NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
    NOTE_D4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4,
    NOTE_E4, NOTE_E4, NOTE_D4, NOTE_G4, NOTE_G4, NOTE_F4,
    NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4,
    NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4,
    NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,
    0
  },
  // 遠き山に日は落ちて
  {
    NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_F4,
    NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_A4,
    NOTE_C5, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4,
    NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4,
    0
  },
  // 赤い靴
  {
    NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_G4,
    NOTE_GS4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_C5, NOTE_DS5,
    NOTE_C5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_GS4, NOTE_GS4,
    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_GS4, NOTE_G4, NOTE_GS4,
    NOTE_G4, NOTE_G4, NOTE_C4,
    0
  },
  // かえるのうた
  {
    NOTE_F4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, 
    NOTE_F4, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_C5, 
    NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, 
    NOTE_F4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, 
    NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, 
    0
  },
  // 君が代
  {
    NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4,
    NOTE_D4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4,
    NOTE_D5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_G4,
    NOTE_A4, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_E4, NOTE_G4,
    NOTE_A4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_D4, NOTE_A4,
    NOTE_C5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_A4, NOTE_G4,
    NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4,
    0
  },
  // 通りゃんせ
  {
    NOTE_A4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_A4,
    NOTE_G4, NOTE_E4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
    NOTE_D5, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_AS4,
    NOTE_AS4, NOTE_D5, NOTE_AS4, NOTE_A4, NOTE_AS4,
    NOTE_A4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_F4,
    NOTE_F4, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_F4,
    NOTE_E4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_F4,
    NOTE_F4, NOTE_F4, NOTE_A4, NOTE_A4, NOTE_F4,
    NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_D4,
    NOTE_E4, //NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
//    NOTE_D5, NOTE_D5, NOTE_AS4, NOTE_A4, NOTE_AS4,
//    NOTE_A4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_F4,
//    NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4,
//    NOTE_A4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_E4,
//    NOTE_D4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_A4,
//    NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4,
//    NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4,
//    NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4,
//    NOTE_F4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_A4,
//    NOTE_AS4, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_AS4,
//    NOTE_A4, NOTE_A4, NOTE_G4, NOTE_A4,
    0
  },
  // かごめかごめ
  {
    NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_C5,
    NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_AS4,
    NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_G4, NOTE_C5, NOTE_AS4,
    NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_G4,
    NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_C5,
    NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_AS4, NOTE_C5, NOTE_AS4,
    NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_G4, NOTE_C5,
    NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5,
    0
  },
  // Auld Lang Syne
  {
    NOTE_D4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_B4,
    NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_G4,
    NOTE_G4, NOTE_B4, NOTE_D5, NOTE_E5, NOTE_E5,
    NOTE_D5, NOTE_B4, NOTE_B4, NOTE_G4, NOTE_A4,
    NOTE_G4, NOTE_A4, NOTE_B4, NOTE_G4, NOTE_E4,
    NOTE_E4, NOTE_D4, NOTE_G4, NOTE_E5, NOTE_D5,
    NOTE_B4, NOTE_B4, NOTE_G4, NOTE_A4, NOTE_G4,
    NOTE_A4, NOTE_E5, NOTE_D5, NOTE_B4, NOTE_B4,
    NOTE_D5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_B4,
    NOTE_B4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4,
    NOTE_B4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_G4,
    0
  }

};

const PROGMEM uint16_t tempoList[songNum] = {
  120, // パーパパパッパパッパ
  120, // チャルメラ
  120, // きらきら星
  110,  // 遠き山に日は落ちて
  120, // 赤い靴
  76, // かえるのうた
  80,  // 君が代
  110, // 通りゃんせ
  110, // かごめかごめ
  90, // Auld Lang Syne
};

const PROGMEM float noteDurations[songNum][256] =
{
  // パーパパパッパパッパ
  {
    4, 8, 8, 4, 4, 4, 4, 4,
    0
  },
  // チャルメラ
  { 
    8, 8, 1.33, 8, 8, 4,
    8, 8, 8, 8, 8, 1,
    0
  },
  // きらきら星
  { 
    4, 4, 4, 4, 4, 4, 2,
    4, 4, 4, 4, 4, 4, 2,
    4, 4, 4, 4, 4, 4, 2,
    4, 4, 4, 4, 4, 4, 2,
    4, 4, 4, 4, 4, 4, 2,
    4, 4, 4, 4, 4, 4, 2,
    0
  },
  // 遠き山に日は落ちて
  {
    2.67, 8, 2, 2.67, 8, 2, 2.67,
    8, 2.67, 8, 1, 2.67, 8, 2, 2.67,
    8, 2, 4, 4, 2.67, 8, 1,
    0
  },
  // 赤い靴
  {
    8, 8, 8, 8, 2, 4, 8, 8, 2,
    4, 4, 4, 4, 1, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 1,
    0
  },
  // かえるのうた
  { 
    8, 8, 8, 8, 8, 8, 4, 8, 8, 
    8, 8, 8, 8, 4, 4, 4, 4, 4, 
    16, 16, 16, 16, 16, 16, 16, 
    16, 8, 8, 4, 
    0
  },
  // 君が代
  {
    4, 4, 4, 4, 4, 4, 2,
    4, 4, 4, 8, 8, 4, 4,
    4, 4, 4, 4, 2, 4, 4,
    2, 4, 4, 4, 4, 2.67,
    8, 2, 4, 4, 2, 4, 4,
    4, 4, 4, 8, 8, 2,
    0
  },
  // 通りゃんせ
  {
    2, 4, 4, 4, 8, 8, 2,
    4, 8, 8, 4, 8, 8, 8,
    8, 8, 8, 2, 4, 4, 8,
    8, 8, 8, 8, 8, 8, 8,
    2, 2.67, 8, 4, 8, 8,
    8, 8, 8, 8, 2, 8, 4,
    8, 8, 8, 8, 8, 8, 8,
    8, 8, 2, //8, 8, 8, 8,
//    8, 8, 8, 8, 8, 8, 8,
//    8, 2.67, 8, 8, 8, 8,
//    8, 8, 8, 8, 8, 8, 8,
//    8, 8, 2, 8, 8, 8, 8,
//    8, 8, 8, 8, 8, 8, 8,
//    8, 8, 8, 2.67, 8, 8,
//    8, 8, 8, 8, 8, 4, 4,
//    8, 8, 4, 4, 8, 8, 2,
    0
  },
  // かごめかごめ
  {
    4, 8, 8, 8, 8, 4, 8,
    16, 16, 8, 16, 16, 8,
    16, 16, 4, 8, 8, 8, 8,
    8, 16, 16, 4, 8, 8, 8,
    8, 8, 8, 4, 8, 16, 16,
    8, 16, 16, 8, 16, 16,
    4, 16, 16, 16, 16, 8,
    8, 5.33, 16, 8,
    0
  },
  // Auld Lang Syne
  {
    4, 2.67, 8, 4, 4, 2.67,
    8, 4, 4, 4, 4, 4, 4, 1.33,
    4, 2.67, 8, 4, 4, 2.67, 8,
    4, 4, 2.67, 8, 4, 4, 1.33,
    4, 2.67, 8, 4, 4, 2.67, 8,
    4, 4, 2.67, 8, 4, 4, 1.33,
    4, 2.67, 8, 4, 4, 2.67, 8,
    4, 4, 2.67, 8, 4, 4, 2,
    0 
  }
};

