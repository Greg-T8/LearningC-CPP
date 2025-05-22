/*
    Program: Echo Input One Word Per Line
    Context: The C Programming Language, Chapter 1, Exercise 1-12
    Description: Reads input and prints each word on a separate line.
    Author: Greg Tate
    Date: 2025-05-22
*/

#include <stdio.h>

int main()
{
    int c;

    // Read characters until EOF and print each word on a new line.
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            putchar('\n');
        }
        else if (c == '\n') {
            // No action needed for newlines
        }
        else if (c == '.' || c == ';' || c == ':') {
            putchar('\n');
            putchar(c);
            putchar('\n');
        }
        else {
            putchar(c);
        }
    }
}
