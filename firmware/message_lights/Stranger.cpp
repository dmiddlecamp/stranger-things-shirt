
#include "application.h"
#include "Stranger.h"
#include "neopixel.h"


//int counter = 0;


    void Stranger::init() {

        this->strip.begin();
        this->strip.show(); // Initialize all pixels to 'off'




        uint32_t red =      this->strip.Color(255, 0, 0);
        uint32_t blue =     this->strip.Color(0, 0, 255);
        uint32_t green =    this->strip.Color(0, 255, 0);

        uint32_t white =    this->strip.Color(255, 255, 255);
        uint32_t yellow =   this->strip.Color(255, 255, 0);

        // 60 - 40
        _mapping[0] =        { 'a', 58, white };
        _mapping[1] =        { 'b', 56, blue };
        _mapping[2] =        { 'c', 54, red };
        _mapping[3] =        { 'd', 52, green };
        _mapping[4] =        { 'e', 50, blue};
        _mapping[5] =        { 'f', 48, yellow };
        _mapping[6] =        { 'g', 46, red };
        _mapping[7] =        { 'h', 44, blue };
        _mapping[8] =        { 'i', 42, green };

        // 40 - 20
        _mapping[9] =        { 'j', 21, red };
        _mapping[10] =       { 'k', 23, blue };
        _mapping[11] =       { 'l', 25, green };
        _mapping[12] =       { 'm', 27, yellow };
        _mapping[13] =       { 'n', 29, red };
        _mapping[14] =       { 'o', 31, red };
        _mapping[15] =       { 'p', 33, white };
        _mapping[16] =       { 'q', 35, red };

        // 20 - 0
        _mapping[17] =       { 'r', 18, green };
        _mapping[18] =       { 's', 16, white };
        _mapping[19] =       { 't', 14, yellow };
        _mapping[20] =       { 'u', 12, blue };
        _mapping[21] =       { 'v', 10, red };
        _mapping[22] =       { 'w', 8, blue };
        _mapping[23] =       { 'x', 6, yellow };
        _mapping[24] =       { 'y', 4, red };
        _mapping[25] =       { 'z', 2, red };

    }

    void Stranger::letter(char letter, bool onOff) {
        int idx = letter - 'a';
        if ((idx < 0) || (idx >= 26)) {
            return;
        }

        LightItem item = this->_mapping[idx];
//        uint32_t color = item.color;
//        if (!onOff) {
//            color = 0;
//        }

        String line = String::format("Letter %c at map index %d at light index %d", letter, idx, item.index);
        Serial.println(line);

        this->strip.setPixelColor(item.index, (onOff) ? item.color : 0);
        strip.show();
    }

    void Stranger::message(String msg) {
        const int letterOnPause = 1000;
        const int betweenLetterPause = 1000;

        int msgLen = msg.length();
        for(int i=0;i<msgLen;i++) {
            if (i > 0) {
                //turn off the previous letter
                this->letter(msg.charAt(i-1), false);
                delay(betweenLetterPause);    //wait, ominously
            }

            this->letter(msg.charAt(i), true);
            delay(letterOnPause);
        }

        //turn off the last letter
        this->letter(msg.charAt(msgLen-1), false);
        delay(letterOnPause);    //wait, ominously
    }

    void Stranger::flashMessage(String msg, int flashes) {

        int msgLen = msg.length();
        for(int f = 0; f < flashes;f++) {

            //turn them all on
            for(int i=0;i<msgLen;i++) {
                this->letter(msg.charAt(i), true);
            }

            delay(250);
            this->allOff();
            delay(100);
        }
    }

    void Stranger::allOff() {
//        for(int i=0;i<26;i++) {
//            LightItem item = this->_mapping[i];
//
//            //turn our letters off
//            this->letter(item.letter, false);
//        }

        for(int i=0;i<PIXEL_COUNT;i++) {
            this->strip.setPixelColor(i, 0);
        }
        strip.show();
    }

    void Stranger::testAll() {
        for(int i=0;i<26;i++) {
            this->letter('a'+ i, true);
            delay(50);
        }
        strip.show();
    }