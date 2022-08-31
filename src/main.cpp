//#include <Arduino.h>
#include <Wire.h>
#include <sensor-test.h>
#include <led.h>

#ifndef _BV
  #define _BV(bit) (1 << (bit)) 
#endif

// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 firstSensor = Adafruit_MPR121();
Adafruit_MPR121 secondSensor = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched, currtouched, lasttouched1, currtouched1 = 0;

void initSensors(){
  Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
  firstSensor.begin(0x5A);
  secondSensor.begin(0x5C);
  Serial.println("Both MPR121 found!");
}

void sensorStatus(){
  // Get the currently touched pads
  currtouched = firstSensor.touched();
  currtouched1 = secondSensor.touched();

  for (int i=0; i<12; i++) {

    int secondTouchPosition = i + 13;

      if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
        Serial.print(i+1); Serial.println(" touched");
        _waterfall(255,255,255,8, i);
      }
      // if it *was* touched and now *isnt*, alert!
      if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
        Serial.print(i+1); Serial.println(" released");
        _waterfall(0,0,0,8, i);
      }

      if ((currtouched1 & _BV(i)) && !(lasttouched1 & _BV(i))) {
        Serial.print(secondTouchPosition); Serial.println(" touched");
        if(i < 10){
          _waterfall(255,255,255,8, secondTouchPosition);
        }
        if(secondTouchPosition == 24){
          setAll(0,0,0);
        }
        
      }
      // if it *was* touched and now *isnt*, alert!
      if (!(currtouched1 & _BV(i)) && (lasttouched1 & _BV(i))) {
        Serial.print(secondTouchPosition); Serial.println(" released");
        if(i < 10){
          _waterfall(0,0,0, 8,secondTouchPosition);
        }  
      }
      showStrip();
  }

  // reset our state
  lasttouched = currtouched;
  lasttouched1 = currtouched1;

}

void sensorLoop(){
  for (int i=0; i<12; i++)
  {
    if(firstSensor.touched()){
      _waterfall(255,255,255,8, i);
    } else{
      _waterfall(0,0,0,8, i);
    }
    if(secondSensor.touched()){
      _waterfall(255,255,255,8, i+13);
    } else{
      _waterfall(0,0,0,8, i+13);
    }
  }
  
}

void extendDebbuging(Adafruit_MPR121 sensor){
  Serial.print("\t\t\t\t\t\t\t\t\t\t\t\t\t 0x"); Serial.println(sensor.touched(), HEX);
  Serial.print("Filt: ");
  for (uint8_t i=0; i<12; i++) {
    Serial.print(sensor.filteredData(i)); Serial.print("\t");
  }
  Serial.println();
  Serial.print("Base: ");
  for (uint8_t i=0; i<12; i++) {
    Serial.print(sensor.baselineData(i)); Serial.print("\t");
  }
  Serial.println();
}

void setup() {
  Serial.begin(9600);

  while (!Serial) {
    delay(10);
  }
  
  initSensors();
  initLedStrip();
  setAll(0,0,0);
  showStrip();
  
}

void loop() {

  sensorStatus();
  //sensorLoop();
  // comment out this line for detailed data from the sensor!
  return;
  
  // debugging info, what
  extendDebbuging(firstSensor);
  extendDebbuging(secondSensor);
  
  // put a delay so it isn't overwhelming
  //delay(100);
}