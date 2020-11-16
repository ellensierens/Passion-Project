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
Servo pluckG; // create servo object to control a servo
Servo pluckC;
Servo pluckE;
Servo pluckA;

//indrukken snaren
Servo fret1;
Servo fret2;
Servo fret3;
Servo fret4;

int offsetG = -10;
int offsetC = 7;
int offsetE = 10;
int offsetA = -4;

//opvullen notes array {noot, snaar nr, fret nr}
//int notes[17][3] = {{A, 4, 0}, {B, 1, 4}, {"C", 2, 0}, {"D", 2, 2}, {"E", 3, 0}, {"F", 3, 1}, {"G", 1, 0}, {"Ab", 3, 4}, {"A#", 4, 1}, {"Bb", 4, 1}, {"C#", 4, 4}, {"Db", 4, 4}, {"D#", 2, 3}, {"Eb", 2, 3}, {"F#", 3, 2}, {"Gb", 3, 2}, {"G#", 3, 4}};
struct nootType
{
  String note;
  int snaar;
  int fret;
};

nootType note;

struct nootType notes[] = {{"A", 4, 0}, {"B", 1, 4}, {"C", 2, 0}, {"D", 2, 2}, {"E", 3, 0}, {"F", 3, 1}, {"G", 1, 0}, {"Ab", 3, 4}, {"A#", 4, 1}, {"Bb", 4, 1}, {"C#", 4, 4}, {"Db", 4, 4}, {"D#", 2, 3}, {"Eb", 2, 3}, {"F#", 3, 2}, {"Gb", 3, 2}, {"G#", 3, 4}};

int posG = 0;
int posA = 0;
int posE = 0;
int posC = 0;

// twelve servo objects can be created on most boards

void setup()
{

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
  pluckA.write(90 + offsetA);
  delay(1000);
  pluckE.write(90 + offsetE);
  delay(1000);
  pluckG.write(90 + offsetG);
  delay(1000);
  pluckC.write(90 + offsetC);
  delay(1000);

  fret1.write(0);
  delay(1000);
  fret2.write(180);
  delay(1000);
  fret3.write(0);
  delay(1000);
  fret4.write(180);
  delay(1000);
}

nootType searchNote(String notePlay)
{
  //Serial.print(sizeof (notes)/ sizeof (notes[0]));
  for (int i = 0; i < sizeof(notes) / sizeof(notes[0]); i++)
  {
    //Serial.print(typeof(notes[i]))
    if (notes[i].note == notePlay)
    {
      return notes[i];
    }
  }
}

void play(String notePlay)
{

  note = searchNote(notePlay);
  Serial.print(note.note);
  if (note.fret == 0)
  {
    if (note.snaar == 1)
    {
      fret1.write(0);
      pluckGFunction();
    }
    else if (note.snaar == 2)
    {
      fret2.write(180);
      pluckCFunction();
    }
    else if (note.snaar == 3)
    {
      fret3.write(0);
      pluckEFunction();
    }
    else if (note.snaar == 4)
    {
      fret4.write(180);
      pluckAFunction();
    }
  }
  else

      if (note.fret == 1)
  {
    if (note.snaar == 1)
    {
      fret1.write(45);
      pluckGFunction();
    }
    else if (note.snaar == 2)
    {
      fret2.write(90);
      pluckCFunction();
    }
    else if (note.snaar == 3)
    {
      fret3.write(135);
      pluckEFunction();
    }
    else if (note.snaar == 4)
    {
      fret4.write(180);
      pluckAFunction();
    }
  }
  else

      if (note.fret == 2)
  {
    if (note.snaar == 1)
    {
      fret1.write(135);
      pluckGFunction();
    }
    else if (note.snaar == 2)
    {
      fret2.write(90);
      pluckCFunction();
    }
    else if (note.snaar == 3)
    {
      fret3.write(45);
      pluckEFunction();
    }
    else if (note.snaar == 4)
    {
      fret4.write(0);
      pluckAFunction();
    }
  }
  else

      if (note.fret == 3)
  {
    if (note.snaar == 1)
    {
      fret1.write(45);
      pluckGFunction();
    }
    else if (note.snaar == 2)
    {
      fret2.write(90);
      pluckCFunction();
    }
    else if (note.snaar == 3)
    {
      fret3.write(135);
      pluckEFunction();
    }
    else if (note.snaar == 4)
    {
      fret4.write(180);
      pluckAFunction();
    }
  }
  else

      if (note.fret == 4)
  {
    if (note.snaar == 1)
    {
      fret1.write(135);
      pluckGFunction();
    }
    else if (note.snaar == 2)
    {
      fret2.write(90);
      pluckCFunction();
    }
    else if (note.snaar == 3)
    {
      fret3.write(45);
      pluckEFunction();
    }
    else if (note.snaar == 4)
    {
      fret4.write(0);
      pluckAFunction();
    }
  }
}

void pluckCFunction()
{
  Serial.println("pluck");
  if (posC == 0)
  {

    pluckC.write(117 + offsetC);
    posC = 1;
  }
  else

      if (posC == 1)
  {
    pluckC.write(88 + offsetC);
    posC = 0;
  }
}

void pluckGFunction()
{
  Serial.println("pluck");
  if (posG == 0)
  {

    pluckG.write(117 + offsetG);
    posG = 1;
  }
  else

      if (posG == 1)
  {
    pluckG.write(88 + offsetG);
    posG = 0;
  }
}

void pluckEFunction()
{
  Serial.println("pluck");
  if (posE == 0)
  {

    pluckE.write(117 + offsetE);
    posE = 1;
  }
  else

      if (posE == 1)
  {
    pluckE.write(88 + offsetE);
    posE = 0;
  }
}

void pluckAFunction()
{
  Serial.println("pluck");
  if (posA == 0)
  {

    pluckA.write(117 + offsetA);
    posA = 1;
  }
  else

      if (posA == 1)
  {
    pluckA.write(88 + offsetA);
    posA = 0;
  }
}

void loop()
{
  delay(1000);
  play("A");
  delay(1000);
  play("G");
  delay(1000);
  play("C");
  delay(1000);
  play("E");
  delay(1000);
  play("D");
  delay(1000);
  play("F");
  delay(1000);
  play("D#");
}
