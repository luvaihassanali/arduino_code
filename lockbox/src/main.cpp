#include <Arduino.h>
#include <AccelStepper.h>

#define DEBUG true
#define FULLSTEP 4

const int BUTTON_PIN = 4;
const int IR_SENSOR_PIN = 5;
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
  pinMode(IR_SENSOR_PIN, INPUT);
  myStepper.setMaxSpeed(1000.0);
  myStepper.setAcceleration(100.0);
  myStepper.setSpeed(250);
  Log("Setup done");
}

void loop()
{

  int buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == LOW)
  {
    Log("Button pushed " + String(forward));
    if (forward)
    {
      forward = false;
      myStepper.moveTo(310);
    }
    else
    {
      forward = true;
      myStepper.moveTo(0);
    }
    delay(500);
    int irState = digitalRead(IR_SENSOR_PIN);
    Log("IR sensor: " + String(irState));
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