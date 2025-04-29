// include the library code:
#include <LiquidCrystal.h>

const int rs = 11, en = 10, d4 = 6, d5 = 7, d6 = 8, d7 = 9;
const int d0 = 2, d1 = 3, d2 = 4, d3 = 5;

byte armsUp[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};


LiquidCrystal lcd(rs, en, d0, d1, d2, d3, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  lcd.createChar(0, armsUp);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("        Timer       ");

  lcd.setCursor(5, 2);
  lcd.print("Seconds: ");
}

volatile bool isEmojiShown = false;

void loop() {
  //lcd.print("hello, world!");
  lcd.setCursor(14, 2);
  lcd.print(millis() / 1000);

  if (!isEmojiShown) {
    lcd.print("");
    lcd.write(byte(0));
  } else {
    lcd.print("  ");
  }

  isEmojiShown = !isEmojiShown;

  delay(500);
}