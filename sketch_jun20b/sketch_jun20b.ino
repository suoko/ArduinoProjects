/*
** NOTE: Tested on Arduino Uno whose I2C pins are A4==SDA, A5==SCL
*/
#include <Wire.h>
//#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x3F // <<----- Add your address here. Find it from I2C Scanner
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

int x = 0;
int y = 0;
//int n = 1;
int row = 16; // <<----- My LCD was 16x2
int column = 2; // <<----- My LCD was 16x2

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup()
{
lcd.begin (row,column);
// Switch on the backlight
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
lcd.home (); // go home
}

void loop()
{
if(x >= row ){ //move a character across all spaces
x = 0;
y++;
}
if(y >= column ) y = 0;
lcd.clear();
lcd.setCursor (x,y);
lcd.print("*");
delay(250);
x++;
}
