#include <Servo.h>         
#include <NewPing.h>     

int motorPin1 = 4;
int motorPin2 = 3;
int motorPin3 = 5;
int motorPin4 = 6;
int distance = 100;
int trig_pin = A0; 
int echo_pin = A1; 
int photocellPin = A5;
int photocellReading;  
int photocellPinB = A4;
int photocellReadingB;  
boolean isGoingForward = false;

NewPing sonar(trig_pin, echo_pin, 200); 
Servo myServo; 

void setup(){  
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  myServo.attach(10); 
  myServo.write(110);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop(){
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20 || photocellReading <= 150 || photocellReadingB <= 100) {
    hault();
    delay(300);
    reverse();
    delay(400);
    hault();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);
    if (distanceRight >= distanceLeft){
      turnRight();
      hault();
    }
    else{
      turnLeft();
      hault();
    }
  }
  else{
    accelerate(); 
  }
    distance = readPing();
    photocellReading = analogRead(photocellPin);  
    photocellReadingB = analogRead(photocellPinB);  
}

int lookRight(){  
  myServo.write(45);
  delay(500);
  int distance = readPing();
  delay(100);
  myServo.write(110);
  return distance;
}

int lookLeft(){
  myServo.write(165);
  delay(500);
  int distance = readPing();
  delay(100);
  myServo.write(110);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void hault(){
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin2, LOW);
}

void accelerate(){
  if(!isGoingForward){
    isGoingForward=true;
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin4, LOW); 
  }
}

void reverse(){
  isGoingForward=false;
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin3, LOW);
}

void turnRight(){
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin4, HIGH); 
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  delay(500);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin4, LOW);
}

void turnLeft(){
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin4, LOW);
  delay(500);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin4, LOW);
}
