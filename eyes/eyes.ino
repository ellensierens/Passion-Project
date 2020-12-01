    #include <FastLED.h>
    #define NUM_LEDS 64
    #define DATA_PIN 3
    #define DATA_PIN2 9

    int BPM = 400;

    bool start = true;
    bool socketConnected = false;
    bool hasBeenConnected = false;
    bool inference = false;
    bool sing = false;

    CRGB leds[NUM_LEDS];

    void setup() { 
      Serial.begin(9600);
      Serial1.begin(9600);
      
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      FastLED.addLeds<NEOPIXEL, DATA_PIN2>(leds, NUM_LEDS);

      FastLED.setBrightness(50);
   }

   void loop() { 

    readSerialPort();
    
    if(start){
      laden_1();
      delay(BPM);
      laden_2();
      delay(BPM);
      laden_3();
      delay(BPM);
      laden_4();
      delay(BPM);
      laden_5();
      delay(BPM);
      laden_6();
      delay(BPM);
      laden_7();
      delay(BPM);
      laden_8();
      delay(BPM);
      laden_9();
      delay(BPM);
      laden_10();
      delay(BPM);
      laden_11();
      delay(BPM);
      laden_12();
      delay(BPM);
    } else if(socketConnected) {
      kijken_3();
    } else if(inference){
      kijken_1();
      delay(BPM);
      kijken_2();
      delay(BPM);
      kijken_3();
      delay(BPM);
      kijken_4();
      delay(BPM);
      kijken_3();
      delay(BPM);
      kijken_2();
      delay(BPM);
    }else if (sing){
      spelen_1();
      delay(BPM);
      spelen_2();
      delay(BPM);
      spelen_3();
      delay(BPM);
      spelen_4();
      delay(BPM);
      spelen_3();
      delay(BPM);
      spelen_2();
      delay(BPM);
    }
   }

   void readSerialPort (){
    //Serial.println("reading");
    String msg ="";
    if(Serial.available()>0){
      delay(10);
      while(Serial.available()>0){
        msg += (char)Serial.read();
      }
    }
    if(Serial1.available()>0){
      delay(10);
      while(Serial1.available()>0){
        msg += (char)Serial1.read();
      }
    }
          Serial.println(msg);
     if(msg == "connected" && hasBeenConnected == false){
      start = false;
      socketConnected = true;
      hasBeenConnected = true;
      
     } else if(msg == "inference"){
      socketConnected = false;
      inference = true;
     } else if(msg == "sing"){
     inference = false;
     sing = true;
     }
     else if(msg == "stop"){
     socketConnected = true;
     sing = false;
     }
   }

    void laden_1 () {
      FastLED.clear(); 
        leds[20] = CRGB::White;
        leds[21] = CRGB::White;
        leds[29] = CRGB::White;
        leds[37] = CRGB::White;
        leds[45] = CRGB::White;
        leds[44] = CRGB::White;
        leds[43] = CRGB::White;
        leds[42] = CRGB::White;
        leds[34] = CRGB::White;
        leds[26] = CRGB::White;
        
        FastLED.show(); 
    }

    void laden_2 () {
      FastLED.clear(); 
        leds[18] = CRGB::White;
        leds[21] = CRGB::White;
        leds[29] = CRGB::White;
        leds[37] = CRGB::White;
        leds[45] = CRGB::White;
        leds[44] = CRGB::White;
        leds[43] = CRGB::White;
        leds[42] = CRGB::White;
        leds[34] = CRGB::White;
        leds[26] = CRGB::White;
        
        FastLED.show(); 
    }

    void laden_3 () {
      FastLED.clear(); 
        leds[18] = CRGB::White;
        leds[19] = CRGB::White;
        leds[29] = CRGB::White;
        leds[37] = CRGB::White;
        leds[45] = CRGB::White;
        leds[44] = CRGB::White;
        leds[43] = CRGB::White;
        leds[42] = CRGB::White;
        leds[34] = CRGB::White;
        leds[26] = CRGB::White;
        
        FastLED.show(); 
    }

        void laden_4 () {
      FastLED.clear(); 
        leds[18] = CRGB::White;
        leds[19] = CRGB::White;
        leds[20] = CRGB::White;
        leds[37] = CRGB::White;
        leds[45] = CRGB::White;
        leds[44] = CRGB::White;
        leds[43] = CRGB::White;
        leds[42] = CRGB::White;
        leds[34] = CRGB::White;
        leds[26] = CRGB::White;
        
        FastLED.show(); 
    }

        void laden_5 () {
      FastLED.clear(); 
        leds[18] = CRGB::White;
        leds[19] = CRGB::White;
        leds[20] = CRGB::White;
        leds[21] = CRGB::White;
        leds[45] = CRGB::White;
        leds[44] = CRGB::White;
        leds[43] = CRGB::White;
        leds[42] = CRGB::White;
        leds[34] = CRGB::White;
        leds[26] = CRGB::White;
        
        FastLED.show(); 
    }


        void laden_6 () {
      FastLED.clear(); 
        leds[18] = CRGB::White;
        leds[19] = CRGB::White;
        leds[20] = CRGB::White;
        leds[21] = CRGB::White;
        leds[29] = CRGB::White;
        leds[44] = CRGB::White;
        leds[43] = CRGB::White;
        leds[42] = CRGB::White;
        leds[34] = CRGB::White;
        leds[26] = CRGB::White;
        
        FastLED.show(); 
    }

        void laden_7 () {
      FastLED.clear(); 
        leds[18] = CRGB::White;
        leds[19] = CRGB::White;
        leds[20] = CRGB::White;
        leds[21] = CRGB::White;
        leds[29] = CRGB::White;
        leds[37] = CRGB::White;
        leds[43] = CRGB::White;
        leds[42] = CRGB::White;
        leds[34] = CRGB::White;
        leds[26] = CRGB::White;
        
        FastLED.show(); 
    }


        void laden_8 () {
      FastLED.clear(); 
        leds[18] = CRGB::White;
        leds[19] = CRGB::White;
        leds[20] = CRGB::White;
        leds[21] = CRGB::White;
        leds[29] = CRGB::White;
        leds[37] = CRGB::White;
        leds[45] = CRGB::White;
        leds[42] = CRGB::White;
        leds[34] = CRGB::White;
        leds[26] = CRGB::White;
        
        FastLED.show(); 
    }

        void laden_9 () {
      FastLED.clear(); 
        leds[18] = CRGB::White;
        leds[19] = CRGB::White;
        leds[20] = CRGB::White;
        leds[21] = CRGB::White;
        leds[29] = CRGB::White;
        leds[37] = CRGB::White;
        leds[45] = CRGB::White;
        leds[44] = CRGB::White;
        leds[34] = CRGB::White;
        leds[26] = CRGB::White;
        
        FastLED.show(); 
    }

        void laden_10 () {
      FastLED.clear(); 
        leds[18] = CRGB::White;
        leds[19] = CRGB::White;
        leds[20] = CRGB::White;
        leds[21] = CRGB::White;
        leds[29] = CRGB::White;
        leds[37] = CRGB::White;
        leds[45] = CRGB::White;
        leds[44] = CRGB::White;
        leds[43] = CRGB::White;
        leds[26] = CRGB::White;
        
        FastLED.show(); 
    }

    
        void laden_11 () {
      FastLED.clear(); 
        leds[18] = CRGB::White;
        leds[19] = CRGB::White;
        leds[20] = CRGB::White;
        leds[21] = CRGB::White;
        leds[29] = CRGB::White;
        leds[37] = CRGB::White;
        leds[45] = CRGB::White;
        leds[44] = CRGB::White;
        leds[43] = CRGB::White;
        leds[42] = CRGB::White;
        
        FastLED.show(); 
    }

        void laden_12 () {
      FastLED.clear(); 
        leds[34] = CRGB::White;
        leds[19] = CRGB::White;
        leds[20] = CRGB::White;
        leds[21] = CRGB::White;
        leds[29] = CRGB::White;
        leds[37] = CRGB::White;
        leds[45] = CRGB::White;
        leds[44] = CRGB::White;
        leds[43] = CRGB::White;
        leds[42] = CRGB::White;
        
        FastLED.show(); 
    }
    

    void spelen_1 () {
      FastLED.clear(); 
        leds[27] = CRGB::White;
        leds[31] = CRGB::White;
        leds[36] = CRGB::White;
        leds[37] = CRGB::White;
        leds[38] = CRGB::White;
        
        FastLED.show(); 
    }
        void spelen_2 () {
        FastLED.clear(); 
        leds[34] = CRGB::White;
        leds[38] = CRGB::White;
        leds[43] = CRGB::White;
        leds[44] = CRGB::White;
        leds[45] = CRGB::White;
        
        FastLED.show(); 
    }
        void spelen_3 () {
        FastLED.clear(); 
        leds[33] = CRGB::White;
        leds[37] = CRGB::White;
        leds[42] = CRGB::White;
        leds[43] = CRGB::White;
        leds[44] = CRGB::White;
        
        FastLED.show(); 
    }

         void spelen_4 () {
        FastLED.clear(); 
        leds[24] = CRGB::White;
        leds[33] = CRGB::White;
        leds[34] = CRGB::White;
        leds[35] = CRGB::White;
        leds[28] = CRGB::White;
        
        FastLED.show(); 
    }

        void kijken_1 () {
      FastLED.clear(); 
        leds[2] = CRGB::White;
        leds[3] = CRGB::White;
        leds[4] = CRGB::White;
        leds[5] = CRGB::White;
        leds[9] = CRGB::White;
        leds[2] = CRGB::White;
        leds[3] = CRGB::White;
        leds[4] = CRGB::White;
        leds[5] = CRGB::White;
        leds[9] = CRGB::White;
        leds[10] = CRGB::White;
        leds[11] = CRGB::White;
        leds[12] = CRGB::White;
        leds[13] = CRGB::White;
        leds[14] = CRGB::White;
        leds[16] = CRGB::White;
        leds[17] = CRGB::White;
        leds[18] = CRGB::White;
        leds[19] = CRGB::White;
        leds[20] = CRGB::White;
        leds[21] = CRGB::White;
        leds[22] = CRGB::White;
        leds[23] = CRGB::White;
        leds[26] = CRGB::White;
        leds[27] = CRGB::White;
        leds[28] = CRGB::White;
        leds[29] = CRGB::White;
        leds[30] = CRGB::White;
        leds[31] = CRGB::White;
        leds[34] = CRGB::White;
        leds[35] = CRGB::White;
        leds[36] = CRGB::White;
        leds[37] = CRGB::White;
        leds[38] = CRGB::White;
        leds[39] = CRGB::White;
        leds[40] = CRGB::White;
        leds[41] = CRGB::White;
        leds[42] = CRGB::White;
        leds[43] = CRGB::White;
        leds[44] = CRGB::White;
        leds[45] = CRGB::White;
        leds[46] = CRGB::White;
        leds[47] = CRGB::White;
        leds[49] = CRGB::White;
        leds[50] = CRGB::White;
        leds[51] = CRGB::White;
        leds[52] = CRGB::White;
        leds[53] = CRGB::White;
        leds[54] = CRGB::White;
        leds[58] = CRGB::White;
        leds[59] = CRGB::White;
        leds[60] = CRGB::White;
        leds[61] = CRGB::White;
        FastLED.show(); 
    }

    
        void kijken_2 () {
      FastLED.clear(); 
        leds[2] = CRGB::White;
        leds[3] = CRGB::White;
        leds[4] = CRGB::White;
        leds[5] = CRGB::White;
        leds[9] = CRGB::White;
        leds[2] = CRGB::White;
        leds[3] = CRGB::White;
        leds[4] = CRGB::White;
        leds[5] = CRGB::White;
        leds[9] = CRGB::White;
        leds[10] = CRGB::White;
        leds[11] = CRGB::White;
        leds[12] = CRGB::White;
        leds[13] = CRGB::White;
        leds[14] = CRGB::White;
        leds[16] = CRGB::White;
        leds[17] = CRGB::White;
        leds[18] = CRGB::White;
        leds[19] = CRGB::White;
        leds[20] = CRGB::White;
        leds[21] = CRGB::White;
        leds[22] = CRGB::White;
        leds[23] = CRGB::White;
        leds[24] = CRGB::White;
        leds[25] = CRGB::White;
        leds[28] = CRGB::White;
        leds[29] = CRGB::White;
        leds[30] = CRGB::White;
        leds[31] = CRGB::White;
        leds[32] = CRGB::White;
        leds[33] = CRGB::White;
        leds[36] = CRGB::White;
        leds[37] = CRGB::White;
        leds[38] = CRGB::White;
        leds[39] = CRGB::White;
        leds[40] = CRGB::White;
        leds[41] = CRGB::White;
        leds[42] = CRGB::White;
        leds[43] = CRGB::White;
        leds[44] = CRGB::White;
        leds[45] = CRGB::White;
        leds[46] = CRGB::White;
        leds[47] = CRGB::White;
        leds[49] = CRGB::White;
        leds[50] = CRGB::White;
        leds[51] = CRGB::White;
        leds[52] = CRGB::White;
        leds[53] = CRGB::White;
        leds[54] = CRGB::White;
        leds[58] = CRGB::White;
        leds[59] = CRGB::White;
        leds[60] = CRGB::White;
        leds[61] = CRGB::White;
        FastLED.show(); 
    }

            void kijken_3 () {
      FastLED.clear(); 
        leds[2] = CRGB::White;
        leds[3] = CRGB::White;
        leds[4] = CRGB::White;
        leds[5] = CRGB::White;
        leds[9] = CRGB::White;
        leds[2] = CRGB::White;
        leds[3] = CRGB::White;
        leds[4] = CRGB::White;
        leds[5] = CRGB::White;
        leds[9] = CRGB::White;
        leds[10] = CRGB::White;
        leds[11] = CRGB::White;
        leds[12] = CRGB::White;
        leds[13] = CRGB::White;
        leds[14] = CRGB::White;
        leds[16] = CRGB::White;
        leds[17] = CRGB::White;
        leds[18] = CRGB::White;
        leds[19] = CRGB::White;
        leds[20] = CRGB::White;
        leds[21] = CRGB::White;
        leds[22] = CRGB::White;
        leds[23] = CRGB::White;
        leds[24] = CRGB::White;
        leds[25] = CRGB::White;
        leds[26] = CRGB::White;
        leds[27] = CRGB::White;
        leds[30] = CRGB::White;
        leds[31] = CRGB::White;
        leds[32] = CRGB::White;
        leds[33] = CRGB::White;
        leds[34] = CRGB::White;
        leds[35] = CRGB::White;
        leds[38] = CRGB::White;
        leds[39] = CRGB::White;
        leds[40] = CRGB::White;
        leds[41] = CRGB::White;
        leds[42] = CRGB::White;
        leds[43] = CRGB::White;
        leds[44] = CRGB::White;
        leds[45] = CRGB::White;
        leds[46] = CRGB::White;
        leds[47] = CRGB::White;
        leds[49] = CRGB::White;
        leds[50] = CRGB::White;
        leds[51] = CRGB::White;
        leds[52] = CRGB::White;
        leds[53] = CRGB::White;
        leds[54] = CRGB::White;
        leds[58] = CRGB::White;
        leds[59] = CRGB::White;
        leds[60] = CRGB::White;
        leds[61] = CRGB::White;
        FastLED.show(); 
    }

                void kijken_4 () {
      FastLED.clear(); 
        leds[2] = CRGB::White;
        leds[3] = CRGB::White;
        leds[4] = CRGB::White;
        leds[5] = CRGB::White;
        leds[9] = CRGB::White;
        leds[2] = CRGB::White;
        leds[3] = CRGB::White;
        leds[4] = CRGB::White;
        leds[5] = CRGB::White;
        leds[9] = CRGB::White;
        leds[10] = CRGB::White;
        leds[11] = CRGB::White;
        leds[12] = CRGB::White;
        leds[13] = CRGB::White;
        leds[14] = CRGB::White;
        leds[16] = CRGB::White;
        leds[17] = CRGB::White;
        leds[18] = CRGB::White;
        leds[19] = CRGB::White;
        leds[20] = CRGB::White;
        leds[21] = CRGB::White;
        leds[22] = CRGB::White;
        leds[23] = CRGB::White;
        leds[24] = CRGB::White;
        leds[25] = CRGB::White;
        leds[26] = CRGB::White;
        leds[27] = CRGB::White;
        leds[28] = CRGB::White;
        leds[29] = CRGB::White;
        leds[32] = CRGB::White;
        leds[33] = CRGB::White;
        leds[34] = CRGB::White;
        leds[35] = CRGB::White;
        leds[36] = CRGB::White;
        leds[37] = CRGB::White;
        leds[40] = CRGB::White;
        leds[41] = CRGB::White;
        leds[42] = CRGB::White;
        leds[43] = CRGB::White;
        leds[44] = CRGB::White;
        leds[45] = CRGB::White;
        leds[46] = CRGB::White;
        leds[47] = CRGB::White;
        leds[49] = CRGB::White;
        leds[50] = CRGB::White;
        leds[51] = CRGB::White;
        leds[52] = CRGB::White;
        leds[53] = CRGB::White;
        leds[54] = CRGB::White;
        leds[58] = CRGB::White;
        leds[59] = CRGB::White;
        leds[60] = CRGB::White;
        leds[61] = CRGB::White;
        FastLED.show(); 
    }

                void fout () {
      FastLED.clear(); 
        leds[2] = CRGB::White;
        leds[3] = CRGB::White;
        leds[4] = CRGB::White;
        leds[5] = CRGB::White;
        leds[9] = CRGB::White;
        leds[2] = CRGB::White;
        leds[3] = CRGB::White;
        leds[4] = CRGB::White;
        leds[5] = CRGB::White;
        leds[9] = CRGB::White;
        leds[10] = CRGB::White;
        leds[11] = CRGB::White;
        leds[12] = CRGB::White;
        leds[13] = CRGB::White;
        leds[14] = CRGB::White;
        leds[16] = CRGB::White;
        leds[17] = CRGB::White;
        leds[18] = CRGB::White;
        leds[19] = CRGB::White;
        leds[20] = CRGB::White;
        leds[21] = CRGB::White;
        leds[22] = CRGB::White;
        leds[23] = CRGB::White;
        
        leds[40] = CRGB::White;
        leds[41] = CRGB::White;
        leds[42] = CRGB::White;
        leds[43] = CRGB::White;
        leds[44] = CRGB::White;
        leds[45] = CRGB::White;
        leds[46] = CRGB::White;
        leds[47] = CRGB::White;
        leds[49] = CRGB::White;
        leds[50] = CRGB::White;
        leds[51] = CRGB::White;
        leds[52] = CRGB::White;
        leds[53] = CRGB::White;
        leds[54] = CRGB::White;
        leds[58] = CRGB::White;
        leds[59] = CRGB::White;
        leds[60] = CRGB::White;
        leds[61] = CRGB::White;
        FastLED.show(); 
    }
