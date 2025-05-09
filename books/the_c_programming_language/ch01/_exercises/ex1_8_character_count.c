/*
    Program: Character Counter
    Context: The C Programming Language, Chapter 1 - Example 1-8
    Author: Greg Tate
    Date: 2025-04-30

    This program counts the number of blanks, tabs, and newlines in the input.
*/

// Include standard input/output library
#include <stdio.h>

// Main function: initializes counters and processes input
int main() {
    // Declare variables for character input and counters
    int character, blanks, tabs, newlines;

    // Initialize counters
    blanks = tabs = newlines = 0;

    // Process input and count blanks, tabs, and newlines
    while((character = getchar()) != EOF) {
        if (character == ' ')
            blanks++;
        if (character == '\t')
            tabs++;
        if (character == '\n')
            newlines++;
    }

    // Output the results
    printf("Here are the results: \n");
    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);
}