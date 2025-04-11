#include <stdio.h>

// This program is an example from "The C Programming Language" by Kernighan and
// Ritchie. It demonstrates a simple for loop to print a Fahrenheit to Celsius
// temperature conversion table.

int main()
{
    int fahr;
    for (fahr = 0; fahr <= 300; fahr += 20)
    {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}