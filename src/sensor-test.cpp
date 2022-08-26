#include <sensor-test.h>

// Reset Pin is used for I2C or SPI
#define CAP1188_RESET 9

// For I2C, connect SDA to your Arduino's SDA pin, SCL to SCL pin
// On UNO/Duemilanove/etc, SDA == Analog 4, SCL == Analog 5

// Use I2C, no reset pin!

Adafruit_MPR121 cap2 = Adafruit_MPR121();
Adafruit_MPR121 cap1 = Adafruit_MPR121();

// uint16_t lasttouched = 0;
// uint16_t currtouched = 0;

// uint16_t lasttouched1 = 0;
// uint16_t currtouched1 = 0;

Adafruit_MPR121 getCap(int8_t sensor)
{
    switch(sensor){
        case 1:
            return cap2;
        break;
        case 2:
            return cap1;
        break;
        default :
            return cap2;
        break;
    }
}

bool initCap1()
{
    if (!cap2.begin(0x5A))
    {
        return false;
        while (1);
    }
    else
    {
        return true;
    }
}

bool initCap2()
{
    if (!cap1.begin(0x5C))
    {
        return false;
        while (1);
    }
    else
    {
        return true;
    }
}

void testcap1()
{
//   currtouched = cap.touched();
  
//   for (uint8_t i=0; i<12; i++) {
//     // it if *is* touched and *wasnt* touched before, alert!
//     if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
//       Serial.print(i); Serial.println(" touched");
//     }
//     // if it *was* touched and now *isnt*, alert!
//     if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
//       Serial.print(i); Serial.println(" released");
//     }
//   }

//   // reset our state
//   lasttouched = currtouched;
}

void testcap2()
{
//   currtouched1 = cap1.touched();
  
//   for (uint8_t i=0; i<12; i++) {
//     // it if *is* touched and *wasnt* touched before, alert!
//     if ((currtouched1 & _BV(i)) && !(lasttouched1 & _BV(i)) ) {
//       Serial.print(i); Serial.println(" B touched");
//     }
//     // if it *was* touched and now *isnt*, alert!
//     if (!(currtouched1 & _BV(i)) && (lasttouched1 & _BV(i)) ) {
//       Serial.print(i); Serial.println(" B released");
//     }
//   }

//   // reset our state
//   lasttouched1 = currtouched1;
}