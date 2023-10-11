#include <avr/wdt.h>

uint32_t count_push = 0;

void setup() {
  Serial.begin(115200);

  pinMode(2, INPUT);
  wdt_enable(WDTO_15MS);
}

void loop() {
  wdt_reset();

  if (digitalRead(2) == HIGH) {
    count_push++;
  } else {
    if (count_push != 0) {
      Serial.println("count_push: " + String(count_push));
    }
    count_push = 0;
  }
}
