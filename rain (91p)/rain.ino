#include <Servo.h>
#define RAIN_SENSOR A0
#define SERVO_PIN 9

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(SERVO_PIN);
  myservo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int rainValue = analogRead(RAIN_SENSOR);
  Serial.println(rainValue);
  if(rainValue >= 300) {
    myservo.write(0);
    delay(2000);
  } else {
    myservo.write(90);
    delay(2000);
  }

}
