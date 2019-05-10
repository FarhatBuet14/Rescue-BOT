#ifndef __MOTOR_DRIVER_H__ //Must Needed
#define __MOTOR_DRIVER_H__
#include "Arduino.h"
class MotorDriver
{
  public:
  MotorDriver();
  void forward();
  void backward();
  void rotate();
  void cease();
  void left();
  void right();
  #define ina 8  // IC pin 2     ina 2
  #define inb 9  // IC pin 7     inb 3
  #define inc 10   // IC pin 15   inc 4
  #define ind 11   // IC pin 10   ind 5
  #define ena 7
  #define enb A0
  #define pwm 255
};
#endif // Must be given
