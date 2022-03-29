unsigned long tiempoactual = 0;
int count = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis()>= tiempoactual + 500){
    tiempoactual = millis();
    Serial.println(count);
    count++;
    

} 
}
