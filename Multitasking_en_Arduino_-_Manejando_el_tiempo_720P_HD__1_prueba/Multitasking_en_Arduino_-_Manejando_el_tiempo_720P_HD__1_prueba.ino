#define LED_A 6
#define LED_B 7
#define LED_C 8
#define BOTON 5
#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(BOTON, INPUT);//por defecto esta asi
}

void loop() {
  // put your main code here, to run repeatedly:
  loop_led_a();
  loop_led_b();
  loop_led_c();
}

void loop_led_a()
{
  //misma variable de tiempo utiliza contador arduino
  static long ultimo_cambio = 0;//generanso variable generica de 64bits me permite tener mayo cant N enteros
  static int Estado_LED = OFF;//ver si esta encendido o apagado led

  long hora = millis();//cuantos milisegundos desde empecezo arduino

  if (hora - ultimo_cambio >100){//si la hora actual es mayor 1seg
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

void loop_led_b()
{
    //misma variable de tiempo utiliza contador arduino
  static long ultimo_cambio = 0;//generanso variable generica de 64bits me permite tener mayo cant N enteros
  static int Estado_LED = OFF;//ver si esta encendido o apagado led

  long hora = millis();//cuantos milisegundos desde empecezo arduino

  if (hora - ultimo_cambio >100){//si la hora actual es mayor 1seg
      ultimo_cambio = hora; 

      Estado_LED = !Estado_LED;
      digitalWrite(LED_B, Estado_LED); 
  }
}

void loop_led_c()
{
  digitalWrite(LED_C, digitalRead(BOTON));
}
