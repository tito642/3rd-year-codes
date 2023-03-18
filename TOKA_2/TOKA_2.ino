#include <SharpIR.h>

#define ir A5
#define model 20150


int GREEN=10;
int YELLOW=11;
int RED=12;
const int buzzer = 13;



SharpIR SharpIR(ir, model);
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
 
  Serial.begin(9600);
lcd.begin(16, 2);
  pinMode(GREEN,OUTPUT);
  pinMode(YELLOW,OUTPUT); 
   pinMode(RED,OUTPUT);
   pinMode(buzzer, OUTPUT);
}

void loop() {
  delay(500);   

  
  unsigned long pepe1=millis();  

  int dis=SharpIR.getDistance();  
lcd.setCursor(0, 0);
  lcd.print("Distance");
  lcd.setCursor(0, 1);
  lcd.print(dis);
  lcd.print("        :cm");
  

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
