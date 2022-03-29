void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Empezamos¡¡");}
   int a =1;
   int b=3;
  
void loop() {
  // put your main code here, to run repeatedly:
  funcion_ejemplo(a++,b);
  delay(1000);}

  void funcion_ejemplo(int x, int y){
    if(x>0){// si x es mayor que cero imprime sino else
      Serial.println(2*y);
    }
    else{
      Serial.print(y);
    }
}
