int juego = 0;
#define LED_A 8
#define LED_B 7
#define LED_C 6
#define LED_D 1
#define LED_E 2
#define LED_F 3
#define LED_G 4
#define BOTON 5
#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0
int x = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(LED_D, OUTPUT);
  pinMode(LED_E, OUTPUT);
  pinMode(LED_F, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(BOTON, INPUT);//por defecto esta asi
  if(x == 0){
    Serial.println("Se cumple");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  loop_led_a();
  loop_led_b();
  loop_led_c();
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  delay(100);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  delay(100);
}

void loop_led_a()
{
  //misma variable de tiempo utiliza contador arduino
  static long ultimo_cambio = 0;//generanso variable generica de 64bits me permite tener mayo cant N enteros
  static int Estado_LED = OFF;

  long hora = millis();
  Serial.println(Estado_LED);

  if (hora - ultimo_cambio >100){
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
  static long ultimo_cambio = 0;//generanso variable generica de 64bits me permite tener mayo cant N enteros
  static int Estado_LED = OFF;

  long hora = millis();

  if (hora - ultimo_cambio >100){
      ultimo_cambio = hora;
//asi como dos formas de hacerlo mismo abajo
      Estado_LED = !Estado_LED;
      digitalWrite(LED_B, Estado_LED);

    //  if(Estado_LED == ON){
    //      digitalWrite(LED_B, LOW);
    //      Estado_LED = OFF;
    //  }else{
   //      digitalWrite(LED_B, HIGH);
    //     Estado_LED = ON ;
   //   }
      
      }
}

void loop_led_c()
{
  
  digitalWrite(LED_C, digitalRead(BOTON));
}
