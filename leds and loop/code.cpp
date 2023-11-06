int timer = 500;           // The higher the number, the slower the timing.
int ledPins[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};       // an array of pin numbers to which LEDs are attached
int pinCount = 10;           // the number of pins (i.e. the length of the array)

void setup() 
{
  // the array elements are numbered from 0 to (pinCount - 1).
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 0; thisPin < pinCount; thisPin++)
 {
    		pinMode(ledPins[thisPin], OUTPUT);
  	}//END for
  
}

void loop() {
 for (int i = 0; i <5 ; i++) {
    for (int j = i+1; j <10 ; j++) {
  	  digitalWrite(ledPins[i], HIGH);
      digitalWrite(ledPins[j], HIGH);
  	  delay(timer);
      digitalWrite(ledPins[i], LOW);
      digitalWrite(ledPins[j], LOW);
       delay(timer);
    }}
}//END 