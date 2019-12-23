#include "Arduino.h" 
#include "Motor_Driver.h"
#include "math.h"

//Must need for a library to create a function like that with the same name
//It will have no output
MotorDriver::MotorDriver()
{
    pinMode(ina, OUTPUT) ;
    pinMode(inb, OUTPUT) ;
    pinMode(inc, OUTPUT) ;
    pinMode(ind, OUTPUT) ;
    pinMode(ena, OUTPUT) ;
    pinMode(enb, OUTPUT) ;
}

void MotorDriver::forward()
{
  analogWrite(ena, pwm);
  analogWrite(enb, pwm);
  
  digitalWrite(ina , HIGH ) ;
  digitalWrite(inb , LOW ) ;
  digitalWrite(inc , HIGH) ;
  digitalWrite(ind , LOW ) ;
}

void MotorDriver::backward()
{
  analogWrite(ena, pwm);
  analogWrite(enb, pwm);
  
  digitalWrite(ina , LOW ) ;
  digitalWrite(inb , HIGH ) ;
  digitalWrite(inc , LOW ) ;
  digitalWrite(ind , HIGH ) ;
}

void MotorDriver::rotate()
{
  analogWrite(ena, pwm);
  analogWrite(enb, pwm);
  
  digitalWrite(ina , HIGH ) ;
  digitalWrite(inb , LOW ) ;
  digitalWrite(inc , LOW ) ;
  digitalWrite(ind , HIGH ) ;
}

void MotorDriver::cease()
{
  analogWrite(ena, 0);
  analogWrite(enb, 0);
  
  digitalWrite(ina , LOW ) ;
  digitalWrite(inb , LOW ) ;
  digitalWrite(inc , LOW ) ;
  digitalWrite(ind , LOW ) ;
}

void MotorDriver::left()
{
  analogWrite(ena, pwm);
  analogWrite(enb, pwm);
  
  digitalWrite(ina , HIGH) ;
  digitalWrite(inb , LOW ) ;
  digitalWrite(inc , LOW ) ;
  digitalWrite(ind , HIGH ) ;
}

void MotorDriver::right()
{
  analogWrite(ena, pwm);
  analogWrite(enb, pwm);
  
  digitalWrite(ina , LOW ) ;
  digitalWrite(inb , HIGH ) ;
  digitalWrite(inc , HIGH ) ;
  digitalWrite(ind , LOW ) ;
}
