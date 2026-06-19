#define MOTOR_INA 10
#define MOTOR_INB 11
int echo =6;
int trig =7;

int cnt =0;

void setup(){
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duration = pulseIn(echo, HIGH);

  float distanceCM = ((34000 * duration) /1000000) /2;

  if(distanceCM <=10)
  {
    if (cnt >=10)
    {
      analogWrite(MOTOR_INA, 255);
      analogWrite(MOTOR_INB, 0);
    }
    else cnt++;

  }
  else
  {
    if (cnt ==0)
    {
      analogWrite(MOTOR_INA, 0);
      analogWrite(MOTOR_INB, 0);
    }
    else cnt--;
  }

  Serial.println(distanceCM);
  delay(100);
}