#define LS 2   // Left IR sensor
#define RS 3   // Right IR sensor
#define LM1 4  // Left motor IN1
#define LM2 5  // Left motor IN2
#define RM1 6  // Right motor IN3
#define RM2 7  // Right motor IN4

void setup() {
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}

void loop() {
  int left = digitalRead(LS);
  int right = digitalRead(RS);

  if (left == LOW && right == LOW) {
    forward();
  } 
  else if (left == HIGH && right == LOW) {
    turnRight();
  } 
  else if (left == LOW && right == HIGH) {
    turnLeft();
  } 
  else {
    stopMotors();
  }
}

void forward() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

void turnRight() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}

void turnLeft() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

void stopMotors() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}
