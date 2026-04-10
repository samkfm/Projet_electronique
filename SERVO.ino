#include <Servo.h>

Servo gauche;
Servo droite;

void setup() {
  // CORRECTION : On utilise D9 et D6 pour respecter les contraintes (pattes 10/11 interdites)
  gauche.attach(9); 
  droite.attach(6); 
  
  // Arrêt complet au démarrage
  gauche.write(90);
  droite.write(90);
  delay(2000); // Pause de 2 sec pour poser la voiture au sol
}

void loop() {
  // AVANCER 
  // On suppose que 180 fait avancer la gauche et 0 fait avancer la droite
  gauche.write(180);
  droite.write(0); 
  delay(1000);

  // TOURNER À GAUCHE (Les deux roues vers l'arrière ou une à l'arrêt)
  gauche.write(90); // Arrêt roue gauche
  droite.write(0);  // Marche avant roue droite
  delay(1000);

  // RECULER
  gauche.write(0);
  droite.write(180);
  delay(1000);
  
  // ARRÊT
  gauche.write(90);
  droite.write(90);
  while(1); // Arrête le programme ici pour ne pas boucler à l'infini pendant les tests
}
