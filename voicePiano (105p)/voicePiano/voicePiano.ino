#define PIEZO_PIN 11 
int echo =6; 
int trig =7;

void setup() {
 Serial.begin(9600);
 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);
 pinMode(PIEZO_PIN,OUTPUT);
}

void loop() {
 digitalWrite(trig, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(trig, LOW);

 unsigned long duration = pulseIn(echo, HIGH);

 float distanceCM = ((34000*duration)/1000000)/2;

  if (distanceCM >= 0 && distanceCM < 10) {
    tone (PIEZO_PIN, 262); // 도
  } else if (distanceCM >= 10 && distanceCM < 13) {
    tone (PIEZO_PIN, 262); // 미
  } else if (distanceCM >= 13 && distanceCM < 16) {
    tone (PIEZO_PIN, 262); // 파
  } else if (distanceCM >= 16 && distanceCM < 19) {
    tone (PIEZO_PIN, 262); // 솔
  } else if (distanceCM >= 19 && distanceCM < 22) {
    tone (PIEZO_PIN, 262); // 라
  } else if (distanceCM >= 22 && distanceCM < 25) {
    tone (PIEZO_PIN, 262); // 시
  } else if (distanceCM >= 25 && distanceCM < 28) {
    tone (PIEZO_PIN, 262); // 도~5옥타브
  } else if (distanceCM >= 28 && distanceCM < 31) {
    tone (PIEZO_PIN, 262); // 레 
} else {
  noTone(PIEZO_PIN);
}

Serial.println(distanceCM);
delay(100);

}
