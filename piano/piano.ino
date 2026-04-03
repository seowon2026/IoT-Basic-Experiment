#define PIEZO_BUZZER 3
#define SW1 12
#define SW2 11
#define SW3 10
#define SW4 9
#define SW5 8

void setup() {
  Serial.begin(9600);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);
  pinMode(SW5, INPUT_PULLUP);
  // put your setup code here, to run once:

}

void loop() {
  
  Serial.println(digitalRead(SW1));
  // put your main code here, to run repeatedly:
  if (digitalRead(SW1) == 0) tone(PIEZO_BUZZER, 261.6);
  else if(digitalRead(SW2) == 0) tone(PIEZO_BUZZER, 293.6);
  else if(digitalRead(SW3) == 0) tone(PIEZO_BUZZER, 329.6);
  else if(digitalRead(SW4) == 0) tone(PIEZO_BUZZER, 349.2);
  else if(digitalRead(SW5) == 0) tone(PIEZO_BUZZER, 391.9);
  else noTone(PIEZO_BUZZER);

}
