int Inductivesensor = 2; // connect Inductive sensor to arduino pin 2


#include <Servo.h>
Servo myservo;
int pos = 0; 

void setup() 
{

myservo.attach(9);

  pinMode (Inductivesensor, INPUT); // sensor pin INPUT
  

Serial.begin(9600);}

void loop()
{
  int statusSensor = digitalRead (Inductivesensor);
  Serial.println(statusSensor);
  if (statusSensor == 1)
   { 
    myservo.write(180);
     delay (7000);
   }
   else  {
 
  myservo.write(0);
 delay (5000);
  }
 
  
}
