int water;
int soil;
int out;
int moto = 10;
int ledgre = 0;
int ledred = 1;
int segA = 2;
int segB = 3;
int segC = 4;
int segD = 5;
int segE = 6;
int segF = 7;
int segG = 8;
void setup() {
  pinMode(A1,INPUT);
  pinMode(13,OUTPUT);
  pinMode(segA,OUTPUT);
  pinMode(segB,OUTPUT);
  pinMode(segC,OUTPUT);
  pinMode(segD,OUTPUT);
  pinMode(segE,OUTPUT);
  pinMode(segF,OUTPUT);
  pinMode(segG,OUTPUT);
  pinMode(ledred,OUTPUT);
  pinMode(9,INPUT);
  pinMode(12,OUTPUT);
  pinMode(ledgre,INPUT);
  pinMode(moto,HIGH);
  Serial.begin(9600);

}

void loop() {
 soil=analogRead(A1);
 out = map (soil,0,596,300,0);
 water=digitalRead(9);
 if(out >=-1&out<=0){
  digitalWrite(segA,HIGH);
  digitalWrite(segB,HIGH);
  digitalWrite(segC,HIGH);
  digitalWrite(segD,HIGH);
  digitalWrite(segE,HIGH);
  digitalWrite(segF,HIGH);
  digitalWrite(segG,LOW);
  }
   if(out>0&out<=10){
  digitalWrite(segA,LOW);
  digitalWrite(segB,HIGH);
  digitalWrite(segC,HIGH);
  digitalWrite(segD,LOW);
  digitalWrite(segE,LOW);
  digitalWrite(segF,LOW);
  digitalWrite(segG,LOW);}
   if(out>10&out<=20){
  digitalWrite(segA,HIGH);
  digitalWrite(segB,HIGH);
  digitalWrite(segC,LOW);
  digitalWrite(segD,HIGH);
  digitalWrite(segE,HIGH);
  digitalWrite(segF,LOW);
  digitalWrite(segG,HIGH);}
   if(out>20&out<=30){
  digitalWrite(segA,HIGH);
  digitalWrite(segB,HIGH);
  digitalWrite(segC,HIGH);
  digitalWrite(segD,HIGH);
  digitalWrite(segE,LOW);
  digitalWrite(segF,LOW);
  digitalWrite(segG,HIGH);}
   if(out>30&out<=40){
  digitalWrite(segA,LOW);
  digitalWrite(segB,HIGH);
  digitalWrite(segC,HIGH);
  digitalWrite(segD,LOW);
  digitalWrite(segE,LOW);
  digitalWrite(segF,HIGH);
  digitalWrite(segG,HIGH);}
   if(out>40&out<=50){
  digitalWrite(segA,HIGH);
  digitalWrite(segB,LOW);
  digitalWrite(segC,HIGH);
  digitalWrite(segD,HIGH);
  digitalWrite(segE,LOW);
  digitalWrite(segF,HIGH);
  digitalWrite(segG,HIGH);}
   if(out>50&out<=60){
  digitalWrite(segA,HIGH);
  digitalWrite(segB,LOW);
  digitalWrite(segC,HIGH);
  digitalWrite(segD,HIGH);
  digitalWrite(segE,HIGH);
  digitalWrite(segF,HIGH);
  digitalWrite(segG,HIGH);}
   if(out>60&out<=70){
  digitalWrite(segA,HIGH);
  digitalWrite(segB,HIGH);
  digitalWrite(segC,HIGH);
  digitalWrite(segD,LOW);
  digitalWrite(segE,LOW);
  digitalWrite(segF,LOW);
  digitalWrite(segG,LOW);}
   if(out>30&out<=40){
  analogWrite(A1,LOW);
  delay(500);
  digitalWrite(ledred,HIGH);
  delay(500);
  digitalWrite(ledred,LOW);
  delay(500);
  digitalWrite(ledred,HIGH);
  delay(500);
  digitalWrite(ledred,LOW);
  delay(500);
  digitalWrite(ledred,HIGH);
  delay(500);
  digitalWrite(ledred,LOW);
  delay(500);
  digitalWrite(12,HIGH);
  delay(500);
  digitalWrite(segA,LOW);
  digitalWrite(segB,LOW);
  digitalWrite(segC,LOW);
  digitalWrite(segD,LOW);
  digitalWrite(segE,LOW);
  digitalWrite(segF,LOW);
  digitalWrite(segG,LOW);
  digitalWrite(10,HIGH);
  }
  Serial.println(out);
  Serial.println(water);
}
