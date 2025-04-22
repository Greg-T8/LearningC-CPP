/*
 * Program: Character Counting (Using a For Loop)
 * Context: Example from "The C Programming Language" by Kernighan and Ritchie, Chapter 1
 * Author: Greg Tate
 * Date: 2025-04-22
 * Description: This program counts the number of characters input by the user until EOF is encountered, using a for loop.
 */

#include <stdio.h>

int main() {
    double nc = 0;                   // Initialize character count to zero
    for (nc = 0; getchar() != EOF; ++nc) {
        // Increment character count for each input character
    }
    printf("%.0f\n", nc);            // Print the total character count without decimals
}
