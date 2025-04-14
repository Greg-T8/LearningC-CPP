#include <stdio.h>
#include <limits.h>

/*
 * Program: Display ranges of integer types
 * Context: Exercise 2-1 from "The C Programming Language" by Kernighan and Ritchie (pp. 36-37)
 * Author: Greg Tate
 * Date: April 14, 2025
 * Synopsis: This program prints the ranges of char, short, int, and long variables,
 *           both signed and unsigned, using values from standard headers.
 *           The exercise also suggests computing these ranges directly,
 *           but this implementation focuses on using predefined constants.
 *
 */

int main () {
    printf("%-20s %15s %15s\n", "Type", "Min Value", "Max Value");
    printf("%-20s %15d %15d\n", "char (signed)", SCHAR_MIN, SCHAR_MAX);
    printf("%-20s %15d %15u\n", "char (unsigned)", 0, UCHAR_MAX);
    printf("%-20s %15d %15d\n", "short (signed)", SHRT_MIN, SHRT_MAX);
    printf("%-20s %15d %15d\n", "short (unsigned)", 0, SHRT_MAX);
    printf("%-20s %15d %15d\n", "int (signed)", INT_MIN, INT_MAX);
    printf("%-20s %15d %15u\n", "int (unsigned)", 0, UINT_MAX);
    printf("%-20s %15d %15d\n", "long (signed)", LONG_MIN, LONG_MAX);
    printf("%-20s %15d %15u\n", "long (unsigned)", 0, ULONG_MAX);
}