/*
Program: Fahrenheit to Celsius Table (Function Version)
Author: Greg Tate
Date: 2025-08-05
Context: The C Programming Language, Chapter 1, Exercise 1-15
*/

#include <stdio.h>

// Function prototype for temperature conversion table
int convert_temp(int lower, int upper, int step);

int main()
{
    // Call function to print Fahrenheit-Celsius table
    convert_temp(0,300, 20);
}

int convert_temp(int lower, int upper, int step)
{
    int fahr;
    // Loop to print Fahrenheit and Celsius values for each step
    for (fahr = lower; fahr <= upper; fahr += step)
    {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
    return 0;
}