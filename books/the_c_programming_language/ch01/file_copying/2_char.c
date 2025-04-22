/*
    Program: Character Input/Output File Copying (Condensed Form)
    Context: The C Programming Language, Chapter 1 - File Copying Example
    Author:  Greg Tate
    Date:    2025-04-22

    Description: This program reads characters from standard input and writes
    them to standard output, copying the input to the output one character at a
    time until EOF is reached. This version uses assignment within the while
    condition for brevity.
*/

#include <stdio.h>

int main() {
    int c;                        // Stores each character read from input

    // Reads and writes characters until EOF is encountered
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}