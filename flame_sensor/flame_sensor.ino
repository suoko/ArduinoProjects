int flameSensorPin = A3; //  a0 
int flameSensorReading; 
int buzzerPin=8; 
void setup(void) 
{  
  pinMode(buzzerPin,OUTPUT);
} 
void loop(void) 
{ 
  //digitalWrite(buzzerPin,HIGH);
  flameSensorReading = analogRead(flameSensorPin);  
  if(flameSensorReading<1023)
{
  digitalWrite(buzzerPin,HIGH);
}
else
{
  digitalWrite(buzzerPin,LOW);
}
 //Serial.print("Analog reading = "); 
 //Serial.println(flameSensorReading); // the raw analog reading delay(1000); 
 delay(500);
}
