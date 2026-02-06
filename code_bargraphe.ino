int leds[3] = {2,3};

void setup() {
  for (int i = 0; i < 2; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // Allumage progressif
  for (int i = 0; i < 2; i++) {
    digitalWrite(leds[i], HIGH);
    delay(150);
  }

  delay(500);

  // Extinction progressive
  for (int i = 0; i < 2; i++) {
    digitalWrite(leds[i], LOW);
    delay(150);
  }

  delay(500);
}
