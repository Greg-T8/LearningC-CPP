#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c != ' ' || c != '\n' || c != '\t') {
            putchar(c);
        }
        else {
            putchar('\r');
            putchar('\n');
        }
    }
}