void setup() {
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
}

void loop() {
  if (Serial.available() > 0) {
    Serial.read();
    int val = 0b10100110;
    shiftOut(2, 4, MSBFIRST, val);
  }

  Serial.print(F("Val: "));
  Serial.print(digitalRead(8));
  Serial.print(digitalRead(7));
  Serial.print(digitalRead(6));
  Serial.println(digitalRead(5));
  delay(1000);

  digitalWrite(4, HIGH);
  delay(10);
  digitalWrite(4, LOW);
  Serial.print(F("Val: "));
  Serial.print(digitalRead(8));
  Serial.print(digitalRead(7));
  Serial.print(digitalRead(6));
  Serial.println(digitalRead(5));
  delay(1000);
}
