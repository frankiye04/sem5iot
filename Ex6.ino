Ex6 Coding:
#include <WiFi.h>
#include "ThingSpeak.h"
const char* ssid = "Wifi Name";
const char* password = "Wifi password";
WiFiClient client;
unsigned long channelID = Channel ID From Thingspeak;
const char* writeAPIKey = "Write API Key from Thingspeak";
#define LM35
PIN A0
_
void setup()
{
Serial.begin(9600); //Baud rate shown at the top right of Serial Monitor
WiFi.begin(ssid, password);while (WiFi.status() != WL
_
CONNECTED)
{
delay(500);
Serial.print("
.
");
}
Serial.println("\nWiFi Connected!");
ThingSpeak.begin(client);
}
void loop() {
long sum = 0;
const int samples = 64; // Take 64 readings
for (int i = 0; i < samples; i++) {
sum += analogRead(LM35
_
PIN);
delay(2); // Small delay between readings (optional)
}
// Calculate average
float raw = sum / (float)samples;
float voltage = raw * (5.0 / 1024.0);
float temperature = voltage * 100.0;
Serial.println("Temperature: " + String(temperature));
ThingSpeak.writeField(channelID, 1, temperature, writeAPIKey);
delay(15000);
}
