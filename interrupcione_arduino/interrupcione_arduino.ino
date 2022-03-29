//attachInterrupt interrupciones solo en pin 2 y 3 
int contador=0;
volatile int interrupcion=0;
volatile int LED=5;

void setup()
{ 
attachInterrupt (digitalPinTointerrupt(2)cuentaInterrupciones,FALLING);
Serial.begin(9600);
pinMode(LED,OUTPUT);
}

void loop(){ 
Serial.print("Contador ");
  Serial.print (contador++);
  Serial.println();
  delay(300);
}  

void cuentaInterrupciones(){

}
