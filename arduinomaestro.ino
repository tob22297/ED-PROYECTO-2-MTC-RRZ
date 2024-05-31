//MAESTRO
#include <LiquidCrystal_I2C.h>

//Codigo para LCD donde se menciona dirección y tamaño
LiquidCrystal_I2C lcd (0x27, 16, 2);

//definición de estados de LCD
typedef enum estados {e0, e1, e2} estados;
estados estadoActual = e0;
estados estadoFuturo = e0;

//pines de switch
const uint8_t boton1 = 12;
const uint8_t boton2 = 13;

// mensajes
String aviso1 = "Falta tiro libre";
String aviso2 = "Patea";

const long interval = 2000;
unsigned long previousMillis = 0;

void setup() {
  //Lcd se prende
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);

//entradas
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
}

void loop() {
  //Estados switchs
  boolean estadoboton1 = digitalRead(boton1);
  boolean estadoboton2 = digitalRead(boton2);
//transiciones de estado
  switch(estadoActual){
    case e0:
      if(estadoboton1 == HIGH)
        estadoFuturo = e1;
      else
        estadoFuturo = e0;
      break;
    case e1:
      if(estadoboton2 == HIGH)
        estadoFuturo = e2;
      else
        estadoFuturo = e1;
      break;
    case e2:
      if(estadoboton1 == LOW)
        estadoFuturo = e0;
      else
        estadoFuturo = e2;
      break;
  }
  
  //salidas en cada estado
  switch(estadoActual){
    case e0:
      lcd.setCursor(0,0);
      lcd.clear();
      break;
    case e1:
      lcd.setCursor(0,0);
      lcd.print(aviso1);
      break;
    case e2:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(aviso2);
      break;
  }

  // Arduino con potenciometros (Arduino 1)
  // Leer valores de los potenciometros
  int poten1 = analogRead(A0);
  int poten2 = analogRead(A1);

 // Mapear los valores de los potenciometros a 0-179 grados
  int ang1 = map(poten1, 0, 1023, 0, 179);
  int ang2 = map(poten2, 0, 1023, 0, 179);

// Enviar valores mapeados por el puerto serie
  Serial.print(ang1);
  Serial.print(",");
  Serial.print(ang2);
  Serial.println(); 




