
int value = 0xAAAA;

void setup() {
  Serial.begin(9600);

  pinMode(3, OUTPUT);

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  digitalWrite(5, value & (1 << 0));
  digitalWrite(6, value & (1 << 1));
  digitalWrite(7, value & (1 << 2));
  digitalWrite(8, value & (1 << 3));

  digitalWrite(9, value & (1 << 4));
  digitalWrite(10, value & (1 << 5));
  digitalWrite(11, value & (1 << 6));
  digitalWrite(12, value & (1 << 7));

  digitalWrite(3, HIGH);
  delay(1);
  digitalWrite(3, LOW);

  delay(1000);
}
