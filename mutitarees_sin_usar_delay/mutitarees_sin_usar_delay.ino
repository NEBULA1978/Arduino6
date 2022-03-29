/*
Hola, soy nuevo en Arduino. :) Estoy siguiendo muchos tutoriales y tengo una duda que no puedo encontrar resolver. Espero me pueda ayudar:

Para ponerles un ejemplo facil, piense en una fontana de agua, o aguas danzantes o como le llamen en su país. Chorros de agua que tienen una secuencia y que en ocasiones son al mismo tiempo, por tanto no sirve la función delay.

Para hacerlo simple pongamos el ejemplo de 3 pines configurados como salida para 3 chorros de agua. Al presionar un boton (configurado a 1 de los pines como imput) comienza el show.

Todo el codigo de configuración inicial ya lo tengo resulto, solo no se como trabajar el concepto de MILLIS. :confused:

Hay posibilidad de alguna forma de configurar que al apretar el boton del pin input el "reloj de millis" tome el valor de cero? En en base a eso ir jugando con los HIGH y LOW de los pines de salida? Por ejemplo, llamemos a los PINES AGUA1 AGUA2 AGUA3 y que la secuencia sea:

En el segundo 0 Comienza AGUA1 por 20 segundos A SU VEZ En el segundo 5 Comienza AGUA2 por 5 segundos A SU VEZ En el segundo 10 Comienza AGUA3 por 20 segundos Y queda todo en LOW en espera a que se aprete el boton de nuevo para dar comienzo a un nuevo show.

Alguien me podría tirar esa linea de código? :) :) :) :) :)

Muy agradecido de antemano.
*/
/*
 * Enunciado: En el segundo 0 comienza agua1 por 20 segundos, a los 5 segundos
 * empieza agua 2 por 5 segundos y a los 10 segundos comienza agua3 por 20
 * segundos.
 *
 * Cuando apretemos el botón se ha de guardar el valor de millis en t y se ha 
 * de poner en marcha el circuito. Transcurrido t+5 se debe encender agua2.
 * En t+10 se debe encender agua3 y apagar agua2 (ya han transcurrido los 5
 * segundos de su funcionamiento. En t+20 será cuando ha de apagarse agua1.
 * Y en t+30 se debe apagar agua3 y detener la secuencia.
 *
 * Se pueder usar millis() > t+X para comparar tiempo, pero tendrá problemas
 * cuando millis se desborde. en cambio si haces millis()-t > X no habrá 
 * problemas y veras que es lo mismo.
 * 
 */

// https://forum.arduino.cc/index.php?topic=655306.0
// Libreria del botón.
//#include <BotonSimple.h>

// Pins de salida.
#define agua1 3
#define agua2 4
#define agua3 5

BotonSimple boton(2);  // El botón estará en el pin 2.
bool enMarcha = false; // La variable enMarcha indica el estado.
unsigned long t;       // La variable de tiempo.

void setup() {
  pinMode(agua1, OUTPUT),
  pinMode(agua2, OUTPUT);
  pinMode(agua3, OUTPUT);
}

void loop() {
  // Actualizamos el estado del botón
  boton.actualizar();
  // Este es el segundo 0, cuando apretas el botón.
  // guardas el valor de millis y se pone en marcha agua1 y la secuencia.
  if ( boton.leer() == SOLTANDOLO ) {
    t = millis();
    enMarcha = true;
    digitalWrite(agua1, HIGH);
  }

  // Solo si estamos en marcha ejecutamos la secuencia.
  if ( enMarcha ) {
    // Nota: si observas comparo desde los valores mayores de secuencia y
    // usando else. Si no lo hiciera asi, afectaría a la secuencia y por ejemplo
    // agua2 se volveria loco al pasar los 10 segundos.
    if (  millis() - t > 30000 ) {
      // Han pasado los 30 segs. con lo que hay que apagar agua3 y detener la
      // secuencia.
      digitalWrite(agua3, LOW);
      enMarcha = false;
    }
    else
    if (  millis() - t > 20000 ) {
      // Han pasado los 20 segs, desde que apretamos el boton asi que hay que
      // apagar agua1.
      digitalWrite(agua1, LOW);
    }
    else
    if ( millis() - t > 10000 ) {
      // A los 10 segs. debe ponerse en marcha agua3 y como agua2 se encendio a
      // los 5 y debe apagarse a los 5, en 10 debe pararse.
      digitalWrite(agua3, HIGH);
      digitalWrite(agua2, LOW);
    }
    else
    if ( millis() - t > 5000 ) {
      // Debe encencersea agua2.
      digitalWrite(agua2, HIGH);
    }
  }
}
