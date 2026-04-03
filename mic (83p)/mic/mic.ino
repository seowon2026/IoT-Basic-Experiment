#define MIC A0
#define LED 8

signed int soundAvg = 0;

int ledState = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int i;
  for (i = 0; i < 10; i++) {
    soundAvg += analogRead(MIC);
  }

  soundAvg = soundAvg / 10;
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int micValue = analogRead(MIC);
  if (micValue - soundAvg >= 20) {
    Serial.println(micValue);
    ledState =! ledState;
    digitalWrite(LED, ledState);
    delay(500);
  }
}
