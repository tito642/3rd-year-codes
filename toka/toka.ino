#include <SharpIR.h>

#define ir A0

#define model 20150

int GREEN=3;
int YELLOW=6;
int RED=9;
const int buzzer = 12;

SharpIR SharpIR(ir, model);

void setup() {
  
  Serial.begin(9600);

  pinMode(GREEN,OUTPUT);
  pinMode(YELLOW,OUTPUT); 
  pinMode(RED,OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  delay(500);   

  unsigned long pepe1=millis();  

  int dis=SharpIR.distance();  


  Serial.print("Mean distance: ");  
  Serial.println(dis);
  
  unsigned long pepe2=millis()-pepe1; 
  Serial.print("Time taken (ms): ");
  Serial.println(pepe2);  
if (dis< 30)
  { 
  digitalWrite(RED,HIGH);
digitalWrite(YELLOW,LOW); 
   digitalWrite(GREEN,LOW);
  tone(buzzer, 3000); 
  delay(300);        
  noTone(buzzer);    
  delay(300);        

    

      
 
}
   else if (dis > 30&&dis< 50 )
   {
    digitalWrite(YELLOW,HIGH);
    digitalWrite(RED,LOW);
    digitalWrite(GREEN,LOW);
    
  tone(buzzer, 600); 
  delay(1000);        
  noTone(buzzer);    
  delay(1000);        

    


    }
    else if (dis > 50){
          
    digitalWrite(YELLOW,LOW);
    digitalWrite(GREEN,HIGH);
    digitalWrite(RED,LOW);

      
}
}
