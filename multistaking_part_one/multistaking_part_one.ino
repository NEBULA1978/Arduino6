unsigned long previusMillis = 0;
long interval = 1000;//cantidad de tiempo a la tarea para que se cumpla la tarea,si es muy grande unsigned long 
unsigned long currentMillis = 0;
void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  
  if ((currentMillis - previousMillis) >= interval)
  {
    previousMillis = currentMillis;
    //tarea
  }
}
