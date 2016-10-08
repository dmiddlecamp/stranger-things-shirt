
#include "Stranger.h"
#define MESSAGE_COUNT_TIMES 3
#define BUFFER_SIZE 1024


SYSTEM_THREAD(ENABLED);




char messageBuffer[BUFFER_SIZE];
unsigned int messageDisplayCount = MESSAGE_COUNT_TIMES;


Stranger things;

void setup() {
    Serial.begin(9600);

    Particle.function("message", onMessage);

    things.init();
    things.allOff();
}

int onMessage(String message) {
    int msgLen = message.length();
    strncpy(messageBuffer, message.c_str(), msgLen);
    messageDisplayCount = 0;
    Particle.publish("message", " got: " + message);
    Particle.publish("message", " displaying: " + String(messageBuffer));
    return msgLen;
}

void loop(){

    if ((messageDisplayCount < MESSAGE_COUNT_TIMES) && (messageBuffer != NULL) && (strlen(messageBuffer) > 0)) {
        things.message(messageBuffer);
        things.flashMessage(messageBuffer, 5);
        messageDisplayCount++;
    }
    else {
        things.message("dance");
        things.flashMessage("dance", 5);
    }

    delay(2500);
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
