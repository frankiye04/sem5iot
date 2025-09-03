#include <WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "Wifi Name";
const char* password = "Wifi password";

WiFiClient client;

unsigned long channelID = Channel_ID_From_Thingspeak;
const char* writeAPIKey = "Write_API_Key_from_Thingspeak";

#define LM35_PIN A0

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");
  ThingSpeak.begin(client);
}

void loop() {
  long sum = 0;
  const int samples = 64;
  for (int i = 0; i < samples; i++) {
    sum += analogRead(LM35_PIN);
    delay(2);
  }
  float raw = sum / (float)samples;
  float voltage = raw * (5.0 / 1024.0);
  float temperature = voltage * 100.0;
  Serial.println("Temperature: " + String(temperature));
  ThingSpeak.writeField(channelID, 1, temperature, writeAPIKey);
  delay(15000);
}
