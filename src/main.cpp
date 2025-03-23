#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <LiquidCrystal_I2C.h>
#include "env.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
 Serial.begin(115200); 

 lcd.init();
 lcd.backlight();

 WiFi.begin(SSID, PASS);

 while (WiFi.status() != WL_CONNECTED)
 {
    delay(500);
    Serial.print(".");
    lcd.setCursor(0, 1);
    lcd.print(".");
 }

 Serial.print("Connected to the Wifi Network with IP addess: ");
 Serial.println(WiFi.localIP());

 lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi Connected");
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());
  delay(2000);

}


void loop(){
    if (WiFi.status()== WL_CONNECTED){
        HTTPClient http;
        http.begin(ENDPOINT);

        http.addHeader("api-key", API_KEY);

        int responseCode = http.GET();

        if (responseCode <= 0){
            Serial.print("An error occured with code: ");
            Serial.println(responseCode);
            http.end();
            return;
        }

        Serial.print("HTTP Response Code: ");
        Serial.println(responseCode);

        String response = http.getString();
        Serial.println(response);
        http.end();

        JsonDocument object;

        DeserializationError error = deserializeJson(object, response);
        if (error){
            Serial.print("Deserializatiion failed:  ");
            Serial.println(error.c_str());
            return; 
        }

        const char* line1 = object["line_1"];
        const char* line2 =object["line_2"];

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(line1);
        lcd.setCursor(0, 1);
        lcd.print(line2);
        
    }

}