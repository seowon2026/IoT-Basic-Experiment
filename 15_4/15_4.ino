#define SW_PIN 3
#define LED_PIN 11

int newSwValue = 1;
int oldSwValue = 1;

int cnt = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SW_PIN, INPUT_PULLUP);
}

void loop() {
  newSwValue = digitalRead(SW_PIN);

  if (newSwValue != oldSwValue)
  {
    oldSwValue = newSwValue;
    if (newSwValue == 0)
    {
      cnt++;
      if (cnt >= 4) cnt = 0;
    }
    delay(200);
  }

  if (cnt == 0) analogWrite(LED_PIN, 0);
  else if (cnt == 1) analogWrite(LED_PIN, 50);
  else if (cnt == 2) analogWrite(LED_PIN, 150);
  else if (cnt == 3) analogWrite(LED_PIN, 255);
}