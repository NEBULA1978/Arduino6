const int LED =13;

//prototipos de las funciones
void alerta(int led);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  alerta(LED);//llamada a la funcion
  delay(3000);//se ejecute cada 3segundos
}

//implementacion delas funciones

//Alerta: hace parpadear un led 3veces
void alerta(int LED){
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
  
}
