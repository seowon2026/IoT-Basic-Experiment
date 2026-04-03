#define LED 11
#define VR A0


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(VR);
  analogWrite(LED, analogValue / 4);

  // put your main code here, to run repeatedly:

}
