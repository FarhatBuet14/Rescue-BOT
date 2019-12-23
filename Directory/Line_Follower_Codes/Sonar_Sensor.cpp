#include "Arduino.h" 
#include "Sonar_Sensor.h"
#include "math.h"


Sonar::Sonar()
{
  
}


void Sonar::SetSonar(int TrigPin, int EchoPin)
{
  trigPin = TrigPin;
  echoPin = EchoPin;
  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
}

float Sonar::measure()
{
  float duration, distance; 
  digitalWrite(trigPin, LOW); //just to make sure that the pin in low first
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); //sends out an 8 cycle sonic burst from the transmitter
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
    
  duration = pulseIn(echoPin, HIGH); //It returns the time in microseconds
  distance = (duration*.0343)/2; //velocity= 0.0343 c/μS,, It will return the distance in cm 
  return distance;
}
