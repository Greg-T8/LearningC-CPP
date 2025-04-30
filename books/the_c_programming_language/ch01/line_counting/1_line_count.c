/*
    Program: Line Counting
    Context: The C Programming Language, Chapter 1 - Example of counting lines in input.
    Author: Greg Tate
    Date: 2025-04-30
*/

#include <stdio.h>

int main() {
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}