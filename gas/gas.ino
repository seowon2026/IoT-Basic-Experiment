#define MQ2 A0
#define MOTOR_INA 5
#define MOTOR_INB 6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int mq2Value = analogRead(MQ2);
  Serial.println(mq2Value);
  if(mq2Value >= 200) {
    analogWrite(MOTOR_INA, 255);
    analogWrite(MOTOR_INB, 0);
  } else {
    analogWrite(MOTOR_INA, 0);
    analogWrite(MOTOR_INB, 0);
  }
}
