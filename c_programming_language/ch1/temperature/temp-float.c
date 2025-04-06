#include <stdio.h>

// This program is an example from "The C Programming Language" by Kernighan and Ritchie.
// It demonstrates the use of floating-point arithmetic to print a Fahrenheit to Celsius conversion table.

main()
{
    float fahr, celsius;
    float lower, upper, step;

    // Initialize the range and step size for the temperature conversion
    lower = 0;   // lower limit of temperature
    upper = 300; // upper limit of temperature
    step = 20;   // step size
    fahr = lower;

    // Print the table header
    printf("Fahrenheit to Celsius Conversion Table\n");

    while (fahr <= upper)
    {
        // Convert Fahrenheit to Celsius using the formula: (5.0 / 9.0) * (fahr - 32)
        celsius = (5.0 / 9.0) * (fahr - 32);
        // Print the Fahrenheit and Celsius values in a formatted table
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        // Increment fahr by the step size
        fahr = fahr + step;
    }
}