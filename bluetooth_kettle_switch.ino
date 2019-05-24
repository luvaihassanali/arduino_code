#include "Servo.h"

char buffer;
String input = "";
Servo myServo; 
boolean firstTime = true; 

void flickTheSwitch() {
  myServo.write(70);
  delay(1000);
  myServo.write(40);
}

void setup()                   
{
 myServo.write(40); 
 myServo.attach(8);
 Serial.begin(9600);       
}

void loop()
{
  if(Serial.available()){
  while(Serial.available())
    {
      char inputChar = (char)Serial.read(); 
      input += inputChar;       
    }
    Serial.println(input);
    while (Serial.available() > 0)  
    { buffer = Serial.read() ; }      
      if(input == "k") { 
      if(firstTime = false) myServo.attach(8);
      flickTheSwitch();
      firstTime = false;
      myServo.detach();      
    }
    input = "";
  }
}
