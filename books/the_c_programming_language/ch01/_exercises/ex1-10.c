/*
 * Replace Tabs, Backspaces, and Backslashes with Visible Escape Sequences
 *
 * Exercise 1-10 from "The C Programming Language" by Kernighan and Ritchie
 * Write a program to copy its input to its output, replacing each tab by \t,
 * each backspace by \b, and each backslash by \\. This makes tabs and
 * backspaces visible in an unambiguous way.
 *
 * Author: Greg Tate
 * Date: 2025-05-09
 */

#include <stdio.h>

int main()
{
    int character;

    /* Process input characters until EOF is encountered */
    while ((character = getchar()) != EOF)
    {
        /* Handle tab character */
        if (character == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        /* Handle backspace character */
        else if (character == '\b')
        {
            putchar('\\');
            putchar('b');
        }
        /* Handle backslash character */
        else if (character == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        /* Output all other characters without modification */
        else
        {
            putchar(character);
        }
    }
}
