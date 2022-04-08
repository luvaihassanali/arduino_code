                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             #include "Servo.h"
#include <NewPing.h>
//l is for left side wheels, r for right
const int enablePinA = 11;
const int enablePinB = 3;
const int motorPin1 = 8; //rf
const int motorPin2 = 7; //rb
const int motorPin3 = 4; //lf
const int motorPin4 = 5; //lb
const int tiltPin = 12;
const int redPin = A0;
const int greenPin = A1;
const int bluePin = A2; 
const int trigPin = A4; 
const int echoPin = A5;

NewPing sonar(trigPin, echoPin, 200); 
Servo wheelServo;
Servo lookServo;

int distance = 100;
int cm = 0;
int tiltReading = 1;
boolean manual = false; 

void setup() {
  pinMode(enablePinA, OUTPUT);
  pinMode(enablePinB, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH); //turn on built-in pull up resistor
  analogWrite(enablePinA, 250); //l
  analogWrite(enablePinB, 255); //r
  wheelServo.write(95);
  wheelServo.attach(9);
  lookServo.write(90);
  lookServo.attach(10);
  Serial.begin(9600);
  //Serial.println("Setup complete");
  greenLight();
  delay(5000);
  lookLeft();
  delay(500);
  lookRight();
  delay(500);
  accelerate();
}

void loop() {   
  if(!manual) {
    Serial.println("automatic");
    distance = readPing();
    tiltReading = digitalRead(tiltPin);
    if(distance <= 20) { redLight(); obstacleDetected(); greenLight(); }
    if(tiltReading == 0) {  blueLight(); obstacleDetected(); greenLight(); }
  } 
  char receiveVal;     
  if(Serial.available() > 0) {          
        receiveVal = Serial.read();  
        switch(receiveVal) {
          case '3':
           // Serial.println("3 manual control");
            if(!manual) {
              hault();
              manual = true; 
            }
            break;
          case '4':
           // Serial.println("4 automatic control");
            if(manual) {
              manual = false;
              wheelServo.write(95);
              delay(300);
              accelerate();
            }
            break;
          case '0':               
            //Serial.println("0: Accelerate");
            if(manual) accelerate();
            break;
          case '1':
            //Serial.println("1: Reverse");
            if(manual) reverse();
            break;
          case '2':
            //Serial.println("2: Stop");
            if(manual) hault();
            break;
          default:
            //Serial.print("Default: ");
            //Serial.println(receiveVal);
            if(manual) moveServo(receiveVal); 
        }
    }   
}
const char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','q','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};
const int nums[] = { 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75 };

void moveServo(char x) {
  for(int i=0; i<41; i++) {
    if(x==letters[i]) {
      wheelServo.write(nums[i]);
    }
  }
}

void accelerate() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

void reverse() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}
void hault() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}

int readPing(){
  cm = sonar.ping_cm();
  if (cm==0) cm=250;
  return cm;
}

int lookRight() {  
  lookServo.write(30);
  delay(500);
  int distance = readPing();
  delay(100);
  lookServo.write(90);
  return distance;
}

int lookLeft() {
  lookServo.write(150);
  delay(500);
  int distance = readPing();
  delay(100);
  lookServo.write(90);
  return distance;
}

void turnRight() {
  for(int i=95; i<116; i++) {
    wheelServo.write(i);
    delay(20); // adjust
  }
  accelerate();
  delay(1000);
  for(int i=115; i>94; i--) {
    wheelServo.write(i);
    delay(20);
  }
}

void turnLeft() {
  for(int i=95; i>74; i--) {
    wheelServo.write(i);
    delay(20); // adjust
  }
  accelerate();
   delay(1000);
  for(int i=75; i<96; i++) {
    wheelServo.write(i);
    delay(20);
  }
}

void obstacleDetected() { 
  //need to adjust delays
  int distanceRight = 0;
  int distanceLeft = 0;
  hault();
  delay(300);
  reverse();
  delay(800);
  hault();
  delay(300);
  distanceRight = lookRight();
  delay(300);
  distanceLeft = lookLeft();
  delay(300);
  //accelerate();
  if (distanceRight >= distanceLeft){
    turnRight();
    distance = distanceRight;
    //hault();
  } else{
    turnLeft();
    distance = distanceLeft;
    //hault();
  }
  //accelerate();
}

void redLight() {
  analogWrite(redPin,255);
  analogWrite(greenPin,0);
  analogWrite(bluePin,0);  
}

void blueLight() {
  analogWrite(redPin,0);
  analogWrite(greenPin,0);
  analogWrite(bluePin,255);  
}

void greenLight() {
  analogWrite(redPin,0);
  analogWrite(greenPin,255);
  analogWrite(bluePin,0);  
}

void lightOff() {
  analogWrite(redPin,0);
  analogWrite(greenPin,0);
  analogWrite(bluePin,0);  
}
