#define pinLed 6
#define pinLed2 7
#define pinBtn 5
int count = 0;
int count2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT );
  pinMode(pinLed2, OUTPUT );
  pinMode(pinBtn, INPUT );// pinMode(pinBtn, INPUT_PULLUP ); si no quiero poner resitencia

  digitalWrite(pinLed, HIGH);
  delay(1000);
  digitalWrite(pinLed, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  count++;
  count2++;
  delay(10);

  lecturaBtn();

  
  if(count == 100){
   ledAzul();
  }
  if(count2 == 50){
    ledRojo();
  }
}

void lecturaBtn(){
  int lectura = digitalRead(pinBtn);
  Serial.println(lectura);
}

void ledAzul(){
  int estadoLed = digitalRead(pinLed);//lee estado led actual
   digitalWrite(pinLed, !estadoLed);//escribir estado led pero invertido si es 0 lee 1
   count = 0;//resetear a cero
}

void ledRojo(){
  int estadoLed = digitalRead(pinLed2);//lee estado led actual
   digitalWrite(pinLed2, !estadoLed);//escribir estado led pero invertido si es 0 lee 1
   count2 = 0;//resetear a cero
}
/*
 *int lectura = digitalRead(pinBtn);
  Serial.println(lectura);
  delay(100);

  
  digitalWrite(pinLed, 1);
  delay(1000);
  digitalWrite(pinLed, 0);
  delay(1000);
 */
