//Inkluderer bibliotek for kommunikasjon
#include <Wire.h>

//inkluderer bibliotek for fjernkontroll
#include <IRremote.h>

//Definerer pin for IR mottaker
int RECV_PIN = 2;

//kobler mottakerPin til biblioteket
IRrecv irrecv(RECV_PIN);
//Dekoder IR signal fra fjernkontroll
decode_results results;

//Lager setup funksjonen
void setup(){
  
Serial.begin(9600); //Starter seriell overvåker
  Wire.begin(); //Starter kommunikasjonen
  irrecv.enableIRIn(); //Akriverer IR mottaker
  
}//Slutt setup()

//Lager loop funksjonen
void loop(){
  
  if(irrecv.decode(&results)){//Hvis mottaker får signal             
  Serial.println(results.value, HEX); //Printer signal i HEX format i seriell overvåker
    switch(results.value){
      
    case 0xFD08F7: //Hvis signalet tilsvarer "xxxxx"
        Wire.beginTransmission(4); //starter kommunikasjon
 		 Wire.write('a');        //Sender 'a' til den andre arduinoen
		  Wire.endTransmission();   //Avslutter sendingen
  delay(500);
      break; //bryt
       	
    case 0xFD8877: //Hvis signalet tilsvarer "xxxxx"
        Wire.beginTransmission(4); //starter kommunikasjon
 		 Wire.write('b');        //Sender 'b' til den andre arduinoen
		  Wire.endTransmission();   //Avslutter sendingen
  delay(500);
      break; //bryt
      
     case 0xFD48B7: //Hvis signalet tilsvarer "xxxxx"
        Wire.beginTransmission(4); //starter kommunikasjon
 		 Wire.write('c');        //Sender 'c' til den andre arduinoen
		  Wire.endTransmission();   //Avslutter sendingen
  delay(500); //Venter 0.5 sek.
      break; //bryt
    }
    irrecv.resume(); //Fortsetter å høre etter signal
  
  }//Slutt IF
  delay(100); //venter 0.1 sek

}//Slutt loop()