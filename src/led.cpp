#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN             23
#define TOP_LEDS        24
#define BOTTOM_LEDS     24
#define LEFT_LEDS       64
#define RIGHT_LEDS      64
#define NUMPIXELS       TOP_LEDS + BOTTOM_LEDS + LEFT_LEDS + RIGHT_LEDS

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// ***************************************
// **********  Common Functions **********
// ***************************************

// Apply LED color changes
void showStrip() {
  strip.show();
}

// Set a LED color (not yet visible)
void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H 
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

// Set all LEDs to a given color and apply it (visible)
void setAll(byte red, byte green, byte blue) {
  Serial.println("setAll()");
  for(uint8_t i = 0; i < NUMPIXELS; i++ ) {
    setPixel(i, red, green, blue); 
  }
  showStrip();
}

//Initialize led strip
void initLedStrip(){
  strip.begin();
  strip.show();
}

void _waterfall(int R, int G, int B, int size, int index)
{

  index = index * size;

  int left = index-1;
  int right = index+1;
  int leftArr [4];
  int rightArr [4];

  if(index == 0){
    left = 176;
  } else if(index == 176){
    right = 0;
  }

  Serial.print("index\t\t"); Serial.println(index); Serial.print("\n");

  size = size / 2;

  setPixel(index, R,G,B);
  
  for (int i = 0; i < size; i++)
  {
    leftArr[i] = left;
    setPixel(left, R,G,B);
    left--;
    if(i < size){
      rightArr[i] = right;
      setPixel(right, R,G,B);
      right++;
    }
  }
  String p1=",";
  Serial.print("left\t\t"); Serial.println(leftArr[0] + p1 + leftArr[1] + p1 + leftArr[2] + p1 + leftArr[3]); Serial.print("\n");
  Serial.print("right\t\t"); Serial.println(rightArr[0] + p1 + rightArr[1] + p1 + rightArr[2] + p1 + rightArr[3]); Serial.print("\n");
}



