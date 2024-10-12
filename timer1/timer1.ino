
volatile long calls_count = 0;

void setup() {
  Serial.begin(115200);

  pinMode(9, OUTPUT);

  TCCR1A = 0;
  TCCR1A |= (1 << COM1A0);

  TCCR1B = 0;
  TCCR1B |= /*(1 << CS10)|(1 << CS11)|*/(1 << CS11); 
  TCCR1B |= (1 << WGM12) | (1 << WGM13);
  TIMSK1 |= (1 << ICIE1);
  ICR1 = 16000000 / 8 / 1000 / 2;

  DDRB |= (1 << PORTB1);
}

ISR(TIMER1_CAPT_vect) {
  calls_count += 1;
}

void loop() {
  // Serial.println("\n------------------");
  // Serial.print("OCR1A: ");
  // Serial.println(OCR1A, HEX);

  // Serial.print("OCR2A: ");
  // Serial.println(OCR2A, HEX);

  // Serial.print("TCNT1L: ");
  // Serial.println(TCNT1L, HEX);

  // Serial.print("TCNT1H: ");
  // Serial.println(TCNT1H, HEX);

  Serial.print("Calls Count: ");
  Serial.println(calls_count);

  // Serial.print("ICR1: ");
  // Serial.println(ICR1, HEX);

  // Serial.print("TIMSK1: ");
  // Serial.println(ICR1, HEX);

  // Serial.print("TIFR1: ");
  // Serial.println(ICR1, HEX);

  // Serial.print("TCCR1A: ");
  // Serial.println(TCCR1A, HEX);

  // Serial.print("TCCR1B: ");
  // Serial.println(TCCR1B, HEX);

  delay(1000);
}
