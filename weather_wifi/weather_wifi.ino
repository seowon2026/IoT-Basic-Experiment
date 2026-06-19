#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* ssid = "jmcjmc";
const char* password = "mela12345";

#define RED_LED D9
#define GREEN_LED D10
#define BLUE_LED D11

void setup() {
    Serial.begin(115200);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println(" ");
    Serial.println(" WiFi connected");
    Serial.println(" IP address: ");
    Serial.println(WiFi.localIP());

    lcd.init();
    lcd.backlight();

    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
}

void loop() {
    if (WiFi.status() == WL_CONNECTED) {

        HTTPClient http;

        String url = "http://openapi.airkorea.or.kr/openapi/services/rest/ArpltnInforInqireSvc/getCtprvnMesureSidoLIst?serviceKey=...&sidoName=...&searchCondition=DAILY";

        http.begin(url);

        int httpCode = http.GET();

        if (httpCode > 0) {

            String payload = http.getString();

            // Serial.println(payload); // 내용 확인

            int pm10Value = payload.indexOf("<pm10Value>");

            if (pm10Value >= 0) {

                String tmp_str = "<pm10Value>";
                String dust_val =
                    payload.substring(
                        payload.indexOf(tmp_str) + tmp_str.length(),
                        pm10Value
                    );

                // Serial.print("pm10 dust: ");
                // Serial.println(dust_val);

                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print(" PM10 = ");
                lcd.print(dust_val);

                int numDustValue = dust_val.toInt();

                if (numDustValue >= 0 && numDustValue <= 30) {

                    digitalWrite(RED_LED, LOW);
                    digitalWrite(GREEN_LED, LOW);
                    digitalWrite(BLUE_LED, HIGH);

                }
                else if (numDustValue >= 31 && numDustValue <= 80) {

                    digitalWrite(RED_LED, LOW);
                    digitalWrite(GREEN_LED, HIGH);
                    digitalWrite(BLUE_LED, LOW);

                }
                else if (numDustValue >= 81 && numDustValue <= 150) {

                    digitalWrite(RED_LED, HIGH);
                    digitalWrite(GREEN_LED, HIGH);
                    digitalWrite(BLUE_LED, LOW);

                }
                else if (numDustValue >= 151) {

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