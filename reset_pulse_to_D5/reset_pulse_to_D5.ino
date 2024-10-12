
int outputValue = 0;
int inputValue = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(5, OUTPUT);
  // pinMode(A1, INPUT);

  digitalWrite(5, HIGH);
  delay(100);
  digitalWrite(5, LOW);

  analogWrite(5, 191);
}

// the loop function runs over and over again forever
void loop() {
  inputValue = analogRead(A1);
  outputValue = map(inputValue, 0, 1023, 0, 255);
  analogWrite(5, outputValue);
  delay(500);
  Serial.println(inputValue);
}
