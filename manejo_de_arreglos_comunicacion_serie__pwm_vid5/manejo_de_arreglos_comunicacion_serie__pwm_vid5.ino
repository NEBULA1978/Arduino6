//fotocelula pwm

int leds[]={9,10,11};
int tiempo=200;
int i = 0;
int foto=1;
int medida=0;
int luzled=0;

void setup() {//llave del main
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(i=0;i<3;i++)//configuro pines 9,10,1 
  {
    pinMode(leds[i], OUTPUT);// como salidas
    delay(tiempo);
  }
}//cierre del main

void loop() {
  // put your main code here, to run repeatedly:
  medida = analogRead(foto);//A0
  Serial.println(medida);
  luzled = 255-(medida/4);
  Serial.print(luzled);
  for(i=0;i<3;i++)
  {
    analogWrite(leds[i],luzled);
  }
}
