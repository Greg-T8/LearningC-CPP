#include <stdio.h>

int main()
{
    int c, word_length;
    int max_word_length;

    max_word_length = 20;
    int word_length_array[max_word_length + 1];

    for (int i = 0; i < (max_word_length + 1); i++)
        word_length_array[i] = 0;

    word_length = 0;
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\n' || c == '\t') {
            if (word_length > 0 && word_length < max_word_length)
                word_length_array[word_length]++;
            word_length = 0;
        }
        else
            word_length++;

    printf("Word Length Histogram");
    for (int i = 0; i < (max_word_length + 1); i++)
        printf("%d: %d", i, word_length_array[i]);

}
