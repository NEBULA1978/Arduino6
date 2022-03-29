const int LED =13;
const int PULSADOR = 7;
int valor=0;//almacena el estado del boton
int estado = 0;
int antiguo_valor= 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(PULSADOR,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valor= digitalRead(PULSADOR);//se actuvo el boton,valor =HIGH,se guarda en valor la lectura
  if((valor == HIGH) &&(antiguo_valor == LOW)){
    estado=1-estado;
    delay(10);
  }
  antiguo_valor = valor;//antiguo_valor=HIGH
  if (estado==1){
    digitalWrite(LED, HIGH);//el pin 13 donde esta el led,se pone en HIGH
  }
  else{
    digitalWrite(LED, LOW);
  }
}
