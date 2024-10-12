
void setup() {
  Serial.begin(115200);
}

void loop() {
  int result = (ACSR >> ACO) & 0x01;

  Serial.println(result);

  delay(100);
}
