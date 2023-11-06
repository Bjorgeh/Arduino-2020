#include <IRremote.h>
//Define Pins
int rodLed = 4;
int gulLed = 3;
int orangeLed = 2;
int gronnLed = 1;
int motor = 6;
const int motorSignal = 41055;

int RECV_PIN = 5;
//IR Library stuff
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{
  //Set Led Pins
  pinMode(rodLed, OUTPUT);
  pinMode(gulLed, OUTPUT);
  pinMode(orangeLed, OUTPUT);
  pinMode(gronnLed, OUTPUT);
  pinMode(motor, OUTPUT);
  
  //Enable serial usage and IR signal in
  //Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); 
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {//irrecv.decode(&results) returns true if anything is recieved, and stores info in varible results
    unsigned int value = results.value; //Get the value of results as an unsigned int, so we can use switch case
    Serial.println(value);
    switch (value) {
      case 2295: 
      	digitalWrite(rodLed, HIGH);
      	delay(500);
      	digitalWrite(rodLed, LOW);
      	break;
      
      case 34935:
      	digitalWrite(gulLed, HIGH);
      	delay(500);
      	digitalWrite(gulLed, LOW);
      	break;
      
      case 18615:
      	digitalWrite(orangeLed, HIGH);
      	delay(500);
      	digitalWrite(orangeLed, LOW);
      	break;
      
      case 10455:
      	digitalWrite(gronnLed, HIGH);
      	delay(500);
      	digitalWrite(gronnLed, LOW);
          
      case motorSignal:
      	digitalWrite(motor, HIGH);
      	delay(500);
      	digitalWrite(motor, LOW);
    }
    
   
    
    
    irrecv.resume(); // Receive the next value
  }
}