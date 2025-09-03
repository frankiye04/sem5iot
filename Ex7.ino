#include <WiFi.h>
#include <ThingSpeak.h>

const int trigPin = 5;
const int echoPin = 18;
const int ledPin = 15;

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

unsigned long myChannelNumber = Enter_Channel_ID;
const char* myWriteAPIKey = "Enter_Write_API_key_from_Thingspeak";

WiFiClient client;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");
  ThingSpeak.begin(client);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  if (distance < 100) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  int statusCode = ThingSpeak.writeField(myChannelNumber, 1, distance, myWriteAPIKey);
  if (statusCode == 200) {
    Serial.println("Channel update successful.");
  } else {
    Serial.print("Problem updating channel. HTTP error code: ");
    Serial.println(statusCode);
  }

  delay(15000);
}
