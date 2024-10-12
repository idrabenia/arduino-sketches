
extern "C" {
  // function prototypes
  void start();
  
  void blink();
}

void setup() {
  start();
  millis();
}

void loop() {
  blink();
}