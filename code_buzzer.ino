#define BUZZER_PIN 8

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  digitalWrite(BUZZER_PIN, HIGH); // Buzzer ON
  delay(500);

  digitalWrite(BUZZER_PIN, LOW);  // Buzzer OFF
  delay(500);
}
