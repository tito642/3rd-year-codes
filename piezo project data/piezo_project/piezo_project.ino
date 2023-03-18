=

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int analogInput=A5;
float vout;
float vin;
float R1 = 980.0;
float R2 = 980.0;
int value;

void setup() {
  
  pinMode(analogInput, INPUT);
  lcd.begin(16, 2);
  
  lcd.setCursor(2, 0);
  lcd.print("Initializing");
  lcd.setCursor(4, 1);
  lcd.print("EE Wave");
  
  delay(1500);
  lcd.clear();
pinMode(11, OUTPUT);
}
void loop() {
  lcd.setCursor(2, 0);
  lcd.print("DC Voltmeter");

  value = analogRead(analogInput);
  vout = (value * 5)/1.024;
  vin = vout / (R2 / (R1 + R2));
  
  if (vin < 0.09)
  {
    vin = 0.0;
    digitalWrite (11,LOW);
  
  }
  
  else if (vin>0.09)
  {digitalWrite (11,HIGH); }
  lcd.setCursor(0, 1);
  lcd.print("Input mv :");
  lcd.print(vin);
  delay(300);
  lcd.clear();

  
}
