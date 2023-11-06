//Legger til bibliotek for Keypad
#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {A5, A4, A3, A2};
byte colPins[COLS] = {13, 0, A0, A1};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

//Legger til LCD biblioteket med pins avsatt til komponenten
#include <LiquidCrystal.h>
LiquidCrystal lcd(6, 5, 4, 3, 2, 1);

#include <Servo.h>

//Pins til lys
const int lysRodPin = 7;
const int lysGulPin = 8;
const int lysGronnPin = 9;

//pins til lyd
const int lydPin = 10;
//Variabel for lyd hertz
int lydHertz = 3000;

//pins til motor
const int motorPin = 12;

//pins til knapp
const int knappPin = 11;
//Variabel for knappstatus 1/0, true/false, high,low
int knappStatus = 0;

//Variabel til kodelås, 1337 er standard
int passord = 1337;
//Variabel for å sjekke om kode er riktig
int passordSjekk = 0;
int trykkeTeller = 0;
const int maxTrykk = 4;

//Starter Setup funksjonen
void setup() {
  //Setter pins til OUTPUT
  pinMode(lysRodPin, OUTPUT);
  pinMode(lysGulPin, OUTPUT);
  pinMode(lysGronnPin, OUTPUT);
  pinMode(lydPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  
  //Setter pins til INPUT
  pinMode(knappPin, INPUT);
  
  //Starter Startskjerm Funksjonen
  startSkjerm();
  
  //Serial.begin(9600); //Gjør LCDoutput korrupt pga serialpins

}// Slutt Setup

//Sarter loop
void loop() {
  input();
  resetKnapp();
}//slutt loop

//Starter startskjermfunksjon
void startSkjerm() {
  trykkeTeller = 0;
  char customKey = '#';
  lcd.begin(16, 2); //Starter LCD med 16 tegn & 2 linjer
  lcd.setCursor(5,0);
  lcd.print("LOCKED");
  lcd.setCursor(0,1);
  lcd.print("Press * for code");
  digitalWrite(lysRodPin, HIGH);
}// Slutt Startskjerm

//Starter funksjon til restartknappen
void resetKnapp() {
knappStatus = digitalRead(knappPin);
  if(knappStatus == HIGH) {
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Restarting");
  lcd.setCursor(6,1);
  lcd.print("*");
  digitalWrite(lysGulPin, HIGH);
  tone(lydPin, lydHertz);
  delay(100);
  noTone(lydPin);
  delay(500);
  digitalWrite(lysGulPin, LOW);
  delay(500);
  lcd.setCursor(6,1);
  lcd.print("**");
  digitalWrite(lysGulPin, HIGH);
  tone(lydPin, lydHertz);
  delay(100);
  noTone(lydPin);
  delay(500);
  digitalWrite(lysGulPin, LOW);
  delay(500);
  lcd.setCursor(6,1);
  lcd.print("***");
  digitalWrite(lysGulPin, HIGH);
  tone(lydPin, lydHertz);
  delay(100);
  noTone(lydPin);
  delay(500);
  digitalWrite(lysGulPin, LOW);
  delay(500);
  lcd.setCursor(6,1);
  lcd.print("****");
  digitalWrite(lysGulPin, HIGH);
  tone(lydPin, lydHertz);
  delay(100);
  noTone(lydPin);
  delay(500);
  digitalWrite(lysGulPin, LOW);
  delay(500);
  lcd.clear();
  trykkeTeller = 0;
  setup();
  }
  else {
  digitalWrite(lysGulPin, LOW);
  }
}// Slutt Resetknapp

void skrivKode() {
 while(trykkeTeller != maxTrykk){
  resetKnapp();
  char customKey = customKeypad.getKey();
  if (customKey) {
  lcd.setCursor(6,1);
  lcd.print("*");
  trykkeTeller++;
    }
  if(trykkeTeller == 2) {
  lcd.setCursor(6,1);
  lcd.print("**");
   }
  if(trykkeTeller == 3) {
  lcd.setCursor(6,1);
  lcd.print("***");
   }
  if(trykkeTeller == 4) {
  lcd.setCursor(6,1);
  lcd.print("****");
  delay(750);
  trykkeTeller = 0;
  setup();
   }
 }// slutt while
}//slutt skrivKode
void input(){
char customKey = customKeypad.getKey();
  if(customKey == '*') {
  tone(lydPin, 750);
  delay(10);
  noTone(lydPin);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Enter Code");
  lcd.setCursor(5,1);
  lcd.print("#");
  skrivKode();
  }  
  if(customKey == '1') {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Invalid input");
  delay(750);
  setup();
  }
    if(customKey == '2') {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Invalid input");
  delay(750);
      setup();
  }
    if(customKey == '3') {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Invalid input");
  delay(750);
      setup();
  }
    if(customKey == '4') {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Invalid input");
  delay(750);
      setup();
  }
    if(customKey == '5') {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Invalid input");
  delay(750); 
      setup();
  }
    if(customKey == '6') {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Invalid input");
  delay(750); 
      setup();
  }
    if(customKey == '7') {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Invalid input");
  delay(750); 
      setup();
  }
    if(customKey == '8') {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Invalid input");
  delay(750); 
      setup();
  }
    if(customKey == '9') {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Invalid input");
  delay(750);
      setup();
  }
    if(customKey == '0') {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Invalid input");
  delay(750); 
      setup();
  }
    if(customKey == '#') {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Invalid input");
  delay(750);
      setup();
  }
    if(customKey == 'A') {
  lcd.clear();
  lcd.setCursor(1,0);;
  lcd.print("Invalid input");
  delay(750);
      setup();
  }
    if(customKey == 'B') {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Invalid input");
  delay(750);
      setup();
  }
    if(customKey == 'C') {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Invalid input");
  delay(750);
      setup();
  }
    if(customKey == 'D') {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Invalid input");
  delay(750);
      setup();
  }
} //slutt input