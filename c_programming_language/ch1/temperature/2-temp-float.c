#include <stdio.h>

// This program is an example from "The C Programming Language" by Kernighan and
// Ritchie. It demonstrates the use of floating-point arithmetic to print a
// Fahrenheit to Celsius conversion table.

main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    printf("Fahrenheit to Celsius Conversion Table\n");
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}