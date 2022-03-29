unsigned long tiempoactual = 0;
unsigned long tiempoactual2 = 0;
unsigned long tiempoactual3 = 0;
unsigned long tiempoactual4 = 0;
unsigned long tiempoactual5 = 0;

//primera alarma
long mitiempo;
long inicio;
long final;

//segunda alarma
long inicio2;
long final2;
long mitiempo2;


//tercera alarma
long inicio3;
long final3;
long mitiempo3;

//cuarta alarma
long inicio4;
long final4;
long mitiempo4;

//quinta alarma
long inicio5;
long final5;
long mitiempo5;

int lecturaboton_old = 1;

//poner hora a reloj
int hour = 14;
int minute = 28;
int second = 0;

//poner hora alarma1 encendido y apagado
int encendido[] = {14, 28, 30};
int apagado[] = {14, 29, 10};

//poner hora alarma2 encendido y apagado
int encendido2[] = {14, 30, 00};
int apagado2[] = {14, 31, 00};

//poner hora alarma3 encendido y apagado
int encendido3[] = {14, 31, 10};
int apagado3[] = {14, 32, 44};

//poner hora alarma4 encendido y apagado
int encendido4[] = {14, 33, 00};
int apagado4[] = {14, 33, 44};

//poner hora alarma5 encendido y apagado
int encendido5[] = {14, 34, 00};
int apagado5[] = {14, 35, 00};

void setup() {
    Serial.begin(9600);
    pinMode(6, OUTPUT);//mio6
    pinMode(7, OUTPUT);//mio7
    pinMode(5, INPUT);//mio 5

    inicio = encendido[0]*100000 + encendido[1]*1000 + encendido[2]*10;
    final = apagado[0]*100000 + apagado[1]*1000 + apagado[2]*10;

    inicio2 = encendido2[0]*100000 + encendido2[1]*1000 + encendido2[2]*10;
    final2 = apagado2[0]*100000 + apagado2[1]*1000 + apagado2[2]*10;

    inicio3 = encendido3[0]*100000 + encendido3[1]*1000 + encendido3[2]*10;
    final3 = apagado3[0]*100000 + apagado3[1]*1000 + apagado3[2]*10;

    inicio4 = encendido4[0]*100000 + encendido4[1]*1000 + encendido4[2]*10;
    final4 = apagado4[0]*100000 + apagado4[1]*1000 + apagado4[2]*10;

    inicio5 = encendido5[0]*100000 + encendido5[1]*1000 + encendido5[2]*10;
    final5 = apagado5[0]*100000 + apagado5[1]*1000 + apagado5[2]*10;
}


void loop() {
    loop2();
    loop3();
    loop4();
    loop5();
    
    int lecturaboton = digitalRead(5);

    if(lecturaboton != lecturaboton_old){
        if(lecturaboton == 0){
            int lecturaled7 = digitalRead(7);
            digitalWrite(7, !lecturaled7);
        }
    }

    lecturaboton_old = lecturaboton;

    if(millis() >= tiempoactual + 1000){
        tiempoactual = millis();
        tiempo(); 
    }


    mitiempo = hour*100000 + minute*1000 + second*10;
    //Serial.println(mitiempo);

    bool minimo = mitiempo > inicio;
    bool maximo = mitiempo < final;
    
    if( minimo && maximo ){
        if(millis() >= tiempoactual2 + 100){
            tiempoactual2 = millis();
            Serial.println("LED!");
            parpadeo();
        }
    }else{
        digitalWrite(6, 0);
    }
}


void parpadeo(){
  int lecturaled = digitalRead(6);
  digitalWrite(6, !lecturaled);
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

void loop2() {
    int lecturaboton = digitalRead(5);

    if(lecturaboton != lecturaboton_old){
        if(lecturaboton == 0){
            int lecturaled7 = digitalRead(7);
            digitalWrite(7, !lecturaled7);
        }
    }

    lecturaboton_old = lecturaboton;

    if(millis() >= tiempoactual2 + 1000){
        tiempoactual2 = millis();
        tiempo2(); 
    }


    mitiempo2 = hour*100000 + minute*1000 + second*10;
    //Serial.println(mitiempo2);

    bool minimo2 = mitiempo2 > inicio2;
    bool maximo2 = mitiempo2 < final2;
    
    if( minimo2 && maximo2 ){
        if(millis() >= tiempoactual2 + 100){
            tiempoactual2 = millis();
            Serial.println("LED!");
            parpadeo2();
        }
    }else{
        digitalWrite(6, 0);
    }
}


void parpadeo2(){
  int lecturaled = digitalRead(6);
  digitalWrite(6, !lecturaled);
}


void tiempo2(){
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
  
  /*  Serial.print(hour);
    
    Serial.print(":");
    
    Serial.print(minute);
    
    Serial.print(":");
    
    Serial.println(second);
   */ 
    
}

//tercera parte alarma 3
void loop3() {
    int lecturaboton = digitalRead(5);

    if(lecturaboton != lecturaboton_old){
        if(lecturaboton == 0){
            int lecturaled7 = digitalRead(7);
            digitalWrite(7, !lecturaled7);
        }
    }

    lecturaboton_old = lecturaboton;

    if(millis() >= tiempoactual3 + 1000){
        tiempoactual3 = millis();
        tiempo3(); 
    }


    mitiempo3 = hour*100000 + minute*1000 + second*10;
    //Serial.println(mitiempo3);

    bool minimo3 = mitiempo3 > inicio3;
    bool maximo3 = mitiempo3 < final3;
    
    if( minimo3 && maximo3 ){
        if(millis() >= tiempoactual3 + 100){
            tiempoactual3 = millis();
            Serial.println("LED!");
            parpadeo3();
        }
    }else{
        digitalWrite(6, 0);
    }
}


void parpadeo3(){
  int lecturaled = digitalRead(6);
  digitalWrite(6, !lecturaled);
}


void tiempo3(){
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
  
  /*  Serial.print(hour);
    
    Serial.print(":");
    
    Serial.print(minute);
    
    Serial.print(":");
    
    Serial.println(second);
   */ 
    
}

//cuarta parte alarma 4
void loop4() {
    int lecturaboton = digitalRead(5);

    if(lecturaboton != lecturaboton_old){
        if(lecturaboton == 0){
            int lecturaled7 = digitalRead(7);
            digitalWrite(7, !lecturaled7);
        }
    }

    lecturaboton_old = lecturaboton;

    if(millis() >= tiempoactual4 + 1000){
        tiempoactual4 = millis();
        tiempo4(); 
    }


    mitiempo4 = hour*100000 + minute*1000 + second*10;
    //Serial.println(mitiempo4);

    bool minimo4 = mitiempo4 > inicio4;
    bool maximo4 = mitiempo4 < final4;
    
    if( minimo4 && maximo4 ){
        if(millis() >= tiempoactual4 + 100){
            tiempoactual3 = millis();
            Serial.println("LED!");
            parpadeo4();
        }
    }else{
        digitalWrite(6, 0);
    }
}


void parpadeo4(){
  int lecturaled = digitalRead(6);
  digitalWrite(6, !lecturaled);
}


void tiempo4(){
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
  
  /*  Serial.print(hour);
    
    Serial.print(":");
    
    Serial.print(minute);
    
    Serial.print(":");
    
    Serial.println(second);
   */ 
    
}

//quinta parte alarma 5
void loop5() {
    int lecturaboton = digitalRead(5);

    if(lecturaboton != lecturaboton_old){
        if(lecturaboton == 0){
            int lecturaled7 = digitalRead(7);
            digitalWrite(7, !lecturaled7);
        }
    }

    lecturaboton_old = lecturaboton;

    if(millis() >= tiempoactual5 + 1000){
        tiempoactual5 = millis();
        tiempo5(); 
    }


    mitiempo5 = hour*100000 + minute*1000 + second*10;
    //Serial.println(mitiempo5);

    bool minimo5 = mitiempo5 > inicio5;
    bool maximo5 = mitiempo5 < final5;
    
    if( minimo5 && maximo5 ){
        if(millis() >= tiempoactual5 + 100){
            tiempoactual5 = millis();
            Serial.println("LED!");
            parpadeo4();
        }
    }else{
        digitalWrite(6, 0);
    }
}


void parpadeo4(){
  int lecturaled = digitalRead(6);
  digitalWrite(6, !lecturaled);
}


void tiempo4(){
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
  
  /*  Serial.print(hour);
    
    Serial.print(":");
    
    Serial.print(minute);
    
    Serial.print(":");
    
    Serial.println(second);
   */ 
    
}
