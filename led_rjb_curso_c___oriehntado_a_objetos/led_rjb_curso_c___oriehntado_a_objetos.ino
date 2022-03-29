//falta la mitad
const bool OFF = false;
const bool ON = true;

const byte red = 2;
const byte green = 3;
const byte blue = 4;
/*
const byte red = 2;
const byte green = 3;
const byte blue = 4;
*/
void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  digitalWrite(red, OFF);
  digitalWrite(green, OFF);
  digitalWrite(blue, OFF);

  randomSeed(analogRead(A0));

  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int redValue = random(0,2);
  int greenValue = random(0,2);
  int blueValue = random(0,2);

  digitalWrite(red, redValue);
  digitalWrite(green, greenValue);
  digitalWrite(blue, blueValue);

  delay(1000);
  
}
