#define VOLT 3
#define delayTime 300

void setup() {
  // put your setup code here, to run once:
pinMode(VOLT, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(VOLT, HIGH);
  delay(delayTime);
  digitalWrite(VOLT, LOW);
  delay(delayTime);

}
