void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    int incomingByte = Serial.read();

    digitalWrite(2, HIGH);
    delay(10);
    digitalWrite(2, LOW);
  }
}
