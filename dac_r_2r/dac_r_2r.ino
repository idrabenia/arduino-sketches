
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(115200);

  int val = 180;

  digitalWrite(9, val & 0x01);
  digitalWrite(8, (val >> 1) & 0x01);
  digitalWrite(7, (val >> 2) & 0x01);
  digitalWrite(6, (val >> 3) & 0x01);

  digitalWrite(5, (val >> 4) & 0x01);
  digitalWrite(4, (val >> 5) & 0x01);
  digitalWrite(3, (val >> 6) & 0x01);
  digitalWrite(2, (val >> 7) & 0x01);
}

double counter = 0.0;

void loop() {
  double curVal = sin(counter);

  int val = ((1 + curVal) * 126);

  digitalWrite(9, val & 0x01);
  digitalWrite(8, (val >> 1) & 0x01);
  digitalWrite(7, (val >> 2) & 0x01);
  digitalWrite(6, (val >> 3) & 0x01);

  digitalWrite(5, (val >> 4) & 0x01);
  digitalWrite(4, (val >> 5) & 0x01);
  digitalWrite(3, (val >> 6) & 0x01);
  digitalWrite(2, (val >> 7) & 0x01);

  // Serial.print(val);
  // Serial.print(" ");
  // Serial.print((val >> 7) & 0x01);
  // Serial.print((val >> 6) & 0x01);
  // Serial.print((val >> 5) & 0x01);
  // Serial.print((val >> 4) & 0x01);

  // Serial.print((val >> 3) & 0x01);
  // Serial.print((val >> 2) & 0x01);
  // Serial.print((val >> 1) & 0x01);
  // Serial.println((val >> 0) & 0x01);

  counter += 0.1;

  if (counter > 2 * 3.14) {
    counter = 0.0;
  }

  //delayMicroseconds(1);
}
