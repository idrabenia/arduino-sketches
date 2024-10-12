
int value = 0x1432;

void setup() {
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);

  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);

  shiftOut(2, 3, LSBFIRST, value);
}

void loop() {
  Serial.print("Val: ");

  Serial.print(digitalRead(5));
  Serial.print(digitalRead(6));
  Serial.print(digitalRead(7));
  Serial.print(digitalRead(8));

  Serial.print(digitalRead(9));
  Serial.print(digitalRead(10));
  Serial.print(digitalRead(11));
  Serial.println(digitalRead(12));

  delay(1000);
}
