#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


const int buttonPin = 2;     // the number of the pushbutton pin
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int count_value =0;
int prestate =0;
void setup() {
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, then the buttonState is HIGH:
  if (buttonState == HIGH && prestate == 0) {
    count_value++;
    prestate = 1;
  } else if(buttonState == LOW) {
    prestate = 0;
  }
  if (count_value =1){
    lcd.setCursor(0,0);
      
        lcd.print("a");
    }
    if (count_value =2){
    lcd.setCursor(0,0);
      
        lcd.print("ab");
       
    }
    if (count_value =3){
    lcd.setCursor(0,0);
      
        lcd.print("abc");
    }
    if (count_value =4){
    lcd.setCursor(0,0);
     
        lcd.print("abcd");
       
    }
   
      if (count_value =5){
    lcd.setCursor(0,0);
     
        lcd.print("abcde");
       
    }if (count_value =6){
    lcd.setCursor(0,0);
     
        lcd.print("abcdef");
       
    }if (count_value =7){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefg");
       
    }if (count_value =8){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefgh");
       
    }if (count_value =9){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghi");
       
    }if (count_value =10){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghij");
       
    }if (count_value =11){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijk");
       
    }if (count_value =12){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijkl");
       
    }if (count_value =13){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijklm");
       
    }if (count_value =14){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijklmn");
       
    }if (count_value =15){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijklmno");
       
    }if (count_value =16){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijklmnop");
       
    }if (count_value =17){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijklmnop");
        lcd.setCursor(1,0);
     
        lcd.print("q");
       
    }
    if (count_value =17){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijklmnop");
        lcd.setCursor(1,0);
     
        lcd.print("q");
    
}
if (count_value =18){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijklmnop");
        lcd.setCursor(1,0);
     
        lcd.print("qrs");}

if (count_value =19){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijklmnop");
        lcd.setCursor(1,0);
     
        lcd.print("qrst");}
if (count_value =20){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijklmnop");
        lcd.setCursor(1,0);
     
        lcd.print("qrstu");}

       if (count_value =20){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijklmnop");
        lcd.setCursor(1,0);
     
        lcd.print("qrstu");}

if (count_value =21){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijklmnop");
        lcd.setCursor(1,0);
     
        lcd.print("qrstuv");}

if (count_value =22){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijklmnop");
        lcd.setCursor(1,0);
     
        lcd.print("qrstuvw");}

        if (count_value =23){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijklmnop");
        lcd.setCursor(1,0);
     
        lcd.print("qrstuvwx");}
        if (count_value =24){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijklmnop");
        lcd.setCursor(1,0);
     
        lcd.print("qrstuvwxy");}
        if (count_value =25){
    lcd.setCursor(0,0);
     
        lcd.print("abcdefghijklmnop");
        lcd.setCursor(1,0);
     
        lcd.print("qrstuvwxyz");}
        }
