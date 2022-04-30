#include <Arduino.h>
#include "constants.h"

void Log(String msg);
void ClearDisplay();
void PrintDigit(char charToPrint, int digitPort, bool printPeriod);
void PrintDisplay(String displayString, int delayLength);

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

  if (DEBUG)
  {
    Serial.begin(9600);
  }

  PrintDisplay("8888", 3000);
  ClearDisplay();
  delay(1000);
  PrintDigit('8', SEGMENT_CHAR_1, true);
  delay(1000);
  PrintDigit('8', SEGMENT_CHAR_2, true);
  delay(1000);
  PrintDigit('8', SEGMENT_CHAR_3, true);
  delay(1000);
  PrintDigit('8', SEGMENT_CHAR_4, true);
  delay(1000);
}

void loop() {}

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

void Log(String msg)
{
  if (DEBUG)
  {
    Serial.println(msg);
  }
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

void PrintDisplay(String displayString, int delayLength)
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

      PrintDigit(char1, SEGMENT_CHAR_1, true);
      delay(2);
      PrintDigit(char2, SEGMENT_CHAR_2, true);
      delay(2);
      PrintDigit(char3, SEGMENT_CHAR_3, true);
      delay(2);
      PrintDigit(char4, SEGMENT_CHAR_4, true);
      delay(2);
    }
  }
  else
  {
    for (int t = 0; t <= stringLength; t++)
    {
      for (int ti = 0; ti <= (delayLength / 8); ti++)
      {
        PrintDigit(char1, SEGMENT_CHAR_1, true);
        delay(2);
        PrintDigit(char2, SEGMENT_CHAR_2, true);
        delay(2);
        PrintDigit(char3, SEGMENT_CHAR_3, true);
        delay(2);
        PrintDigit(char4, SEGMENT_CHAR_4, true);
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