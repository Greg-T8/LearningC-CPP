/*
    Program: Squeeze Blanks
    Description: Exercise 1-9 - Copies input to output, replacing each string of one or more blanks by a single blank.
    Context: The C Programming Language, Chapter 1, Character Counting
    Author: Greg Tate
    Date: 2025-04-30
*/

#include <stdio.h>

// Declare main function and variables for character input and blank counting
int main() {
    int c;
    int blanks;

    // Initialize blank counter and process input character by character
    blanks = 0;
    while ((c = getchar()) != EOF)
    {
        // Check for blank characters and count consecutive blanks
        if (c == ' ') {
            blanks++;
        } else {
            // Output a single blank if blanks were counted, then output the non-blank character and reset counter
            if (blanks > 0) {
                putchar(' ');
            }
            putchar(c);
            blanks = 0;
        }
    }
}