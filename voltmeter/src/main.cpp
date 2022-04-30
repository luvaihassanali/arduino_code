#include <Arduino.h>
#include "constants.h"

void setup()
{
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop()
{
  printDisplay("2021", 1000); // use this function to print a string (has numbers, characters or phrases) when the length of string is 4 or less than 4, the second variable is the time for printing on display
  Reset();                    // use this function to reset the display
  delay(1000);
  // printDisplay("all usable characters [[ 1 2 3 4 5 6 7 8 9 0 a b c d e f g h i j l n o p q r s t u y - _ . [ ] ? ]]",300);// when the length of string is more than 4, the second variable is custom speed for movement
  // delay(1000);
  printDigit('y', D1, true); // print any char on any digit
  delay(1000);
}


void Reset()
{
  digitalWrite(D1, !HIGH);
  digitalWrite(D2, !HIGH);
  digitalWrite(D3, !HIGH);
  digitalWrite(D4, !HIGH);
  for (byte i = 0; i < 8; i++)
  {
    digitalWrite(seg[i], HIGH);
  }
}
void printDigit(char Chara, int digitPort, bool printPeriod = false)
{
  Reset();
  int character = -1;
  digitalWrite(digitPort, HIGH);
  for (int i = 0; i < charsInArray; i++)
  {
    if (Chara == Char[i][8])
    {
      character = i;
    }
  }
  if (character == -1)
  {
    digitalWrite(pinG, !HIGH);
  }
  else
  {
    for (int i = 0; i <= 7; i++)
    {
      digitalWrite(seg[i], !Char[character][i]);
      if (i == 7 && printPeriod == true)
      {
        digitalWrite(13, 0);
      }
    }
  }
}
void printDisplay(String Phrase, int Delay)
{
  char char1 = Phrase.charAt(0);
  char char2 = Phrase.charAt(1);
  char char3 = Phrase.charAt(2);
  char char4 = Phrase.charAt(3);
  // char char5 = Phrase.charAt(4);
  char char1Num = 0;
  char char2Num = 0;
  char char3Num = 0;
  char char4Num = 0;
  int stringLength = Phrase.length();
  if (stringLength < 5)
  {
    for (int ti = 0; ti <= (Delay / 8); ti++)
    {
      if (1 > stringLength)
        char1 = ' ';
      else
        char1 = Phrase.charAt(0);
      if (2 > stringLength)
        char2 = ' ';
      else
        char2 = Phrase.charAt(1);
      if (3 > stringLength)
        char3 = ' ';
      else
        char3 = Phrase.charAt(2);
      if (4 > stringLength)
        char4 = ' ';
      else
        char4 = Phrase.charAt(3);

      printDigit(char1, D1);
      delay(2);
      printDigit(char2, D2);
      delay(2);
      printDigit(char3, D3);
      delay(2);
      printDigit(char4, D4);
      delay(2);
    }
  }
  else
  {
    for (int t = 0; t <= stringLength; t++)
    {
      for (int ti = 0; ti <= (Delay / 8); ti++)
      {
        /*Reset();
        delay(2);*/
        printDigit(char1, D1);
        delay(2);
        printDigit(char2, D2);
        delay(2);
        printDigit(char3, D3);
        delay(2);
        printDigit(char4, D4);
        delay(2);
      }
      if (t + 1 > stringLength)
        char1 = ' ';
      else
        char1 = Phrase.charAt(t);
      if ((t + 2) > stringLength)
        char2 = ' ';
      else
        char2 = Phrase.charAt(t + 1);
      if ((t + 3) > stringLength)
        char3 = ' ';
      else
        char3 = Phrase.charAt(t + 2);
      if ((t + 4) > stringLength)
        char4 = ' ';
      else
        char4 = Phrase.charAt(t + 3);
    }
  }
}