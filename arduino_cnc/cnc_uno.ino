#include <Stepper.h>

int stepsPerRevolution = 20; //general dvd stepper motor rating

Stepper y_axis(stepsPerRevolution, 2,3,4,5); // USB 2.0 Slim External drive stepper motor
Stepper x_axis(stepsPerRevolution, 8,9,10,11); // Power Mac G4 dvd drive stepper motor
Stepper z_axis(100, A2, A3, A4, A5); // 28BYJ-48 stepper motor with ULN2003 driver

//keep track of pen position 
struct point { 
  float x; 
  float y; 
  float z; 
};

//configuration variables (https://github.com/gnea/grbl/wiki/Grbl-v1.1-Configuration - stepsPerX explanation [steps per mm]) 
struct point currPos; 
int stepDelay = 0;
int lineDelay = 50;
int penDelay = 1500;
float stepIncrement = 1;
float stepsPerX = 6.0;
float stepsPerY = 6.0;
float x_min = 0;
float x_max = 40;
float y_min = 0;
float y_max = 40;
float z_min = 0;
float z_max = 1;
float x_pos = x_min;
float y_pos = y_min;
float z_pos = z_max; 

void setup() {
  Serial.begin(9600);
  x_axis.setSpeed(250); //can be lowered but not higher for dvd motors
  y_axis.setSpeed(250);  
  z_axis.setSpeed(250);
}

//loop processes lines of gcode file inputted and executes commands
void loop() {
  delay(200);
  char line[512]; 
  char input;
  int index;
  bool isComment, isSemicolon;
  index = 0;
  isSemicolon = false;
  isComment = false;
  while (1) {
    while (Serial.available()>0) {
      input = Serial.read();
      if ((input == '\n') || (input == '\r')) {             // if end of line
        if (index > 0) {                        // if exists input
          line[index] = '\0';                   
          processNextLine(line, index);
          index = 0;
        } 
        else { } // skip
        isComment = false;
        isSemicolon = false;
        Serial.println("200"); // success code (mimic http)   
      } 
      else {
        if ((isComment) || (isSemicolon)) {   // ignore comments
          if (input == ')')  isComment = false;    
        } 
        else {
          if (input <= ' ') { }                           // ignore whitespace
          else if (input == '/') { }                      // ignore
          else if (input == '(') { isComment = true; }    // if comment 
          else if (input == ';') { isSemicolon = true; }  // if semicolon 
          else if (index >= 512 - 1) {                    // overflow (unlikely to occur)
            Serial.println("Error: buffer overflow");
            isComment = false;
            isSemicolon = false;
          } 
          else if (input >= 'a' && input <= 'z') {        // deal with character case
            line[index++] = input - 'a' + 'A';
          } 
          else {
            line[index++] = input;
          }
        }
      }
    }
  }
}
 
// Need to parse:
// G1 - move [ G1 X60 Y30 or G1 X30 Y50 ]
// G4 P150 - delay
// M300 with S30 (pen down)or S50 (pen up)
// mimics http 200 code for success of above commands and 404 error for anything else that is unrecognized/unnecessary

void processNextLine(char* line, int line_index) {
  int currIndex = 0;
  char buffer[64];                                
  struct point newPos;
  newPos.x = 0.0;
  newPos.y = 0.0;
  while(currIndex < line_index) {
    switch (line[currIndex++]) {          
    case 'G':
      buffer[0] = line[currIndex++];
      buffer[1] = '\0';
      switch (atoi(buffer)){                  
      //  case 4:
         // Serial.println("(pause)"); //insert delay here if necessary 
          //delay(150);  
        case 0:                                  // same as 1 (speed diff. for gcode)
        case 1:
          char* x_index = strchr(line + currIndex, 'X');  
          char* y_index = strchr(line + currIndex, 'Y');
          if (y_index <= 0) {
            newPos.x = atof(x_index + 1); 
            newPos.y = currPos.y;
          } 
          else if (x_index <= 0) {
            newPos.y = atof(y_index + 1);
            newPos.x = currPos.x;
          } 
          else {
            newPos.y = atof(y_index + 1);
            y_index = '\0';
            newPos.x = atof(x_index + 1);
          }     
          drawLine(newPos.x, newPos.y );  
          currPos.x = newPos.x;
          currPos.y = newPos.y;
          break;
        }
        break;
    case 'M':
      buffer[0] = line[currIndex++];       
      buffer[1] = line[currIndex++];
      buffer[2] = line[currIndex++];
      buffer[3] = '\0';
      switch (atoi(buffer)){
        case 300:
        {
          char* s_index = strchr(line + currIndex, 'S');
          float s_pos = atof(s_index + 1);
          if (s_pos == 30) { penDown(); }
          if (s_pos == 50) { penUp(); }
          break;
        }
        default:
          Serial.print("404: M");
          Serial.println(buffer);
      }
    }
  }
}

//based off https://www.marginallyclever.com/blog/2013/08/how-to-build-an-2-axis-arduino-cnc-gcode-interpreter/
void drawLine(float x1, float y1) {
  //check for out of bounds -> squish to max dimension if true
  if (x1 >= x_max) { x1 = x_max; }
  if (x1 <= x_min) { x1 = x_min; }
  if (y1 >= y_max) { y1 = y_max; }
  if (y1 <= y_min) { y1 = y_min; }
  //coordinates into steps
  x1 = (int)(x1 * stepsPerX);
  y1 = (int)(y1 * stepsPerY);
  float x0 = x_pos;
  float y0 = y_pos;
  //perform steps
  long distance_x = abs(x1 - x0);
  long distance_y = abs(y1 - y0);
  //configure direction
  int step_x = x0 < x1 ? stepIncrement : -stepIncrement;
  int step_y = y0 < y1 ? stepIncrement : -stepIncrement;
  long i;
  long processed = 0;
  if (distance_x > distance_y) {
    for (i = 0; i < distance_x; i++) {
      x_axis.step(step_x);
      processed += distance_y;
      if (processed >= distance_x) {
        processed -= distance_x;
        y_axis.step(step_y);
      }
      delay(stepDelay);
    }
  }
  else {
    for (i = 0; i < distance_y; i++) {
      y_axis.step(step_y);
      processed += distance_x;
      if (processed >= distance_y) {
        processed -= distance_y;
        x_axis.step(step_x);
      }
      delay(stepDelay);
    }    
  }
  delay(lineDelay);
  //update position variables
  x_pos = x1;
  y_pos = y1;
}

void penUp() { 
  z_axis.step(-250); //adjust values for less/more height
  delay(penDelay); ; 
  z_pos = z_max;
}

void penDown() { 
  z_axis.step(250);
  delay(penDelay); 
  z_pos = z_min;  
}
