#define LIGHT_CDS A0
#define LED 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(LIGHT_CDS));
  delay(10);
}
