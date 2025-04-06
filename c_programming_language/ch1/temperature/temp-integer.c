#include <stdio.h>

// This program is inspired by "The C Programming Language" by Kernighan and Ritchie.
// It demonstrates the use of integer arithmetic to print a Fahrenheit to Celsius conversion table.

main()
{
    int fahr, celsius;
    int lower, upper, step;

    // Initialize the range and step size for the temperature conversion
    lower = 0;   // lower limit of temperature
    upper = 300; // upper limit of temperature
    step = 20;   // step size
    fahr = lower;

    while (fahr <= upper)
    {
        // Convert Fahrenheit to Celsius using integer arithmetic: 5 * (fahr - 32) / 9
        celsius = 5 * (fahr - 32) / 9;
        // Print the Fahrenheit and Celsius values in a formatted table
        printf("%3d\t%6d\n", fahr, celsius);
        // Increment fahr by the step size
        fahr = fahr + step;
    }
}