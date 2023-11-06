int i=0; 

const int buzzer = 1; 

void setup() { 

pinMode(buzzer, OUTPUT); 

} //end setup 

void loop() { 

  i++; 

  if (i%5==0){  //modulodivisjon, rest = 0 ? 

  tone(buzzer,200);} 

  else 

  {tone(buzzer,200);} 

 delay(300); 

} 