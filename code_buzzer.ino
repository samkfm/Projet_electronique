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


//melody bonus qui sert pas
#define BUZZER_PIN 8

int melody1[] = {392, 349, 392, 330};
int melody2[]={494, 440, 494, 392};
int duration = 250;

void setup() {
}

void loop() {
  for (int i=0; i<8; i++){
    for (int j = 0; j<4; j++){
      tone(BUZZER_PIN, melody1[j]);
      delay(duration);
    }
    for (int k = 0; k<4; k++){
      tone(BUZZER_PIN, melody2[k]);
      delay(duration);
    }
  }
  noTone(BUZZER_PIN);
  delay(1000);
}
