#define HUMAN_DETECT 5
#define LED 8



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(HUMAN_DETECT, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int humanValue = digitalRead(HUMAN_DETECT);
  Serial.println(humanValue);
  if (humanValue == 1) {
    digitalWrite(LED, HIGH);
    delay(5000);
  } else {
    digitalWrite(LED, LOW);
  }
}
