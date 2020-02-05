#include <SoftwareSerial.h>
SoftwareSerial esp8266(9, 8);
#define DEBUG true
#define LED 13 //blue
#define GREEN 12
#define RED 11

//Motor A
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293
//Motor B
const int motorPin3  = 3; // Pin  7 of L293
const int motorPin4  = 4;  // Pin  2 of L293

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  Serial.begin(9600);
  esp8266.begin(9600);
  digitalWrite(LED, HIGH);
  esp8266Data("AT+RST\r\n", 2000, DEBUG); //reset module
  esp8266Data("AT+CWMODE=1\r\n", 1000, DEBUG); //set station mode
  esp8266Data("AT+CWJAP=\"AAAA Good Wi-Fi 2.4\",\"Chandler\"\r\n", 2000, DEBUG);   //connect wifi network
  while (!esp8266.find("OK")) {
    /*wait for connection*/
  }
  esp8266Data("AT+CIFSR\r\n", 1000, DEBUG);
  esp8266Data("AT+CIPMUX=1\r\n", 1000, DEBUG);
  esp8266Data("AT+CIPSERVER=1,80\r\n", 1000, DEBUG);
  digitalWrite(LED, LOW);
}

void loop() {
  if (esp8266.available()) {
    if (esp8266.find("+IPD,")) {
      String msg;
      esp8266.find("?");
      msg = esp8266.readStringUntil(' ');
      String command = msg.substring(0, 3);
      String valueStr = msg.substring(4);
      int value = valueStr.toInt();
      if (DEBUG) {
        Serial.println(command);
        Serial.println(value);
      }
      switch (value) {
        case 0:
          Serial.println("stop");
          digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, LOW);
          break;
        case 1:
          Serial.println("f");
          digitalWrite(motorPin1, HIGH);
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, HIGH);
          digitalWrite(motorPin4, LOW);
          break;
        case 2:
          Serial.println("b");
          digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, HIGH);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, HIGH);
          break;
        case 3:
          Serial.println("l");
          digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, HIGH);
          digitalWrite(motorPin4, LOW);
          break;
        case 4:
          Serial.println("r");
          digitalWrite(motorPin1, HIGH);
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, LOW);
          break;
        case 5:
          digitalWrite(LED, HIGH);
          digitalWrite(GREEN, LOW);
          digitalWrite(RED, LOW);
          break;
        case 6:
          digitalWrite(LED, LOW);
          digitalWrite(GREEN, HIGH);
          digitalWrite(RED, LOW);
          break;
        case 7:
          digitalWrite(LED, LOW);
          digitalWrite(GREEN, LOW);
          digitalWrite(RED, HIGH);
          break;
        case 8:
          digitalWrite(LED, LOW);
          digitalWrite(GREEN, LOW);
          digitalWrite(RED, LOW);
          break;
      }
      delay(200);
    }
  }
}

String esp8266Data(String command, const int timeout, boolean debug) {
  String response = "";
  esp8266.print(command);
  long int time = millis();
  while ((time + timeout) > millis()) {
    while (esp8266.available()) {
      char c = esp8266.read();
      response += c;
    }
  }
  if (debug) {
    Serial.print(response);
  }
  return response;
}
