#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

static const uint8_t PROGMEM
  smile[] =
  { B00000000,
    B11100111,
    B10100101,
    B11100111,
    B00000000,
    B10000001,
    B01111110,
    B00000000},
  wink[] = {
    B00000000,
    B11100000,
    B10100111,
    B11100000,
    B00000000,
    B10000001,
    B01111110,
    B00000000,
  };

void setup() {
  // put your setup code here, to run once:

  // setup the LED matrix
  matrix.begin(0x70);  // pass in the address
}

void face_smile() {
  matrix.clear();
  matrix.drawBitmap(0, 0, smile, 8, 8, LED_ON);
  matrix.writeDisplay();
}

void face_wink(){
  matrix.clear();
  matrix.drawBitmap(0, 0, smile, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);
  matrix.clear();
  matrix.drawBitmap(0, 0, wink, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);
  matrix.clear();
  matrix.drawBitmap(0, 0, smile, 8, 8, LED_ON);
  matrix.writeDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:

  face_wink();
  delay(500);
}
