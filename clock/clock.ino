
const byte DIGITS[] = { 0x03, 0x02, 0x01, 0x00 };

#define NUM_E 0b00000000
#define NUM_0 0b11111100
#define NUM_1 0b01100000
#define NUM_2 0b11011010
#define NUM_3 0b11110010
#define NUM_4 0b01100110
#define NUM_5 0b10110110
#define NUM_6 0b10111110
#define NUM_7 0b11100000
#define NUM_8 0b11111110
#define NUM_9 0b11110110

#define CLOCK 0
#define EDIT_HOURS_LG 1
#define EDIT_HOURS_SM 2
#define EDIT_MINUTES_LG 3
#define EDIT_MINUTES_SM 4

const byte NUMS[] = { 
  NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, 
  NUM_5, NUM_6, NUM_7, NUM_8, NUM_9,
  NUM_E
};

const byte SEGMENT_PINS[] = { 4, 5, 6, 7, 10, 11, 19 };

void setupDisplay() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
}

volatile long previousPressTime = 0;
volatile long previousRotateTime = 0;
volatile int hours = 0;
volatile int minutes = 0;
volatile int seconds = 0;
volatile int8_t state = CLOCK;
volatile long prevMillis = millis();
volatile long dotMillis = millis();
volatile long blinkMillis = millis();
volatile int firstEncoderPinState = 0;
volatile bool dots[4] = { 0, 1, 0, 0 };

void showDigit(int digitNum, int digitVal, bool showDot) {
  int curDigitNumCode = DIGITS[digitNum - 1];

  digitalWrite(2, curDigitNumCode & 0x01);
  digitalWrite(3, (curDigitNumCode >> 1) & 0x01);
  digitalWrite(18, !showDot);

  int curDigitCode = ~(NUMS[digitVal]);

  for (int i = 0; i < 7; i += 1) {
    digitalWrite(SEGMENT_PINS[i], (curDigitCode >> (7 - i)) & 0x01);
  }
}

void printBufferToDisplay(char buffer[5], bool showDot[4]) {
  for (int i = 0; i < 4; i += 1) {
    delay(1);
    showDigit(i + 1, buffer[i] - 0x30, showDot[i]);
  }
}

void printBufferToDisplayBlink(char buffer[5], int blinkDigit, bool showDot[4]) {
  for (int i = 0; i < 4; i += 1) {
    delay(1);

    if (blinkDigit == i + 1 && millis() - blinkMillis < 300) {
      showDigit(i + 1, 10, showDot[i]);
    } else {
      showDigit(i + 1, buffer[i] - 0x30, showDot[i]);
    }

    if (blinkDigit == i + 1 && millis() - blinkMillis > 600) {
      blinkMillis = millis();
    }
  }
}

void setup() {
  Serial.begin(115200);

  PCICR = 0x03;
  PCMSK0 = 0x10;
  PCMSK1 = 0x02;

  DDRB = 0x00;
  PORTB = 0x10;

  DDRC = 0x00;
  PORTC = 0x06;

  firstEncoderPinState = PINC & 0x02;

  setupDisplay();
}

ISR(PCINT0_vect) {
  if ((PINC & 0x01) == 0) {
    if (millis() - previousPressTime > 300) {
      state = (state + 1) % 5;
    }

    previousPressTime = millis();
  }
}

ISR(PCINT1_vect) {
  int change = PINC & 0x06;
  int first = (change & 0x02) >> 1;
  int second = (change & 0x04) >> 2;

  Serial.print(first);
  Serial.print(" ");
  Serial.println(second);

  if (millis() - previousRotateTime < 30) {
    previousRotateTime = millis();
    return;
  }

  if (firstEncoderPinState == first) {
    firstEncoderPinState = first;
    return;
  }

  Serial.print(first);
  Serial.print(" <-> ");
  Serial.println(second);

  previousRotateTime = millis();
  firstEncoderPinState = first;

  if ((!first && second) || (first & !second)) {
    switch (state) {
      case EDIT_HOURS_LG:
        hours = (hours + 10) % 30;
        break;
      case EDIT_HOURS_SM:
        hours = (hours + 1) % 24;
        break;
      case EDIT_MINUTES_LG:
        minutes = (minutes + 10) % 60;
        break;
      case EDIT_MINUTES_SM:
        minutes = (minutes + 1) % 60;
        break;
    }
  } else {
    switch (state) {
      case EDIT_HOURS_LG:
        hours = (hours + 20) % 30;
        break;
      case EDIT_HOURS_SM:
        hours = (hours + 23) % 24;
        break;
      case EDIT_MINUTES_LG:
        minutes = (minutes + 50) % 60;
        break;
      case EDIT_MINUTES_SM:
        minutes = (minutes + 59) % 60;
        break;
    }
  }
}

void loop() {
  char buffer[5];
  sprintf(buffer, "%02d%02d", hours, minutes);

  if (millis() - dotMillis > 500) {
    dots[1] = !dots[1];
    dotMillis = millis();
  }

  switch (state) {
    case CLOCK: 
      printBufferToDisplay(buffer, dots);
      break;
    case EDIT_HOURS_LG:
      dots[1] = 1;
      printBufferToDisplayBlink(buffer, 1, dots);
      break;
    case EDIT_HOURS_SM:
      dots[1] = 1;
      printBufferToDisplayBlink(buffer, 2, dots);
      break;
    case EDIT_MINUTES_LG:
      dots[1] = 1;
      printBufferToDisplayBlink(buffer, 3, dots);
      break;
    case EDIT_MINUTES_SM:
      dots[1] = 1;
      printBufferToDisplayBlink(buffer, 4, dots);
      break;
  }

  if (state == CLOCK && millis() - prevMillis >= 1000) {
    prevMillis = millis();

    int secondsAbs = seconds + 1;
    int minutesInc = secondsAbs / 60;
    seconds = secondsAbs % 60;

    int minutesAbs = minutes + minutesInc;
    int hoursInc = minutesAbs / 60;
    minutes = minutesAbs % 60;

    hours = (hours + hoursInc) % 24;
  }
}
