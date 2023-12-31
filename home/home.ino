#define break_switch (2)
#define accel_switch (3)
#define hazard_led (9)
#define break_led (10)

#define ON HIGH
#define OFF LOW
  
void setup() {
  Serial.begin(9600);
  Serial.println("reset");

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  
  if(digitalRead(break_switch) == ON){
    digitalWrite(break_led, HIGH);
    digitalWrite(hazard_led, HIGH);
    delay(500);
    digitalWrite(hazard_led, LOW);
    delay(500);
    digitalWrite(hazard_led, HIGH);
    delay(500);
    digitalWrite(hazard_led, LOW);
    delay(500);
    digitalWrite(hazard_led, HIGH);
    delay(500);
    digitalWrite(hazard_led, LOW);
    delay(500);
  }
  if(digitalRead(break_switch) == OFF && digitalRead(accel_switch) == ON){
    digitalWrite(break_led, LOW);
    digitalWrite(hazard_led, LOW);
  }

  digitalWrite(13, LOW);
}
