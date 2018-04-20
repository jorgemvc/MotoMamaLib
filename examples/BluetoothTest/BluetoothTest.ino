/** @file    BlueToothTest.h
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    18.Abr.2018  
 *  @version 1.0 
 *  
 *  @brief   Libray for easy usage of MotoMama H-Bridge.
 *           with the Bluetooth Bee v2.0
 *
 *  @licence  MIT License
 */
// ---- Libraries
#include <MotoMamaLib.h>
#include <SoftwareSerial.h>

// ---- Variables
MotoMamaLib Robot;
SoftwareSerial bt(0, 1);  // TX, RX
char   lectura;
String hilera = "";
int    i, v;

void setup() {
  Robot.begin();
  bt.begin(9600);
}  // void setup

void loop() {
  if (bt.available()) {
    while (bt.available()) {
      lectura = (char)bt.read();
      hilera += lectura;
    }
    if (hilera == "l") {
      Robot.left();
    } else if (hilera == "r") {
      Robot.right();
    } else if (hilera == "u") {
      Robot.forward();
    } else if (hilera == "d") {
      Robot.backward();
    } else if (hilera == "s") {
      Robot.stop();
    } else if (isDigit(hilera[0])) {
      i = hilera.toInt();
      if (i == 0) i = 10;
      v = map(i, 1, 10, 0, 255);
      Robot.setSpeed(v, v);
    }
    hilera = "";
  }
}  // void loop
