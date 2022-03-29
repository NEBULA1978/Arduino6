int ledPin=10;
int estadoled=LOW;
long tiempoanterior=0;
long intervalo=1000;//intervalo de 1segundo

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long tiempoactual=millis();
  if(tiempoactual-tiempoanterior>=intervalo){
  tiempoanterior=tiempoactual;
  if(estadoled=HIGH){
  estadoled= LOW;  
  }else {
    estadoled=HIGH;
    Serial.println(estadoled);
  }
  digitalWrite(ledPin, estadoled);
  Serial.println("ledPin, estadoled");
  }
}
