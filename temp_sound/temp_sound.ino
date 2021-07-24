
#include <Wire.h>
#include <hd44780.h>                       // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c expander i/o class header
#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;
hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip

const int LCD_COLS = 16;
const int LCD_ROWS = 2;
const int mic =  8;

void setup()
{

Serial.begin(9600);
pinMode(mic, INPUT);
int status;

 status = lcd.begin(LCD_COLS, LCD_ROWS);
 if(status) // non zero status means it was unsuccesful
 {
 status = -status; // convert negative status value to positive number

 hd44780::fatalError(status); // does not return
 }


}

void loop() {


   digitalWrite(13, LOW);

   if (digitalRead(mic) == HIGH) {
     digitalWrite(13, HIGH);
     //delay(500);   
     DHT.read11(dht_apin);
     lcd.setCursor(0,0);
     lcd.clear();
     lcd.print((String)"INIZIO");
     delay(700); 
     lcd.clear();
     lcd.print((String)"Umidita': " + DHT.humidity);
     delay(500);
     lcd.setCursor(0,1);
     lcd.print((String)"Temp: " + DHT.temperature);
     delay(5000);
     lcd.clear();
     lcd.print((String)"FINE");
     //delay(2000);
   }
   
  }
