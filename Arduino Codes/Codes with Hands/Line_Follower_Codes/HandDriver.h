#ifndef __HAND_DRIVER_H__ //Must Needed
#define __HAND_DRIVER_H__
#include "Arduino.h"
#include <Servo.h>

class HandDriver
{                                                        //hand = 1 ~~~ Left
  public:                                                //hand = 2 ~~~ Right
  HandDriver();    
                                                         //part = 1 ~~~ Base
  //Enable the hands                                     //part = 2 ~~~ Middle
  void Hand_ON(int hand);                                //part = 3 ~~~ Top                 
  void Hand_Start_Position(int hand);
  
  //Full Hand Move
  void Put_Hand(int hand, int base, int middle, int top); 
  
  //Partwise Move
  void Custom_Move(int hand, int part, int ang);     
  
  //Keep Rotating
  void Rotate_parts(int hand, int part);

  
  Servo leftBase;       //Left                         //hand = 1 ~~~ Left
  Servo leftMiddle;                                    //hand = 2 ~~~ Right
  Servo leftTop; 
  Servo rightBase;      //Right
  Servo rightMiddle;   
  Servo rightTop; 
  
  //Arduino Connection Pins
  #define rightBasePin   2      //Right  //
  #define rightMiddlePin 3
  #define rightTopPin    4
  
  #define leftBasePin   5       //Left
  #define leftMiddlePin 6
  #define leftTopPin    7
 
 
  //Starting Angles
  #define rightBaseStart    180   //Front                           //Righht
  #define rightMiddleStart    0   //LOW
  #define rightTopStart       0   //Right
  
  #define leftBaseStart         0  //Front                            //Left
  #define leftMiddleStart       165 //Low
  #define leftTopStart          0  ////Right
  
  
  //Ending Angles
  #define rightBaseEnd      0    //Back                             //Righht
  #define rightMiddleEnd  135    //High
  #define rightTopEnd     180    //Left
  
  #define leftBaseEnd        180    //Back                             //Left
  #define leftMiddleEnd      30    //High 
  #define leftTopEnd         180    //Left
  
};
#endif // Must be given
