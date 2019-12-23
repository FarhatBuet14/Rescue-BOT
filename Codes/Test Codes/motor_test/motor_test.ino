#include "Motor_Driver.h"
#include "math.h"
MotorDriver motor;
void setup() {
  Serial.begin(9600);
}
void loop() {
      motor.right();
      Serial.println(" Right");
//      delay(3000);
//      motor.forward();
//      Serial.println(" forward");
//      delay(300);
//      motor.left();
//      Serial.println(" left");
//      delay(1000);
//      motor.forward();
//      Serial.println(" forward");
      //delay(3);
}
