#include <LiquidCrystal.h>
#include <TimerOne.h>
const int rs = 9, en = 8, d11 =2, d12 = 3, d13 = 4, d14 = 5;
LiquidCrystal lcd (rs, en, d11, d12, d13, d14);
#define VOLTS_Panneaux A0 //Le diviseur de tension côté panneaux PV est connecté au pin A0
#define AMPS_Panneaux A1//Le capteur de courant ACS712 côté panneaux PV est connecté au pin A1
#define VOLTS_Batterie A2 //Le diviseur de tension côté batterie est connecté au pin A2
#define pin_PWM 9 //La pin 9 de sortie du PWM est utilisée pour commander les MOSFETs, FSW est 50000 Hz
#define pin_Driver 10 //La pin 10 pour activer le Driver IR2104
#define BAT_Min 10.5 //Tension minimale de batterie
#define BAT_Max 15 //Tension maximale de batterie
#define LVD 11.5
#define Ps1 14.4 //Bulk_Charge
#define Ps2 13.6 //Float_Charge
//Indication de batterie
#define greenLed 11
#define yellowLed 12 
#define redLed 13
#define pwm_min 30
float Vpv = 0.0; //V_PV
float Vbat = 0; // V_Batterie
float Ipv = 0.0;//I_PV
int ledDelay = 1000;
float R1 =100000.0;
float R2 =10000.0;
float R3 =10000.0;
float R4 =2200.0;
int Lecture =0;
float Charge_status =0.0;
float error =0;
float Ep =0;
int Rap_cyclique =0;
unsigned int Nbr_iterations=50;
float Moyen =0.0, AvgAcs =0.0, AcsValueF =0.0;
int SensmVA = 162; //En utilisant 162 mV/A pour ACS712 de 30A
int ACSoffset = 468; // Tention de sortie de ACS721 = 0.468V
float Lecture_pin(int pin) {
for (int i = 0; i < Nbr_iterations; i++) {
Lecture = analogRead(pin);
Moyen = Moyen + Lecture;
}
Moyen = Moyen/100.0;
return Moyen;
}
void Lecture_donnees (void) {
/** Lecture de la valeur sur les pins A0 et A2 et ensuite transformer la mesure (nombre entier) en tension (V)
via un produit en croix, **/
Vpv = Lecture_pin(VOLTS_Panneaux)* (5.0/ 1023.0)/( R2/(R1+R2));
Vbat = Lecture_pin( VOLTS_Batterie)* (5.0/ 1023.0)/( R4/(R3+R4));
Ipv = (Lecture_pin(AMPS_Panneaux)* (5000.0/ 1023.0))- (ACSoffset / SensmVA);
}
void Print_data_Monitor (void)
{
Serial.print ("Vpv=");
Serial.print (Vpv,2);
Serial.print ("Ipv=");
Serial.print (Ipv,2);
Serial.print ("A");
Serial.print ("Vbat=");
Serial.print (Vbat,2);
Serial.print ("V");
delay (500);
}
void Print_data_lcd (void)
{
lcd.setCursor (0,0);
lcd.print ("Vpv="); // Afficher la valeur de la tension du PV sur l'écran LCD
lcd.print (Vpv,2); // deux nombre aprés la virgul
lcd.print ("V");
lcd.setCursor (0,1);
lcd.print ("Ipv="); //Afficher la valeur du courant du PV sur l'écran LCD
lcd.print (Ipv,2); // deux nombre aprés la virgul
lcd.print ("A");
delay (500);
lcd.setCursor (0,2);
lcd.print ("Vbat="); // Afficher la valeur du tension du batterie sur l'écran LCD
lcd.print (Vbat,2);
lcd.print ("V");
if ( Charge_status==1 ){
lcd.setCursor (0,3);
lcd.print ("Bulk charge"); // Afficher l'étape de charge en cours sur l'écran LCD
}
else {
lcd.setCursor (0,4);
lcd.print ("float charge"); // Afficher l'étape de charge en cours sur l'écran LCD
}
}
void Test_Batterie (void)
{
if( Vbat >= BAT_Max ){
digitalWrite(greenLed, HIGH); digitalWrite(redLed, LOW); digitalWrite(yellowLed, LOW); Serial.print("Charge Absorbtion"); }
else if ( Vbat <= BAT_Min ){
digitalWrite(redLed, HIGH); digitalWrite(greenLed, LOW); digitalWrite(yellowLed, LOW); Serial.print("charge Bulk"); }
else{
digitalWrite(yellowLed, HIGH); digitalWrite(redLed, LOW); digitalWrite(greenLed, LOW); Serial.print("charge float");}
}
void cycle_charge(void) {
if (Vpv > Vbat && Vbat <= Ps1){
if (Vbat<= Ps2) {
Charge_status=1; //Bulk charge
Rap_cyclique=1023;
Timer1.pwm (pin_PWM,Rap_cyclique);
}
else if ( Vbat > Ps2 && Vbat <= Ps1){
Charge_status=2; //Float charge
error = Ps1 - Vbat;
Ep = error * 100;
if (Ep < 0)
{ Timer1.pwm (pin_PWM,pwm_min);}
else if (Ep > 100)
{ Timer1.pwm (pin_PWM, 1023);}
else {
  Rap_cyclique= (Ep*1023)/100;
  Timer1.pwm (pin_PWM,Rap_cyclique);
}
}
}
}


void setup() {
  pinMode (pin_PWM, OUTPUT);
pinMode (pin_Driver, OUTPUT);
pinMode (greenLed, OUTPUT);
pinMode (yellowLed, OUTPUT);
pinMode (redLed, OUTPUT);
digitalWrite (redLed, LOW);
digitalWrite (yellowLed, LOW);
digitalWrite (greenLed, LOW);
digitalWrite (redLed, LOW);
digitalWrite (pin_PWM, LOW);
digitalWrite (pin_Driver, HIGH);
Timer1.initialize (20); // Déclaraion de la période ... Fréquence = (1/20microsec)=50KHz
Timer1.pwm(pin_PWM,0);
Serial.begin (9600); // Initialise la communication avec le PC
lcd.begin (16, 4);
lcd.clear ();
lcd.write("current= ");delay(2000);lcd.clear ();

}

void loop() {
  Timer1.pwm(9,512); // 50% du rapport cyclique (duty cycle)
Lecture_donnees ();
Test_Batterie ();
cycle_charge ();
Print_data_lcd ();

}
