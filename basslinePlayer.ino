#include "pitches.h"
#include "basslineGenerator.h"
#include <LiquidCrystal.h>

// BUTTON FUNCTIONALITY DEFINITIONS
#define selectButton 9
#define debounceTimeout 50

long int lastDebounceTime;

// Reflects whether there is currently audio playing
bool loopCurrentlyPlaying = false;

// Reflects whether the program is getting ready to generate a chord progression
bool readyToGenerate = false;

// Additional menu functions

// LCD DISPLAY DEFINTIONS
#define contrast 75
#define rs 12
#define en 13 
#define d4 2
#define d5 3
#define d6 4
#define d7 5

//initializing the lcd: lcd(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

bool firstBoot = true;        // only need to play this once

void setup() {
  // Initializing the LCD screen:
  lcd.begin(16,2);
  analogWrite(6, contrast);
  lcd.setCursor(0,0);
  lcd.print("Press the button");
  lcd.setCursor(0,1);
  lcd.print("to start..");

  // Initialize buttons/menu screen:
  pinMode(selectButton, INPUT);

  // Initializing random number generator for bassline generator algorithm 
  randomSeed(analogRead(10));               

  delay(300);
}

void loop() {
  // Menu configuration

  // Reading the button:
  int selectButtonPressed = digitalRead(selectButton);
  
  // Get current time:
  long int currentTime = millis();

  // Dealing w/ debounce
  if (!selectButtonPressed) {
    // Reset count time while button is not pressed
    lastDebounceTime = currentTime;
  }

  if ((currentTime - lastDebounceTime) > debounceTimeout) {
    if(selectButtonPressed == HIGH) {
      if (firstBoot && !loopCurrentlyPlaying && !readyToGenerate) {
        // Print message
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Welcome to");
        lcd.setCursor(0,1);
        lcd.print("Harmonizer!");

        firstBoot = false;
        readyToGenerate = true;

        delay(1000);

        // Prompt the user to press the button and generate a new chord progression
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Press button for");
        lcd.setCursor(0,1);
        lcd.print("a progression");
        
     } else if (!loopCurrentlyPlaying && readyToGenerate) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Generating chord");
        lcd.setCursor(0,1);
        lcd.print("progression");

        // fancy loading message
        for (int i = 0; i < 2; ++i) {
          lcd.setCursor(11,1);
          lcd.print(".");
          delay(500);
          lcd.setCursor(12,1);
          lcd.print(".");
          delay(500);
          lcd.setCursor(13,1);
          lcd.print(".");
          delay(500);
          lcd.setCursor(11,1);
          lcd.print("   ");
          delay(500);
        }

        loopCurrentlyPlaying = true;
        readyToGenerate = true;
          
        // Time to dive into the fun part: playing music! Call the functions in basslineGenerator.cpp
        int majorOrMinor= chooseMajorOrMinor();
        int chosenKey = chooseKey();
        firstBarNotes();
        secondBarNotes();
        thirdBarNotes();
        fourthBarNotes();

        // Loop for a certain amount of time:
        for (int i = 0; i < 50; i++) {
          lcd.clear();
          lcd.setCursor(0,0);
        
          if (majorOrMinor== 0) {
            // Dealing w/ major key
            lcd.clear();
            
            // Updating display based on what key we're in:
            if (chosenKey == 0) {
              // C Major
              playFirstBar();
              lcd.setCursor(0,0);
              lcd.print("ii-V-I in C");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - Dm");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - G");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: I - C");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: I - C");
              
            } else if (chosenKey == 1) {
              // C# Major
              playFirstBar();
              lcd.setCursor(0,0);
              lcd.print("ii-V-I in C#");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - D#m");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - G#");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: I - C#");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: I - C#");
              
            } else if (chosenKey == 2) {
              // D Major
              playFirstBar();
              lcd.setCursor(0,0);
              lcd.print("ii-V-I in D");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - Em");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - A");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: I - D");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: I - D");
              
            } else if (chosenKey == 3) {
              // Eb Major

              playFirstBar();
              lcd.setCursor(0,0);
              lcd.print("ii-V-I in Eb");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - Fm");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - Bb");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: I - Eb");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: I - Eb");
              
            } else if (chosenKey == 4) {
              // E Major

              playFirstBar();
              lcd.setCursor(0, 0);
              lcd.print("ii-V-I in E");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - F#m");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - B");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: I - E");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: I - E");
              
            } else if (chosenKey == 5) {
              // F Major

              playFirstBar();
              lcd.setCursor(0, 0);
              lcd.print("ii-V-I in F");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - Gm");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - C");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: I - F");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: I - F");
              
            } else if (chosenKey == 6) {
               // F# major
              
              playFirstBar();
              lcd.setCursor(0, 0);
              lcd.print("ii-V-I in F#");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - G#m");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - C#");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: I - F#");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: I - F#");
              
            } else if (chosenKey == 7) {
              // G major

              playFirstBar();
              lcd.setCursor(0, 0);
              lcd.print("ii-V-I in G");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - Am");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - D");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: I - G");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: I - G");
              
            } else if (chosenKey == 8) {
              // Ab major

              playFirstBar();
              lcd.setCursor(0, 0);
              lcd.print("ii-V-I in Ab");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - Bbm");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - Eb");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: I - Ab");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: I - Ab");
              
            } else if (chosenKey == 9) {
              // A major

              playFirstBar();
              lcd.setCursor(0, 0);
              lcd.print("ii-V-I in A");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - Bm");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - E");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: I - A");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: I - A");
              
            } else if (chosenKey == 10) {
              // Bb major
              playFirstBar();
              lcd.setCursor(0, 0);
              lcd.print("ii-V-I in Bb");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - Cm");
              

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - F");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: I - Bb");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: I - Bb");
              
            } else if (chosenKey == 11) {
              // B Major

              playFirstBar();
              lcd.setCursor(0, 0);
              lcd.print("ii-V-I in B");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - C#m");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - F#");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: I - B");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: I - B");
              
            } else {
              Serial.println("Fatal error - traceback to loop() - !loopCurrentlyPlaying");
            }
            
          } else if (majorOrMinor == 1) {
            // Dealing w/ minor key
            lcd.clear();
            lcd.print("Now playing: ii-V-i");

            if (chosenKey == 0) {
              // C minor
              playFirstBar();
              lcd.setCursor(0,0);
              lcd.print("ii-V-i in Cm");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - Dm");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - G");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: i - Cm");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: i - Cm");
              
            } else if (chosenKey == 1) {
              // C# Minor

               playFirstBar();
              lcd.setCursor(0,0);
              lcd.print("ii-V-i in C#m");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - D#m");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - G#");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: i - C#m");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: i - C#m");
              
            } else if (chosenKey == 2) {
              // D minor

              playFirstBar();
              lcd.setCursor(0,0);
              lcd.print("ii-V-i in Dm");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - Em");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - A");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: i - Dm");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: i - Dm");
              
            } else if (chosenKey == 3) {
              // Eb Minor

              playFirstBar();
              lcd.setCursor(0,0);
              lcd.print("ii-V-i in Ebm");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - Fm");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - Bb");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: i - Ebm");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: i - Ebm");
              
            } else if (chosenKey == 4) {
              // E Minor

              playFirstBar();
              lcd.setCursor(0, 0);
              lcd.print("ii-V-i in Em");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - F#m");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - B");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: i - Em");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: i - Em");
              
            } else if (chosenKey == 5) {
              // F Minor

              playFirstBar();
              lcd.setCursor(0, 0);
              lcd.print("ii-V-i in Fm");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - Gm");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - C");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: i - Fm");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: i - Fm");
              
            } else if (chosenKey == 6) {
              // F# minor
              
              playFirstBar();
              lcd.setCursor(0, 0);
              lcd.print("ii-V-i in F#m");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - G#m");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - C#");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: i - F#m");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: i - F#m");
              
            } else if (chosenKey == 7) {
              // G minor

              playFirstBar();
              lcd.setCursor(0, 0);
              lcd.print("ii-V-i in Gm");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - Am");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - D");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: i - Gm");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: i - Gm");
              
            } else if (chosenKey == 8) {
              // Ab minor

              playFirstBar();
              lcd.setCursor(0, 0);
              lcd.print("ii-V-i in Abm");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - Bbm");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - Eb");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: i - Abm");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: i - Abm");
              
            } else if (chosenKey == 9) {
              // A minor

              playFirstBar();
              lcd.setCursor(0, 0);
              lcd.print("ii-V-i in Am");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - Bm");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - E");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: i - Am");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: i - Am");
              
            } else if (chosenKey == 10) {
              // Bb minor

              playFirstBar();
              lcd.setCursor(0, 0);
              lcd.print("ii-V-i in Bbm");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - Cm");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - F");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: i - Bbm");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: i - Bbm");
              
            } else if (chosenKey == 11) {
              // B Minor

              playFirstBar();
              lcd.setCursor(0, 0);
              lcd.print("ii-V-i in Bm");
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 1: ii - C#m");

              playSecondBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 2: V - F#");

              playThirdBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 3: i - Bm");

              playFourthBar();
              lcd.setCursor(0,1);
              lcd.print("                     ");
              lcd.print("Bar 4: i - Bm");
              
            } else {
              Serial.println("Fatal error - traceback to loop() - !loopCurrentlyPlaying");
            }
          }
        }
        
      } else if (loopCurrentlyPlaying && readyToGenerate) {
        noTone(8);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Stopping the");
        lcd.setCursor(0,1);
        lcd.print("loop...");

        delay(500);
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Press button for");
        lcd.setCursor(0,1);
        lcd.print("a progression");

        loopCurrentlyPlaying = false;
        readyToGenerate = true;
      }
    }
  }

  
}
