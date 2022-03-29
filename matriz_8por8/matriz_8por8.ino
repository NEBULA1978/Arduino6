/*Copyright (C) 2017 Iván Rodríguez Méndez*/



// Tutorial 15 - Matriz LED 8x8 

 
unsigned long tiempo = 0;
#include "LedControlMS.h" 
#define LED_A 8
#define LED_B 7
#define LED_C 6
#define BOTON 5
#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0


LedControl lc=LedControl(12,11,10,1); // Los numeros se refieren a que pin de ARDUINO tienes en cada uno de los terminales

/* 12 para el DIN, 11 para el CLK, 10 para el CS y el 1 se refiere a la asignacion de la matriz*/ 

 

void setup()

{

  // El numero que colocamos como argumento de la funcion se refiere a la direccion del decodificador

  lc.shutdown(0,false);

  lc.setIntensity(0,8);// La valores estan entre 1 y 15 

  lc.clearDisplay(0);

  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(BOTON, INPUT);//por defecto esta asi
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

  loop_led_A();
  loop_led_B();
  loop_led_C();

}


void loop_led_A()
{
  //misma variable de tiempo utiliza contador arduino
  static long ultimo_cambio = 0;//generanso variable generica de 64bits me permite tener mayo cant N enteros
  static int Estado_LED = OFF;//variableestaticavalorinicial

  long hora = millis();

  if (hora - ultimo_cambio >1000){
      ultimo_cambio = hora;

      if(Estado_LED == ON){
          digitalWrite(LED_A, LOW);
          Estado_LED = OFF;
      }else{
         digitalWrite(LED_A, HIGH);
         Estado_LED = ON ;
      }
      
  }
}

void loop_led_C()
{
  static long ultimo_cambio = 0;//generanso variable generica de 64bits me permite tener mayo cant N enteros
  static int Estado_LED = OFF;

  long hora = millis();//que hora actual

  if (hora - ultimo_cambio >250){//hora actualmenos horaultimo cambio es mayor a 1segundo
      ultimo_cambio = hora;

      Estado_LED = !Estado_LED;//si era 1 pasa a 0 
      digitalWrite(LED_C, Estado_LED);

    //  if(Estado_LED == ON){
    //      digitalWrite(LED_A, LOW);
    //      Estado_LED = OFF;
    //  }else{
   //      digitalWrite(LED_A, HIGH);
    //     Estado_LED = ON ;
   //   }
      
      }
}

void loop_led_B()
{
  digitalWrite(LED_B, digitalRead(BOTON));
}
