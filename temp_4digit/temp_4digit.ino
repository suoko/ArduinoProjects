#define sensorPin A0
#include <SevSeg.h>
  int digitBuffer[4] = { 0};
SevSeg sevseg; //Instantiate a seven segment controller object

unsigned long previousMillis = 0;
const long interval = 1000;
int i, j, k;

void setup()
{
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(10);
  //Serial.begin(9600);

}

void loop()
{

   
  int reading = analogRead(sensorPin);
  float tempC = reading * (5000 / 1024.0) / 10;
  
  
  /*unsigned long timerGlobal = millis();
  sevseg.setNumber(timerGlobal/1000);  
  sevseg.refreshDisplay();*/

  static unsigned long timer = millis();
  if (millis() >= timer) {
    timer += 300;
    sevseg.setNumber(tempC, 2);
  }
  
  //sevseg.setNumber(tempC,2);
  sevseg.refreshDisplay();
  /*Serial.print(tempC);
  Serial.print(" \xC2\xB0"); // shows degree symbol
  Serial.println("C");
  delay(1000);*/


}
