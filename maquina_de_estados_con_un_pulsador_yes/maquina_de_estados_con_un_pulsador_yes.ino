int led = 7;
int pulsador = 2;
bool encendido = false;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(led, INPUT);

}

void loop() {
  if(digitalRead(pulsador)==HIGH){
    encendido = not(encendido);
  }
  delay(400);
  if(encendido == true){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led,LOW);
  }

}
