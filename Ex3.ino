#define trigPin 8
#define echoPin 9
#define led 3
#define led2 7

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = (duration / 2) / 29.1;

  digitalWrite(led, (distance < 100) ? HIGH : LOW);
  digitalWrite(led2, (distance > 100) ? HIGH : LOW);

  if (distance >= 120 || distance <= 0) {
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(1000);
}
