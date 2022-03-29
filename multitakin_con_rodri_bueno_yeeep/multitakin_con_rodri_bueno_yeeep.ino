#define LED_A 3
#define LED_B 4
#define LED_C 5
#define LED_D 7
#define LED_E 20
#define LED_F 19
#define LED_G 18

#define LED_H 14
#define LED_I 15
#define LED_J 21

#define BOTON 6
#define BOTON2 8
#define BOTON3 17
#define BOTON4 16

#define BOTON5 11
#define BOTON6 10
#define BOTON7 9

#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0

//otra forma milis
unsigned long tiempo = 0;
unsigned long tiempo1 = 0;
unsigned long tiempo2 = 0;

int diferencia1=1000;
int diferencia2=500;

boolean estado1=false;
boolean estado2=false;

void setup()
{
    pinMode(LED_A, OUTPUT);
    pinMode(LED_B, OUTPUT);
    pinMode(LED_C, OUTPUT);

    //otra forma milis
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT); 
    Serial.begin(9600);
}

void loop()
{
    loop_led_a();
    loop_led_b();
    loop_led_c();
    loop1();
    loop_led_d();
    loop_led_e();
    loop_led_f();
    loop_led_g();
    loop_led_h();
    loop_led_i();
    loop_led_j();
}

void loop_led_a()
{
    static long ultimo_cambio = 0;
    static int Estado_LED = OFF;

    long hora = millis();

    if (hora - ultimo_cambio > 1000) {
        ultimo_cambio = hora;

        if (Estado_LED == ON) {
            digitalWrite(LED_A, LOW);
            Estado_LED = OFF;
        } else {
            digitalWrite(LED_A, HIGH);
            Estado_LED = ON;
        }
    }
}

void loop_led_b()
{
    static long ultimo_cambio = 0;
    static int Estado_LED = OFF;

    long hora = millis();

    if (hora - ultimo_cambio > 250) {
        ultimo_cambio = hora;

        Estado_LED = !Estado_LED;
        digitalWrite(LED_B, Estado_LED);
    }
}

void loop_led_c()
{
    digitalWrite(LED_C, digitalRead(BOTON));
}

void loop_led_d()
{
    digitalWrite(LED_D, digitalRead(BOTON2));
}

void loop_led_e()
{
    static long ultimo_cambio = 0;
    static int Estado_LED = OFF;

    long hora = millis();

    if (hora - ultimo_cambio > 250) {
        ultimo_cambio = hora;

        Estado_LED = !Estado_LED;
        digitalWrite(LED_E, Estado_LED);
    }
}

void loop_led_f()
{
    digitalWrite(LED_F, digitalRead(BOTON3));
}

void loop_led_g()
{
    digitalWrite(LED_G, digitalRead(BOTON4));
}

void loop_led_h()
{
    digitalWrite(LED_H, digitalRead(BOTON5));
}

void loop_led_i()
{
    digitalWrite(LED_I, digitalRead(BOTON6));
}

void loop_led_j()
{
    digitalWrite(LED_J, digitalRead(BOTON7));
}

//otra forma con milisegundos yep

void loop1()
{
  tiempo = millis();
  
  if(tiempo >= (tiempo1+diferencia1))
  {
    tiempo1=tiempo;
    estado1 = !estado1;
    digitalWrite(13,estado1);
  }
  
  if(tiempo >= (tiempo2+diferencia2))
  {
    tiempo2=tiempo;
    estado2 = !estado2;
    digitalWrite(12,estado2);
  }
}
