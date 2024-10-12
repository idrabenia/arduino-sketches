
#include <stdio.h>

#define DELAY 1

const uint8_t DIGITS[] = {
  0xEE, 0x60, 0x2F, 0x6D, 0xE1,
  0xCD, 0xCF, 0x68, 0xEF, 0b11101101,
  0x00
};

volatile long counter = 0;

void setup() {
  Serial.begin(115200);

  DDRD = 0xF0;
  DDRB = 0x03;
}

void printDigit(uint8_t digit, uint8_t value, uint8_t dot) {
  uint8_t code = DIGITS[value] | (dot << 4);

  PORTD = digit << 4;
  PORTB = 0x00;
  delayMicroseconds(DELAY);
  PORTB = 0x02;
  delayMicroseconds(DELAY);
  PORTB = 0x00;
  delayMicroseconds(DELAY);

  PORTD = (code & 0x0F) << 4;
  PORTB = 0x01;
  delayMicroseconds(DELAY);
  PORTB = 0x03;
  delayMicroseconds(DELAY);
  PORTB = 0x01;
  delayMicroseconds(DELAY);

  PORTD = (code & 0xF0);
  PORTB = 0x01;
  delayMicroseconds(DELAY);
  PORTB = 0x03;
  delayMicroseconds(DELAY);
  PORTB = 0x01;
  delayMicroseconds(DELAY);

  PORTB = 0x01;
  PORTD = 0x00;
  delayMicroseconds(DELAY);
}

void loop() {
  counter += 1;
  char buffer[11];
  sprintf(buffer, "%010d", counter);
  // Serial.println(buffer);

  printDigit(9, buffer[9] - 0x30, false);
  printDigit(8, buffer[8] - 0x30, true);
  printDigit(7, buffer[7] - 0x30, false);
  printDigit(6, buffer[6] - 0x30, false);
  printDigit(5, buffer[5] - 0x30, false);
  printDigit(4, buffer[4] - 0x30, false);
  printDigit(3, buffer[3] - 0x30, false);
  printDigit(2, buffer[2] - 0x30, false);
  printDigit(1, buffer[1] - 0x30, false);
  printDigit(0, buffer[0] - 0x30, false);

  delay(100);
}
