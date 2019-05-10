#ifndef __SONAR_SENSOR_H__ //Must Needed
#define __SONAR_SENSOR_H__
#include "Arduino.h"
class Sonar
{
  public:
  int trigPin;
  int echoPin;
  
  Sonar();
  void SetSonar(int TrigPin, int EchoPin);
  float measure();
};
#endif // Must be given
