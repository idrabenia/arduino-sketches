
void setup() {
  Serial.begin(9600);

  PCICR = 0x02;
  PCMSK1 = 0x03;

  DDRC = 0x00;
  PORTC = 0x07;
}

volatile long previousCallTime = 0;

ISR(PCINT1_vect) {
  if (PINC & 0x01 == 0) {
    if (millis() - previousCallTime > 100) {
      Serial.println("CLICK");
    }

    previousCallTime = millis();
  } else {
    int first = (PINC & 0x04) >> 2;
    int second = (PINC & 0x02) >> 1;

    Serial.println(first);
    Serial.println(second);
    if ((!first && second) || (first & !second)) {
      Serial.println("LEFT");
    } else {
      Serial.println("RIGHT");
    }
  }
}

void loop() {

}
