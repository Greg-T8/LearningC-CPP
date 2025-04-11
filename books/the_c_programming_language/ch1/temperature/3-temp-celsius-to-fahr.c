// This program is inspired by "The C Programming Language" by Kernighan and
// Ritchie. It demonstrates the use of floating-point arithmetic to print a
// Celsius to Fahrenheit conversion table.

int main()
{
    float celsius, fahr;
    float lower, upper, step;

    lower = -45.0; // lower limit of temperature
    upper = 100.0; // upper limit of temperature
    step = 10.0;   // step size

    printf("Celsius to Fahrenheit Conversion Table\n");
    while (celsius <= upper)
    {
        fahr = (9.0 / 5.0) * celsius + 32;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}