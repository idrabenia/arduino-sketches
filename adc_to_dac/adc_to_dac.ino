
volatile int cap = 16000000 / 8 / 1000;

void setup() {
  Serial.begin(115200);

  TCCR1A = 0;
  TCCR1A |= (1 << COM1A0);

  TCCR1B = 0;
  TCCR1B |= /*(1 << CS10)|(1 << CS11)|*/(1 << CS11); 
  TCCR1B |= (1 << WGM12) | (1 << WGM13);
  TIMSK1 |= (1 << ICIE1);
  ICR1 = cap;

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(A1, INPUT);
}

void write_dac(int val) {
  digitalWrite(9, val & 0x01);
  digitalWrite(8, (val >> 1) & 0x01);
  digitalWrite(11, (val >> 2) & 0x01);
  digitalWrite(10, (val >> 3) & 0x01);

  digitalWrite(5, (val >> 4) & 0x01);
  digitalWrite(4, (val >> 5) & 0x01);
  digitalWrite(3, (val >> 6) & 0x01);
  digitalWrite(2, (val >> 7) & 0x01);
}

ISR(TIMER1_CAPT_vect) {
  ICR1 = cap;

  int value = analogRead(A1);
  write_dac(map(value, 0, 1023, 0, 255));

  //Serial.println(value);
}

void loop() {

}
