#ifndef LED_H
#define LED_H
#include <Arduino.h>

void initLedStrip();

void setAll(byte red, byte green, byte blue);

void showStrip();

void _waterfall(int R, int G, int B, int Size, int index);

#endif