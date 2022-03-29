//multitareas usando funciones para varias multitareas
int Delay=1000;
int inc=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void led6(){//variable global que va estar enmarcada 1segundo
  delay(Delay);
  inc=inc+1;
  if(inc==10){//esta funcion linea anterior la que esta aqui entre llaves
  digitalWrite(6, 1);
  delay(100);
  digitalWrite(6, 0);
  delay(100);
  inc=0; 
}}
void led7(){
  digitalWrite(7, 1);
  delay(100);
  digitalWrite(7, 0);
  delay(100); 
}
void led8(){
  digitalWrite(8, 1);
  delay(100);
  digitalWrite(8, 0);
  delay(100); 
}
void loop() {
  // put your main code here, to run repeatedly:
  led6();
  led7();
  led8();
}
