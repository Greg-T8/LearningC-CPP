/*
    Program: Character Input/Output File Copying
    Context: The C Programming Language, Chapter 1 - File Copying Example
    Author:  Greg Tate
    Date:    2025-04-22

    Description: This program reads characters from standard input and writes
    them to standard output, effectively copying the input to the output one
    character at a time until EOF is reached.
*/

#include <stdio.h>

int main() {
    int c;                        // Variable to store each character read from input

    c = getchar();                // Read the first character from input
    while (c != EOF) {            // Loop until End Of File (EOF) is encountered
        putchar(c);               // Output the character to standard output
        c = getchar();            // Read the next character from input
    }
}