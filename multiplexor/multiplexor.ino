void setup() {
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  digitalWrite(7, LOW);
  digitalWrite(8, LOW);

  tone(2, 600);
}

int channel = 0;
long time = 0;

void loop() {

  if (millis() - time >= 10) {
    channel = !channel;
    digitalWrite(8, channel);
    time = millis();
    Serial.print(channel);
    Serial.print(" ");
    Serial.println(time);
  }

  digitalWrite(3, HIGH);
  delay(1);
  digitalWrite(3, LOW);
  delay(1);
}
