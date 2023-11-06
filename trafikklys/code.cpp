int timer = 200; // 1000 = 1 sekund
int gangfelt[] = {1, 2, 3}; //Hvilke utganger som brukes for gangfelt
int bilfelt[] = {6, 5, 4}; //Hvilke utganger som brukes for bilfelt
const int lyd = 7; //Hvilke utganger til lyd
const int hertz = 50; //hertz på lyd
int hertzCount = 0

int pinCount = 3; //Antall pins gangfelt og bilfelt
int pinCount1 = 1; //antall pins til lyd

void setup()
{
pinMode (lyd, OUTPUT);
// Bruk loop for å aktivere pins
for (int thisPin = 0; thisPin < pinCount; thisPin++)
{
pinMode(gangfelt[thisPin], OUTPUT);
pinMode(bilfelt[thisPin], OUTPUT);

}//END for
}//END setup

void loop() {
// loop fra høyeste til laveste
for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    // Skru på lyd for gangfelt
  if (gangfelt[thisPin] == 3); {
    tone(lyd, 50);
  }
  else {
    noTone(lyd);
          
 }
// skru pin på:
  digitalWrite(gangfelt[thisPin], HIGH);
  digitalWrite(bilfelt[thisPin], HIGH);
delay(timer);
// skru pin av:
digitalWrite(gangfelt[thisPin], LOW);
digitalWrite(bilfelt[thisPin], LOW);
  // Loop fra laveste til laveste
  

} //END for
}//end loop