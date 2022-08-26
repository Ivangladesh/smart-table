#ifndef LED_H
#define LED_H
#include <Arduino.h>

class Parameters {
  public:
    uint8_t R;
    uint8_t G;
    uint8_t B;
    uint8_t Size;
    int Position;
    bool Fade;
};

void initLedStrip();

void _waterfall(Parameters params);

#endif