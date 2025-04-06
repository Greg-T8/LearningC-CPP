#include <stdio.h>

// This program is an example from "The C Programming Language" by Kernighan and Ritchie.
// It demonstrates a simple for loop to print a Fahrenheit to Celsius temperature conversion table.

int main()
{
    int fahr;
    // Loop through Fahrenheit values from 0 to 300 in steps of 20
    for (fahr = 0; fahr <= 300; fahr += 20)
    {
        // Print Fahrenheit and corresponding Celsius value
        // Celsius is calculated using the formula: (5.0 / 9.0) * (fahr - 32)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}