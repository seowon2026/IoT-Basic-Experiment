#include <SoftwareSerial.h>

SoftwareSerial btSerial = SoftwareSerial(9, 10);

#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6

void setup()
{
    Serial.begin(115200);
    btSerial.begin(115200);
}

void loop()
{
    if (btSerial.available() > 0)
    {
        String strData = btSerial.readStringUntil('\n');

        if (strData.indexOf("RED") >= 0)
        {
            String strValue = strData.substring(3, strData.length());

            analogWrite(RED_PIN, strValue.toInt());

            Serial.print("RED=");
            Serial.println(strValue.toInt());
        }
        else if (strData.indexOf("GREEN") >= 0)
        {
            String strValue = strData.substring(5, strData.length());

            analogWrite(GREEN_PIN, strValue.toInt());

            Serial.print("GREEN=");
            Serial.println(strValue.toInt());
        }
        else if (strData.indexOf("BLUE") >= 0)
        {
            String strValue = strData.substring(4, strData.length());

            analogWrite(BLUE_PIN, strValue.toInt());

            Serial.print("BLUE=");
            Serial.println(strValue.toInt());
        }
    }
}