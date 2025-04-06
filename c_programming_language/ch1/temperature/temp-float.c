#include <stdio.h>

// print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300

main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;   // lower limit of temperature
    upper = 300; // upper limit of temperature
    step = 20;   // step size
    fahr = lower;

    // print header
    printf("Fahrenheit to Celsius Conversion Table\n");

    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32); // convert Fahrenheit to Celsius
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step; // increment fahr by step
    }
}