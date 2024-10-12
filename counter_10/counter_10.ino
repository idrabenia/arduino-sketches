
void setup() {
  Serial.begin(9600);

  pinMode(A0, OUTPUT);
  pinMode(2, OUTPUT);

  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(A1, INPUT);

  Serial.print("Val 1: ");
  Serial.print(digitalRead(3));
  Serial.print(digitalRead(4));
  Serial.print(digitalRead(5));
  Serial.print(digitalRead(6));
  Serial.print(digitalRead(7));
  Serial.print(digitalRead(8));
  Serial.print(digitalRead(9));
  Serial.print(digitalRead(10));
  Serial.print(digitalRead(11));
  Serial.print(digitalRead(12));
  Serial.print(" Carry: ");
  Serial.println(digitalRead(A1));

  delay(10);
  digitalWrite(A0, HIGH);
  delay(10);

  digitalWrite(A0, LOW);

  Serial.print("Val 1: ");
  Serial.print(digitalRead(3));
  Serial.print(digitalRead(4));
  Serial.print(digitalRead(5));
  Serial.print(digitalRead(6));
  Serial.print(digitalRead(7));
  Serial.print(digitalRead(8));
  Serial.print(digitalRead(9));
  Serial.print(digitalRead(10));
  Serial.print(digitalRead(11));
  Serial.print(digitalRead(12));
  Serial.print(" Carry: ");
  Serial.println(digitalRead(A1));

  delay(100);
}

void loop() {
  delay(10);
  digitalWrite(2, HIGH);
  delay(10);

  digitalWrite(2, LOW);

  Serial.print("Val: ");
  Serial.print(digitalRead(3));
  Serial.print(digitalRead(4));
  Serial.print(digitalRead(5));
  Serial.print(digitalRead(6));
  Serial.print(digitalRead(7));
  Serial.print(digitalRead(8));
  Serial.print(digitalRead(9));
  Serial.print(digitalRead(10));
  Serial.print(digitalRead(11));
  Serial.print(digitalRead(12));
  Serial.print(" Carry: ");
  Serial.println(digitalRead(A1));

  delay(100);
}
