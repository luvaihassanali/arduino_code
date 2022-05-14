#include <Stepper.h>

int stepsPerRevolution = 20; 
int steps = 100;

//Stepper x_axis(stepsPerRevolution, 2,3,4,5);
Stepper y_axis(stepsPerRevolution, 8,9,10,11); 
//Stepper z_axis(100, A2, A3, A4, A5);

void reset() {
  //x_axis.step(-300);
  y_axis.step(-300);
}

void up(int x) {
  //z_axis.step(-x); 
}

void down(int x) {
  //z_axis.step(x);
}

void upDown() {
  //z_axis.step(-250);
  //z_axis.step(250);
}

void full() {
  //z_axis.step(250);
  //delay(1000);
  //x_axis.step(steps);
  y_axis.step(100); 
  delay(1000);
  //x_axis.step(-steps);
  y_axis.step(-100);
  //z_axis.step(-250); 

  //x_axis.step(50);
  //x_axis.step(-50);
}

void setup() {
  //x_axis.setSpeed(250);
  y_axis.setSpeed(250);
  //z_axis.setSpeed(250);
  // up(120);
  //down(250);
  //delay(2500);
  //up(300);
  reset();
  //upDown();
  //x_axis.step(150);
  //x_axis.step(-150);
  // x_axis.step(-100);
  full();
}
 
void loop() {}
