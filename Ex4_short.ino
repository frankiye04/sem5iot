#define buzzPin 9
#define irSensorPin 8
#define ledPin 10

void setup() {
  Serial.begin(9600);
  pinMode(irSensorPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int irValue = digitalRead(irSensorPin);
  if (irValue == HIGH) {
    digitalWrite(buzzPin, HIGH);
    digitalWrite(ledPin, HIGH);
    Serial.println("Intruder detected!");
  } else {
    digitalWrite(buzzPin, LOW);
    digitalWrite(ledPin, LOW);
    Serial.println("No Intruder");
  }
  delay(100);
}