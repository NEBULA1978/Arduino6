//minuto 39.52 Multitasking usando millis()   Práctica - Arduino(720P_HD)_1
//minuto 56.18 Multitasking usando millis()   Práctica - Arduino(720P_HD)_1
unsigned long tiempoactual = 0;
unsigned long tiempoactual2 = 0;
int lecturaboton_old = 0;

int second = 56;
int minute = 32;
int hour = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(5, INPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lecturaboton = digitalRead(5);
 // Serial.println(lecturaboton);


  if(lecturaboton != lecturaboton_old){
      if(lecturaboton == 0){
          int lecturaled7 = digitalRead(7);
          digitalWrite(7, !lecturaled7);
      }
      

   } 
  //return; para comprobar que va bien el pulsador  : me da 1 si pulso 0
  
  lecturaboton_old = lecturaboton;

  
  if(millis()>= tiempoactual + 1000){
    tiempoactual = millis();
    tiempo();
    parpadeo();
    }
  if(millis()>= tiempoactual2 + 100){
      tiempoactual2 = millis();
      parpadeo();
    
    }
}

void parpadeo(){
  int lecturaled = digitalRead(6);
  digitalWrite(6,!lecturaled); //si ecribo un 0 me pone un 1 on y al reves anterior
}

void tiempo(){
      second++;
    if(second == 60){
       second = 0;
       minute++;
    }
    
    
    if(minute == 60){
      minute = 0;
      hour++;
    }
    if(hour == 24){
      hour = 0;
    }
    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.println(second);
} 
