int timer = 1000; // The higher the number, the slower the timing.
int ledPins[] = {1, 2, 3, 4, 5, 6}; // an array of pin numbers to which LEDs are attached
int pinCount = 6; // the number of pins (i.e. the length of the array)
void setup()
{
// the array elements are numbered from 0 to (pinCount - 1).
// use a for loop to initialize each pin as an output:
for (int thisPin = 0; thisPin < pinCount; thisPin++)
{
pinMode(ledPins[thisPin], OUTPUT);
}//END for
}//END setup
void loop() {
// loop from the lowest pin to the highest:
for (int thisPin = 0; thisPin < pinCount; thisPin++) {
// turn the pin on:
digitalWrite(ledPins[thisPin], HIGH);
delay(timer);
// turn the pin off:
digitalWrite(ledPins[thisPin], LOW);
} //END for
// loop from the highest pin to the lowest:
for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
// turn the pin on:
digitalWrite(ledPins[thisPin], HIGH);
delay(timer);
// turn the pin off:
digitalWrite(ledPins[thisPin], LOW);
}//END for
}//END loop