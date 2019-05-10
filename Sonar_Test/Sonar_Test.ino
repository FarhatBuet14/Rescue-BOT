#define trigPin 6
#define echoPin 5

float duration = 0, distance = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);  //trigPin
  pinMode(echoPin, INPUT);   //echoPin
}

void loop() {
   
  digitalWrite(trigPin, LOW); //just to make sure that the pin in low first
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); //sends out an 8 cycle sonic burst from the transmitter
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
    
  duration = pulseIn(echoPin, HIGH); //It returns the time in microseconds
  distance = (duration*.0343)/2; //velocity= 0.0343 c/μS,, It will return the distance in cm
  
  Serial.println(distance);
  delay(200);
}
