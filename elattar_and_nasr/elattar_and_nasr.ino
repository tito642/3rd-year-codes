#include <SharpIR.h>

#define ir A0
#define model 20150
// ir: the pin where your sensor is attached
// model: an int that determines your sensor:  1080 for GP2Y0A21Y
//                                            20150 for GP2Y0A02Y
//                                            (working distance range according to the datasheets)
int GREEN=10;
int YELLOW=11;
int RED=12;
const int buzzer = 13;

SharpIR SharpIR(ir, model);
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
lcd.begin(16, 2);
  pinMode(GREEN,OUTPUT);
  pinMode(YELLOW,OUTPUT); 
   pinMode(RED,OUTPUT);
   pinMode(buzzer, OUTPUT);
}

void loop() {
  delay(500);   

  
  unsigned long pepe1=millis();  // takes the time before the loop on the library begins

  int dis=SharpIR.distance();  // this returns the distance to the object you're measuringz
lcd.setCursor(0, 0);
  lcd.print("distance");
  lcd.setCursor(0, 1);
  lcd.print( dis);
  lcd.print("         :cm  ");
  //delay(200);
  //lcd.clear();

  Serial.print("Mean distance: ");  // returns it to the serial monitor
  Serial.println(dis);
  
  unsigned long pepe2=millis()-pepe1;  // the following gives you the time taken to get the measurement
  Serial.print("Time taken (ms): ");
  Serial.println(pepe2); 

  


if (dis< 30)
  { 
  digitalWrite(RED,HIGH);
digitalWrite(YELLOW,LOW); 
   digitalWrite(GREEN,LOW);
  tone(buzzer, 1000); 
  delay(100);        
  noTone(buzzer);    
  delay(100);        

    
//digitalWrite(RED2,LOW);
//digitalWrite(RED2,LOW);
//delay(1000);
//digitalWrite(RED,LOW);
//digitalWrite(RED1,HIGH);
//digitalWrite(RED2,LOW);
//delay(1000);

//digitalWrite(RED,LOW);
//digitalWrite(RED1,LOW);
//digitalWrite(RED2,HIGH); 
//delay(1000);
      
 
}
   else if (dis > 30&&dis< 50 )
   {
    digitalWrite(YELLOW,HIGH);
    digitalWrite(RED,LOW);
    digitalWrite(GREEN,LOW);
  tone(buzzer, 3000); 
  delay(1000);        
  noTone(buzzer);    
  delay(1000);        

    
//digitalWrite(YELLOW1,LOW);
//digitalWrite(YELLOW2,LOW);
//delay(1000);
//digitalWrite(YELLOW,LOW);
//digitalWrite(YELLOW1,HIGH);
///digitalWrite(YELLOW2,LOW);
//delay(1000);

//digitalWrite(YELLOW,LOW);
//digitalWrite(YELLOW1,LOW);
//digitalWrite(YELLOW2,HIGH); 
//delay(1000);

    }
    else if (dis > 50){
      //tone(buzzer, 300); 
  //delay(1000);        
 // noTone(buzzer);    
  //delay(1000);        
    digitalWrite(YELLOW,LOW);
    digitalWrite(GREEN,HIGH);
    digitalWrite(RED,LOW);
//digitalWrite(GREEN1,LOW);
//digitalWrite(GREEN2,LOW);
//delay(1000);
//digitalWrite(GREEN,LOW);
//digitalWrite(GREEN1,HIGH);
//digitalWrite(GREEN2,LOW);
//delay(1000);

//digitalWrite(GREEN,LOW);
//digitalWrite(GREEN1,LOW);
//digitalWrite(GREEN2,HIGH); 
//delay(1000);
      
}

}
