int level = LOW;

void setup() {
  pinMode(2, OUTPUT);
  // pinMode(4, OUTPUT);
}

void loop() {
  // digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  delay(10);

  // digitalWrite(4, level);
  // level = !level;
  // //delay(1);

  digitalWrite(2, HIGH);
  delay(10);
  //tone(2, 30);
}
