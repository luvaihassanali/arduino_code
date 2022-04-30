#ifndef CONSTANTS_H
#define CONSTANTS_H

/*

https://create.arduino.cc/projecthub/aboda243/how-to-use-4-digit-7-segment-without-library-b8e014

      A
     ---
  F |   | B
    | G |
     ---
  E |   | C
    |   |
     --- . P
      D

*/

#define pinA 2
#define pinB 3
#define pinC 4
#define pinD 5
#define pinE 7
#define pinF 12
#define pinG 8
#define pinDP 13
#define D1 6
#define D2 9
#define D3 10
#define D4 11
#define DP 30

const int charsInArray = 37;
byte digits[]{D1, D2, D3, D4};
byte seg[]{pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP};
byte Char[37][9]{
    {1, 1, 1, 1, 1, 1, 0, 0, '0'}, // 0
    {0, 1, 1, 0, 0, 0, 0, 0, '1'}, // 1
    {1, 1, 0, 1, 1, 0, 1, 0, '2'}, // 2
    {1, 1, 1, 1, 0, 0, 1, 0, '3'}, // 3
    {0, 1, 1, 0, 0, 1, 1, 0, '4'}, // 4
    {1, 0, 1, 1, 0, 1, 1, 0, '5'}, // 5
    {1, 0, 1, 1, 1, 1, 1, 0, '6'}, // 6
    {1, 1, 1, 0, 0, 0, 0, 0, '7'}, // 7
    {1, 1, 1, 1, 1, 1, 1, 0, '8'}, // 8
    {1, 1, 1, 1, 0, 1, 1, 0, '9'}, // 9
    {1, 1, 1, 0, 1, 1, 1, 0, 'a'}, // A/1
    {0, 0, 1, 1, 1, 1, 1, 0, 'b'}, // b/2
    {0, 0, 0, 1, 1, 0, 1, 0, 'c'}, // C/3
    {0, 1, 1, 1, 1, 0, 1, 0, 'd'}, // d/4
    {1, 0, 0, 1, 1, 1, 1, 0, 'e'}, // E/5
    {1, 0, 0, 0, 1, 1, 1, 0, 'f'}, // F/6
    {1, 0, 1, 1, 1, 1, 0, 0, 'g'}, // G/7
    {0, 1, 1, 0, 1, 1, 1, 0, 'h'}, // H/8
    {0, 1, 1, 0, 0, 0, 0, 0, 'i'}, // I/9
    {0, 1, 1, 1, 1, 0, 0, 0, 'j'}, // J/10
    {0, 0, 0, 1, 1, 1, 0, 0, 'l'}, // L/11
    {0, 0, 1, 0, 1, 0, 1, 0, 'n'}, // n/12
    {0, 0, 1, 1, 1, 0, 1, 0, 'o'}, // o/13
    {1, 1, 0, 0, 1, 1, 1, 0, 'p'}, // P/14
    {1, 1, 1, 0, 0, 1, 1, 0, 'q'}, // q/15
    {0, 0, 0, 0, 1, 0, 1, 0, 'r'}, // r/16
    {1, 0, 1, 1, 0, 1, 1, 0, 's'}, // S/17   looks like number 5
    {0, 0, 0, 1, 1, 1, 1, 0, 't'}, // t/18
    {0, 1, 1, 1, 1, 1, 0, 0, 'u'}, // U/19
    {0, 1, 1, 1, 0, 1, 1, 0, 'y'}, // y/20
    {0, 0, 0, 0, 0, 0, 0, 1, '.'}, //.
    {0, 0, 0, 0, 0, 0, 1, 0, '-'}, // dash/negative
    {0, 0, 0, 1, 0, 0, 0, 0, '_'}, // underscore
    {1, 0, 0, 1, 1, 1, 0, 0, '['}, //[
    {1, 1, 1, 1, 0, 0, 0, 0, ']'}, //]
    {1, 1, 0, 0, 1, 0, 1, 0, '?'}, //?
    {0, 0, 0, 0, 0, 0, 0, 0, ' '}  // blank
};

void Reset();
void printDigit(char Chara, int digitPort, bool printPeriod = false);
void printDisplay(String Phrase, int Delay);

#endif