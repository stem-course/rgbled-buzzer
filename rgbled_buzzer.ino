/*
  Code by: www.munphurid.com
  Syed Rafay Hashmi

  This is a code that makes a pattern generator which changes colous of light and different tunes on buzzer

  Hardware:
  -Arduino
  -RGB light
  -buzzer

  Connections:

  -Connect +ve of buzzer to pin 11 of Arduino
  -Connect -ve of buzzer to GND of Arduino

  Connect redpin of RGB to pin 3 of Arduino
  Connect greenpin of RGB to pin 5 of Arduino
  Connect bluepin of RGB to pin 6 of Arduino
*/

int buzzer = 11;                                             //Buzzer is connected to pin11
int redPin = 3;
int greenPin = 5;
int bluePin = 6;
//#include "pitches.h"

int melody[] = {                                              // notes in the melody
  2000, 2000, 2000, 2000, 2000                                 //Enter notes or frequencies here
};

int noteDurations[] = {                                       // note durations: 4 = quarter note, 8 = eighth note, etc.:
  4, 8, 8, 4, 4, 4, 4, 4                                      //Enter duration of each note or frequency
};

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void loop() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {          // iterate over the notes of the melody:

    // to calculate the note duration, take one second
    // divided by the note type.
    int noteDuration = 1000 / noteDurations[thisNote];        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    tone(buzzer, melody[thisNote], noteDuration);
    switch (thisNote) {
      case 0:
        setColor(150, 0, 255);
        break;
      case 1:
        setColor(255, 0, 0);              // red
        break;
      case 2:
        setColor(0, 255, 0);              // green
        break;
      case 3:
        setColor(0, 0, 255);              // blue
        break;
      case 4:
        setColor(255, 255, 0);            // yellow
        break;
      case 5:
        setColor(80, 0, 80);              // purple
        break;
      case 6:
        setColor(0, 255, 255);            // aqua
        break;
      case 7:
        setColor(0, 80, 255);             // aqua
        break;
    }


    int pauseBetweenNotes = noteDuration * 1.30;              // to distinguish the notes, set a minimum time between them.
    delay(pauseBetweenNotes);                                 // the note's duration + 30% seems to work well:
    noTone(buzzer);                                           // stop the tone playing:
    delay(10);
  }
  // no need to repeat the melody.
}
void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
#endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
