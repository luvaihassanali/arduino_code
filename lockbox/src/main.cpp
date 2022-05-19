#include <Arduino.h>
#include <Servo.h>
//#include <arduino-timer.h>

#define DEBUG true

const int IR_SENSOR_PIN = 7;
// const int TICK_LENGTH = 5000;

Servo servo;

// auto timer = timer_create_default();
// bool locked = true;
bool open = false;
int servoPos = 0;

// void Lock();
void Log(String msg);
// bool Unlock(void *);

void setup()
{
  if (DEBUG)
  {
    Serial.begin(9600);
  }

  pinMode(IR_SENSOR_PIN, INPUT);
  // pinMode(LED_BUILTIN, OUTPUT);

  servo.write(0);
  servo.attach(2);
  Log("setup done");

  // Log("set timer tick: " + String(TICK_LENGTH));
  // timer.every(TICK_LENGTH, Unlock); // 7200000
  // digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{

  int irState = digitalRead(IR_SENSOR_PIN);
  if (irState == 0)
  {
    if (!open)
    {
      Log("IR sensor: " + String(irState));
      for (servoPos = 0; servoPos <= 180; servoPos += 1)
      {
        // in steps of 1 degree
        servo.write(servoPos);
        delay(15);
      }
      Log("moveto 310");
      open = true;
      delay(100);
    }
  }
  else
  {
    if (open)
    {
      Log("IR sensor: " + String(irState));
      for (servoPos = 180; servoPos >= 0; servoPos -= 1)
      {
        servo.write(servoPos);
        delay(15);
      }
      Log("moveto 0");
      open = false;
      delay(100);
    }
  }

  /*if (!locked)
  {
    int irState = digitalRead(IR_SENSOR_PIN); // 1 is open 0 is closed
    if (!open)
    {
      if (irState == 1)
      {
        Log("open = true, IR sensor: " + String(irState));
        open = true;
        //delay(5000);
      }
    }
    else
    {
      if (irState == 0)
      {
        Log("open = false, IR sensor: " + String(irState));
        open = false;
        //delay(1000);
        Lock();
      }
    }
  }*/
}

void Log(String msg)
{
  if (DEBUG)
  {
    Serial.println(msg);
  }
}
/*
void Lock()
{
  Log("lock");
  locked = true;
  digitalWrite(LED_BUILTIN, LOW);
  stepper.moveTo(END_POS);
  Log("set timer tick: " + String(TICK_LENGTH));
  //timer.every(TICK_LENGTH, Unlock);
}

bool Unlock(void *)
{
  Log("unlock");
  locked = false;
  digitalWrite(LED_BUILTIN, HIGH);
  stepper.moveTo(0);
  return false;
}*/