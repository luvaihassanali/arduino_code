#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Stepper.h>

#define DEBUG true

const int IR_SENSOR_PIN = 2;
const int STEPS_TO_MOVE = 2048;
const int MAX_SPEED = 400;
const int NUM_STEPS = 100; // total number of steps for this motor
Stepper stepper = Stepper(NUM_STEPS, 8, 10, 9, 11);

SoftwareSerial esp8266(8, 7);
const String WIFI_SSID = "ssid";
const String WIFI_PASS = "password";
const String WIFI_PORT = "3000";
const String CONNECTION_STRING = "AT+CWJAP=\"" + WIFI_SSID + "\",\"" + WIFI_PASS + "\"\r\n";
const String SERVER_STRING = "AT+CIPSERVER=1," + WIFI_PORT + "\r\n";

void Log(String msg);

void setup()
{
  stepper.setSpeed(MAX_SPEED);
}

void loop()
{
  stepper.step(STEPS_TO_MOVE);
  delay(1000);
  stepper.step(-STEPS_TO_MOVE);
  delay(1000);
}

void Log(String msg)
{
  if (DEBUG)
  {
    Serial.println(msg);
  }
}