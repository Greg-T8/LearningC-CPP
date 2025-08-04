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
        char_frequency[ASCII_OFFSET - c]++;
    }

    // Print histogram header
    printf("Character frequency histogram:\n");

    // Print each printable ASCII character in the histogram
    for (int i = 0; i < char_arraysize; i++) {
        putchar(i + ASCII_OFFSET);

    }


}
