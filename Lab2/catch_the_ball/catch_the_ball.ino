#include <LiquidCrystal.h> 
#include "pitches.h"
#define melodyPin 9

// constants won't change. They're used here to set pin numbers:
const int buttonPin_start = 7;     // the number of the START pushbutton pin
const int buttonPin_end = 6;      // the number of the END pushbutton pin
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// make some custom characters:
byte ball[8] = {
  0b00000,
  0b01110,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00000,
  0b00000
};
byte antiball[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
byte sidewaysheart[8] = {
  0b00000,
  0b11100,
  0b11110,
  0b01111,
  0b11110,
  0b11100,
  0b00000,
  0b00000
};
byte barrier[8] = {
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000
};
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};
byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};
byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

int falling = 0;
long randSpeed;
long randMove;
                 
//Mario main theme melody
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};
// Feilure
int feilure_melody[] = {
  NOTE_C4, NOTE_B4, NOTE_AS4, NOTE_A4,
};
// Feilure tempo
int feilure_tempo[] = {
  5, 5, 5, 2
};

// variables will change:
int buttonState_start = 0;         // variable for reading the START pushbutton status
int buttonState_end = 0;         // variable for reading the end pushbutton status
uint32_t t_start = micros();   // variable storing the start time 
uint32_t t_end = micros();    // variable storing the end time
uint32_t t_bottom = micros(); // variable storing the time ball reaches bottom
uint32_t time_diff = 0;
int b1_on_num = 0;



void setup() {

  // initialize the pushbutton pins as inputs:
  pinMode(buttonPin_start, INPUT);
  pinMode(buttonPin_end, INPUT);
  // initialize the lcd screen
  lcd.begin(16, 2);
  // create a new character
  lcd.createChar(0, ball);
  lcd.createChar(1, antiball);
  lcd.createChar(2, barrier);
  lcd.createChar(3, smiley);
  lcd.createChar(4, frownie);

  Serial.begin(9600); 
  pinMode(9, OUTPUT);//buzzer
  pinMode(13, OUTPUT);//led indicator when singing a note
  //    //sing the tunes
  
}

void loop() {
 // read the state of the pushbutton value:
 buttonState_start = digitalRead(buttonPin_start);
 buttonState_end = digitalRead(buttonPin_end);
 if (buttonState_start == HIGH) {
   b1_on_num = 1; // record the start time and start the animation
   t_start = micros();
 }
 
 if (b1_on_num == 1) {//start button has been pressed 
   // start the animation
   //create barrier
   lcd.setCursor(15, 0);
   lcd.write((byte)2);
   lcd.setCursor(15, 1);
   lcd.write((byte)2);
   
   // read the potentiometer on A0:
   int sensorReading = analogRead(A0);
   // map the result to 200 - 1000:
   //random ball speed
   randSpeed = random(50, 1000);
   //random ball movement
   randMove = random(0, 2);
   int delayTime = map(sensorReading, 0, 1023, 200, randSpeed);
   lcd.setCursor(falling, randMove);
   lcd.write(byte(0));
   delay(delayTime);
   lcd.setCursor(falling, randMove);
   lcd.write(byte(1));
   if(falling < 16){
     if(falling == 15){
       Serial.println("bottom");
       t_bottom = micros();
     }
     falling= falling +1;
   }
   else{
     falling = 0;
   }
   lcd.setCursor(falling, randMove);
   delay(delayTime);
 }
 // check if the END pushbutton is pressed. If it is, the buttonState is HIGH:
 if (buttonState_end == HIGH) {
    t_end = micros();
    lcd.clear();
    delay(5);
    time_diff = t_end - t_bottom;
    if (abs(time_diff)<=500000){
      YouWon();
      sing(1);
    }
    else{
      YouLost();
      sing(2);
    }
    lcd.setCursor(12, 0);
    // print the number of seconds elipse
    lcd.print((t_end - t_start) / 1000);
    // Turn on the display:
    lcd.display();
 }
}

int song = 0;

void sing(int s) {
  // iterate over the notes of the melody:
  song = s;
  if (song == 2) {
    Serial.println(" 'Feilure Theme'");
    int size = sizeof(feilure_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / feilure_tempo[thisNote];

      buzz(melodyPin, feilure_melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);

    }

  } else {

    Serial.println(" 'Mario Theme'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo[thisNote];

      buzz(melodyPin, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);

    }
  }
}

void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(13, LOW);

}

void YouWon()
{
    lcd.setCursor(0, 0);
    lcd.write((byte)3);
    lcd.print("You won!!");
    lcd.write((byte)3);
}
void YouLost()
{
    lcd.setCursor(0, 0);
    lcd.write((byte)4);
    lcd.print("You Lost");
    lcd.write((byte)4);
}
