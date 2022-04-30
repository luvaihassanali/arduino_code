#include <Arduino.h>
#include "constants.h"

int analogInput = A0;
float vOut = 0.00;
float vIn = 0.00;
String voltageString = "0.00";
// Resistance of anode resistor (R1 100K)
float resistor100k = 100000.00;
// Resistance of cathode (R2 10K)
float resistor10k = 10000.00;
int analogVal = 0;
int dotIncrement = 1;

void Log(float val);
void ClearDisplay();
String ParseVoltage(float value);
void PrintDigit(char charToPrint, int digitPort, bool printPeriod);
void PrintDisplay(String displayString, int delayLength, int periodIndex);

void setup()
{
  // Segment sections
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_P, OUTPUT);
  // 4 segments of display
  pinMode(SEGMENT_CHAR_1, OUTPUT);
  pinMode(SEGMENT_CHAR_2, OUTPUT);
  pinMode(SEGMENT_CHAR_3, OUTPUT);
  pinMode(SEGMENT_CHAR_4, OUTPUT);
  // Voltage analog pin
  pinMode(analogInput, INPUT);

  if (DEBUG)
  {
    Serial.begin(9600);
  }

  ClearDisplay();
}

void loop()
{
  analogVal = analogRead(analogInput);
  // Formula for calculating voltage out i.e. V+, here 5.00 (analogReference(DEFAULT))
  vOut = (analogVal * 5.00) / 1024.00;
  // Formula for calculating voltage in i.e. GND Vin (R2/R1+R2)
  vIn = vOut / (resistor10k / (resistor100k + resistor10k));
  // Floor undesired vIn values
  if (vIn < 0.09)
  {
    vIn = 0.00;
  }
  Log(vIn);
  voltageString = ParseVoltage(vIn);

  if (vIn == 0.00)
  {
    PrintDisplay(voltageString, DELAY_VAL, dotIncrement);
    dotIncrement++;
    if (dotIncrement == 5)
    {
      dotIncrement = 1;
    }
  }
  else
  {
    dotIncrement = 1;
    PrintDisplay(voltageString, DELAY_VAL, 2);
  }
}

void ClearDisplay()
{
  digitalWrite(SEGMENT_CHAR_1, !HIGH);
  digitalWrite(SEGMENT_CHAR_2, !HIGH);
  digitalWrite(SEGMENT_CHAR_3, !HIGH);
  digitalWrite(SEGMENT_CHAR_4, !HIGH);

  for (byte i = 0; i < 8; i++)
  {
    digitalWrite(SEGMENT_SECTIONS[i], HIGH);
  }
}

void Log(float val)
{
  if (DEBUG)
  {
    Serial.println(String(val));
  }
}

String ParseVoltage(float value)
{
  String result = "";
  if (value < 10)
  {
    result = "0";
    result += String(value);
    result.replace(".", "");
  }
  else
  {
    result = String(value);
    result.replace(".", "");
  }
  return result;
}

void PrintDigit(char charToPrint, int segmentChar, bool printPeriod)
{
  ClearDisplay();
  int character = -1;
  digitalWrite(segmentChar, HIGH);

  for (int i = 0; i < PRINTABLE_CHARS_LENGTH; i++)
  {
    if (charToPrint == PRINTABLE_CHARS[i][8])
    {
      character = i;
    }
  }

  if (character == -1)
  {
    digitalWrite(PIN_G, !HIGH);
  }
  else
  {
    for (int i = 0; i <= 7; i++)
    {
      digitalWrite(SEGMENT_SECTIONS[i], !PRINTABLE_CHARS[character][i]);
      if (i == 7 && printPeriod == true)
      {
        digitalWrite(13, 0);
      }
    }
  }
}

void PrintDisplay(String displayString, int delayLength, int periodIndex)
{
  char char1 = displayString.charAt(0);
  char char2 = displayString.charAt(1);
  char char3 = displayString.charAt(2);
  char char4 = displayString.charAt(3);

  int stringLength = displayString.length();
  if (stringLength < 5)
  {
    for (int ti = 0; ti <= (delayLength / 8); ti++)
    {
      if (1 > stringLength)
        char1 = ' ';
      else
        char1 = displayString.charAt(0);
      if (2 > stringLength)
        char2 = ' ';
      else
        char2 = displayString.charAt(1);
      if (3 > stringLength)
        char3 = ' ';
      else
        char3 = displayString.charAt(2);
      if (4 > stringLength)
        char4 = ' ';
      else
        char4 = displayString.charAt(3);

      bool pIndex1 = periodIndex == 1 ? true : false;
      bool pIndex2 = periodIndex == 2 ? true : false;
      bool pIndex3 = periodIndex == 3 ? true : false;
      bool pIndex4 = periodIndex == 4 ? true : false;

      PrintDigit(char1, SEGMENT_CHAR_1, pIndex1);
      delay(2);
      PrintDigit(char2, SEGMENT_CHAR_2, pIndex2);
      delay(2);
      PrintDigit(char3, SEGMENT_CHAR_3, pIndex3);
      delay(2);
      PrintDigit(char4, SEGMENT_CHAR_4, pIndex4);
      delay(2);
    }
  }
  else
  {
    for (int t = 0; t <= stringLength; t++)
    {
      for (int ti = 0; ti <= (delayLength / 8); ti++)
      {
        bool pIndex1 = periodIndex == 1 ? true : false;
        bool pIndex2 = periodIndex == 2 ? true : false;
        bool pIndex3 = periodIndex == 3 ? true : false;
        bool pIndex4 = periodIndex == 4 ? true : false;

        PrintDigit(char1, SEGMENT_CHAR_1, pIndex1);
        delay(2);
        PrintDigit(char2, SEGMENT_CHAR_2, pIndex2);
        delay(2);
        PrintDigit(char3, SEGMENT_CHAR_3, pIndex3);
        delay(2);
        PrintDigit(char4, SEGMENT_CHAR_4, pIndex4);
        delay(2);
      }

      if (t + 1 > stringLength)
        char1 = ' ';
      else
        char1 = displayString.charAt(t);
      if ((t + 2) > stringLength)
        char2 = ' ';
      else
        char2 = displayString.charAt(t + 1);
      if ((t + 3) > stringLength)
        char3 = ' ';
      else
        char3 = displayString.charAt(t + 2);
      if ((t + 4) > stringLength)
        char4 = ' ';
      else
        char4 = displayString.charAt(t + 3);
    }
  }
}
