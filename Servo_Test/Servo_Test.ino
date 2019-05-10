

#include <Servo.h> 
#include "math.h"
 
Servo myservo;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;

          
 
int pos = 0;    

void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(5);  // left 
  myservo2.attach(6);
  myservo3.attach(7);
  myservo4.attach(2);  // right 
  myservo5.attach(3);
  myservo6.attach(4);
  
  myservo.write(0);
  myservo2.write(165); 
  myservo3.write(0);

  myservo4.write(180);
  myservo5.write(0); 
  myservo6.write(0);
  delay(30);
} 
 
void loop() 
{
  for(pos = 0; pos <= 180; pos += 3) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    Serial.println(pos);
    //myservo2.write(pos);
    delay(100);                       // waits 15ms for the servo to reach the position 
     
  }
  delay(3000);
  pos = 0; 
  myservo.write(0);
  //myservo2.write(0);  
  delay(3000);
  
  
  
  
  for(pos = 180; pos >= 30; pos -= 3) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
    Serial.println(pos);
    //myservo2.write(pos);
    delay(100);                       // waits 15ms for the servo to reach the position 
     
  }
  delay(3000);
  pos = 165; 
  myservo2.write(180);  
  delay(3000);
  
  
  
  
  for(pos = 0; pos <= 180; pos += 3) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo3.write(pos);              // tell servo to go to position in variable 'pos' 
    Serial.println(pos);
    //myservo2.write(pos);
    delay(100);                       // waits 15ms for the servo to reach the position 
     
  }
  delay(3000);
  pos = 0; 
  myservo3.write(0);
  delay(3000);
  
  
  
  
  
  for(pos = 180; pos >= 0; pos -= 3) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo4.write(pos);              // tell servo to go to position in variable 'pos' 
    Serial.println(pos);
    //myservo2.write(pos);
    delay(100);                       // waits 15ms for the servo to reach the position 
     
  }
  delay(3000);
  pos = 180; 
  myservo4.write(180);
  //myservo2.write(0);  
  delay(3000);
  
  
  
  
  for(pos = 0; pos <= 135; pos += 3) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo5.write(pos);              // tell servo to go to position in variable 'pos' 
    Serial.println(pos);
    //myservo2.write(pos);
    delay(100);                       // waits 15ms for the servo to reach the position 
     
  }
  delay(3000);
  pos = 0; 
  myservo5.write(0);  
  delay(3000);
  
  
  
  
  for(pos = 0; pos <= 180; pos += 3) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo6.write(pos);              // tell servo to go to position in variable 'pos' 
    Serial.println(pos);
    //myservo2.write(pos);
    delay(100);                       // waits 15ms for the servo to reach the position 
     
  }
  delay(3000);
  pos = 0; 
  myservo6.write(0);
  delay(3000);
  
  
  
  
  
} 






















