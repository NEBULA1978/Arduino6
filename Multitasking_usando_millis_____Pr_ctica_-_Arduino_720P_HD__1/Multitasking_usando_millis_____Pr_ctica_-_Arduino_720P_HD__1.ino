void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(micros());
  pinMode(A5, 1);
  digitalWrite(A5, 0);
  Serial.println(micros());
}

void loop() {
  // put your main code here, to run repeatedly:
 /* unsigned long lectura = millis();
  delay(1000); 
  Serial.println(lectura);*/
}
