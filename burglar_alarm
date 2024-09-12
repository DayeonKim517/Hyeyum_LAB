// 가속도자이로센서를 이용한 도난방지기

#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

#define BUZZER_PIN 10

float AccBuf[2];
int bufCnt = 0; 

void setup() {
  serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(false);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  mpu6050.update();
  AccBuf[bufCnt++] = mpu6050.getAccX();
  if (bufCnt == 2) bufCnt = 0;

  if(abs(AccBuf[0] - AccBuf[1]) >= 0.1)
  {
    for(int i = 0; i < 10; i++)
    {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(200);
      digitalWrite(BUZZER_PIN, LOW);
      delay(200);
    }
    mpu6050.update();
    AccBuf[0] = mpu6050.getAccX();
    AccBuf[1] = mpu6050.getAccX();
    bufCnt = 0;
  }
}
