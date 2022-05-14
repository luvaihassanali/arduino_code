#include <Arduino.h>
#include <AccelStepper.h>

#define DEBUG true
#define FULLSTEP 4

// const int TILT_SENSOR_PIN = A0;
const int BUTTON_PIN = 4;
// const int IR_SENSOR_PIN = 2;
bool forward = true;
AccelStepper myStepper(FULLSTEP, 8, 10, 9, 11);

void Log(String msg);

void setup()
{
  if (DEBUG)
  {
    Serial.begin(9600);
  }
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  myStepper.setMaxSpeed(1000.0);
  myStepper.setAcceleration(100.0);
  myStepper.setSpeed(250);
  Log("Setup done");
}

void loop()
{
  int sensorVal = digitalRead(BUTTON_PIN);

  if (sensorVal == LOW)
  {
    Log("Button pushed " + String(forward));
    if (forward) {
      forward = false;
      myStepper.moveTo(300);
    } else {
      forward = true;
      myStepper.moveTo(0);
    }
    delay(500);
  }

  myStepper.run();
}

void Log(String msg)
{
  if (DEBUG)
  {
    Serial.println(msg);
  }
}