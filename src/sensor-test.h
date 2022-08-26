#ifndef SENSOR_TEST_H
#define SENSOR_TEST_H
#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

Adafruit_MPR121 getCap(int8_t sensor);

bool initCap1();
bool initCap2();

void testcap1();
void testcap2();

#endif