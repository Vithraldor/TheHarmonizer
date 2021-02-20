#include "pitches.h"

/***********************************************
                  MAJOR KEYS
***********************************************/
const int cMaj[8] = {NOTE_C1, NOTE_D1, NOTE_E1, NOTE_F1, NOTE_G1, NOTE_A1, NOTE_B1, NOTE_C2};            // 0
const int cSharpMaj[8] = {NOTE_CS1, NOTE_DS1, NOTE_F1, NOTE_FS1, NOTE_GS1, NOTE_AS1, NOTE_C2, NOTE_CS2}; // 1
const int dMaj[8] = {NOTE_D1, NOTE_E1, NOTE_FS1, NOTE_G1, NOTE_A1, NOTE_B1, NOTE_CS2, NOTE_D2};          // 2
const int ebMaj[8] = {NOTE_DS1, NOTE_F1, NOTE_G1, NOTE_GS1, NOTE_AS1, NOTE_C2, NOTE_D2, NOTE_DS2};       // 3
const int eMaj[8] = {NOTE_E1, NOTE_FS1, NOTE_GS1, NOTE_A1, NOTE_B1, NOTE_CS2, NOTE_DS2, NOTE_E2};        // 4
const int fMaj[8] = {NOTE_F1, NOTE_G1, NOTE_A1, NOTE_AS1, NOTE_C2, NOTE_D2, NOTE_E2, NOTE_F2};           // 5
const int fSharpMaj[8] = {NOTE_FS1, NOTE_GS1, NOTE_AS1, NOTE_B1, NOTE_CS2, NOTE_DS2, NOTE_F2, NOTE_FS2}; // 6
const int gMaj[8] = {NOTE_G1, NOTE_A1, NOTE_B1, NOTE_C2, NOTE_D2, NOTE_E2, NOTE_FS2, NOTE_G2};           // 7
const int abMaj[8] = {NOTE_GS1, NOTE_AS1, NOTE_C2, NOTE_CS2, NOTE_DS2, NOTE_F2, NOTE_G2, NOTE_GS2};      // 8
const int aMaj[8] = {NOTE_A1, NOTE_B1, NOTE_CS2, NOTE_D2, NOTE_E2, NOTE_FS2, NOTE_GS2, NOTE_A2};         // 9
const int bbMaj[8] = {NOTE_AS1, NOTE_C2, NOTE_D2, NOTE_DS2, NOTE_F2, NOTE_G2, NOTE_A2, NOTE_AS2};        // 10
const int bMaj[8] = {NOTE_B1, NOTE_CS2, NOTE_DS2, NOTE_E2, NOTE_FS2, NOTE_GS2, NOTE_AS2, NOTE_B2};       // 11


/***********************************************
                  MINOR KEYS
***********************************************/
const int cMin[8] = {NOTE_C1, NOTE_D1, NOTE_DS1, NOTE_F1, NOTE_G1, NOTE_GS1, NOTE_AS1, NOTE_C2};         // 0
const int cSharpMin[8] = {NOTE_CS1, NOTE_DS1, NOTE_E1, NOTE_FS1, NOTE_GS1, NOTE_A1, NOTE_B1, NOTE_CS2};  // 1
const int dMin[8] = {NOTE_D1, NOTE_E1, NOTE_F1, NOTE_G1, NOTE_A1, NOTE_AS1, NOTE_C2, NOTE_D2};           // 2
const int ebMin[8] = {NOTE_DS1, NOTE_F1, NOTE_FS1, NOTE_GS1, NOTE_AS1, NOTE_B1, NOTE_CS2, NOTE_DS2};     // 3
const int eMin[8] = {NOTE_E1, NOTE_FS1, NOTE_G1, NOTE_A1, NOTE_B1, NOTE_C2, NOTE_D2, NOTE_E2};           // 4
const int fMin[8] = {NOTE_F1, NOTE_G1, NOTE_GS1, NOTE_AS1, NOTE_C2, NOTE_CS2, NOTE_DS2, NOTE_F2};        // 5
const int fSharpMin[8] = {NOTE_FS1, NOTE_GS1, NOTE_A1, NOTE_B1, NOTE_CS2, NOTE_D2, NOTE_E2, NOTE_F2};    // 6
const int gMin[8] = {NOTE_G1, NOTE_A1, NOTE_AS1, NOTE_C2, NOTE_D2, NOTE_DS2, NOTE_F2, NOTE_G2};          // 7
const int abMin[8] = {NOTE_GS1, NOTE_AS1, NOTE_B1, NOTE_CS2, NOTE_DS2, NOTE_E2, NOTE_FS2, NOTE_GS2};     // 8
const int aMin[8] = {NOTE_A1, NOTE_B1, NOTE_C2, NOTE_D2, NOTE_E2, NOTE_F2, NOTE_G2, NOTE_A2};            // 9
const int bbMin[8] = {NOTE_AS1, NOTE_C2, NOTE_CS2, NOTE_DS2, NOTE_F2, NOTE_FS2, NOTE_GS2, NOTE_AS2};     // 10
const int bMin[8] = {NOTE_B1, NOTE_CS2, NOTE_D2, NOTE_E2, NOTE_FS2, NOTE_G2, NOTE_A2, NOTE_B2};          // 11


/***********************************************
                 ACCIDENTALS
***********************************************/
// Used in the ii-V-I progression AND the I-vi-ii-V progression: equivalent to sharpened 4th in key
// This is also used in the minor ii-V-i progression
const int iiSharp3rd[12] = {NOTE_FS1, NOTE_G1, NOTE_GS1, NOTE_A1, NOTE_AS1, NOTE_B1, NOTE_C2, NOTE_CS2, NOTE_D2, NOTE_DS2, NOTE_E2, NOTE_F2};

// Used in the ii-V-I progression: equivalent to flat 7th in key
// Also used in the minor ii-V-i progression
const int VFlat3rd[12] = {NOTE_AS1, NOTE_B1, NOTE_C2, NOTE_CS2, NOTE_D2, NOTE_DS2, NOTE_E2, NOTE_F2, NOTE_FS2, NOTE_G2, NOTE_GS2, NOTE_A2};

// Used in the ii-V-i progression: equivalent to sharpened tonic note in key
const int iMinSharp1st[12] = {NOTE_CS1, NOTE_D1, NOTE_DS1, NOTE_E1, NOTE_F1, NOTE_FS1, NOTE_G1, NOTE_GS1, NOTE_A1, NOTE_AS1, NOTE_B1, NOTE_C2};


/***********************************************
                 FUNCTIONS
***********************************************/

int chooseMajorOrMinor();        // Chooses the chord progression & whether its major or minor

int chooseKey();                               // Chooses the key of the chord progression

void firstBarNotes();                           // Chooses the notes to be played in the first bar, dependent of chord progression & whether the key is major or minor

void secondBarNotes();                          // Chooses the notes to be played in the second bar

void thirdBarNotes();                           // Chooses the notes to be played in the third bar

void fourthBarNotes();                          // Chooses the notes to be played in the fourth bar

void playFirstBar();                            // Play first bar of the bassline

void playSecondBar();                           // Play second bar of the bassline

void playThirdBar();                            // Play third bar of the bassline

void playFourthBar();                           // Play fourth bar of the bassline
