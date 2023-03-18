//********************* LCD ********************************
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//******************** Keypad ****************************

#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {22, 24, 26, 28}; 
byte colPins[COLS] = {30, 32, 34, 36}; 

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
//*************************** STEPPER **********************
#include <Stepper.h>
 int stepsPerRevolution = 200;
Stepper myStepper_1(stepsPerRevolution, A0,A1,A2,A3);
Stepper myStepper_2(stepsPerRevolution, 40,42,44,46);
Stepper myStepper_3(stepsPerRevolution, 48,50,52,53);
Stepper myStepper_4(stepsPerRevolution, 31,33,35,37);

//*********** variabled *******************************
int i = 0;  
unsigned char Count1=2;
unsigned char Count2=2;
unsigned char Count3=2;
unsigned char Count4=2;
int s=0;
int S=0;
int vv=0;
char x = 0;
int value = 0;
char customKey ='\0';
char med1 = 6223000760017;
/*char med2 = ............;
char med3 = ............;
char med4 = ............;*/


void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  
  myStepper_1.setSpeed(85);
  myStepper_2.setSpeed(85);
  myStepper_3.setSpeed(85);
  myStepper_4.setSpeed(85);

  
}

void loop() {
  myStepper_1.step(0);
  myStepper_2.step(0);
  myStepper_3.step(0);
  myStepper_4.step(0);



   //*************** Step 1 **************************
   if(s==0)
   {
    lcd.setCursor(0,0);
    lcd.print("Scan Code .......");
    
     if(Serial.available() > 0)  
  {
    x = Serial.read();
     Serial.print("scan  = ");
     Serial.println("\n");
  
    if(x == med1)
   {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("NAme 1");
    lcd.setCursor(13,0);
    lcd.print(Count1);
    lcd.setCursor(0,1);
    lcd.print("A-to take");
    lcd.setCursor(10,1);
    lcd.print("B-Exit");
    s=1;
    
  }
   if(x== '2')
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("NAme 2");
    lcd.setCursor(13,0);
    lcd.print(Count2);
    lcd.setCursor(0,1);
    lcd.print("A-to take");
    lcd.setCursor(10,1);
    lcd.print("B-Exit");
        s=1;

  }

 if(x== '3')
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("NAme 3");
    lcd.setCursor(13,0);
    lcd.print(Count3);
    lcd.setCursor(0,1);
    lcd.print("A-to take");
    lcd.setCursor(10,1);
    lcd.print("B-Exit");
        s=1;

  }

 if(x== '4')
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("NAme 4");
    lcd.setCursor(13,0);
    lcd.print(Count4);
    lcd.setCursor(0,1);
    lcd.print("A-to take");
    lcd.setCursor(10,1);
    lcd.print("B-Exit");
        s=1;

  }
}
   }
//************************** step 2 *****************************
   if(s==1)
   {
      customKey = customKeypad.getKey();

      if(customKey == 'A')
      {
          
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Enter Num : ");
         
         S=1;
      }
      if(customKey == 'B')
      {
        lcd.clear();
        s=0;
      }     

      if(customKey >= '0' && customKey <='9' && S==1)
      {

        value = customKey - '0';
        Serial.print("value = ");
        Serial.println(value);
        lcd.print(customKey);
      }

      if(customKey == '#')
      {
        vv=1;
        
      }
   }
   
//************ MOTOR ROTAT ***********************
      if(vv == 1)
      {   if(x=='1')
          {
                 for(int i = 0 ; i <= (10 * value) ; i++ )
                 {
                    myStepper_1.step(+stepsPerRevolution); 
                   
                 }
                    Count1 -= value;
                    customKey = '\0';
                    value = 0;
                    vv=0;
          }
           if(x=='2')
           {
             for(int i = 0 ; i <= (10 * value) ; i++ )
             {
                myStepper_2.step(+stepsPerRevolution); 
               
             }
                Count2 -= value;
                customKey = '\0';
                value = 0;
                vv=0;
           }
                if(x=='3')
                {
             for(int i = 0 ; i <= (10 * value) ; i++ )
             {
               
                myStepper_3.step(+stepsPerRevolution); 
             }
                Count3 -= value;
                customKey = '\0';
                value = 0;
                vv=0;
                }
                if(x=='4')
                {
             for(int i = 0 ; i <= (10 * value) ; i++ )
             {
               
                myStepper_4.step(+stepsPerRevolution); 
             }
              Count4 -= value;
                customKey = '\0';
                value = 0;
                vv=0;
               }
       }
}
