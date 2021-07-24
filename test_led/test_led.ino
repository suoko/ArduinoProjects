  /*   
modified on June 5, 2018
by Arduino Examples from arduino.cc/en/Tutorial/ReadAnalogVoltage
https://electropeak.com/learn/ 
*/ 
/*
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A2);
  // print out the value you read:
  Serial.println(sensorValue);
} */

/*   
modified on Spe 2, 2020
by MohammedDamirchi
https://electropeak.com/learn/ 
*/ 
const int mic =  8;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the digital pin as an input:
  pinMode(mic, INPUT);
}

void loop() {
  digitalWrite(13, LOW);
  // check if the mic digitalout is high.
  if (digitalRead(mic) == HIGH) {
    digitalWrite(13, HIGH);
  }
}
