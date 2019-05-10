#include <Servo.h>
#include "Motor_Driver.h"
#include "Sonar_Sensor.h"
//#include "HandDriver.h"
#include "math.h"
#include <Servo.h>

int FrontPin = 8;
int LeftPin = 9;
int RightPin = 10;

float distanceFront=0;
float distanceLeft=0;
float distanceRight=0;
float diff=0;
char blueData = '0';

MotorDriver motor;
Sonar Front;
Sonar Left;
Sonar Right;
Servo myservo;
//HandDriver hand;


void setup() {
  Serial.begin(9600);

  myservo.attach(A5);
  myservo.write(0);
  
  pinMode(FrontPin, OUTPUT);
  pinMode(LeftPin, OUTPUT);
  pinMode(RightPin, OUTPUT);
  digitalWrite(FrontPin, LOW);
  digitalWrite(LeftPin, LOW);
  digitalWrite(RightPin, LOW);
  
  Front.SetSonar(2, 3);        //Sonar Sensor
  Left.SetSonar(4, 5);
  Right.SetSonar(6, 7);
}

void loop() {
     read_send();

     ////////////////////////  Sonar Sensor  /////////////////////

     distanceFront = Front.measure();
     distanceLeft = Left.measure();
     distanceRight = Right.measure(); 

//     Serial.print("Front: ");
     Serial.print(distanceFront);
     Serial.print("               ");
     Serial.print(distanceLeft);
     Serial.print("               ");
     Serial.print(distanceRight);
     
   
     ////////////////////////  MOTOR Command  /////////////////////

     diff = distanceLeft-distanceRight;

     if(blueData == '0')
     {
      motor.cease();
      delay(10000);
      
     }
     else if(blueData == '1')
     {
      myservo.write(0);
     }

     else if(blueData == '2')
     {
      myservo.write(50);
     }
     
     else if(blueData == '3')
     {
      myservo.write(100);
     }
     else
     {
      
     }


     
     if(distanceFront >1000)
     {
       Serial.println("         Forward");
       motor.forward();
       delay(30);
       motor.cease();
     }
     
     else if(distanceFront <30 || distanceLeft < 20 ||  distanceRight < 20)
     {
       if(diff > 10 || distanceRight < 20)
       {
         Serial.println("           Left");
         motor.left();
         delay(30);
         motor.cease();
       }
       else if(diff < -10 || distanceLeft < 20)
       {      
         Serial.println("           Right");
         motor.right();
         delay(30);
         motor.cease();
       }
//       else if(diff <20 && diff >-20)
//       {
//         Serial.println("         Forward");
//         motor.forward();
//         delay(100);
//         motor.cease();
//       }
       else
       {
//         Serial.println("         Forward");
//         motor.forward();
//         delay(100);
//         motor.cease();
       }
     }
     else
     {
       Serial.println("         Forward");
       motor.forward();
       delay(30);
       motor.cease();
     }
     blueData = '0'; 

}



//////////////_________Main Code_________/////////////////
//------------------------------------------------------//
//------------------------------------------------------//  
//////////////_________Functions_________/////////////////


////////////////////  Bluetooth Read Function  /////////////////////

void read_send()
{
  if (Serial.available() > 0)
    {
      delay(10);
      blueData = Serial.read();
      Serial.print(blueData);
    }





  /////////////   Bluetooth Module Read   ///////////////
//    String data="";
//    while(Serial.available() > 0)
//    {
//      delay(10);
//      char c = Serial.read();
//      if (c=='#'){break;}
//      data += c;
//      
//    }
//    if(data.length()>0)
//    {
//      blueData = data;
//    }
}
