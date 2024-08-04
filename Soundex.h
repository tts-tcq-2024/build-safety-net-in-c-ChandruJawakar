#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"  // Include itself for completeness (though usually unnecessary here)
#include <ctype.h>    // For toupper() function
#include <string.h>   // For strlen() function

// Soundex mapping for each letter from 'A' to 'Z'
const int soundexMapping[26] = {
    0, 1, 2, 3, 0, 1, 2, 0, 0, 2,
    2, 4, 5, 5, 0, 1, 2, 6, 2, 3,
    0, 1, 0, 2, 0, 2
};

// Function: getSoundexCode
// Returns the Soundex code for a given character 'c'
char getSoundexCode(char c) {
    c = toupper(c);  // Convert character to uppercase
    if (c < 'A' || c > 'Z') {
        return '0';  // Return '0' for non-alphabet characters
    }
    return soundexMapping[c - 'A'] + '0';  // Return the mapped Soundex code as a character
}

// Function: appendSoundexCode
// Appends a Soundex code 'code' to the 'soundex' string if it's not '0' and not the same as the last appended code
void appendSoundexCode(char code, char *soundex, int *sIndex) {
    if (code != '0' && code != soundex[*sIndex - 1]) {
        soundex[(*sIndex)++] = code;  // Append the code to soundex and increment sIndex
    }
}

// Function: finalizeSoundex
// Finalizes the 'soundex' string by padding with '0's until it reaches a length of 4 characters
void finalizeSoundex(char *soundex, int sIndex) {
    while (sIndex < 4) {
        soundex[sIndex++] = '0';  // Fill remaining characters with '0'
    }
    soundex[4] = '\0';  // Null-terminate the string
}

// Function: generateSoundex
// Generates the Soundex code for a given 'name' and stores it in 'soundex'
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);     // Calculate length of 'name'
    soundex[0] = toupper(name[0]);  // Store the uppercase first letter of 'name' in 'soundex'
    int sIndex = 1;  // Initialize index for 'soundex'

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);  // Get Soundex code for current character in 'name'
        appendSoundexCode(code, soundex, &sIndex);  // Append code to 'soundex' if necessary
    }

    finalizeSoundex(soundex, sIndex);  // Finalize 'soundex' to ensure it is exactly 4 characters long
}

#endif // SOUNDEX_H
