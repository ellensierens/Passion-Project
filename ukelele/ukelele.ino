
#include <Servo.h>

int new_splitter = -1;
int old_splitter = -1;
int counter = 0;
String parsedNotes[20];
int teller = 0;

String bpmStr;
float bpm;

bool replay;

int val;
int amountReplays;
int valPotReplay;
int tempoChange;
int valPotPitch;
int pitchChange;
int oldPitchChange;

struct String incomingNotes[] = {};

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

int offsetG = -8;
int offsetC = 31;
int offsetE = -13;
int offsetA = 6;


struct nootType
{
  String note;
  int snaar;
  int fret;
};

nootType note;

struct nootType notes[] = {{"C3", 2, 0}, {"C#3", 2, 1}, {"D3", 2, 2}, {"D#3", 2, 3}, {"E3", 3, 0}, {"F3", 3, 1}, {"F#3", 3, 2}, {"G3", 1, 0}, {"G#3", 3, 4}, {"A3", 4, 0}, {"A#3", 4, 1}, {"B3", 1, 4}, {"C4", 4, 3}, {"C#4", 4, 4}};

//test alle noten: 100;C3,C#3,D3,D#3,E3,F3,F#3,G3,G#3,A3,A#3,B3,C4,C#4,

int posG = 0;
int posA = 0;
int posE = 0;
int posC = 0;

int draaiDelay = 600;

// twelve servo objects can be created on most boards

void setup()
{

  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.print("setup");
  //setup button
  pinMode(10, INPUT);

  val = 0;
  amountReplays = 1;
  valPotReplay = 0;
  tempoChange = 0;
  valPotPitch = 0;
  pitchChange = 0;
  oldPitchChange = 0;

  replay = false;

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
  for (int i = 0; i < sizeof(notes) / sizeof(notes[0]); i++)
  {
    Serial.println("searching... " + notes[i].note + i);
    if (notes[i].note == notePlay)
    {

      Serial.println("Aha! I found it!");
      return notes[i];
    }
    else if (i == sizeof(notes) / sizeof(notes[0]) - 1)
    {
      return {notePlay, 0, 0};
    }
  }
}

void spelen(String notePlay)
{
  Serial.println("Preparing... " + notePlay);
  note = searchNote(notePlay);

  Serial.println("note to play: " + note.note + " string: " + note.snaar + " fret: " + note.fret);
  if (notePlay == "Rest")
  {
    Serial.print("resting");
    Serial.println((((1/(bpm / 60)) * 1000) - 650) + tempoChange);
    delay(draaiDelay + (((1/(bpm / 60)) * 1000) - 650) + tempoChange);
  }
  // spelen open snaren
  if (note.fret == 0)
  {
    fret1.write(0);
    fret2.write(180);
    fret3.write(0);
    fret4.write(180);
    delay(draaiDelay);
    if (note.snaar == 1)
    {
      pluckGFunction();
      delay(100);
    }
    else if (note.snaar == 2)
    {
      pluckCFunction();
      delay(100);
    }
    else if (note.snaar == 3)
    {
      pluckEFunction();
      delay(100);
    }
    else if (note.snaar == 4)
    {
      pluckAFunction();
      delay(100);
    }
  }
  else if (note.fret == 1)
  // spelen noten op fret 1
  {
    fret2.write(180);
    fret3.write(0);
    fret4.write(180);
    if (note.snaar == 1)
    {
      fret1.write(45);
      delay(draaiDelay);
      pluckGFunction();
      delay(100);
    }
    else if (note.snaar == 2)
    {
      fret1.write(90);
      delay(draaiDelay);
      pluckCFunction();
      delay(100);
    }
    else if (note.snaar == 3)
    {
      fret1.write(135);
      delay(draaiDelay);
      pluckEFunction();
      delay(100);
    }
    else if (note.snaar == 4)
    {
      fret1.write(180);
      delay(draaiDelay);
      pluckAFunction();
      delay(100);
    }
  }
  else

      if (note.fret == 2)
  {
    fret1.write(0);
    fret3.write(0);
    fret4.write(180);
    if (note.snaar == 1)
    {
      fret2.write(135);
      delay(draaiDelay);
      pluckGFunction();
      delay(100);
    }
    else if (note.snaar == 2)
    {
      fret2.write(90);
      delay(draaiDelay);
      pluckCFunction();
      delay(100);
    }
    else if (note.snaar == 3)
    {
      fret2.write(45);
      delay(draaiDelay);
      pluckEFunction();
      delay(100);
    }
    else if (note.snaar == 4)
    {
      fret2.write(0);
      delay(draaiDelay);
      pluckAFunction();
      delay(100);
    }
  }
  else

      if (note.fret == 3)
  {
    fret1.write(0);
    fret2.write(180);
    fret4.write(180);
    if (note.snaar == 1)
    {
      fret3.write(45);
      delay(draaiDelay);
      pluckGFunction();
      delay(100);
    }
    else if (note.snaar == 2)
    {
      fret3.write(90);
      delay(draaiDelay);
      pluckCFunction();
      delay(100);
    }
    else if (note.snaar == 3)
    {
      fret3.write(135);
      delay(draaiDelay);
      pluckEFunction();
      delay(100);
    }
    else if (note.snaar == 4)
    {
      fret3.write(180);
      delay(draaiDelay);
      pluckAFunction();
      delay(100);
    }
  }
  else

      if (note.fret == 4)
  {
    fret1.write(0);
    fret2.write(180);
    fret3.write(0);
    if (note.snaar == 1)
    {
      fret4.write(135);
      delay(draaiDelay);
      pluckGFunction();
      delay(100);
    }
    else if (note.snaar == 2)
    {
      fret4.write(90);
      delay(draaiDelay);
      pluckCFunction();
      delay(100);
    }
    else if (note.snaar == 3)
    {
      fret4.write(45);
      delay(draaiDelay);
      pluckEFunction();
      delay(100);
    }
    else if (note.snaar == 4)
    {
      fret4.write(0);
      delay(draaiDelay);
      pluckAFunction();
      delay(100);
    }
  }
  else
  {
    Serial.print("errorrrrrrrr does not compute!!!!!!!" + note.note);
  }
}

void pluckCFunction()
{
  Serial.println("pluck");
  if (posC == 0)
  {

    pluckC.write(107 + offsetC);
    posC = 1;
  }
  else

      if (posC == 1)
  {
    pluckC.write(93 + offsetC);
    posC = 0;
  }
}

void pluckGFunction()
{
  Serial.println("pluck");
  if (posG == 0)
  {

    pluckG.write(108 + offsetG);
    posG = 1;
  }
  else

      if (posG == 1)
  {
    pluckG.write(92 + offsetG);
    posG = 0;
  }
}

void pluckEFunction()
{
  Serial.println("pluck");
  if (posE == 0)
  {

    pluckE.write(108 + offsetE);
    posE = 1;
  }
  else

      if (posE == 1)
  {
    pluckE.write(92 + offsetE);
    posE = 0;
  }
}

void pluckAFunction()
{
  Serial.println("pluck");
  if (posA == 0)
  {

    pluckA.write(108 + offsetA);
    posA = 1;
  }
  else

      if (posA == 1)
  {
    pluckA.write(92 + offsetA);
    posA = 0;
  }
}

void loop()
{
  readSerialPort();
  val = digitalRead(10);
  if(val == HIGH){
    replay = true;
    Serial.print("button pushed");
    playReceivedNotes(pitchChange);
  }
}

String leesVanPi()
{
  String msg = "";
  if (Serial.available() > 0)
  {
    delay(1500); //wait for all data to come throug; serial continues through delay
    while (Serial.available() > 0)
    {
      msg += (char)Serial.read();
    }
    clearParsedNotes(); //clear the parsednotes array before returning new raw values
    return msg;
  }
}

int zetOmNaarArray(String omTeZetten)
{
  Serial.println("converting...");
  bool bpmSaved = false;
  bpmStr= "";
  bpm=0;
  for (int i = 0; i < omTeZetten.length(); i++)
  {

    // controleer of het een komma is
    if (omTeZetten[i] == ';')
    {
      bpmSaved = true;
    }
    else if (omTeZetten[i] == ',')
    {
      teller++;
    }
    else
    {
      if (bpmSaved == false)
      {
        bpmStr += omTeZetten[i];
      }
      else if (bpmSaved == true)
      {
        parsedNotes[teller] += omTeZetten[i];
      }
    }
  }
  for (int i = 0; i < teller; i++)
  {
    Serial.println("converted: " + parsedNotes[i]);
  }
  return teller;
}

void readSerialPort()
{
  String gelezen = "";
  gelezen = leesVanPi();
  if (gelezen != "")
  {
    Serial.println("serial: " + gelezen);
    int aantal = zetOmNaarArray(gelezen);
    bpm = bpmStr.toInt();
    Serial.print((bpm / 60) * 1000 - 600);
    playReceivedNotes(pitchChange);
  }
}

void playReceivedNotes(int pitchChange){
  Serial1.write(3);
     Serial.print("tempoChange: ");
     Serial.print((((1/(bpm / 60)) * 1000) - 650));


    if(replay == true){
           valPotReplay = analogRead(A0);
    amountReplays = map(valPotReplay, 0, 1023, 1, 10);
    
    tempoChange = analogRead(A1); 
         Serial.print("tempoChange extra: ");
     Serial.print(tempoChange);
    
    valPotPitch = analogRead(A2);
    oldPitchChange = pitchChange;
    pitchChange = map(valPotPitch, 0, 1023, 0, 12);
    replay = false;
    }else {
      amountReplays = 1;
      tempoChange = 0;
      pitchChange = 0;
    }



      Serial.print("potentios: ");
  Serial.print(valPotReplay);
  Serial.print(tempoChange);
  Serial.println(valPotPitch);

    Serial.print("pitchChange new: ");
    Serial.println(valPotPitch);

    Serial.print("extra delay: ");
    Serial.println((((1/(bpm / 60)) * 1000) - 600));

    Serial.print("bpm: ");
    Serial.println(bpm);
    
    for(int t = 0; t<amountReplays; t++){
            for (int i = 0; i < teller; i++)
    {
        for (int j = 0; j < sizeof(notes) / sizeof(notes[0]); j++){
           if(parsedNotes[i] == notes[j].note){
           int pitch = (pitchChange + j) % 14 ;
           Serial.print("note to play: ");
           Serial.println(parsedNotes[i]);
           Serial.println(notes[pitch].note);
           spelen(notes[pitch].note);
           if ((((1/(bpm / 60)) * 1000) - 650) >= 0)
           {                
           Serial.print("tempoChange: ");
           Serial.println((((1/(bpm / 60)) * 1000) - 650) + tempoChange);
            delay((((1/(bpm / 60)) * 1000) - 650) + tempoChange);
           }else {
            delay(50 + tempoChange);
           }
           break;
           
        }else if(parsedNotes[i] == "Rest"){
            spelen("Rest");
            break;
           }
      }

     }
      if(t == amountReplays-1){
      Serial.write("stop");
      Serial1.write(4);
    }
    }
     

}

void clearParsedNotes()
{
  for (int i = 0; i < teller; i++)
  {
    parsedNotes[i] = "";
  }
  teller = 0;
}
