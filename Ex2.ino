#include <Servo.h>

const int IR_SENSOR_PIN = 2;
const int SERVO_PIN = 9;

Servo myServo;

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  myServo.attach(SERVO_PIN);
  myServo.write(0);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(IR_SENSOR_PIN) == HIGH) {
    myServo.write(90);
    Serial.println("Object detected! Rotating to 90 degrees.");
  } else {
    myServo.write(0);
    Serial.println("No object detected. Returning to 0 degrees.");
  }
  delay(100);
}
