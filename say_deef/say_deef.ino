#include <SoftwareSerial.h>
SoftwareSerial myserial (5,6) ;// bluetooth : Tx = 5 , Rx = 6  

const int flexPin = A5; //pin A2 to read analog input

//Variables:
int value; //save analog value





void setup() {
myserial.begin(9600); 
Serial.begin (9600) ;  
pinMode(A5,INPUT);
}








void loop() {
  if(myserial.available() )
  {
    Serial.write( myserial.read() ); 
    }
  
    if (Serial.available () )
    {
     myserial.write(Serial.read() );

      
      }
value = analogRead(flexPin);
//Read and save analog value from potentiometer
              //Print value
  //value = map(value, 0, 1023, 0, 255);//Map value 0-1023 to 0-255 (PWM)
 
if((value>=211)&&(value<=258)){
myserial.write("بحبك i love you");}
   if((value>=186)&&(value<=210)){
myserial.write("اسمك ايه");
  
 }
 
 if((value>=166)&&(value<=185)){
myserial.write("كويس");
  
 }
 
  if((value>=100)&&(value<=150)){
myserial.write("");
  
 }
  if((value>=151)&&(value<=165)){
myserial.write("hello doctor sheren");
  
 }
else{
  
  myserial.write("");}




  //myserial.println(value);
 Serial.println(value);
 delay(5000);
 
   }



  
