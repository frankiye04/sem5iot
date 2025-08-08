const int led1 = 3;
const int led2 = 4;
const int led3 = 5;
const int button1 = 6;
const int button2 = 7;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(button1) == LOW) {
    pattern1();
  } else if (digitalRead(button2) == LOW) {
    pattern2();
  } else {
    allOff();
  }
}

void pattern1() {
  digitalWrite(led1, HIGH);
  delay(500);
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led3, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  delay(500);
  digitalWrite(led2, LOW);
  delay(500);
  digitalWrite(led3, LOW);
  delay(500);
}

void pattern2() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  delay(300);
}

void allOff() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}