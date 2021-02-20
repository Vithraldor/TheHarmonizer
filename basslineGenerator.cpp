#include "basslineGenerator.h"
#include <Arduino.h>

/***********************************************
               GLOBAL VARIABLES
***********************************************/
int majorOrMinor, chosenKey;
#define tempo 120

// Arrays that hold the notes to be played
int firstBar[4];
int secondBar[4];
int thirdBar[4];
int fourthBar[4];

/***********************************************
                 FUNCTIONS
***********************************************/
int chooseMajorOrMinor() {
  long randomNumber = random(2);         // returns number between 0 and 2
  return (int) randomNumber;
}

int chooseKey() {
  long randomNumber = random(13);       // returns number between 0 and 12
  return (int) randomNumber;
}

void firstBarNotes() {
  // First bar notes are the same regardless if you're in a major or minor key:

  if (chosenKey == 0) {
    firstBar[0] = cMaj[1];
    firstBar[1] = cMaj[2];
    firstBar[2] = cMaj[3];
    firstBar[3] = iiSharp3rd[0];
    return;

  } else if (chosenKey == 1) {
    firstBar[0] = cSharpMaj[1];
    firstBar[1] = cSharpMaj[2];
    firstBar[2] = cSharpMaj[3];
    firstBar[3] = iiSharp3rd[1];
    return;

  } else if (chosenKey == 2) {
    firstBar[0] = dMaj[1];
    firstBar[1] = dMaj[2];
    firstBar[2] = dMaj[3];
    firstBar[3] = iiSharp3rd[2];
    return;

  } else if (chosenKey == 3) {
    firstBar[0] = ebMaj[1];
    firstBar[1] = ebMaj[2];
    firstBar[2] = ebMaj[3];
    firstBar[3] = iiSharp3rd[3];
    return;

  } else if (chosenKey == 4) {
    firstBar[0] = eMaj[1];
    firstBar[1] = eMaj[2];
    firstBar[2] = eMaj[3];
    firstBar[3] = iiSharp3rd[4];
    return;

  } else if (chosenKey == 5) {
    firstBar[0] = fMaj[1];
    firstBar[1] = fMaj[2];
    firstBar[2] = fMaj[3];
    firstBar[3] = iiSharp3rd[5];
    return;

  } else if (chosenKey == 6) {
    firstBar[0] = fSharpMaj[1];
    firstBar[1] = fSharpMaj[2];
    firstBar[2] = fSharpMaj[3];
    firstBar[3] = iiSharp3rd[6];
    return;

  } else if (chosenKey == 7) {
    firstBar[0] = gMaj[1];
    firstBar[1] = gMaj[2];
    firstBar[2] = gMaj[3];
    firstBar[3] = iiSharp3rd[7];
    return;

  } else if (chosenKey == 8) {
    firstBar[0] = abMaj[1];
    firstBar[1] = abMaj[2];
    firstBar[2] = abMaj[3];
    firstBar[3] = iiSharp3rd[8];
    return;

  } else if (chosenKey == 9) {
    firstBar[0] = aMaj[1];
    firstBar[1] = aMaj[2];
    firstBar[2] = aMaj[3];
    firstBar[3] = iiSharp3rd[9];
    return;

  } else if (chosenKey == 10) {
    firstBar[0] = bbMaj[1];
    firstBar[1] = bbMaj[2];
    firstBar[2] = bbMaj[3];
    firstBar[3] = iiSharp3rd[10];
    return;

  } else if (chosenKey == 11) {
    firstBar[0] = bMaj[1];
    firstBar[1] = bMaj[2];
    firstBar[2] = bMaj[3];
    firstBar[3] = iiSharp3rd[11];
    return;

  } else {
    Serial.println("Fatal error - traceback to firstBarNotes function");
    return;
  }

}

void secondBarNotes() {
  // Second bar is the same regardless of whether you're in a major or minor key

  if (chosenKey == 0) {
    secondBar[0] = cMaj[4];
    secondBar[1] = cMaj[5];
    secondBar[2] = VFlat3rd[0];
    secondBar[3] = cMaj[6];
    return;

  } else if (chosenKey == 1) {
    secondBar[0] = cSharpMaj[4];
    secondBar[1] = cSharpMaj[5];
    secondBar[2] = VFlat3rd[1];
    secondBar[3] = cSharpMaj[6];
    return;

  } else if (chosenKey == 2) {
    secondBar[0] = dMaj[4];
    secondBar[1] = dMaj[5];
    secondBar[2] = VFlat3rd[2];
    secondBar[3] = dMaj[6];
    return;

  } else if (chosenKey == 3) {
    secondBar[0] = ebMaj[4];
    secondBar[1] = ebMaj[5];
    secondBar[2] = VFlat3rd[3];
    secondBar[3] = ebMaj[6];
    return;

  } else if (chosenKey == 4) {
    secondBar[0] = eMaj[4];
    secondBar[1] = eMaj[5];
    secondBar[2] = VFlat3rd[4];
    secondBar[3] = eMaj[6];
    return;

  } else if (chosenKey == 5) {
    secondBar[0] = fMaj[4];
    secondBar[1] = fMaj[5];
    secondBar[2] = VFlat3rd[5];
    secondBar[3] = fMaj[6];
    return;

  } else if (chosenKey == 6) {
    secondBar[0] = fSharpMaj[4];
    secondBar[1] = fSharpMaj[5];
    secondBar[2] = VFlat3rd[6];
    secondBar[3] = fSharpMaj[6];
    return;

  } else if (chosenKey == 7) {
    secondBar[0] = gMaj[4];
    secondBar[1] = gMaj[5];
    secondBar[2] = VFlat3rd[7];
    secondBar[3] = gMaj[6];
    return;

  } else if (chosenKey == 8) {
    secondBar[0] = abMaj[4];
    secondBar[1] = abMaj[5];
    secondBar[2] = VFlat3rd[8];
    secondBar[3] = abMaj[6];
    return;

  } else if (chosenKey == 9) {
    secondBar[0] = aMaj[4];
    secondBar[1] = aMaj[5];
    secondBar[2] = VFlat3rd[9];
    secondBar[3] = aMaj[6];
    return;

  } else if (chosenKey == 10) {
    secondBar[0] = bbMaj[4];
    secondBar[1] = bbMaj[5];
    secondBar[2] = VFlat3rd[10];
    secondBar[3] = bbMaj[6];
    return;

  } else if (chosenKey == 11) {
    secondBar[0] = bMaj[4];
    secondBar[1] = bMaj[5];
    secondBar[2] = VFlat3rd[11];
    secondBar[3] = bMaj[6];
    return;

  } else {
    Serial.println("Fatal error - traceback to secondBarNotes function");
    return;
  }
}

void thirdBarNotes() {
  // Now need to differeniate between the major and minor key here:

  if (majorOrMinor == 0) {
    // Dealing with a major key

    if (chosenKey == 0) {
      // C Major
      thirdBar[0] = cMaj[7];
      thirdBar[1] = cMaj[5];
      thirdBar[2] = cMaj[4];
      thirdBar[3] = cMaj[3];
      return;

    } else if (chosenKey == 1) {
      // C# Major
      thirdBar[0] = cSharpMaj[7];
      thirdBar[1] = cSharpMaj[5];
      thirdBar[2] = cSharpMaj[4];
      thirdBar[3] = cSharpMaj[3];
      return;

    } else if (chosenKey == 2) {
      // D Major
      thirdBar[0] = dMaj[7];
      thirdBar[1] = dMaj[5];
      thirdBar[2] = dMaj[4];
      thirdBar[3] = dMaj[3];
      return;

    } else if (chosenKey == 3) {
      // Eb Major
      thirdBar[0] = ebMaj[7];
      thirdBar[1] = ebMaj[5];
      thirdBar[2] = ebMaj[4];
      thirdBar[3] = ebMaj[3];
      return;

    } else if (chosenKey == 4) {
      // E Major
      thirdBar[0] = eMaj[7];
      thirdBar[1] = eMaj[5];
      thirdBar[2] = eMaj[4];
      thirdBar[3] = eMaj[3];
      return;

    } else if (chosenKey == 5) {
      //  F Major
      thirdBar[0] = fMaj[7];
      thirdBar[1] = fMaj[5];
      thirdBar[2] = fMaj[4];
      thirdBar[3] = fMaj[3];
      return;

    } else if (chosenKey == 6) {
      // F# Major
      thirdBar[0] = fSharpMaj[7];
      thirdBar[1] = fSharpMaj[5];
      thirdBar[2] = fSharpMaj[4];
      thirdBar[3] = fSharpMaj[3];
      return;

    } else if (chosenKey == 7) {
      // G Major
      thirdBar[0] = gMaj[7];
      thirdBar[1] = gMaj[5];
      thirdBar[2] = gMaj[4];
      thirdBar[3] = gMaj[3];
      return;

    } else if (chosenKey == 8) {
      // Ab Major
      thirdBar[0] = abMaj[7];
      thirdBar[1] = abMaj[5];
      thirdBar[2] = abMaj[4];
      thirdBar[3] = abMaj[3];
      return;

    } else if (chosenKey == 9) {
      // A Major
      thirdBar[0] = aMaj[7];
      thirdBar[1] = aMaj[5];
      thirdBar[2] = aMaj[4];
      thirdBar[3] = aMaj[3];
      return;

    } else if (chosenKey == 10) {
      // Bb Major
      thirdBar[0] = bbMaj[7];
      thirdBar[1] = bbMaj[5];
      thirdBar[2] = bbMaj[4];
      thirdBar[3] = bbMaj[3];
      return;

    } else if (chosenKey == 11) {
      // B Major
      thirdBar[0] = bMaj[7];
      thirdBar[1] = bMaj[5];
      thirdBar[2] = bMaj[4];
      thirdBar[3] = bMaj[3];
      return;

    } else {
      Serial.println("Fatal error - traceback to major thirdBarNotes function");
    }

  } else if (majorOrMinor == 1) {
    // Dealing with a minor key

    if (chosenKey == 0) {
      // C Minor
      thirdBar[0] = cMin[7];
      thirdBar[1] = cMin[6];
      thirdBar[2] = cMin[5];
      thirdBar[3] = cMin[4];
      return;

    } else if (chosenKey == 1) {
      // C# Minor
      thirdBar[0] = cSharpMin[7];
      thirdBar[1] = cSharpMin[6];
      thirdBar[2] = cSharpMin[5];
      thirdBar[3] = cSharpMin[4];
      return;

    } else if (chosenKey == 2) {
      // D minor
      thirdBar[0] = dMin[7];
      thirdBar[1] = dMin[6];
      thirdBar[2] = dMin[5];
      thirdBar[3] = dMin[4];
      return;

    } else if (chosenKey == 3) {
      // Eb minor
      thirdBar[0] = ebMin[7];
      thirdBar[1] = ebMin[6];
      thirdBar[2] = ebMin[5];
      thirdBar[3] = ebMin[4];
      return;

    } else if (chosenKey == 4) {
      // E minor
      thirdBar[0] = eMin[7];
      thirdBar[1] = eMin[6];
      thirdBar[2] = eMin[5];
      thirdBar[3] = eMin[4];
      return;

    } else if (chosenKey == 5) {
      // F minor
      thirdBar[0] = fMin[7];
      thirdBar[1] = fMin[6];
      thirdBar[2] = fMin[5];
      thirdBar[3] = fMin[4];
      return;

    } else if (chosenKey == 6) {
      // F# minor
      thirdBar[0] = fSharpMin[7];
      thirdBar[1] = fSharpMin[6];
      thirdBar[2] = fSharpMin[5];
      thirdBar[3] = fSharpMin[4];
      return;

    } else if (chosenKey == 7) {
      // G minor
      thirdBar[0] = gMin[7];
      thirdBar[1] = gMin[6];
      thirdBar[2] = gMin[5];
      thirdBar[3] = gMin[4];
      return;

    } else if (chosenKey == 8) {
      // Ab minor
      thirdBar[0] = abMin[7];
      thirdBar[1] = abMin[6];
      thirdBar[2] = abMin[5];
      thirdBar[3] = abMin[4];
      return;

    } else if (chosenKey == 9) {
      // A minor
      thirdBar[0] = aMin[7];
      thirdBar[1] = aMin[6];
      thirdBar[2] = aMin[5];
      thirdBar[3] = aMin[4];
      return;

    } else if (chosenKey == 10) {
      // Bb minor
      thirdBar[0] = bbMin[7];
      thirdBar[1] = bbMin[6];
      thirdBar[2] = bbMin[5];
      thirdBar[3] = bbMin[4];
      return;

    } else if (chosenKey == 11) {
      // B minor
      thirdBar[0] = bMin[7];
      thirdBar[1] = bMin[6];
      thirdBar[2] = bMin[5];
      thirdBar[3] = bMin[4];
      return;

    } else {
      Serial.println("Fatal error - traceback to minor thirdBarNotes function");
    }

  } else {
    Serial.println("Fatal error - traceback to thirdBarNotes function (no min/maj found)");
  }
}

void fourthBarNotes() {
  // Need to differentiate between whether the key is major or minor

  if (majorOrMinor == 0) {
    // Dealing with major key

    if (chosenKey == 0) {
      // C major
      fourthBar[0] = cMaj[2];
      fourthBar[1] = cMaj[1];
      fourthBar[2] = cMaj[0];
      fourthBar[3] = iMinSharp1st[0];
      return;

    } else if (chosenKey == 1) {
      // C# major
      fourthBar[0] = cSharpMaj[2];
      fourthBar[1] = cSharpMaj[1];
      fourthBar[2] = cSharpMaj[0];
      fourthBar[3] = iMinSharp1st[1];
      return;

    } else if (chosenKey == 2) {
      // D major
      fourthBar[0] = dMaj[2];
      fourthBar[1] = dMaj[1];
      fourthBar[2] = dMaj[0];
      fourthBar[3] = iMinSharp1st[2];
      return;

    } else if (chosenKey == 3) {
      // Eb major
      fourthBar[0] = ebMaj[2];
      fourthBar[1] = ebMaj[1];
      fourthBar[2] = ebMaj[0];
      fourthBar[3] = iMinSharp1st[3];
      return;

    } else if (chosenKey == 4) {
      // E major
      fourthBar[0] = eMaj[2];
      fourthBar[1] = eMaj[1];
      fourthBar[2] = eMaj[0];
      fourthBar[3] = iMinSharp1st[4];
      return;

    } else if (chosenKey == 5) {
      // F Major
      fourthBar[0] = fMaj[2];
      fourthBar[1] = fMaj[1];
      fourthBar[2] = fMaj[0];
      fourthBar[3] = iMinSharp1st[5];
      return;

    } else if (chosenKey == 6) {
      // F# MAjor
      fourthBar[0] = fSharpMaj[2];
      fourthBar[1] = fSharpMaj[1];
      fourthBar[2] = fSharpMaj[0];
      fourthBar[3] = iMinSharp1st[6];
      return;

    } else if (chosenKey == 7) {
      // G Maj
      fourthBar[0] = gMaj[2];
      fourthBar[1] = gMaj[1];
      fourthBar[2] = gMaj [0];
      fourthBar[3] = iMinSharp1st[7];
      return;

    } else if (chosenKey == 8) {
      // Ab Major
      fourthBar[0] = abMaj[2];
      fourthBar[1] = abMaj[1];
      fourthBar[2] = abMaj[0];
      fourthBar[3] = iMinSharp1st[8];
      return;

    } else if (chosenKey == 9) {
      // A Major
      fourthBar[0] = aMaj[2];
      fourthBar[1] = aMaj[1];
      fourthBar[2] = aMaj[0];
      fourthBar[3] = iMinSharp1st[9];
      return;

    } else if (chosenKey == 10) {
      // Bb Major
      fourthBar[0] = bbMaj[2];
      fourthBar[1] = bbMaj[1];
      fourthBar[2] = bbMaj[0];
      fourthBar[3] = iMinSharp1st[10];
      return;

    } else if (chosenKey == 11) {
      // B Major
      fourthBar[0] = bMaj[2];
      fourthBar[1] = bMaj[1];
      fourthBar[2] = bMaj[0];
      fourthBar[3] = iMinSharp1st[11];
      return;

    } else {
      Serial.println("Fatal error - traceback to major fourthBarNotes function");
    }

  } else if (majorOrMinor == 1) {
    // Dealing with minor key

    if (chosenKey == 0) {
      // C minor
      fourthBar[0] = cMin[2];
      fourthBar[1] = cMin[1];
      fourthBar[2] = cMin[0];
      fourthBar[3] = iMinSharp1st[0];
      return;

    } else if (chosenKey == 1) {
      // C# minor
      fourthBar[0] = cSharpMin[2];
      fourthBar[1] = cSharpMin[1];
      fourthBar[2] = cSharpMin[0];
      fourthBar[3] = iMinSharp1st[1];
      return;

    } else if (chosenKey == 2) {
      // D minor
      fourthBar[0] = dMin[2];
      fourthBar[1] = dMin[1];
      fourthBar[2] = dMin[0];
      fourthBar[3] = iMinSharp1st[2];
      return;

    } else if (chosenKey == 3) {
      // Eb minor
      fourthBar[0] = ebMin[2];
      fourthBar[1] = ebMin[1];
      fourthBar[2] = ebMin[0];
      fourthBar[3] = iMinSharp1st[3];
      return;

    } else if (chosenKey == 4) {
      // E minor
      fourthBar[0] = eMin[2];
      fourthBar[1] = eMin[1];
      fourthBar[2] = eMin[0];
      fourthBar[3] = iMinSharp1st[4];
      return;

    } else if (chosenKey == 5) {
      // F minor
      fourthBar[0] = fMin[2];
      fourthBar[1] = fMin[1];
      fourthBar[2] = fMin[0];
      fourthBar[3] = iMinSharp1st[5];
      return;

    } else if (chosenKey == 6) {
      // F# Minor
      fourthBar[0] = fSharpMin[2];
      fourthBar[1] = fSharpMin[1];
      fourthBar[2] = fSharpMin[0];
      fourthBar[3] = iMinSharp1st[6];
      return;

    } else if (chosenKey == 7) {
      // G minor
      fourthBar[0] = gMin[2];
      fourthBar[1] = gMin[1];
      fourthBar[2] = gMin[0];
      fourthBar[3] = iMinSharp1st[7];
      return;

    } else if (chosenKey == 8) {
      // Ab minor
      fourthBar[0] = abMin[2];
      fourthBar[1] = abMin[1];
      fourthBar[2] = abMin[0];
      fourthBar[3] = iMinSharp1st[8];
      return;

    } else if (chosenKey == 9) {
      // A minor
      fourthBar[0] = aMin[2];
      fourthBar[1] = aMin[1];
      fourthBar[2] = aMin[0];
      fourthBar[3] = iMinSharp1st[9];
      return;

    } else if (chosenKey == 10) {
      // Bb minor
      fourthBar[0] = bbMin[2];
      fourthBar[1] = bbMin[1];
      fourthBar[2] = bbMin[0];
      fourthBar[3] = iMinSharp1st[10];
      return;

    } else if (chosenKey == 11) {
      // B minor
      fourthBar[0] = bMin[2];
      fourthBar[1] = bMin[1];
      fourthBar[2] = bMin[0];
      fourthBar[3] = iMinSharp1st[11];
      return;

    } else {
      Serial.println("Fatal error - traceback to major fourthBarNotes function");
    }

  } else {
    Serial.println("Fatal error - traceback to fourthBarNotes function (no min/maj found)");
  }
}


// The following functions call upon the firstBar, secondBar, thirdBar, and fourthBar arrays to determine which note to play.

void playFirstBar() {
  const int noteDurations[4] = {4, 4, 4, 4};
  
  for (int thisNote = 0; thisNote < 4; thisNote++) {
    int noteDuration = (int)((1000 * (60 * 4 / tempo)) / noteDurations[thisNote]);
    tone(8, firstBar[thisNote], noteDuration);
  }

  return;
}

void playSecondBar() {
  const int noteDurations[4] = {4, 4, 4, 4};
  
  for (int thisNote = 0; thisNote < 4; thisNote++) {
    int noteDuration = (int)((1000 * (60 * 4 / tempo)) / noteDurations[thisNote]);
    tone(8, secondBar[thisNote], noteDuration);
  }

  return;
}

void playThirdBar() {
  const int noteDurations[4] = {4, 4, 4, 4};
  
  for (int thisNote = 0; thisNote < 4; thisNote++) {
    int noteDuration = (int)((1000 * (60 * 4 / tempo)) / noteDurations[thisNote]);
    tone(8, thirdBar[thisNote], noteDuration);
  }

  return;
}

void playFourthBar() {
  const int noteDurations[4] = {4, 4, 4, 4};
  
  for (int thisNote = 0; thisNote < 4; thisNote++) {
    int noteDuration = (int)((1000 * (60 * 4 / tempo)) / noteDurations[thisNote]);
    tone(8, fourthBar[thisNote], noteDuration);
  }

  return;
}
