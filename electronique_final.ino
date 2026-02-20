int leds[3] = {2,3};
#define BUZZER_PIN 8
void setup() {
  for (int i = 0; i < 2; i++) {
    pinMode(leds[i], OUTPUT);
  }
   pinMode(BUZZER_PIN, OUTPUT);
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

  digitalWrite(BUZZER_PIN, HIGH); // Buzzer ON
  delay(500);

  digitalWrite(BUZZER_PIN, LOW);  // Buzzer OFF
  delay(500);
}
