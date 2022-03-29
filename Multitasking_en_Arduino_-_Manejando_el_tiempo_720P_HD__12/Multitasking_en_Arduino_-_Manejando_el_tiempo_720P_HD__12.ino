#define LED_A 3
#define LED_B 4
#define LED_C 5
#define BOTON 6
#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0

void setup() {//los pines pordefecto estan cofigurados como entrada
  // put your setup code here, to run once:
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(BOTON, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  loop_led_a();
  loop_led_b();
  loop_led_c();
}

void loop_led_a()
{ 
  //variable local se queda aqui el resultado
  static long ultimo_cambio = 0;//valor de la variable se conserva entre consecutivos de la funcion
  static int Estado_LED = OFF;//variable estatica valor incial

  long hora = millis();//pregunto cuantos milisegundos pasaron desde empieza arduino
  
  if(hora -ultimo_cambio > 1000){//hora actual menos hora ultimo cambio es >que 1segundo
    ultimo_cambio = hora;

    if(Estado_LED == ON){
      digitalWrite(LED_A, LOW);
      Estado_LED = OFF;
    }else{
       digitalWrite(LED_A, HIGH);
      Estado_LED = ON;
    }
  }
}

void loop_led_b()
{
    //variable local se queda aqui el resultado
  static long ultimo_cambio = 0;//valor de la variable se conserva entre consecutivos de la funcion
  static int Estado_LED = OFF;//variable estatica valor incial

  long hora = millis();//pregunto cuantos milisegundos pasaron desde empieza arduino
  
  if(hora -ultimo_cambio > 250){//hora actual menos hora ultimo cambio es >que 1cuarto de segundo
    ultimo_cambio = hora;

    Estado_LED = !Estado_LED;//si estaba en estao 0 pasa a 1 lo opuesto
    digitalWrite(LED_B, Estado_LED);//digitalwrite va ser estado led y me aorro el if else de abajo

/*    if(Estado_LED == ON){
      digitalWrite(LED_B, LOW);
      Estado_LED = OFF;
    }else{
       digitalWrite(LED_B, HIGH);
      Estado_LED = ON;
    }*/
  }
}
void loop_led_c()
{
  digitalWrite(LED_C,digitalRead(BOTON));
}
