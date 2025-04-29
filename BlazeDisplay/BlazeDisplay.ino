
#define DB0 2
#define DB1 3
#define DB2 4
#define DB3 5
#define DB4 6
#define DB5 7
#define DB6 8
#define DB7 9

#define E 10
#define RS 11
#define RW 12

void setup() {
  Serial.begin(115200);

  pinMode(DB0, OUTPUT);
  pinMode(DB1, OUTPUT);
  pinMode(DB2, OUTPUT);
  pinMode(DB3, OUTPUT);

  pinMode(DB4, OUTPUT);
  pinMode(DB5, OUTPUT);
  pinMode(DB6, OUTPUT);
  pinMode(DB7, OUTPUT);

  pinMode(E, OUTPUT);
  pinMode(RS, OUTPUT);
  pinMode(RW, OUTPUT);

  delayMicroseconds(50000); 
  write(0, 0x34); 

  delayMicroseconds(4500); 
  write(0, 0x0C); 

  delayMicroseconds(4500); 
  write(0, 0x06); 

  delayMicroseconds(4500); 
  write(0, 0x01); 

  delayMicroseconds(4500); 
  write(0, 0x80); 
}

void loop() {
  delayMicroseconds(4500); 
  write(0, 0x80); 

  delayMicroseconds(4500); 
  writeStr("\xA8p\xB8\xB3\x65\xBF, World!!!");
}

void write(uint8_t isData, uint8_t data) {
  digitalWrite(RS, isData);
  digitalWrite(RW, LOW);

  delayMicroseconds(10);

  digitalWrite(DB0, data & 1);
  digitalWrite(DB1, (data >> 1) & 1);
  digitalWrite(DB2, (data >> 2) & 1);
  digitalWrite(DB3, (data >> 3) & 1);
  digitalWrite(DB4, (data >> 4) & 1);
  digitalWrite(DB5, (data >> 5) & 1);
  digitalWrite(DB6, (data >> 6) & 1);
  digitalWrite(DB7, (data >> 7) & 1);

  digitalWrite(E, LOW);
  delayMicroseconds(10);

  digitalWrite(E, HIGH);
  delayMicroseconds(10);

  digitalWrite(E, LOW);
  delayMicroseconds(10);
}

void writeStr(char* str) {
  for (int i = 0; i < strlen(str); i++) {
    write(1, (char) str[i]);
  }
}
