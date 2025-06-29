/*
    Program: Count Character Occurrences
    Context: The C Programming Language, Chapter 1, Arrays
    Description: Counts occurrences of digits, whitespace, and other characters from input.
    Author: Greg Tate
    Date: 2025-06-29
*/

#include <stdio.h>

int main()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    // Initialize counters
    nwhite = nother = 0;

    // Initialize digit count array
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;

    // Process input characters
    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    // Output results
    printf("digits = ");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", whitespace = %d, other = %d\n", nwhite, nother);
}