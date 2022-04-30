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

#define DEBUG true

#define PIN_A 2
#define PIN_B 3
#define PIN_C 4
#define PIN_D 5
#define PIN_E 7
#define PIN_F 12
#define PIN_G 8
#define PIN_P 13
#define SEGMENT_CHAR_1 6
#define SEGMENT_CHAR_2 9
#define SEGMENT_CHAR_3 10
#define SEGMENT_CHAR_4 11

const byte SEGMENT_SECTIONS[]{PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_P};
const int PRINTABLE_CHARS_LENGTH = 37;
const byte PRINTABLE_CHARS[PRINTABLE_CHARS_LENGTH][9]{
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
    {1, 0, 1, 1, 0, 1, 1, 0, 's'}, // S/17
    {0, 0, 0, 1, 1, 1, 1, 0, 't'}, // t/18
    {0, 1, 1, 1, 1, 1, 0, 0, 'u'}, // U/19
    {0, 1, 1, 1, 0, 1, 1, 0, 'y'}, // y/20
    {0, 0, 0, 0, 0, 0, 0, 1, '.'}, // .
    {0, 0, 0, 0, 0, 0, 1, 0, '-'}, // dash/negative
    {0, 0, 0, 1, 0, 0, 0, 0, '_'}, // underscore
    {1, 0, 0, 1, 1, 1, 0, 0, '['}, // [
    {1, 1, 1, 1, 0, 0, 0, 0, ']'}, // ]
    {1, 1, 0, 0, 1, 0, 1, 0, '?'}, // ?
    {0, 0, 0, 0, 0, 0, 0, 0, ' '}  // blank
};

#endif