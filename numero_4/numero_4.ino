#include "SevSeg.h"
SevSeg sevseg; 

void setup(){
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {7, 6, 4, 3, 2, 8, 9, 5};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}

void loop(){
  for (int i = 0; i < 10; i++) {
    
        sevseg.setBrightness(90);
        sevseg.setNumber(i);
        sevseg.refreshDisplay(); 
        delay(1500);
        
        /*sevseg.setChars("A");
        sevseg.refreshDisplay(); 
        delay(1500);

        sevseg.setChars("B");
        sevseg.refreshDisplay(); 
        delay(1500);
        
        sevseg.setChars("C");
        sevseg.refreshDisplay(); 
        delay(1500);*/
  }
     
}
