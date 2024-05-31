#include <Servo.h>

//declarando variables de servos
Servo servomotor1;
Servo servomotor2;

void setup() {
  Serial.begin(9600);

  //pines de servos
  servomotor1.attach(9);
  servomotor2.attach(10);
}
void loop() {
  if (Serial.available() > 0) {
    // Leer datos del puerto serie
    int ang1Recibido = Serial.parseInt(); // Lee el primer número
    int ang2Recibido = Serial.parseInt(); // Lee el segundo número

    // Controlar los servomotores
    servomotor1.write(ang1Recibido);
    servomotor2.write(ang2Recibido);
  }
  delay(100);
}