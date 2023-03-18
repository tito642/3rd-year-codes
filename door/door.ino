#include<LiquidCrystal.h>  //تعريف مكتبه الشاشه
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // البنات الي هوصل الشاشه عليهم في الاردوينو 

#include <Servo.h> 

Servo myservo;  

int sensorPin = A0;   

int sensorValue ; 

int   RED=11; 

int YELLOW=12;
int GREEN=13;




void setup() {

lcd.begin(16,2); 
lcd.setCursor(3,0); 
lcd.print("water ditch"); 
lcd.setCursor(0,1); 
lcd.print("    control");
delay(2000); 
lcd.clear();

lcd.begin(16,2);
lcd.clear();
lcd.setCursor(2,0);
lcd.print(" designed by ");
lcd.setCursor(2,1); 
lcd.print("  hoda-manar");
delay(2000);
lcd.clear();

lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print(" programmed by ");
lcd.setCursor(0,1); 
lcd.print("  attar-fawaz");
delay(3000);
lcd.clear();


lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("  under visor ");
lcd.setCursor(0,1); 
lcd.print("dr ahmed shehata");
delay(3000);
lcd.clear();

Serial.begin(9600); 


myservo.attach(3); 

pinMode(RED,OUTPUT); 
 pinMode(YELLOW,OUTPUT); 
pinMode(GREEN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorValue = analogRead(sensorPin); 
sensorValue =analogRead(sensorPin)/5.66;
Serial.println(sensorValue);
delay(500);


lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("  door height ");
lcd.setCursor(0,1); 
lcd.print(sensorValue/1.8);
lcd.setCursor(5,1); 
lcd.print("%");
//delay(500);
//lcd.clear();

myservo.write(sensorValue);  

if ((sensorValue<180)&&(sensorValue>120)){
digitalWrite(RED,HIGH);
digitalWrite(YELLOW,LOW);
digitalWrite(GREEN,LOW);}

else if ((sensorValue<120)&&(sensorValue>60)){
digitalWrite(RED,LOW);
digitalWrite(YELLOW,HIGH);
digitalWrite(GREEN,LOW);}

else if ((sensorValue<60)&&(sensorValue>0)){
digitalWrite(RED,LOW);
digitalWrite(YELLOW,LOW);
digitalWrite(GREEN,HIGH); }
}
