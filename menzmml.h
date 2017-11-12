#ifndef MenzMML_h
#define MenzMML_h

#include <Arduino.h>

#define DEBUG

class MenzMML {
  public:
    MenzMML();
    void mml_initialize(char* mml);
    void fetch_mml();
    void reset_cursol();
    int tempo;
    int note;
    int duration;
    static const int NOTE_END = 0;
    static const int REST = 1;

  private:
    int get_duration(char number1, char number2, char dot, float baseDuration);
    int is_digit(char checkChar);
    int get_note();
    int char_to_keynumber(char key);
    int char_to_int(char number);
    int currentCur, mmlSize, tmpCursol;
    char mmlNotes[512];
    int noteSendFlag;
    float baseDuration;
    int octave, baseOctave;
};

#endif
