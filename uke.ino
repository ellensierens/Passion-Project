/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

// aanmaken variabelen servo
//plukken snaren 
Servo pluckG;  // create servo object to control a servo
Servo pluckC;  
Servo pluckE;
Servo pluckA;

//indrukken snaren
Servo fret1;
Servo fret2;
Servo fret3;
Servo fret4;

int posG = 0;
int posA = 0;
int posE = 0;
int posC = 0;

// twelve servo objects can be created on most boards

void setup() {
  Serial.begin(9600);
  Serial.print("setup");
  // attach servos to pin
  pluckG.attach(4);
  pluckC.attach(5);
  pluckE.attach(2);  
  pluckA.attach(3);

  fret1.attach(8);
  fret2.attach(6);
  fret3.attach(9);
  fret4.attach(7);

  //setup 
  pluckA.write(0);
  delay(1000);
  pluckE.write(0);
  delay(1000);
  pluckG.write(0);
  delay(1000);
  pluckC.write(0);
  delay(1000);

  fret1.write(0);
  delay(1000);
  fret2.write(0);
  delay(1000);
  fret3.write(0);
  delay(1000);
  fret4.write(0);
  delay(1000);

}

void pluckCFunction () {
  Serial.println("pluck");
    if(posC == 0) {
      
    pluckC.write(30);
    posC = 1;
    }else

    if(posC == 1) {
    pluckC.write(0);
    posC = 0;
    }
}

void pluckGFunction () {
  Serial.println("pluck");
    if(posG == 0) {
      
    pluckG.write(30);
    posG = 1;
    }else

    if(posG == 1) {
    pluckG.write(0);
    posG = 0;
    }
}

void pluckEFunction () {
  Serial.println("pluck");
    if(posE == 0) {
      
    pluckE.write(30);
    posE = 1;
    }else

    if(posE == 1) {
    pluckE.write(0);
    posE = 0;
    }
}

void pluckAFunction () {
  Serial.println("pluck");
    if(posA == 0) {
      
    pluckA.write(30);
    posA = 1;
    }else

    if(posA == 1) {
    pluckA.write(0);
    posA = 0;
    }
}

void loop() {
  Serial.println("loop");
  delay(100);
  pluckCFunction();
  delay(100);
  pluckGFunction();
  delay(100);
  pluckEFunction();
  delay(100);
  pluckAFunction();
  delay(100);

}




