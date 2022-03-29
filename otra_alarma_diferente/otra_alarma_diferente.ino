/**
   GeekFactory - "Construye tu propia tecnologia"
   Distribucion de materiales para el desarrollo e innovacion tecnologica
   www.geekfactory.mx

   Ejemplo de Programación de Eventos con Arduino con las librerias Time y TimeAlarms
   en este programa, la hora se configura en el inicio del arduino y solamente se utiliza el
   CPU de arduino para llevar el conteo del tiempo, en este ejemplo NO se utiliza el reloj en
   tiempo real externo.
*/

#include <Time.h>
#include <TimeAlarms.h>

void setup() {
  Serial.begin(9600);

  // Configurar la fecha / hora manualmente cada vez que se reinicia el arduino
  // Configurar al lunes 22 de agosto de 2016 a las 13:59:50
  setTime(13, 59, 50, 22, 8, 16);

  // Crear las alarmas y configurar las funciones correspondientes a cada una
  Alarm.alarmRepeat(14, 0, 0, Alarma1400);  // Evento a las 14:00 diario
  Alarm.alarmRepeat(14, 5, 0, Alarma1405);  // Evento a las 14:05 diario
  Alarm.alarmRepeat(14, 10, 0, Alarma1410);  // Evento a las 14:10 diario
}

void loop() {
  // Mostrar el reloj en el monitor serial
  digitalClockDisplay();

  // Esperar 1 segundo y procesar las Alarmas mientras tanto...
  Alarm.delay(1000);
}

void Alarma1400()
{
  Serial.println("Evento de las 14:00:00");
}

void Alarma1405()
{
  Serial.println("Evento de las 14:05:00");
}

void Alarma1410()
{
  Serial.println("Evento de las 14:10:00");
}


/**
   Funciones para la impresion del reloj al monitor serial de arduino
*/
void digitalClockDisplay() {
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println();
}

void printDigits(int digits) {
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
