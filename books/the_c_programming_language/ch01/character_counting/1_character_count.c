/*
 * Program: Character Counting
 * Context: Example from "The C Programming Language" by Kernighan and Ritchie, Chapter 1
 * Author: Greg Tate
 * Date: 2025-04-22
 * Description: This program counts the number of characters input by the user until EOF is encountered.
 */

#include <stdio.h>

int main() {
    long nc = 0;                     // Initialize character count to zero
    while (getchar() != EOF) {       // Loop until EOF is encountered
        ++nc;                        // Increment character count
        printf("%ld\n", nc);         // Print the current character count
    }
}