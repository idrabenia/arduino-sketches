void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(5, INPUT);
  pinMode(6, INPUT);
}

void loop() {
  Serial.println("---------------------");
  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  delay(50);

  String message1 = "a: 0, b: 0, carry: 0, Output: ";
  Serial.println(message1 + " " + digitalRead(5) + " " + digitalRead(6));
  delay(50);

  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  delay(50);

  String message2 = "a: 1, b: 0, carry: 0, Output: ";
  Serial.println(message2 + " " + digitalRead(5) + " " + digitalRead(6));
  delay(50);

  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  delay(50);

  String message3 = "a: 0, b: 1, carry: 0, Output: ";
  Serial.println(message3 + " " + digitalRead(5) + " " + digitalRead(6));
  delay(50);

  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  delay(50);

  String message4 = "a: 1, b: 1, carry: 0, Output: ";
  Serial.println(message4 + " " + digitalRead(5) + " " + digitalRead(6));
  delay(50);

  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(50);

  String message6 = "a: 1, b: 0, carry: 1, Output: ";
  Serial.println(message6 + " " + digitalRead(5) + " " + digitalRead(6));
  delay(50);

  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  delay(50);

  String message7 = "a: 0, b: 1, carry: 1, Output: ";
  Serial.println(message7 + " " + digitalRead(5) + " " + digitalRead(6));
  delay(50);

  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  delay(50);

  String message8 = "a: 1, b: 1, carry: 1, Output: ";
  Serial.println(message8 + " " + digitalRead(5) + " " + digitalRead(6));
  delay(50);

  digitalWrite(4, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  delay(1000);

  String message5 = "a: 0, b: 0, carry: 1, Output: ";
  Serial.println(message5 + " " + digitalRead(5) + " " + digitalRead(6));
  delay(50);

  delay(1000);
}

