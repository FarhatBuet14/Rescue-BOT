#include "HandDriver.h" 
#include "Motor_Driver.h"
#include "math.h"
#include <Servo.h>

//Must need for a library to create a function like that with the same name
//It will have no output


HandDriver::HandDriver()   
{
                                                        //hand = 1 ~~~ Left
                                                        //hand = 2 ~~~ Right

}


//////////////////////////////////////////////////////////////////////////////////////

                                                       //part = 1 ~~~ Base
//Enable the hands                                     //part = 2 ~~~ Middle 
void HandDriver::Hand_ON(int hand)                     //part = 3 ~~~ Top
{
  if(hand == 1)
  {
    leftBase.attach(leftBasePin);     
    leftMiddle.attach(leftMiddlePin); 
    leftTop.attach(leftTopPin); 
  }
  else if(hand == 2)
  {
    rightBase.attach(rightBasePin);     
    rightMiddle.attach(rightMiddlePin); 
    rightTop.attach(rightTopPin); 
  }
  else{}

}    


//////////////////////////////////////////////////////////////////////////////////////


//Give Start Position to the hands
void HandDriver::Hand_Start_Position(int hand)
{
  if(hand == 1)
  {
    leftBase.write(leftBaseStart);     
    leftMiddle.write(leftMiddleStart); 
    leftTop.write(leftTopStart);
    delay(1000);
  }
  else if(hand == 2)
  {
    rightBase.write(rightBaseStart);     
    rightMiddle.write(rightMiddleStart); 
    rightTop.write(rightTopStart);
    delay(1000);
  }
  else{}
} 


//////////////////////////////////////////////////////////////////////////////////////



//Full Hand Move
void HandDriver::Put_Hand(int hand, int base, int middle, int top) 
{
  if(hand == 1)                     //Left
  {
    leftBase.write(base);      
    leftMiddle.write(middle); 
    leftTop.write(top);
    delay(1000);
  }
  else if(hand == 2)                //Right
  {
    rightBase.write(base);     
    rightMiddle.write(middle); 
    rightTop.write(top);
    delay(1000);
  }
  else{}
} 


//////////////////////////////////////////////////////////////////////////////////////


//Partwise Move
void HandDriver::Custom_Move(int hand, int part, int ang)  
{
  
  if(hand == 1)                   //Left
  {
    switch (part) 
    {
      case 1 :
        leftBase.write(ang);
        delay(1000);
        break;
      case 2 :
        leftMiddle.write(ang);
        delay(1000);
        break;
      case 3 :
        leftTop.write(ang);
        delay(1000);
        break;  
        
      default:
        break;
      
    }
    
  }
    
  else if(hand == 2)             //Right
  {
    switch (part) 
    {
      case 1 :
        rightBase.write(ang);
        delay(1000);
        break;
      case 2 :
        rightMiddle.write(ang);
        delay(1000);  
        break;
      case 3 :
        rightTop.write(ang);
        delay(1000);
        break;  
        
      default:
        break;
    }

  }
  
  else{}
} 


//////////////////////////////////////////////////////////////////////////////////////


//Keep Rotating
void HandDriver::Rotate_parts(int hand, int part)
{
  if(hand == 1)                                                                //Left
  {
    switch (part)            
    {
      case 1 :                                                                  //Base
        {
          for (int pos=leftBaseStart; pos<=leftBaseEnd; pos=pos + 3)
          { 
            leftBase.write(pos); 
            delay(100);
          }
          delay(2000);
          leftBase.write(leftBaseStart);   
          delay(5000);
          break;
        }
 //----------------------------------
        
      case 2 :                                                                 //Middle
        for (int pos = leftMiddleStart ; pos >= leftMiddleEnd; pos = pos - 3)
        { 
          leftMiddle.write(pos); 
          delay(100);
        }
        delay(2000);
        leftMiddle.write(leftMiddleStart);   
        delay(5000);
        break;
        
 //----------------------------------
          
      case 3 :                                                                 //Top
        for(int pos = leftTopStart; pos <= leftTopEnd; pos += 3)
        { 
          leftTop.write(pos); 
          delay(100);
        }
        delay(2000);
        leftTop.write(leftTopStart);  
        delay(5000);
        break;
        
 //----------------------------------
     
      default:
        break;
      
    }
  }
  

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  else if(hand == 2)                //Right
  {
    switch (part) 
    { 
      case 1 :                                                                   //Base
        for(int pos = rightBaseStart; pos >= rightBaseEnd; pos -= 3)
        { 
          rightBase.write(pos); 
          delay(100);
        }
        delay(2000);
        rightBase.write(rightBaseStart);   
        delay(5000);
        break;
        
 //----------------------------------
        
      case 2 :                                                                   //Middle
        for(int pos = rightMiddleStart; pos <= rightMiddleEnd; pos += 3)
        { 
          rightMiddle.write(pos); 
          delay(100);
        }
        delay(2000);
        rightMiddle.write(rightMiddleStart);   
        delay(5000);
        break;
        
 //----------------------------------
          
      case 3 :                                                                   //Top
        for(int pos = rightTopStart; pos <= rightTopEnd; pos += 3)
        { 
          rightTop.write(pos); 
          delay(100);
        }
        delay(2000);
        rightTop.write(rightTopStart);  
        delay(5000);
        break;
        
 //----------------------------------
     
      default:
        break;
      
    }
  }
  
  
  else{}
} 


//////////////////////////////////////////////////////////////////////////////////////











