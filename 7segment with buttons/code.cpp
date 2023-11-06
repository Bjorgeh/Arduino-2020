int samlet = 0; //sum av knapper trykket
int klikkTeller = 0; //teller for antall trykk
int knappStatus1 = 0; //Høy eller lav status på knapp 1
int knappStatus2 = 0; //Høy eller lav status på knapp 2
int knappStatus3 = 0; //Høy eller lav status på knapp 3
int knappStatus4 = 0; //Høy eller lav status på knapp 4
const int knappPin1 = A1; //Pin til knapp 1
const int knappPin2 = A2; //Pin til knapp 2
const int knappPin3 = A3; //Pin til knapp 3
const int knappPin4 = A4; //Pin til knapp 4

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  
}

void loop() {
  knappStatus1 = digitalRead(knappPin1);
  knappStatus2 = digitalRead(knappPin2);
  knappStatus3 = digitalRead(knappPin3);
  knappStatus4 = digitalRead(knappPin4);
  
  if (klikkTeller == 0) {
    ingenlys();
    //end if
    }
  if(knappStatus1 == HIGH) {
    klikkTeller +=1;
    delay(200);
    Serial.print("Klikkteller =");
    Serial.println(klikkTeller);
    plusser();
    //end if
    }
  else if (knappStatus2 == HIGH) {
    klikkTeller +=2;
    delay(200);
    Serial.print("Klikkteller =");
    Serial.println(klikkTeller);    
    plusser();
    //end else if
    }
  else if (knappStatus3 == HIGH) {
    klikkTeller +=4;
    delay(200);
    Serial.print("Klikkteller =");
    Serial.println(klikkTeller);    
    plusser();
    //end else if
    }
  else if (knappStatus4 == HIGH) {
    klikkTeller +=8;
    delay(200);
    Serial.print("Klikkteller =");
    Serial.println(klikkTeller);      
    plusser();
    //end else if
    }
//end loop
}
void plusser() {
  if (klikkTeller == 0) {
    ingenlys();
    }
  if (klikkTeller == 1) {
    en();
  }
  if (klikkTeller == 2) {
    to();
  }
  if (klikkTeller == 3) {
    tre();
  }
  if (klikkTeller == 4) {
    fire();
    }
  if (klikkTeller == 5) {
    fem();
    }
  if (klikkTeller == 6) {
    seks();
    }
  if (klikkTeller == 7) {
    syv();
    }
  if (klikkTeller == 8) {
    atte();
    }
  if (klikkTeller == 9) {
    ni();
    }
  if (klikkTeller == 10) {
    aaa();
    }
  if (klikkTeller == 11) {
    bbb();
    }
  if (klikkTeller == 12) {
    ccc();
    }
  if (klikkTeller == 13) {
    ddd();
    }
  if (klikkTeller == 14) {
    eee();
    }
  if (klikkTeller == 15) {
    fff();
    }
  if (klikkTeller >= 16) {
    klikkTeller = 0;
    }
}
void ingenlys() {
  //slår av alle segmenter
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  }
void Nul() {
  //viser 0 på displayet
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
}
void en() {
  //viser 1 på displayet
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
}
void to() {
  //viser 2 på displayet
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
}
void tre() {
  //viser 3 på displayet
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
}
void fire() {
  //viser 4 på displayet
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
}
void fem() {
  //viser 5 på displayet
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
}
void seks() {
  //viser 6 på displayet
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
}
void syv() {
  //viser 7 på displayet
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
}
void atte() {
  //viser 8 på displayet
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
}
void ni() {
  //viser 9 på displayet
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
}
void aaa() {
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
}
void bbb() {
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
}
void ccc() {
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
}
void ddd() {
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
}
void eee() {
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
}
void fff() {
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
}