// Program: Fahrenheit to Celsius Conversion Table
// Author: Greg Tate
// Date Last Updated: 2025-04-06
// Context: Chapter 1: The C Programming Language
// Synopsis: This program prints a table converting Fahrenheit to Celsius
//           using symbolic constants for the lower limit, upper limit, and step
//           size.

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}