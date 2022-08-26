#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN             23 // On Trinket or Gemma, suggest changing this to 1
#define TOP_LEDS        24
#define BOTTOM_LEDS     24
#define LEFT_LEDS       64
#define RIGHT_LEDS      64
#define NUMPIXELS       TOP_LEDS + BOTTOM_LEDS + LEFT_LEDS + RIGHT_LEDS

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


class Parameters {
  public:
    uint8_t R;
    uint8_t G;
    uint8_t B;
    uint8_t Size;
    int Position;
    bool Fade;
};

Parameters params;

void initLedStrip(){
  strip.begin();
  strip.show();
}

void _waterfall(Parameters params)
{
  int left = params.Position;
  int right = params.Position;
  strip.setPixelColor(params.Position, params.R, params.G, params.B);
  for (uint8_t j = 0; j < params.Size; j++)
  {
    right++;
    left--;
    Serial.println(left);
    if(left < 0){
      left = 176 - right;
    }
    if(params.Fade){
      uint8_t fadeRed = params.R - floor(params.R / params.Size) * (j + 1) + 10;
      uint8_t fadeGreen = params.G - floor(params.G / params.Size) * (j + 1) + 10;
      uint8_t fadeBlue = params.B - floor(params.B / params.Size) * (j + 1) + 10;
      strip.setPixelColor(right, strip.Color(fadeRed, fadeGreen, fadeBlue));
      strip.setPixelColor(left, strip.Color(fadeRed, fadeGreen, fadeBlue));
    } else{
      strip.setPixelColor(right, strip.Color(params.R, params.G, params.B));
      strip.setPixelColor(left, strip.Color(params.R, params.G, params.B));
    }
  }
  strip.show();
}