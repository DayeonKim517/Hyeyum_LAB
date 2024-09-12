### 스텝 모터 사용

#include <Stepper.h>

const int stepsPerRevolution = 2048;

Stepper stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  stepper.setSpeed(19);  //1~19
}

void loop() {
  stepper.step(stepsPerRevolution);
  delay(500);
  stepper.step(-stepsPerRevolution);
  delay(500);
}
