/** @file    MotoMamaLib.cpp
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    18.Abr.2018  
 *  @version 1.0 
 *  
 *  @brief   Libray for convenient use of MotoMama
 *           https://www.itead.cc/wiki/MotoMama
 *
 *  @licence  MIT License
 */
/** 
 *   @brief  Constructor
 */
#include "MotoMamaLib.h"

MotoMamaLib::MotoMamaLib(){
}  // constructor

/** 
 *   @brief  Initialize the class
 *  
 *   @return void
 */ 
void MotoMamaLib::begin(){
  // ---- Initialize the digital ports
  pinMode(RIGHTDIR1 , OUTPUT);
  pinMode(RIGHTDIR2 , OUTPUT);
  pinMode(RIGHTSPEED, OUTPUT);
  pinMode(LEFTDIR1  , OUTPUT);
  pinMode(LEFTDIR2  , OUTPUT);
  pinMode(LEFTSPEED , OUTPUT);
  
  //  ---- Stops both motors
  stop();
}  // void begin

/** 
 *   @brief  Move forward both motors.   
 *  
 *   @return void
 */ 
void MotoMamaLib::forward() {
  setMotors(LOW, LOW);
  setSpeed(leftSpeed, rightSpeed);
}  // void forward

/** 
 *   @brief  Move forward just for ms period
 *  
 *   @param  ms is the time in milliseconds to move forward  
 *   @return void
 */ 
void MotoMamaLib::forward(
  int ms
){
  forward();
  delay(ms);
  stop();
}  // void forward

/** 
 *   @brief  Move backward both motors.   
 *  
 *   @return void
 */ 
void MotoMamaLib::backward() {
  setMotors(HIGH, HIGH);
  setSpeed(leftSpeed, rightSpeed);
}  // void backward

/** 
 *   @brief  Move backward just for ms period
 *  
 *   @param  ms is the time in milliseconds to move backward
 *   @return void
 */ 
void MotoMamaLib::backward(
  int ms
){
  backward();
  delay(ms);
  stop();
}  // void backward

/** 
 *   @brief  Move left.
 *  
 *   @return void
 */ 
void MotoMamaLib::left(){
  setMotors(LOW, HIGH);
  setSpeed(leftSpeed, rightSpeed);
}  // void left

/**
 *   @brief  Move left just for ms period (milliseconds)
 *  
 *   @param  ms is the time in milliseconds to move to the left
 *   @return void
 */ 
void MotoMamaLib::left (
  int ms
){
 left();
 delay(ms);
 stop();
}  // void left

void MotoMamaLib::right () {
  setMotors(HIGH, LOW);
  setSpeed(leftSpeed, rightSpeed);
}  // void right

/**
 *   @brief  Move right just for ms period (milliseconds)
 *  
 *   @param  ms is the time in milliseconds to move to the right
 *   @return void
 */ 
void MotoMamaLib::right(
  int ms
){
  right();
  delay(ms);
  stop();
}  // void right

/**
 *   @brief  Sets turn direction for both motors
 *  
 *   @return void
 */ 
void MotoMamaLib::setMotors(
  bool leftVal,
  bool rightVal
) {
    digitalWrite(LEFTDIR1, !leftVal);
    digitalWrite(LEFTDIR2,  leftVal);
    digitalWrite(RIGHTDIR1, !rightVal);  
    digitalWrite(RIGHTDIR2,  rightVal);
}  // void setMotors

/**
 *   @brief  Sets speed for both motors
 *  
 *   @return void
 */ 
void MotoMamaLib::setSpeed(
  int leftVal,
  int rightVal
) {
  // ---- Constrains speed values between 0 and 255
  leftSpeed  = constrain(leftVal , 0, 255);
  rightSpeed = constrain(rightVal, 0, 255);

  analogWrite(LEFTSPEED, leftSpeed);
  analogWrite(RIGHTSPEED, rightSpeed);
}  // void setSpeed

/**
 *   @brief  Stops boths motors
 *  
 *   @return void
 */ 
void MotoMamaLib::stop(){
  analogWrite(LEFTSPEED , 0);
  analogWrite(RIGHTSPEED, 0);
}  // void stop
