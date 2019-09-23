/*
  Code by:
  Syed Rafay Hashmi and M.Hashir

  This is a code that makes a pattern generator which changes colous of light and plays different tunes on buzzer

  Hardware:
  -Arduino
  -RGB light
  -buzzer

Connections:
Hold the led in your hand such that the longest pin of RGB LED is second pin from left.
Left most pin is pin 1 and right most pin is pin 4

  Connect pin 1 (red) of RGB LED to pin 3 of Arduino
  Connect pin 2 (VCC) of RGB LED to resistor and connect other end of resistor to pin 5V of Arduino
  Connect pin 3 (green) of RGB LED to pin 5 of Arduino
  Connect pin 4 (blue) of RGB LED to pin 6 of Arduino

  -Connect longer leg of buzzer to pin 11 of Arduino
  -Connect shorter leg of buzzer to GND of Arduino
*/

//Comment this line if not using Common Anode LED
#define COMMON_ANODE

int buzzer = 11;                                             //Buzzer is connected to pin11
int redPin = 3;
int greenPin = 5;
int bluePin = 6;

int melody[] = {                                              
  2000, 2000, 2000, 2000, 2000,1000,4000,3000                                 //These frequencies of sound will be played
};

int noteDurations[] = {                               
  4, 8, 8, 4, 4, 4, 4, 4                                      //Enter duration of each note or frequency
};

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void loop() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {          //Do not edit this line

    int noteDuration = 1000 / noteDurations[thisNote];        //Do not edit this line
    tone(buzzer, melody[thisNote], noteDuration);             //Do not edit this line
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
delay(5000);        //Wait before repeating
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
