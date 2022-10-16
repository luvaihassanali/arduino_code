#include <Arduino.h>
#include <Servo.h>
#include <arduino-timer.h>

#define DEBUG false

const int BAUD_RATE = 9600;
const int DOOR_DELAY = 2000;
const int IR_SENSOR_PIN = 8;
const int SERVO_DELAY = 15;
const int SERVO_UNLOCK_POS = 20;
const int SERVO_PIN = 12;
const int SERVO_LOCK_POS = 45;
const long TICK_LENGTH = 14400000; //7200000;
const int RED_LIGHT_PIN = 9;
const int GREEN_LIGHT_PIN = 10;
const int BLUE_LIGHT_PIN = 11;
Servo servo;

auto timer = timer_create_default();
bool locked = true;
bool open = false;
bool halfway = false;

enum RGB_COLOR
{
  RED,
  GREEN,
  BLUE
};

void Lock();
void Log(String msg);
inline const char *RGB_ToString(RGB_COLOR c);
void RGB_color(int r, int g, int b);
void ServoLock();
void ServoUnlock();
bool Unlock(void *);
void TurnOnLed(RGB_COLOR color);

void setup()
{
  if (DEBUG)
  {
    Serial.begin(BAUD_RATE);
  }

  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(RED_LIGHT_PIN, OUTPUT);
  pinMode(GREEN_LIGHT_PIN, OUTPUT);
  pinMode(BLUE_LIGHT_PIN, OUTPUT);

  servo.write(SERVO_LOCK_POS);
  servo.attach(SERVO_PIN);

  Log("Set timer tick: " + String(TICK_LENGTH));
  timer.every(TICK_LENGTH, Unlock);

  TurnOnLed(RED);
  ServoUnlock();
  delay(DOOR_DELAY);
  ServoLock();
}

void loop()
{
  timer.tick();
  if (!locked)
  {
    int irState = digitalRead(IR_SENSOR_PIN); // 1 (HIGH) is open 0 (LOW) is closed
    if (!open)
    {
      if (irState == HIGH)
      {
        Log("Open = true, IR sensor: " + String(irState));
        open = true;
        TurnOnLed(BLUE);
        delay(DOOR_DELAY);
      }
    }
    else
    {
      if (irState == LOW)
      {
        Log("Open = false, IR sensor: " + String(irState));
        open = false;
        delay(DOOR_DELAY);
        Lock();
      }
    }
  }
}

void Log(String msg)
{
  if (DEBUG)
  {
    Serial.println(msg);
  }
}

void Lock()
{
  Log("Lock");
  TurnOnLed(RED);
  locked = true;
  ServoLock();
  Log("Set timer tick: " + String(TICK_LENGTH));
  timer.every(TICK_LENGTH, Unlock);
}

void ServoLock()
{
  for (int servoPos = SERVO_UNLOCK_POS; servoPos <= SERVO_LOCK_POS; servoPos += 1)
  {
    servo.write(servoPos);
    delay(SERVO_DELAY);
  }
}

bool Unlock(void *)
{
  Log("Unlock");
  TurnOnLed(GREEN);
  locked = false;
  ServoUnlock();
  return false;
}

void ServoUnlock()
{
  for (int servoPos = SERVO_LOCK_POS; servoPos >= SERVO_UNLOCK_POS; servoPos -= 1)
  {
    servo.write(servoPos);
    delay(SERVO_DELAY);
  }
}

void TurnOnLed(RGB_COLOR color)
{
  Log(RGB_ToString(color));
  switch (color)
  {
  case RED:
    RGB_color(255, 0, 0); // Red
    break;
  case GREEN:
    RGB_color(0, 255, 0); // Green
    break;
  case BLUE:
    RGB_color(0, 0, 255); // Blue
    break;
  }
}

void RGB_color(int r, int g, int b)
{
  analogWrite(RED_LIGHT_PIN, r);
  analogWrite(GREEN_LIGHT_PIN, g);
  analogWrite(BLUE_LIGHT_PIN, b);
}

inline const char *RGB_ToString(RGB_COLOR c)
{
  switch (c)
  {
  case RED:
    return "RED";
  case GREEN:
    return "GREEN";
  case BLUE:
    return "BLUE";
  }
}