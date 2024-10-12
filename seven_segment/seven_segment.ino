
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

const byte NUMS[] = { 
  NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, 
  NUM_5, NUM_6, NUM_7, NUM_8, NUM_9,
  NUM_E
};

const byte SEGMENT_PINS[] = { 4, 5, 6, 7, 10, 11, 12 };

void setupDisplay() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void showDigit(int digitNum, int digitVal) {
  int curDigitNumCode = DIGITS[digitNum - 1];

  digitalWrite(2, curDigitNumCode & 0x01);
  digitalWrite(3, (curDigitNumCode >> 1) & 0x01);

  int curDigitCode = ~NUMS[digitVal];

  for (int i = 0; i < 7; i += 1) {
    digitalWrite(SEGMENT_PINS[i], (curDigitCode >> (7 - i)) & 0x01);
  }
} 

void printBufferToDisplay(char buffer[5]) {
  delay(5);
  showDigit(1, buffer[0] - 0x30);

  delay(5);
  showDigit(2, buffer[1] - 0x30);

  delay(5);
  showDigit(3, buffer[2] - 0x30);

  delay(5);
  showDigit(4, buffer[3] - 0x30);
}

void setup() {
  Serial.begin(115200);

  setupSevenSegment();
}

int counter = 0;
long prevMillis = 0;

void loop() {
  char buffer[5];
  sprintf(buffer, "%04d", counter);

  printBufferToDisplay(buffer);

  if (millis() - prevMillis > 100) {
    counter = (counter + 1) % 10000;
    prevMillis = millis();
  }
}
