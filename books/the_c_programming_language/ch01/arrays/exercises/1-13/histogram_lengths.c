/*
    Program: Word Length Histogram
    Author: Greg Tate
    Date: 2025-08-03
    Context: The C Programming Language, Chapter 1, Arrays, Exercise 1-13
*/

#include <stdio.h>

int main()
{
    int c, word_length;
    int max_word_length;

    max_word_length = 20;
    int word_length_array[max_word_length + 1];

    // Initialize the word length array to zero
    for (int i = 0; i < (max_word_length + 1); i++)
        word_length_array[i] = 0;

    // Read input and count word lengths
    word_length = 0;
    while ((c = getchar()) != EOF) {

        // Check if character is part of a word
        if (c != ' ' && c != '\n' && c != '\t') {
            word_length++;
        }
        else {
            // If word boundary is reached, update histogram and reset word length
            if (word_length > 0 && word_length < max_word_length) {
                word_length_array[word_length]++;
            }
            else {
                // Reset word length if not a valid word
                word_length = 0;
            }
    }

    // Print the word length histogram
    printf("Word Length Histogram:\n");
    for (int i = 0; i < (max_word_length + 1); i++)
        printf("%d: %d", i, word_length_array[i]);

}
