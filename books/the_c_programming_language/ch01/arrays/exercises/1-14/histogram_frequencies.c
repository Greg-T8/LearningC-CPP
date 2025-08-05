/*
Program: Histogram of ASCII Character Frequencies
Author: Greg Tate
Date: 2025-08-04
Context: The C Programming Language, Chapter 1, Exercise 1-13
Purpose: Reads input and prints a histogram of frequencies for printable ASCII characters.
*/

#include <stdio.h>

// Note: ASCII printable characters are from 32 - 127
#define ASCII_OFFSET 32

int main()
{
    int c;

    // Declare array size and frequency array for ASCII printable characters
    int char_arraysize = 127 - ASCII_OFFSET;
    int char_frequency[char_arraysize];

    // Initialize ASCII character frequency array
    for (int i = 0; i < char_arraysize; i++) {
        char_frequency[i] = 0;
    }

    // Read input and count frequency of each printable ASCII character
    while ((c = getchar()) != EOF) {
        // Skip non-printable ASCII characters
        if (c < 32 || c > 127) { continue; }
        // Increment frequency for the corresponding character
        char_frequency[c - ASCII_OFFSET]++;
    }

    // Print histogram header
    printf("Character frequency histogram:\n");

    // Print each printable ASCII character in the histogram
    for (int i = 0; i < char_arraysize; i++) {
        // Skip characters with zero frequency
        if (char_frequency[i] == 0) { continue; }
        // Print character and its frequency as histogram bars
        putchar(i + ASCII_OFFSET);
        printf(": ");
        for (int j = 0; j < char_frequency[i]; j++) { putchar('|'); }
        printf("\n");
    }
}
