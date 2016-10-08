
#include "application.h"
#include "neopixel.h"

#define PIXEL_PIN D0
#define PIXEL_COUNT 60
#define PIXEL_TYPE WS2812B

//Adafruit_NeoPixel strip;// = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);


struct LightItem {
    char letter;
    int index;
    uint32_t color;
};




class Stranger {
    public:

    void init();
    void letter(char letter, bool onOff);
    void message(String msg);
    void flashMessage(String msg, int flashes);

    void allOff();
    void testAll();

    // fade all in
    // marquee
    //

    Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
    LightItem _mapping[26];
    int lettersHash[26];

//     = {
//        { 'a', 0, red },
//        { 'b', 2, red },
//        { 'c', 4, red },
//        { 'd', 6, red },
//        { 'e', 8, red },
//        { 'f', 10, red },
//        { 'g', 12, red },
//        { 'h', 14, red },
//        { 'i', 16, red },
//        { 'j', 18, red },
//        { 'k', 20, red },
//        { 'l', 22, red },
//        { 'm', 24, red },
//        { 'n', 26, red },
//        { 'o', 28, red },
//        { 'p', 30, red },
//        { 'q', 32, red },
//        { 'r', 34, red },
//        { 's', 36, red },
//        { 't', 38, red },
//        { 'u', 40, red },
//        { 'v', 42, red },
//        { 'w', 44, red },
//        { 'x', 46, red },
//        { 'y', 48, red },
//        { 'z', 50, red }
//        };
};