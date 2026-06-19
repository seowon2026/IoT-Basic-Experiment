#include <Servo.h>

#define SERVO_PIN 9

int echo =6;
int trig =7;

Servo myservo;

int cnt =0;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myservo.attach(SERVO_PIN);
}

void loop() {

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duration = pulseIn(echo, HIGH);

  float distanceCM = (34000.0 * duration / 1000000.0) / 2.0;

  if (distanceCM <=30)
  {
    if(cnt >=10)
    {
      myservo.write(90);
    }
    else cnt = cnt +2;
  }
  else
  {
    if(cnt ==0)
    {
      myservo.write(0);
    }
    else cnt--;
  }

  Serial.println(distanceCM);
  delay(100);
}