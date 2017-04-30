const int songNum = 10;

const PROGMEM uint16_t melody[songNum][256] =
{
  // ようこそなんとかパークへ
  {
    NOTE_F4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4,
    NOTE_AS4, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_F4,
    NOTE_F4, NOTE_D5, NOTE_C5, NOTE_F4, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_F4, NOTE_G4,
    0
  },
  // なん本桜
  {
    NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, REST, NOTE_A4,
    NOTE_C5, NOTE_D5, NOTE_G4, NOTE_F4, NOTE_A4,
    NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, REST, NOTE_A4,
    NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4,
    NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, REST, NOTE_A4,
    NOTE_C5, NOTE_D5, NOTE_G4, NOTE_F4, NOTE_A4,
    NOTE_D4, NOTE_F4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4,
    NOTE_A4, NOTE_E4, NOTE_C4, NOTE_D4,
    0
  },
  // Daydreamなんとか
  // {
  //   NOTE_G5, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6,
  //   NOTE_AS5, NOTE_AS5, NOTE_GS5, NOTE_GS5, NOTE_G5, NOTE_GS5, NOTE_G5, NOTE_F5,
  //   NOTE_E5, NOTE_AS5, NOTE_E5, NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_G5,
  //   NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_G5, NOTE_G5, NOTE_B5, NOTE_C6,
  //   NOTE_F5, NOTE_G5, NOTE_GS5, NOTE_G5, NOTE_E5, NOTE_GS5, NOTE_G5, NOTE_E5, NOTE_C6, NOTE_AS5,
  //   0
  // },
  // なんとかのなんとかリオン
  {
    NOTE_E4, NOTE_E4, NOTE_B4, NOTE_B4,
    NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_GS4, NOTE_FS4,
    NOTE_E4, NOTE_E5, NOTE_DS5, NOTE_B4, NOTE_CS5,
    NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_CS5,
    NOTE_B4, NOTE_GS4, NOTE_FS4, NOTE_E4, NOTE_FS4, NOTE_GS4,
    NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_B4, NOTE_GS4,
    NOTE_A4, NOTE_GS4, NOTE_FS4,
    0
  },
  // 鳥のなんとか
  {
    NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_A5,
    NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_FS5,
    NOTE_E5, NOTE_FS5, NOTE_A5, NOTE_E5, NOTE_CS5, NOTE_D5,
    NOTE_CS5, NOTE_CS5, NOTE_B4, NOTE_FS4,
    NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_A5,
    NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_FS5,
    NOTE_E5, NOTE_FS5, NOTE_A5, NOTE_FS5, NOTE_A5, NOTE_D6,
    NOTE_CS6, NOTE_B5, NOTE_FS5, NOTE_E5,
    NOTE_FS5, NOTE_A5, NOTE_B5, NOTE_CS6,
    NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_FS5,
    NOTE_E5, NOTE_FS5, NOTE_A5, NOTE_E5, NOTE_CS5, NOTE_D5,
    NOTE_CS5, NOTE_CS5, NOTE_B4, NOTE_FS4,
    NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_A5,
    NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_FS5,
    NOTE_E5, NOTE_FS5, NOTE_A5, NOTE_FS5, NOTE_A5, NOTE_D6,
    NOTE_CS6, NOTE_B5,
    NOTE_B5, NOTE_B5,
    NOTE_CS6, NOTE_B5,
    NOTE_B5,
    0
  },
  // 残酷なやつ
  {
    NOTE_C5, NOTE_DS5, NOTE_F5, NOTE_DS5, NOTE_F5,
    NOTE_F5, NOTE_F5, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_F5, NOTE_G5,
    NOTE_G5, NOTE_AS5, NOTE_C6, NOTE_F5, NOTE_DS5,
    NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_F5, NOTE_DS5, NOTE_DS5,

    NOTE_C5, NOTE_DS5, NOTE_F5, NOTE_DS5, NOTE_F5,
    NOTE_F5, NOTE_F5, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_F5, NOTE_G5,
    NOTE_G5, NOTE_AS5, NOTE_C6, NOTE_F5, NOTE_DS5,
    NOTE_AS5, NOTE_AS5, NOTE_G5, NOTE_AS5, NOTE_AS5, NOTE_C6,

    NOTE_C5, NOTE_DS5, NOTE_F5, NOTE_DS5, NOTE_F5,
    NOTE_F5, NOTE_F5, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_F5, NOTE_G5,
    NOTE_G5, NOTE_AS5, NOTE_C6, NOTE_F5, NOTE_DS5,
    NOTE_AS5, NOTE_AS5, NOTE_G5, NOTE_AS5, NOTE_AS5, NOTE_C6,
    0
  },
  // なんとかワールド
  {
    NOTE_E5, NOTE_DS5, NOTE_E5,
    NOTE_B5, NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_GS5, NOTE_E5,
    NOTE_GS5, NOTE_A5, NOTE_B5,
    NOTE_B5, NOTE_E6, NOTE_DS6, NOTE_B5, NOTE_GS5, NOTE_A5,
    NOTE_GS5, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_GS5, NOTE_E5, NOTE_E5, NOTE_B4,
    NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_GS5, NOTE_A5, NOTE_B5, NOTE_FS5,

    NOTE_B5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_FS5,
    NOTE_GS5, NOTE_E5,
    NOTE_GS5, NOTE_A5, NOTE_B5,
    NOTE_B5, NOTE_E6, NOTE_D6, NOTE_B5, NOTE_GS5, NOTE_A5,

    NOTE_GS5, NOTE_E5, NOTE_GS5, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_A5,
    NOTE_GS5, NOTE_A5, NOTE_GS5, NOTE_E5, NOTE_B4,
    NOTE_E5, NOTE_FS5, NOTE_GS5, NOTE_A5, NOTE_B5, NOTE_E5, NOTE_FS5,

    0
  },
  // なんとかぴっぴはなんとかかんとか
  {
    NOTE_GS4, NOTE_GS4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_AS4, NOTE_C5, NOTE_C5,
    NOTE_DS5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_AS4,
    NOTE_G4, NOTE_G4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_G4,
    NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_G4, NOTE_AS4, NOTE_B4, NOTE_C5,
    NOTE_GS4, NOTE_GS4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_AS4, NOTE_C5, NOTE_C5,
    NOTE_DS5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_AS4,
    NOTE_DS5, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_DS5, NOTE_C5, NOTE_C5, NOTE_AS4,
    NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_B4, NOTE_CS5,
    0
  },
  // 翔べなにダム
  {
    NOTE_E4, NOTE_G4, NOTE_C5, NOTE_C5, NOTE_C5,
    NOTE_E4, NOTE_G4, NOTE_C5, NOTE_C5, NOTE_C5,
    NOTE_E4, NOTE_G4, NOTE_C5, NOTE_C5, NOTE_C5,
    NOTE_B4, NOTE_A4, NOTE_B4, NOTE_B4,
    NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_A4,

    NOTE_E4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C5, NOTE_A4,
    NOTE_E4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C5, NOTE_A4,
    NOTE_A4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_C5,
    NOTE_C5, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_F5, NOTE_E5, NOTE_D5,
    NOTE_G4, NOTE_G4, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4,
    NOTE_B4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_G4,
    NOTE_G4, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_E5,
    NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5,
    NOTE_D5, NOTE_C5, NOTE_C5, NOTE_C5,
    0
  },
  // Godなんとか
  {
    NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4,
    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4,
    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_C5,
    NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_D5,
    NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,

    NOTE_D4, NOTE_D4, NOTE_A4, NOTE_A4,
    NOTE_G4, NOTE_A4, NOTE_C5, NOTE_G4,
    NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4,
    NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4,

    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4,
    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_C5,
    NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_D5,

    NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
    NOTE_D4, NOTE_A4, NOTE_A4,
    NOTE_G4, NOTE_A4, NOTE_C5, NOTE_G4,
    NOTE_G4, NOTE_F4,

    NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
    0
  },
  // Auld Lang Syne
  {
    NOTE_C4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_A4, NOTE_G4, NOTE_F4,
    NOTE_G4, NOTE_A4, NOTE_F4, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_D5,

    NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4,
    NOTE_G4, NOTE_A4, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_F4,

    NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4,
    NOTE_G4, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5,

    NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4,
    NOTE_G4, NOTE_A4, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_F4,
  }

};

const PROGMEM uint16_t defaultSongs[songNum][256] =
{
  // パーパパパーパーパーパー
  {
     NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, NOTE_B3, NOTE_C4,
     0
  },
  // キラキラ星
  {
    NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
    NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,
    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
    NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
    NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,
    0
  },
  // ナウシカレクイエム
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
  }
};

const PROGMEM uint16_t tempoList[songNum] = {
  170, 154
};

// 休符は二つ連続で入れちゃダメよー
const PROGMEM uint16_t noteDurations[songNum][256] =
{
  // ようこそなんとかパークへ
  {
    8, 8, 8, 4, 8, 8, 4,
    8, 8, 4, 8, 8, 8, 
    4, 4, 4, 4, 8, 8,
    8, 8, 2,
    0
  },
  // 何本桜
  {
    8, 8, 6, 6, 8, 4, 8, 8,
    8, 8, 8, 8, 4,
    8, 8, 6, 6, 8, 4, 8, 8,
    8, 8, 8, 8, 4,
    8, 8, 6, 6, 8, 4, 8, 8,
    8, 8, 8, 8, 4,
    8, 8, 4, 4, 4, 4, 8,
    8, 8, 8, 4,
    0
  },
  // 鳥のなんとか
  {
    4, 8, 8, 8,
    4, 8, 8, 2,
    3, 8, 8, 8, 8,
    4, 8, 16, 2,
    4, 8, 4, 8, 8, 8,
    4, 8, 8, 2, 4,
    8, 8, 8, 8, 8, 8,
    8, 6, 3, 8,
    4, 4, 4, 4,
    4, 8, 16, 1,
    4, 8, 8, 8, 8, 8, 8,
    4, 8, 16, 1,
    3, 4, 8, 8, 8,
    4, 8, 16, 1,
    4, 8, 8, 8, 8, 8, 8,
    6, 8,
    2, 4,
    2, 4,
    1,
    0
  },
};

