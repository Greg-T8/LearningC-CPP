#include <stdio.h>

/*
 * Program: Celsius to Fahrenheit Conversion Table (Reversed)
 * Author: Greg Tate
 * Date Last Updated: 2023-10-06
 * Context: Exercise 1-5 from "The C Programming Language" by Kernighan and
 * Ritchie
 *
 * Synopsis: This program demonstrates the use of a for loop with a decreasing
 * control variable to print a temperature conversion table in reverse order. It
 *           modifies the original temperature conversion example to print from
 * the highest temperature to the lowest, as requested in Exercise 1-5.
 */

int main()
{
    float celsius, fahr;
    float lower, upper, step;

    lower = -45.0;
    upper = 100.0;
    step = 10.0;

    printf("Celsius to Fahrenheit Conversion Table (Reversed)\n");
    for (celsius = upper; celsius >= lower; celsius -= step)
    {
        fahr = (9.0 / 5.0) * celsius + 32;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
    }
    return 0;
}