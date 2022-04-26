#include "PinDefinitionsAndMore.h"
#include <IRremote.h>
#include "LowPower.h"

const uint8_t LED_CMD = 0x80;
const uint8_t LED_ON = 0x12;
const uint8_t LED_OFF = 0x1A;
const byte IR_SENSOR_PIN = 2;
byte irInteruptState = 0;

void irInterupt() {}

void setup()
{
  pinMode(IR_SENSOR_PIN, INPUT);
  IrSender.sendNEC(LED_CMD, LED_OFF, 1);
}

void loop()
{
  attachInterrupt(0, irInterupt, CHANGE);
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  detachInterrupt(0);

  irInteruptState = digitalRead(IR_SENSOR_PIN);
  if (irInteruptState == HIGH) {
    IrSender.sendNEC(LED_CMD, LED_ON, 1);
  } else {
    IrSender.sendNEC(LED_CMD, LED_OFF, 1);
  }
}
