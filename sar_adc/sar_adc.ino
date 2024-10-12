
void setup() {
  Serial.begin(115200);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
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

int read_cmp() {
  return (ACSR >> ACO) & 0x01;
}

void loop() {
  int result = 0;

  for (int i = 7; i >= 0; i -= 1) {
    result |= (1 << i);
    write_dac(result);
    delay(1);

    int cmp = read_cmp();

    if (!cmp) {
      result &= ~(1 << i);
    }
  }

  Serial.println(result, BIN);
  delay(100);
}
