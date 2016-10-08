
#include "Stranger.h"

Stranger things;

void setup() {
    Serial.begin(9600);

    things.init();
    things.allOff();
}


void loop(){

    things.testAll();
    delay(2500);

    things.allOff();


    //things.messxage("thequickbrownfoxjumpedoverthelazyyellowdog");
    //things.flashMessage("thequickbrownfoxjumpsoverthelazyyellowdog", 5);

    things.message("dance");
    things.flashMessage("dance", 5);

    delay(1000);

}


//void rainbow(uint8_t wait) {
//  uint16_t i, j;
//
//  for(j=0; j<256; j++) {
//    for(i=0; i<strip.numPixels(); i++) {
//      strip.setPixelColor(i, Wheel((i+j) & 255));
//    }
//    strip.show();
//    delay(wait);
//  }
//}
//
//// Input a value 0 to 255 to get a color value.
//// The colours are a transition r - g - b - back to r.
//uint32_t Wheel(byte WheelPos) {
//  if(WheelPos < 85) {
//  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
//  } else if(WheelPos < 170) {
//  WheelPos -= 85;
//  return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
//  } else {
//  WheelPos -= 170;
//  return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
//  }
//}
