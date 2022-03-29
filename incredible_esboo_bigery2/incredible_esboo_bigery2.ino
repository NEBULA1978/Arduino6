// C++ code
//encender y apgar 1led usando 2 pulsadores con sentencias if else

int s1 = 3;
int s2 = 5;
int led= 7;
int a;
int b;

void setup()
{
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(led, OUTPUT);
}

void loop(){
  
a = digitalRead(s1);
  b = digitalRead(s2);
  
  if (a== HIGH || b == HIGH)
  {
    digitalWrite(led, HIGH);  
  } 
  
  else if (b == LOW || a== HIGH)
  {
    digitalWrite(led, LOW);
  } 
}
