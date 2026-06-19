#define RED_LED_PIN 10
#define GREEN_LED_PIN 9
#define BUZZER_PIN 12

unsigned long currTime = 0;
unsigned long prevTime = 0;

int cnt = 1;

int echo = 6;
int trig = 7;

int stopNgo = 0;

float ultraSonic();

void setup() {
  Serial.begin(9600);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  currTime = millis();
  if (currTime - prevTime >= 1000) 
  {
    prevTime = currTime;

    cnt++;
    if (cnt >= 16) cnt = 1;


    if (cnt >= 1 && cnt <= 10) {
      digitalWrite(RED_LED_PIN, HIGH);
      digitalWrite(GREEN_LED_PIN, LOW);
      stopNgo = 0;
    } else if (cnt >= 11 && cnt <= 15) {
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, HIGH);
      stopNgo = 1;
    }
  }

  float distans = ultraSonic();
  Serial.println(distans);

  if (distans <= 10 && stopNgo == 0) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }
}

float ultraSonic() 
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duration = pulseIn(echo, HIGH);

  float distanceCM = ((34000.0 * duration) / 1000000.0) / 2;

  return distanceCM;
}