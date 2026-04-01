int leds[11] = {2,3,4,5,6,7,8,9,10,11};

void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // Allumage progressif
  for (int i = 0; i < 10; i++) {
    digitalWrite(leds[i], HIGH);
    delay(150);
  }

  delay(500);

  // Extinction progressive
  for (int i = 0; i < 10; i++) {
    digitalWrite(leds[i], LOW);
    delay(150);
  }

  delay(500);
}
