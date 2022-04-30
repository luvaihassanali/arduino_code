#include <Stepper.h>

const int stepsPerRevolution = 2048;

Stepper myStepper = Stepper(100, 8, 10, 9, 11);

void setup() {
  myStepper.setSpeed(400);
}

void loop() {
  myStepper.step(stepsPerRevolution);
  delay(1000);
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}
