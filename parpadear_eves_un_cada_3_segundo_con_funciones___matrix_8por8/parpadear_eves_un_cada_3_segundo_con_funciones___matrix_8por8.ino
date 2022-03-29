/*Copyright (C) 2017 Iván Rodríguez Méndez*/
const int LED =13;

//prototipos de las funciones
void alerta(int led);


// Tutorial 15 - Matriz LED 8x8 

 
unsigned long tiempo = 0;
#include "LedControlMS.h" 



LedControl lc=LedControl(12,11,10,1); // Los numeros se refieren a que pin de ARDUINO tienes en cada uno de los terminales

/* 12 para el DIN, 11 para el CLK, 10 para el CS y el 1 se refiere a la asignacion de la matriz*/ 

 

void setup()

{

  // El numero que colocamos como argumento de la funcion se refiere a la direccion del decodificador

  lc.shutdown(0,false);

  lc.setIntensity(0,8);// La valores estan entre 1 y 15 

  lc.clearDisplay(0);
  pinMode(LED,OUTPUT);


}




  


void loop()

 


{

  for (int row=0; row<8; row++)
  

  {

    for (int col=0; col<8; col++)

    {

      lc.setLed(0,col,row,true); // 

      tiempo = millis();

    }

  }

 

  for (int row=0; row<8; row++)

  {

    for (int col=0; col<8; col++)

    {

      lc.setLed(0,col,row,false); // 

      tiempo = millis();

    }

  }

  tiempo = millis();

  lc.writeString(0,"Piensa 3D");

  tiempo = millis();

  alerta(LED);//llamada a la funcion
  delay(3000);//se ejecute cada 3segundos


}

//Alerta: hace parpadear un led 3veces
void alerta(int LED){
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
  
}
