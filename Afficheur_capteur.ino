#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED 128x32
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// IRS09A
#define IRS_ADDR 0x29      // adresse I2C du capteur
#define REG_DATA 0x00      // registre à lire (valeur brute)

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);

  // Initialisation OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Erreur OLED");
    while(true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Initialisation...");
  display.display();
  delay(1000);
}

void loop() {
  byte val = readIRS();

  // Conversion approximative de la valeur brute en cm
  float distance = val * 150.0 / 255.0;
  if (distance < 4) distance = 4; // seuil minimal

  // Affichage dans le terminal
  Serial.print("Distance : ");
  Serial.print(distance, 1); // 1 chiffre après la virgule
  Serial.println(" cm");

  // Affichage sur OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Distance capteur:");
  display.setTextSize(2);
  display.setCursor(0, 15);
  display.print(distance, 1); // 1 chiffre après la virgule
  display.println(" cm");
  display.display();

  delay(200); // 5 lectures par seconde
}

// Fonction pour lire la valeur brute du capteur IRS09A
byte readIRS() {
  Wire.beginTransmission(IRS_ADDR);
  Wire.write(REG_DATA);
  if (Wire.endTransmission(false) != 0) return 0;

  Wire.requestFrom(IRS_ADDR, 1);
  if (Wire.available()) return Wire.read();
  else return 0;
}
