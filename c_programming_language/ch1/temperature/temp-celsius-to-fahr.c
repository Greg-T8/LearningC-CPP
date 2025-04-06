int main()
{
    float celsius, fahr;
    float lower, upper, step;
    lower = -45.0;
    upper = 100.0;
    step = 10.0;

    printf("Celsius to Fahrenheit Conversion Table\n");

    while (celsius <= upper)
    {
        fahr = (9.0 / 5.0) * celsius + 32; // convert Celsius to Fahrenheit
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step; // increment celsius by step
    }
}