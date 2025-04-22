/*
    Program: Demonstrates reading input until EOF and printing the final value of c.
    Context: The C Programming Language, Chapter 1, File Copying Example (Exercise 1-6).
    Author:  Greg Tate
    Date:    2025-04-22
*/

#include <stdio.h>

// Declare main function and variable for input character
int main() {
    int c;

    // Read characters from input until EOF is encountered
    while ((c = getchar()) != EOF) {
    }

    // Print the value of c after EOF is reached
    printf("The value of c is: %2d", c);
}