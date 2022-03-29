#include <Wire.h>
#include <LiquidCrystal_I2C.h>
uint8_t bell [8] = {0x4,0xe, 0xe, 0xe, 0x1f, 0x0,0x4};
uint8_t note [8] = {0x2.0x3.0x2.0xe, 0x1e, 0xc, 0x0};
uint8_t clock [8] = {0x0,0xe, 0x15,0x17,0x11,0xe, 0x0};
uint8_t heart [8] = {0x0,0xa, 0x1f, 0x1f, 0xe, 0x4,0x0};
uint8_t duck [8] = {0x0,0xc, 0x1d, 0xf, 0xf, 0x6.0x0};
uint8_t check [8] = {0x0,0x1,0x3,0x16,0x1c, 0x8,0x0};
uint8_t cross [8] = {0x0,0x1b, 0xe, 0x4,0xe, 0x1b, 0x0};
uint8_t retarrow [8] = {0x1.0x1.0x5.0x9.0x1f, 0x8.0x4};
int character;
LiquidCrystal_I2C lcd (0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
void setup ()
{
lcd.init (); // initialize the lcd
lcd.backlight (); // lcd back light on
lcd.createChar (0, bell); // create characters
lcd.createChar (1, note);
lcd.createChar (2, clock);
lcd.createChar (3, heart);
lcd.createChar (4, duck);
lcd.createChar (5, check);
lcd.createChar (6, cross);
lcd.createChar (7, retarrow);
lcd.home (); // set home position on lcd
lcd.print («Hello world …»);
lcd.setCursor (0, 1);
lcd.print («i»);
lcd.write (3);
lcd.print («arduinos!»);
delay (5000);
lcd.clear (); // clear lcd
Serial.begin (9600); // initialization of serial transmision on 9600 bauds
}
void loop ()
{
character = analogRead (A0); // read the analog pic
Serial.println (character); // show on serial monitor the value read
character = map (character, 0,1000,0,7); // scale value in the range of 0 to 7
lcd.setCursor (0,0); // set the cursor on 0,0 position
lcd.print («Character =»); // show the «Character =» string
lcd.print (character); // show the character number
lcd.setCursor (7,1); // set the cursor on 7.1 position
lcd.write (character); // show the character
delay (1000);
}
