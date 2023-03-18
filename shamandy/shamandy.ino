int IRSensor = 2; // connect ir sensor to arduino pin 2
int LED = 13; // conect Led to arduino pin 13

#include <Servo.h>
Servo myservo;
int pos = 0; 

void setup() 
{

myservo.attach(9);

  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (LED, OUTPUT); // Led pin OUTPUT

Serial.begin(9600);}

void loop()
{
  int statusSensor = digitalRead (IRSensor);
  Serial.println(statusSensor);
  if (statusSensor == 1)
   { digitalWrite(LED, LOW);
    myservo.write(90);// LED LOW 
   }
   else  {
    digitalWrite(LED, HIGH); // LED High
  myservo.write(0);
 delay (5000);
  }
 
  
}
