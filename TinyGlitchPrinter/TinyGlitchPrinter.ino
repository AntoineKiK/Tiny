/*
-------------------------------------------------------------------------------

TinyGlitch Printer (ATtiny85 Trinket Derivative)
By Antoine KiK (Brigade Neurale)
http://blog.brigadeneurale.org/2014/02/04/atelier-diy-9-attiny
http://www.cargocollective.com/kik

-------------------------------------------------------------------------------

ATtiny85 test program to control a thermal printer. 
Using Adafruit's Trinket bootloader, transfered with Atmel AVR ISP mkII.

I used Trinket bootloader for the 16Mhz overclocking ans it's working really well

The thermal printer is a KYOSHA MTP640, with a L488 character generator
Didn't find anything usefull to make it print something "readable" and
since that damned thing didn't want to hear anything, I maked it glitch.

The code is really simple but it demonstrate that you can do :
- Serial communication with ATtiny
- Activate random() function of Arduino IDE - Thanks to Trinket bootloader

*/
#include <SoftwareSerial.h> // Serial communication with any pin
#include <avr/power.h> // Overclocking

SoftwareSerial mySerial(0, 1); // RX, TX
char ascii;
void setup ()
{
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1); // 16Mhz internal oscillator
  
mySerial.begin(9600); 

}
void loop() 
{

ascii = random(0,127);
mySerial.print(ascii); // Send random ASCII decimal value to the printer
}
  
  

 


