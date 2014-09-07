/*
iDevice glitcher

Send specific frequencies to the mic input to play with remote control commands.



Tested on : Macbook
Not working on : iPod Touch 1G

ATtiny85 version - copy this bootloader to your boards.txt

attiny85arduinoisp.name=ATtiny85 (w/ Arduino as ISP)
attiny85arduinoisp.upload.using=arduino:arduinoisp
attiny85arduinoisp.upload.maximum_size=8192
attiny85arduinoisp.build.mcu=attiny85
attiny85arduinoisp.build.f_cpu=1000000L
attiny85arduinoisp.build.core=attiny45_85

With this bootloader tone() and random() functions works

*/


const int speaker = 0; // ATtiny pin 5

int note[8] = {12000, 12001, 12539, 12540, 12635, 12654, 13000, 13001};

int time = 50;

void setup() {
  
  pinMode(speaker, OUTPUT);
  
}

void loop() {

  
 freq(note[random(0,7)]);
 delay(random(time, 500)); 
 // delay() change the behaviour of the remote.
 // It only trigger Play / Stop if delay is too long

}

void freq(int x) {
  
  tone(speaker, x, time);
  delay(time);
  tone(speaker, x, time);
}


