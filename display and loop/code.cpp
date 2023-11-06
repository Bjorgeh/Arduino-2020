// inkluder lib
#include <LiquidCrystal.h>

// start lib for pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // plassering av tekst
  lcd.begin(16, 2);
  // Print på lcd
  lcd.print("Ostepop?");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
 