#include <LiquidCrystal.h> 
LiquidCrystal lcd(12,11,5,4,3,2);   //(RS,E,D4,D5,D6,D7)
const int analogInPin = A5;
int sensorValue ;  
int moisture ;
void setup() {
  sensorValue = analogRead(analogInPin);
  moisture = map(sensorValue,0,1023,0,100);
  Serial.begin(9600);
lcd.begin(16, 2);

} 
void loop() {
  Serial.print(sensorValue);
  Serial.println(moisture); 
  
lcd.clear();
lcd.print("moisture=");
lcd.print(moisture);
lcd.print("%");
delay(100);
}
