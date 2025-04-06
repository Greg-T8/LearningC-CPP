#include <stdio.h>

// This program is inspired by "The C Programming Language" by Kernighan and
// Ritchie. It demonstrates the use of integer arithmetic to print a Fahrenheit
// to Celsius conversion table.

main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;

    while (fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3d\t%6d\n", fahr, celsius);
        fahr = fahr + step;
    }
}