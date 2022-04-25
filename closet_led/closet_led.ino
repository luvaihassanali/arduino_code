
#include "PinDefinitionsAndMore.h"
#include <IRremote.h>

const int IR_SENSOR_PIN = 2;
const uint8_t LED_CMD = 0x80;
const uint8_t LED_ON = 0x12;
const uint8_t LED_OFF = 0x1A;
const bool debugLog  = true;

bool ledOn = false;

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  if (debugLog) {
    Serial.begin(9600);
    Log("Ready");
  }
}

void loop() {
  if (digitalRead(IR_SENSOR_PIN) == HIGH) {
    Log("High");
    if (!ledOn) {
      Log("in high");
      IrSender.sendNEC(LED_CMD, LED_ON, 1);
      ledOn = true;
    }
  } else {
    Log("Low");
    if (ledOn) {
      Log("in low");
      IrSender.sendNEC(LED_CMD, LED_OFF, 1);
      ledOn = false;
    }
  }
}

void Log(String msg) {
  if (debugLog) {
    Serial.println(msg);
  }
}
/*
ON
23:53:06.552 -> Protocol=NEC Address=0x80 Command=0x12 Raw-Data=0xED127F80 32 bits LSB first
OFF
23:53:12.448 -> Protocol=NEC Address=0x80 Command=0x1A Raw-Data=0xE51A7F80 32 bits LSB first
*/
