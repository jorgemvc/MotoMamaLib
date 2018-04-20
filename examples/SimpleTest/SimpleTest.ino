/** @file    SimpleTest.h
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    19.Abr.2018  
 *  @version 1.0 
 *  
 *  @brief   Libray for easy usage of MotoMama H-Bridge.
 *
 *  @licence  MIT License
 */
// ---- Libraries
#include <MotoMamaLib.h>

// ---- Variables
MotoMamaLib Robot;

void setup() {
  Robot.begin();
  Robot.setSpeed(175,175);
}  // void setup

void loop() {
  Robot.forward(500);
  Robot.left(500);
  Robot.backward(500);
  Robot.right(500); 
  Robot.stop();
  
  delay(1000);
}  // void loop
