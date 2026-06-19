#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* ssid = "jmcjmc";
const char* password = "melab12345";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "kr.pool.ntp.org", 32400, 3600000);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println(" ");
  Serial.println("WiFi connected");
  Serial.println("IP address:");
  Serial.println(WiFi.localIP());

  lcd.init();
  lcd.backlight();

  timeClient.begin();
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {

    timeClient.update();

    unsigned long epochTime = timeClient.getEpochTime();

    struct tm *ptm = gmtime((time_t *)&epochTime);

    int currentYear = ptm->tm_year + 1900;
    int currentMonth = ptm->tm_mon + 1;
    int currentDay = ptm->tm_mday;

    String currentDate = String(currentYear);

    if (currentMonth < 10)
      currentDate += "0" + String(currentMonth);
    else
      currentDate += String(currentMonth);

    if (currentDay < 10)
      currentDate += "0" + String(currentDay);
    else
      currentDate += String(currentDay);

    WiFiClient client;
    HTTPClient http;

    const String url =
      "http://openapi.data.go.kr/openapi/service/rest/Covid19/getCovid19SidoInfStateJson?serviceKey=";

    const String apiKey =
      "FFWLxGIoKo8cQCIu5SIs1fvOiXKXdls%2FU5DSGRwzmbiwIBI0nlz5V6jlex1rGLKR9y8wV3E3i0SMPTLtAhyw%3D%3D";

    const String page = "&pageNo=1&numOfRows=30&";

    const String date =
      "startCreateDt=" + currentDate +
      "&endCreateDt=" + currentDate;

    http.begin(client, url + apiKey + page + date);

    int httpCode = http.GET();

    if (httpCode > 0) {

      String payload = http.getString();

      payload = payload.substring(
        payload.indexOf("합계"),
        payload.indexOf("합계") + 100
      );

      Serial.println(payload);

      int local = payload.indexOf("</incDec>");

      if (local >= 0) {

        String tmp_str = "<incDec>";

        String incDec =
          payload.substring(
            payload.indexOf("<incDec>") + tmp_str.length(),
            local
          );

        lcd.clear();

        lcd.setCursor(3, 0);
        lcd.print(currentDate);

        lcd.setCursor(0, 1);
        lcd.print("today: ");
        lcd.print(incDec);
      }
    }

    http.end();
  }

  for (int i = 0; i < 60; i++) {
    delay(60000);
  }
}