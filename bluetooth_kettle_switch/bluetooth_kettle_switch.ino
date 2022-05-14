#include "Servo.h"

char buffer;
String input = "";
Servo myServo; 

void flickTheSwitch() {
  myServo.write(80);
  delay(1000);
  myServo.write(10);
}

void setup()                   
{
 myServo.write(10); 
 myServo.attach(8);
 Serial.begin(9600);  
 //flickTheSwitch();     
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
      flickTheSwitch();     
    }
    input = "";
  }
}
