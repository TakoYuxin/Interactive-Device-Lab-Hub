#include "pitches.h"

int led = 13; // led that we will toggle
char inChar;  // character we will use for messages from the RPi

int button = 2;
int buttonState;

// notes in the melody:
int melodyA[] = {
  NOTE_A3,NOTE_C4, NOTE_B3, NOTE_A3, 0, NOTE_E4, NOTE_D4, 0, NOTE_B3, 0 , NOTE_A3,NOTE_C4, NOTE_B3, NOTE_G3, 0, NOTE_AS3, NOTE_E3
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurationsA[] = {
  4, 8, 8, 4, 8, 4, 4, 4, 4,4,4, 8, 8, 4, 8, 4,4
};

int melodyB[] = {NOTE_CS6,NOTE_FS5,NOTE_FS5,NOTE_CS6,NOTE_FS5,NOTE_FS5,NOTE_CS6,NOTE_D5,NOTE_FS5,
               NOTE_CS6,NOTE_FS5,NOTE_FS5,NOTE_CS6,NOTE_FS5,NOTE_FS5,NOTE_CS6,NOTE_D5,NOTE_FS5,
               NOTE_C6,NOTE_F5,NOTE_F5,NOTE_C6,NOTE_F5,NOTE_F5,NOTE_C6,NOTE_F5,NOTE_CS5,NOTE_F5,
               NOTE_C6,NOTE_F5,NOTE_F5,NOTE_C6,NOTE_F5,NOTE_F5,NOTE_C6,NOTE_F5,NOTE_CS5,NOTE_F5,
               NOTE_B5,NOTE_E5,NOTE_E5,NOTE_B5,NOTE_E5,NOTE_E5,NOTE_B5,NOTE_E5,NOTE_C6,NOTE_E5,
               NOTE_B5,NOTE_E5,NOTE_E5,NOTE_B5,NOTE_E5,NOTE_E5,NOTE_B5,NOTE_E5,NOTE_C6,NOTE_E5};
int noteDurationsB[] = {4,4,4,4,4,4,4,4,4,
                      4,4,4,4,4,4,4,4,4,
                      4,4,4,4,4,4,4,4,4,4,
                      4,4,4,4,4,4,4,4,4,4,
                      4,4,4,4,4,4,4,4,4,4,
                      4,4,4,4,4,4,4,4,4,4};

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // read the character we recieve on the serial port from the RPi
  if(Serial.available()) {
    inChar = (char)Serial.read();
  }

  // if we get a 'H', turn the LED on, else turn it off
  if(inChar == 'H'){
    digitalWrite(led, HIGH);
    for (int thisNote = 0; thisNote < 58; thisNote++) {
  
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDurationB = 1000 / noteDurationsB[thisNote];
      tone(8, melodyB[thisNote], noteDurationB);
    
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDurationB * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
    }
  }
  else{
    digitalWrite(led, LOW);
  }

  // Button event checker - if pressed, send message to RPi
  int newState = digitalRead(button);
  if (buttonState != newState) {
    buttonState = newState;
    if(buttonState == HIGH){
      Serial.println("light"); //note println put a /r/n at the end of a line
       // iterate over the notes of the melody:
      for (int thisNote = 0; thisNote < 17; thisNote++) {
    
        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDurationA = 1000 / noteDurationsA[thisNote];
        tone(8, melodyA[thisNote], noteDurationA);
    
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDurationA * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
      }
    }
    else{
      Serial.println("dark");
    }
  }
}
