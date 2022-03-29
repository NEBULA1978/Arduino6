#define LED_A 3
#define LED_B 4
#define LED_C 5
#define BOTON 6
#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0


void setup() {
  // put your setup code here, to run once:
    pinMode(LED_A, OUTPUT);
    pinMode(LED_B, OUTPUT);
    pinMode(LED_C, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  loop_led_a();
  loop_led_b();
  loop_led_b();
  
}

void loop_led_a()
{
      static long ultimo_cambio = 0;
    static int Estado_LED = OFF;

    long hora = millis();

    if (hora - ultimo_cambio > 5000) {
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

    if (hora - ultimo_cambio > 2500) {
        ultimo_cambio = hora;

        if (Estado_LED == ON) {
            digitalWrite(LED_B, LOW);
            Estado_LED = OFF;
        } else {
            digitalWrite(LED_B, HIGH);
            Estado_LED = ON;
        }
    }
}

void loop_led_c()
{
  digitalWrite(LED_C,digitalRead(BOTON));
  
}
