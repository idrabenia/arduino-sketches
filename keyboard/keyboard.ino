
#define DELAY 300
#define LOOP_CNT 1000
#define ACTIVE_LEVEL LOW

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);

  digitalWrite(7, !ACTIVE_LEVEL);
  digitalWrite(8, !ACTIVE_LEVEL);
  digitalWrite(9, !ACTIVE_LEVEL);
  digitalWrite(10, !ACTIVE_LEVEL);

  Serial.begin(9600);
}

volatile long lastPressed = 0;

void loop() {
  digitalWrite(5, !ACTIVE_LEVEL);
  digitalWrite(2, ACTIVE_LEVEL);

  for (int i = 0; i < LOOP_CNT; i += 1) {
    if (digitalRead(7) == ACTIVE_LEVEL && millis() - lastPressed > DELAY) {
      Serial.println("1");
      lastPressed = millis();
    }

    if (digitalRead(8) == ACTIVE_LEVEL && millis() - lastPressed > DELAY) {
      Serial.println("2");
      lastPressed = millis();
    }

    if (digitalRead(9) == ACTIVE_LEVEL && millis() - lastPressed > DELAY) {
      Serial.println("3");
      lastPressed = millis();
    }

    if (digitalRead(10) == ACTIVE_LEVEL && millis() - lastPressed > DELAY) {
      Serial.println("A");
      lastPressed = millis();
    }
  }

  digitalWrite(2, !ACTIVE_LEVEL);
  digitalWrite(3, ACTIVE_LEVEL);

  for (int i = 0; i < LOOP_CNT; i += 1) {
    if (digitalRead(7) == ACTIVE_LEVEL && millis() - lastPressed > DELAY) {
      Serial.println("4");
      lastPressed = millis();
    }

    if (digitalRead(8) == ACTIVE_LEVEL && millis() - lastPressed > DELAY) {
      Serial.println("5");
      lastPressed = millis();
    }

    if (digitalRead(9) == ACTIVE_LEVEL && millis() - lastPressed > DELAY) {
      Serial.println("6");
      lastPressed = millis();
    }

    if (digitalRead(10) == ACTIVE_LEVEL && millis() - lastPressed > DELAY) {
      Serial.println("B");
      lastPressed = millis();
    }
  }

  digitalWrite(3, !ACTIVE_LEVEL);
  digitalWrite(4, ACTIVE_LEVEL);

  for (int i = 0; i < LOOP_CNT; i += 1) {
    if (digitalRead(7) == ACTIVE_LEVEL && millis() - lastPressed > DELAY) {
      Serial.println("7");
      lastPressed = millis();
    }

    if (digitalRead(8) == ACTIVE_LEVEL && millis() - lastPressed > DELAY) {
      Serial.println("8");
      lastPressed = millis();
    }

    if (digitalRead(9) == ACTIVE_LEVEL && millis() - lastPressed > DELAY) {
      Serial.println("9");
      lastPressed = millis();
    }

    if (digitalRead(10) == ACTIVE_LEVEL && millis() - lastPressed > DELAY) {
      Serial.println("C");
      lastPressed = millis();
    }
  }

  digitalWrite(4, !ACTIVE_LEVEL);
  digitalWrite(5, ACTIVE_LEVEL);

  for (int i = 0; i < LOOP_CNT; i += 1) {
    if (digitalRead(7) == ACTIVE_LEVEL && millis() - lastPressed > DELAY) {
      Serial.println("D");
      lastPressed = millis();
    }

    if (digitalRead(8) == ACTIVE_LEVEL && millis() - lastPressed > DELAY) {
      Serial.println("0");
      lastPressed = millis();
    }

    if (digitalRead(9) == ACTIVE_LEVEL && millis() - lastPressed > DELAY) {
      Serial.println("E");
      lastPressed = millis();
    }

    if (digitalRead(10) == ACTIVE_LEVEL && millis() - lastPressed > DELAY) {
      Serial.println("F");
      lastPressed = millis();
    }
  }
}
