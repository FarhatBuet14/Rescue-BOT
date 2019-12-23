#include <Servo.h>

Servo myservo;

int pos = 0;

void setup() {
  myservo.attach(A5);
}

void loop() {
  myservo.write(120);
  delay(3000);
  myservo.write(150);
  delay(3000);
  myservo.write(180);
  delay(3000);
  myservo.write(150);
  delay(3000);
  
// -----------------  For Testing Purposes
//
//  for (pos = 120; pos <= 180; pos += 5) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= 120; pos -= 5) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }

}
