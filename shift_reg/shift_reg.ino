void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  tone(4, 1000);
}

void loop() {
  // if (Serial.available() > 0) {
  //   // read the incoming byte:
  //   int incomingByte = Serial.read();

  //   digitalWrite(2, HIGH);
  //   delay(100);
  //   digitalWrite(2, LOW);
  // }

    digitalWrite(2, HIGH);
    delay(5);
    digitalWrite(2, LOW);
    delay(5);
}
