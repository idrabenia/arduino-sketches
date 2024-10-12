
volatile uint16_t freq = 9000;
volatile uint16_t icr_val = 16000000 / 8 / freq / 2;;

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
  if (Serial.available() > 0) {
    String newValue = Serial.readString();
    freq = newValue.toInt();
    icr_val = 16000000 / 8 / freq / 2;
  }

  delay(100);
}
