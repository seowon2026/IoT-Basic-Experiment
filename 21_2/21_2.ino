#include <MPU6050_tockn.h>
#include <Wire.h>
#include <math.h>

MPU6050 mpu6050(Wire);

#define BUZZER_PIN 10

float AccBuf[2] = {0, 0};
int bufCnt = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(false);

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  // 초기값 설정
  mpu6050.update();
  AccBuf[0] = mpu6050.getAccX();
  AccBuf[1] = AccBuf[0];
}

void loop() {
  mpu6050.update();

  float accX = mpu6050.getAccX();

  // 시리얼 출력
  Serial.print("AccX: ");
  Serial.print(accX);
  Serial.print(" | Diff: ");
  Serial.println(fabs(AccBuf[0] - AccBuf[1]));

  AccBuf[bufCnt++] = accX;
  if (bufCnt == 2) bufCnt = 0;

  if (fabs(AccBuf[0] - AccBuf[1]) >= 0.1)
  {
    Serial.println("⚠️ 움직임 감지!");

    for (int i = 0; i < 5; i++)
    {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(100);
      digitalWrite(BUZZER_PIN, LOW);
      delay(100);
    }

    // 값 재설정
    mpu6050.update();
    AccBuf[0] = mpu6050.getAccX();
    AccBuf[1] = AccBuf[0];
    bufCnt = 0;
  }

  delay(50); // 너무 빠른 출력 방지
}