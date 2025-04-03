#include <stdio.h>

// print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300

main()
{
    int fahr, celsius;
    int lower, upper, step;
    lower = 0;   // lower limit of temperature
    upper = 300; // upper limit of temperature
    step = 20;   // step size
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9; // convert Fahrenheit to Celsius
        printf("%3d\t%6d\n", fahr, celsius);
        fahr = fahr + step; // increment fahr by step
    }
}