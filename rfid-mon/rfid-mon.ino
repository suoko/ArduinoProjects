#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); 

// for a led 
int lock = 6;

int serrure = 3; 


char st[20];

void setup() 
{
  pinMode(lock, OUTPUT);
 
  pinMode (serrure, OUTPUT);
 
 
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init(); 

  Serial.println("Access test via RFID tag");
  Serial.println();
}

void loop() 
{
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  Serial.print("Tag :");
  String tag= "";
  byte caractere;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     tag.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     tag.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  tag.toUpperCase();
  

  if (tag.substring(1) == "06 62 20 02") // le numero de tag est visible lorsqu on presente la carte ou le badge via le moniteur serie
  
 
  {
    digitalWrite(lock, HIGH);
    Serial.println("TAG checked - Access allow !");
    Serial.println();
    delay(3000);
   // if you want to set a led 
    digitalWrite(lock, LOW);
   
    digitalWrite(serrure, LOW); 
   
    }
 

 else if (tag.substring(1) == "D4 A9 42 DB") 
  {
    digitalWrite(lock, HIGH);
    Serial.println("TAG checked - Access allow !");
    Serial.println();
    delay(3000);
    digitalWrite(lock, LOW);
    
    digitalWrite(serrure, LOW);
    
    }
  
  else
  
  {
    
    Serial.println("Unknown tag - Access refused !!!");
    Serial.println();
  
    for (int i= 1; i<5 ; i++)
    {
     
      digitalWrite(lock, HIGH);
      delay(200);
      digitalWrite(lock, LOW);
      delay(200);
    }
  }
  delay(1000);
}
