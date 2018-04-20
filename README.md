# Biblioteca MotoMamaLib
Biblioteca para el manejo del **L298N H-Bridge Motor Driver Shield (MotoMama)** de (itead studio)[https://www.itead.cc/wiki/MotoMama].

## Autor
Jorge Villalobos Carvajal - Abril.2018

## Uso
Se declara una variable con el tipo de la biblioteca y se inicializa por medio del método **begin** en el **setup** del sketch.

#### Ejemplo
```
#include <MotoMamaLib.h>

MotoMamaLib Robot;

void setup() {
  Robot.begin();             // Se realiza la inicialización de la placa
}  // setup

void loop() {
  robot.setSpeed(175, 175);  // Se establece una velocidad de 175 (0-255)
  robot.forward(500);        // Se avanza hacia adelante por medio segundo
  robot.left(500);           // Se gira a la izquierda por medio segundo
  robot.right(500);          // Se gira a la derecha por medio segundo
  robot.backward(500);       // Se retrocede por medio segundo
}
```
