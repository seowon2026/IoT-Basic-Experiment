#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* ssid = "개미";
const char* password = "00000000";

#define RED_LED D9
#define GREEN_LED D10
#define BLUE_LED D11

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password); // 1. 오타 수정: WiFibegin -> WiFi.begin

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println(" ");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  lcd.init();
  lcd.backlight();

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client; 
    HTTPClient http;

    const String url = "http://apis.data.go.kr/B552584/ArpltnInforInqireSvc/getCtprvnRltmMesureDnsty?serviceKey=532a651fa4bf6070696597a2a7ad285bb8de693c6bc4fdc0fc43eef515409a66&returnType=xml&numOfRows=1&pageNo=14&sidoName=%EC%B6%A9%EB%B6%81&ver=1.0"; // 3. HTTPS 접속 에러 방지를 위해 http://로 변경

    http.begin(client, url); // 
    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      int pm10ValueStart = payload.indexOf("<pm10Value>"); // 5. 파싱 변수명 명확화 및 로직 수정
      int pm10ValueEnd = payload.indexOf("</pm10Value>");

      if (pm10ValueStart >= 0 && pm10ValueEnd > pm10ValueStart) {
        String tmp_str = "<pm10Value>"; // 6. 데이터 추출 구간 수정 (시작 태그 끝점부터 닫는 태그 시작점까지)
        String dust_val = payload.substring(pm10ValueStart + tmp_str.length(), pm10ValueEnd);

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("PM10:");
        lcd.print(dust_val);

        int numDustValue = dust_val.toInt();

        if (numDustValue >= 0 && numDustValue <= 30) {
          digitalWrite(RED_LED, LOW);
          digitalWrite(GREEN_LED, LOW);
          digitalWrite(BLUE_LED, HIGH);
        } else if (numDustValue >= 31 && numDustValue <= 80) {
          digitalWrite(RED_LED, LOW);
          digitalWrite(GREEN_LED, HIGH);
          digitalWrite(BLUE_LED, LOW);
        } else if (numDustValue >= 81 && numDustValue <= 150) {
          digitalWrite(RED_LED, HIGH);
          digitalWrite(GREEN_LED, HIGH);
          digitalWrite(BLUE_LED, LOW);
        } else if (numDustValue >= 151) {
          digitalWrite(RED_LED, HIGH);
          digitalWrite(GREEN_LED, LOW);
          digitalWrite(BLUE_LED, LOW);
        }
      }
    }
    http.end();
  }
  delay(10000);
}