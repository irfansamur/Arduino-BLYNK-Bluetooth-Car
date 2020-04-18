char auth[] = "c3072b9dcaba4061b3c14385c7da4344";
const int motorA1  = 5;  // L298N'in IN1 Girişi
const int motorA2  = 6;  // L298N'in IN2 Girişi
const int motorB1  = 10; // L298N'in IN3 Girişi
const int motorB2  = 9;  // L298N'in IN4 Girişi
float state;
#define BLYNK_PRINT Serial
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>

BLYNK_WRITE(V1) {
  int x = param[0].asInt();
  int y = param[1].asInt();
  Serial.print("X = ");
  Serial.print(x);
  Serial.print("; Y = ");
  Serial.println(y);


void setup() {
  Serial.begin(9600);
  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);
  Serial.println("Waiting for connections...");
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT); 
  } 
  
void loop(){
  if (x == 128 && y == 128) {
      analogWrite(motorA1, LOW);
      analogWrite(motorB1, LOW);
      analogWrite(motorA1, LOW);
      analogWrite(motorB2, LOW);
    }
    
   else if (x<128) {
      analogWrite(motorA2, HIGH);
      analogWrite(motorB2, HIGH); 
    }
  else if (x>128) {
      analogWrite(motorA2, HIGH);
      analogWrite(motorB2, HIGH); 
    }

   else if (y<128) {
      analogWrite(motorA1, LOW);
      analogWrite(motorB1, HIGH); 
   }
   
      else if (x<128) {
      analogWrite(motorA2, HIGH);
      analogWrite(motorB2, HIGH); 
    }  
    Blynk.run(); 
}
