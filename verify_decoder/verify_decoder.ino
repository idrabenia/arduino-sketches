void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
}

void loop() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);

  String message1 = "Code: 00, Output: ";
  Serial.println(message1 + !digitalRead(4) + " " + !digitalRead(5) + " " + !digitalRead(6) + " " + !digitalRead(7));

  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);

  String message2 = "Code: 01, Output: ";
  Serial.println(message2 + !digitalRead(4) + " " + !digitalRead(5) + " " + !digitalRead(6) + " " + !digitalRead(7));

  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);

  String message3 = "Code: 10, Output: ";
  Serial.println(message3 + !digitalRead(4) + " " + !digitalRead(5) + " " + !digitalRead(6) + " " + !digitalRead(7));

  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);

  String message4 = "Code: 11, Output: ";
  Serial.println(message4 + !digitalRead(4) + " " + !digitalRead(5) + " " + !digitalRead(6) + " " + !digitalRead(7));

  delay(1000);
}

