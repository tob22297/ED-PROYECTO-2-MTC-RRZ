//MAESTRO
#include <LiquidCrystal_I2C.h>

//Codigo para LCD donde se menciona dirección y tamaño
LiquidCrystal_I2C lcd (0x27, 16, 2);

//definición de estados de LCD
typedef enum estados {e0, e1, e2} estados;
estados estadoActual = e0;
estados estadoFuturo = e0;
