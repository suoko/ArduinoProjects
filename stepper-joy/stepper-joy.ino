int s1 = 2;
int s2 = 3;
int s3 = 4;
int s4 = 5;
int x;
void setup() {
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(s4, OUTPUT);
  pinMode(A4, INPUT);
 }
void loop() {
  x = analogRead(A4);
  
  if(x<500)
  {
 digitalWrite(s1, HIGH);
 digitalWrite(s2, LOW);
 digitalWrite(s3, LOW);
 digitalWrite(s4, LOW);
 delay(5);
 digitalWrite(s1, LOW);
 digitalWrite(s2, HIGH);
 digitalWrite(s3, LOW);
 digitalWrite(s4, LOW);
 delay(5);
 digitalWrite(s1, LOW);
 digitalWrite(s2, LOW);
 digitalWrite(s3, HIGH);
 digitalWrite(s4, LOW);
 delay(5);
 digitalWrite(s1, LOW);
 digitalWrite(s2, LOW);
 digitalWrite(s3, LOW);
 digitalWrite(s4, HIGH);
 delay(5);
 }
 else if(x>550)
 {
  digitalWrite(s1, LOW);
 digitalWrite(s2, LOW);
 digitalWrite(s3, LOW);
 digitalWrite(s4, HIGH);
 delay(5);
 digitalWrite(s1, LOW);
 digitalWrite(s2, LOW);
 digitalWrite(s3, HIGH);
 digitalWrite(s4, LOW);
 delay(5);
 digitalWrite(s1, LOW);
 digitalWrite(s2, HIGH);
 digitalWrite(s3, LOW);
 digitalWrite(s4, LOW);
 delay(5);
 digitalWrite(s1, HIGH);
 digitalWrite(s2, LOW);
 digitalWrite(s3, LOW);
 digitalWrite(s4, LOW);
 delay(5);
 }
 else if(x > 500 && x < 550)
 {
 digitalWrite(s1, LOW);
 digitalWrite(s2, LOW);
 digitalWrite(s3, LOW);
 digitalWrite(s4, LOW);
 }
}
