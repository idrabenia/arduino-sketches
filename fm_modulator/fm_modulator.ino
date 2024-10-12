
volatile uint16_t icr_val = 16000000 / 8 / 9000 / 2;
volatile double angle = 0.0;

void setup() {
  Serial.begin(115200);

  TCCR1A = 0;
  TCCR1A |= (1 << COM1A0);

  TCCR1B = 0;
  TCCR1B |= /*(1 << CS10)|(1 << CS11)|*/(1 << CS11); 
  TCCR1B |= (1 << WGM12) | (1 << WGM13);
  TIMSK1 |= (1 << ICIE1);
  ICR1 = icr_val;

  DDRB |= (1 << PORTB1);
}

ISR(TIMER1_CAPT_vect) {
  ICR1 = icr_val;
}

void loop() {
  double curSinVal = sin(angle);
  angle += 0.1;

  int sinAsInt = (1.0 + curSinVal) * 10000; 
  icr_val = 16000000 / 8 / (sinAsInt + 4000) / 2;

  if (angle > 2 * 3.14) {
    angle = 0.0;
  }

  delay(10);
}
