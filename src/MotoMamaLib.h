/** @file    MotoMamaLib.cpp
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    18.Abr.2018  
 *  @version 1.0 
 *  
 *  @brief   Libray for convenient use of Motomama
 *           https://www.itead.cc/wiki/MotoMama
 *
 *  @licence  MIT License
 */
#include <Arduino.h>

#ifndef __MOTOMAMALIB_H__
#define __MOTOMAMALIB_H__

class MotoMamaLib {

  // ---- CONSTANTS
  #define RIGHTSPEED 11
  #define RIGHTDIR1 12
  #define RIGHTDIR2 13
  #define LEFTSPEED 10
  #define LEFTDIR1 8
  #define LEFTDIR2 9

  public:
  // ---- CONSTRUCTORS
  MotoMamaLib();          // Constructor w/default values

  // ---- PUBLIC METHODS
  void begin();
  void forward();
  void forward(int ms);
  void backward();
  void backward(int ms);
  void left();
  void left(int ms);
  void right();
  void right(int ms);
  void stop();
  void setMotors(bool leftVal, bool rightVal);
  void setSpeed(int leftVal, int rightVal);

  private:
    // ---- PRIVATE VARIABLES
    int
      leftSpeed  = 0,     // Value between 0 and 255
      rightSpeed = 0;     // Value between 0 and 255
      
};  // class MotoMamaLib

#endif
