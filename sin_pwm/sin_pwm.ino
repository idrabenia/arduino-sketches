void setup() {
  pinMode(5, OUTPUT);
  Serial.begin(115200);
}

double counter = 0.0;

void loop() {
  double curVal = sin(counter);

  analogWrite(5, ((1 + curVal) * 127));
  //Serial.println((1 + curVal) * 127);

  counter += 0.01;

  if (counter > 2 * 3.14) {
    counter = 0.0;
  }

  //delayMicroseconds(1);
}
