
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup()
{
  lcd.begin(16,2);                
  lcd.home ();                   
  lcd.print("Arduino i2c ");  
  lcd.setCursor ( 0, 1 );        
  lcd.print (" Test lcd!   ");
  delay ( 1000 );
  lcd.clear();
}

void loop()
{

  lcd.home ();
  lcd.print("testtest");
  lcd.setCursor(3,1);
  lcd.print("more test");
  delay (200);
}
