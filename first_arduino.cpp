/*Garasjeport av Asgeir Bjørgen Huskebakk
*
* Dette prosjektet inneholder:
	- DC motor
    - motorstyrer (L293D)
    - ledlys
    - lampe
    - strømforsyning
    - LCD display
    - 4 knapper
    - IR mottaker
    - fjernkontroll
    - 2 stk arduino
    - motstander
    - potensiometer
    
* Funksjon:
	- Garasjeporten starter åpen.
    - knapp opp (1 på fjernkontroll) kjører porten opp
    - knapp ned (2 på fjernkontroll) kjører porten ned
    - knapp lys (3 på fjernkontroll) gir lampe lys i variabel tid (40 sec)
    - knapp motstand fungerer som montstand når heisen går nedover
   		trykkes denne inn, stopper motor og går 0.2 meter oppover.
    - lampe lyser i 40 sec etter at motor et stoppet.
    - LCD printer portens status
    - led lyser mens motor går
    - Info kan også sees i seriell overvåker.
 
*/

//LiquidCrystal(RS, E, D4, D5, D6, D7)
#include <LiquidCrystal.h>

//Definerer pins til LCD
#define D4 A2
#define D5 A1
#define D6 A0
#define D7 11
#define E 12
#define RS 13

//kobler sammen bibliotek og pins
LiquidCrystal lcd(RS, E, D4, D5, D6, D7); 

//inkluderer bibliotek for kommunikasjon
#include <Wire.h>

//Variabel for åpen/lukket port
int port = 0;

//Variabel for tid port opp/ned
int tid_opp_ned = 500; //4 sekunder = 2 meter|2000 = 1 meter| 500 = 0,5 meter|

//Variabel for tid, lys
int tid_lys = 4000; //4 sekunder(for test) (40 000 vil gi 40 sekunder)

//Definerer pins for motor og motorkontroller
const int motor_opp = 9;
const int motor_ned = 8;
const int motor_aktiver = 10;

//Variabel for blinkende lys
int blinklys = 0;

//Variabel for motor
int motor_drive = 0;

//Definerer pins til knapper
const int knapp_opp = 5;
const int knapp_ned = 4;
const int knapp_lys = 3;
const int knapp_nod = 2;

//Variabler for knappStatus
int knapp_opp_status = 0;
int knapp_ned_status = 0;
int knapp_lys_status = 0;
int knapp_nod_status = 0;

//Definerer pin til lyspære
const int lampe = 6;

//Definerer pin til ledlys
const int ledlys = 7;

//Lager setup funksjonen
void setup(){
  
  //starter LCD
  lcd.begin(16,2); 
  
  //Starter kommunikasjon mellom arduinoene
  Wire.begin(4);                
  Wire.onReceive(receiveEvent); 
  
  //Starter seriell overvåker
  Serial.begin(9600);
  
  //setter motorPins til OUTPUT
  pinMode(motor_opp, OUTPUT);
  pinMode(motor_ned, OUTPUT);
  pinMode(motor_aktiver, OUTPUT);
  
  //Setter knappePins til OUTPUT
  pinMode(knapp_opp, INPUT);
  pinMode(knapp_ned, INPUT);
  pinMode(knapp_lys, INPUT);
  pinMode(knapp_nod, INPUT);
  
  //Setter lampePin til OUTPUT
  pinMode(lampe, OUTPUT);
  
  //Setter ledlys til OUTPUT
  pinMode(ledlys, OUTPUT);
  
}//Slutt setup()

//Lager loop funksjonen
void loop(){
  
  skjerm();
   
  //port_status();
  //delay(200);

  lampe_lys(); //Starter lampe funksjon
  motorOPP(); //Starter motoropp funksjon
  motorNED(); //Starter motorned funksjon
  
}//Slutt loop()

//Lager lampe_lys funksjonen
void lampe_lys() {
  
knapp_lys_status = digitalRead(knapp_lys); //bruker variabel knapp_lys_status
  
  //Hvis lysknapp blir trykket, lyser lampe i 40 sekunder.
  if(knapp_lys_status == HIGH){
    
  digitalWrite(lampe, HIGH); //gir lampe strøm
  delay(tid_lys); //Venter 40 sekunder
  digitalWrite(lampe, LOW);//Slår av lampe
    
  }//Slutt IF
  
}//Slutt lampe_lys()

//Lager motorOPP funksjonen
void motorOPP() {
  
knapp_opp_status = digitalRead(knapp_opp); //Bruker variabel knapp_opp_status
  
  //Hvis knapp opp er aktiv og porten er lukket:
  if(knapp_opp_status == HIGH && port == 1) {
  port_status(); //Printer i seriell overvåker
  digitalWrite(lampe, HIGH); //gir lampe strøm
  digitalWrite(motor_aktiver, HIGH); //aktiverer motorstyrer
  digitalWrite(motor_opp, HIGH); //gir motor opp strøm
  digitalWrite(motor_ned, LOW); //Holder motor ned avslått
  led_blink_delay_opp(); //Delay og blinklys (ønsket verdi i variabel)
  //delay(tid_opp_ned); //Venter 4 sekunder
  blinklys = 0;
  port = 0; //Setter portstatus til 0
  digitalWrite(motor_aktiver, LOW); //kutter strøm til pin
  digitalWrite(motor_opp, LOW);//kutter strøm til pin
  digitalWrite(motor_ned, LOW);//kutter strøm til pin
  port_status(); //Printe i seriell overvåker
  delay(tid_lys); //Delay med variabel tid
  digitalWrite(lampe, LOW);//Slår av lampe
    
  }//Slutt IF
  
}//SLutt motorOPP()

//Lager motorNED funksjonen
void motorNED(){
  
knapp_ned_status = digitalRead(knapp_ned); //Bruker variabel knapp_ned status
  
  //Hvis knapp ned er aktiv og porten er åpen:
  if(knapp_ned_status == HIGH && port == 0) {
  port_status();//Printe i seriell overvåker
  digitalWrite(lampe, HIGH); //gir lampe strøm
  digitalWrite(motor_aktiver, HIGH); //Aktiverer motorstyring
  digitalWrite(motor_opp, LOW); //Kutter strøm til motor opp
  digitalWrite(motor_ned, HIGH); //Gir strøm til motor ned
  led_blink_delay_ned();//Delay og blinklys (ønsket verdi i variabel)
    //delay(tid_opp_ned); //Venter 4 sekunder
  port = 1; //Setter portstatus til 1
  digitalWrite(motor_aktiver, LOW); //kutter strøm til pin
  digitalWrite(motor_opp, LOW);//kutter strøm til pin
  digitalWrite(motor_ned, LOW);//kutter strøm til pin
  port_status();//Prnter i seriell overvåker
  delay(tid_lys);//Delay med variabel tid
  digitalWrite(lampe, LOW);//Slår av lampe
  
  }//Slutt IF
  
}//Slutt motorNED()

//Lager motormotstand funksjonen
void motor_motstand(){
  
knapp_nod_status = digitalRead(knapp_nod); //bruker variabel knapp_nod_status
  
  //Hvis knapp nod er aktiv mens port går ned:
  if(knapp_nod_status == HIGH){
  tid_opp_ned = 0; //Setter tid til 0.
  digitalWrite(motor_aktiver, LOW); //Kutter strøm til pin
  digitalWrite(motor_opp, LOW);//Kutter strøm til pin
  digitalWrite(motor_ned, LOW);//Kutter strøm til pin
  delay(400); //Venter i 0.4 sekunder
  digitalWrite(motor_aktiver, HIGH);//Aktiverer motorstyring
  digitalWrite(motor_opp, HIGH); //Kjører motor oppover
  digitalWrite(motor_ned, LOW); //Kutter strøm til pin
  delay(400); //400 fordi 1m = 2 sek. 20% av 2 sek = 0.4sek
  digitalWrite(motor_aktiver, LOW);//Kutter strøm til pin
  digitalWrite(motor_opp, LOW);//Kutter strøm til pin
  digitalWrite(motor_ned, LOW);//Kutter strøm til pin
  tid_opp_ned = 500; //venter 0.5 sek
  }//Slutt IF
}//SLutt motor_motstand()

//Lager port_status funksjonen
void port_status() {
  //Denne funksjonen printer kun i seriell overvåker
  Serial.println();
  Serial.print("port status: ");
  Serial.print(port);
  Serial.println();
  Serial.print("1 = lukket, 0 = åpen");
}//Slutt port_status()

//Lager led_blink_delay_ned funksjonen
void led_blink_delay_ned() {
  
  digitalWrite(ledlys, HIGH);//Gir pin strøm
  motor_motstand(); //Sjekker etter motstand mens porten går nedover
  delay(tid_opp_ned); //Venter i tid/8 for 2 meter, 4 sekunder
  digitalWrite(ledlys, LOW);//Kutter strøm til pin
  motor_motstand();//Sjekker etter motstand mens porten går nedover
  delay(tid_opp_ned);//Venter i tid/8 for 2 meter, 4 sekunder
  digitalWrite(ledlys, HIGH);//Gir pin strøm
  motor_motstand();//Sjekker etter motstand mens porten går nedover
  delay(tid_opp_ned);//Venter i tid/8 for 2 meter, 4 sekunder
  digitalWrite(ledlys, LOW);//Kutter strøm til pin
  motor_motstand();//Sjekker etter motstand mens porten går nedover
  delay(tid_opp_ned);//Venter i tid/8 for 2 meter, 4 sekunder
  digitalWrite(ledlys, HIGH);//Gir pin strøm
  motor_motstand();//Sjekker etter motstand mens porten går nedover
  delay(tid_opp_ned);//Venter i tid/8 for 2 meter, 4 sekunder
  digitalWrite(ledlys, LOW);//Kutter strøm til pin
  motor_motstand();//Sjekker etter motstand mens porten går nedover
  delay(tid_opp_ned);//Venter i tid/8 for 2 meter, 4 sekunder
  digitalWrite(ledlys, HIGH);//Gir pin strøm
  motor_motstand();//Sjekker etter motstand mens porten går nedover
  delay(tid_opp_ned);//Venter i tid/8 for 2 meter, 4 sekunder
  digitalWrite(ledlys, LOW);//Kutter strøm til pin
  motor_motstand();//Sjekker etter motstand mens porten går nedover
  delay(tid_opp_ned);//Venter i tid/8 for 2 meter, 4 sekunder
  
}//Slutt led_blink_delay_ned()

//Lager led_blink_delay_opp funksjonen 
void led_blink_delay_opp() {
  
  digitalWrite(ledlys, HIGH);//Gir pin strøm
  
  delay(tid_opp_ned);//Venter i tid/8 for 2 meter, 4 sekunder
  digitalWrite(ledlys, LOW);//Kutter strøm til pin
  
  delay(tid_opp_ned);//Venter i tid/8 for 2 meter, 4 sekunder
  digitalWrite(ledlys, HIGH);//Gir pin strøm
  
  delay(tid_opp_ned);//Venter i tid/8 for 2 meter, 4 sekunder
  digitalWrite(ledlys, LOW);//Kutter strøm til pin
  
  delay(tid_opp_ned);//Venter i tid/8 for 2 meter, 4 sekunder
  digitalWrite(ledlys, HIGH);//Gir pin strøm
  
  delay(tid_opp_ned);//Venter i tid/8 for 2 meter, 4 sekunder
  digitalWrite(ledlys, LOW);//Kutter strøm til pin
  
  delay(tid_opp_ned);//Venter i tid/8 for 2 meter, 4 sekunder
  digitalWrite(ledlys, HIGH);//Gir pin strøm
  
  delay(tid_opp_ned);//Venter i tid/8 for 2 meter, 4 sekunder
  digitalWrite(ledlys, LOW);//Kutter strøm til pin
  
  delay(tid_opp_ned);//Venter i tid/8 for 2 meter, 4 sekunder
  
}//SLutt led_blink_delay_opp()

//Lager ReciveEvent funksjonen
void receiveEvent(int howMany){
  
    char c = Wire.read(); //c = informasjonen fra arduino 2
    Serial.println(c);  //Printer informasjonen i seriell overvåker
  
  //Hvis signalet er 'a':
  if (c=='a'){
    
    delay(200); //Venter i 0.2 sekunder
    //Hvis portstatus er 1:
    if(port == 1) {
  digitalWrite(lampe, HIGH); //gir lampe strøm
  digitalWrite(motor_aktiver, HIGH); //Aktiverer motorstyring
  digitalWrite(motor_opp, HIGH); //Gir strøm til motor opp
  digitalWrite(motor_ned, LOW); //kutter strøm til motor ned
  led_blink_delay_opp();//delay(tid_opp_ned); //Venter 4 sekunder
  
  blinklys = 0; //setter Blinklys status til 0
  port = 0; //Setter portstatus til 0
  digitalWrite(motor_aktiver, LOW);//deaktiverer motorstyring
  digitalWrite(motor_opp, LOW); //kutter strøm til motor opp
  digitalWrite(motor_ned, LOW);//kutter strøm til motor ned
  delay(tid_lys); //venter i variabel tid for lys til å slukke
  digitalWrite(lampe, LOW);//Slår av lampe
    
  }//Slutt IF
}//Slutt IF
  
  //Hvis signaler er 'b':
  if (c=='b'){
    
    delay(200); //Venter i 0.2 sekunder
    //Hvis portstatus er 0:
  	if(port == 0) {
  digitalWrite(lampe, HIGH); //gir lampe strøm
  digitalWrite(motor_aktiver, HIGH);//Aktiverer motorstyring
  digitalWrite(motor_opp, LOW);//kutter strøm til motor opp
  digitalWrite(motor_ned, HIGH);//Gir strøm til motor ned
  led_blink_delay_ned();//delay(tid_opp_ned); //Venter 4 sekunder
  
  port = 1;//Setter portstatus til 0
  digitalWrite(motor_aktiver, LOW);//deaktiverer motorstyring
  digitalWrite(motor_opp, LOW);//kutter strøm til motor opp
  digitalWrite(motor_ned, LOW);//kutter strøm til motor ned
  delay(tid_lys);//venter i variabel tid for lys til å slukke
  digitalWrite(lampe, LOW);//Slår av lampe
  
  }//Slutt IF
}//Slutt IF
  
  //Hvis signalet er 'c':
  if (c=='c'){
  
  digitalWrite(lampe, HIGH); //gir lampe strøm
  delay(tid_lys); //Venter 40 sekunder
  digitalWrite(lampe, LOW);//Slår av lampe
    
  }//Slutt IF
}//SLutt receiveEvent


//Lager skjerm funksjonen
void skjerm(){
  //Hvis port er åpen:
  if(port == 0){ 
  // lcd.clear(); //renser LCD
  lcd.setCursor(0,1); //Setter markøren fremst på linje 2
  lcd.print("Door open"); //printer på lcd
    
  }//Slutt IF
  
  //Port er lukker:
  else{
  lcd.setCursor(0,1); //Setter markøren fremst på linje 2
  lcd.print("Door closed");//printer på lcd
    
  }//Slutt else
}//Slutt skjerm()