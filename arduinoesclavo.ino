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
