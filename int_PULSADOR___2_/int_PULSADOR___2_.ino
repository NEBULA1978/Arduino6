//bloque1
int PULSADOR = 2;
int LED = 3;
int ESTADO = LOW; 

//bloque2
int PULSADOR2 = 4;
int LED2 = 5;
int ESTADO2 = LOW; 

//bloque3
int PULSADOR3 = 6;
int LED3 = 7;
int ESTADO3 = LOW;

void setup() {
  //bloque1
  pinMode(PULSADOR, INPUT); // pin 2 entrada
  pinMode(LED, OUTPUT); // pin 3 salida

 //bloque2
  pinMode(PULSADOR2, INPUT); // pin 4 entrada
  pinMode(LED2, OUTPUT); // pin 5 salida

  //bloque3
  pinMode(PULSADOR3, INPUT); // pin 6 entrada
  pinMode(LED3, OUTPUT); // pin 7 salida
}

void loop () {
  loop1 ();
  loop2 ();
  loop3 ();
}

void loop1 () {
  while(digitalRead(PULSADOR) == LOW){ } // espero a que el pulsador se presione
  ESTADO = digitalRead(LED);       // leo estado del LED
  digitalWrite(LED, !ESTADO);      // escribo valor contrario
  while (digitalRead (PULSADOR) == HIGH){ } // antirebote
}

//bloque2
void loop2 () {
  while(digitalRead(PULSADOR2) == LOW){ } // espero a que el pulsador se presione
  ESTADO2 = digitalRead(LED2);       // leo estado del LED2
  digitalWrite(LED2, !ESTADO2);      // escribo valor contrario
  while (digitalRead (PULSADOR2) == HIGH){ } // antirebote
}


//bloque3
void loop3 () {
  while(digitalRead(PULSADOR3) == LOW){ } // espero a que el pulsador se presione
  ESTADO3 = digitalRead(LED3);       // leo estado del LED3
  digitalWrite(LED3, !ESTADO3);      // escribo valor contrario
  while (digitalRead (PULSADOR3) == HIGH){ } // antirebote
}
