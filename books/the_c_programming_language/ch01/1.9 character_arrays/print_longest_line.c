/*
Program: Name
Author: Greg Tate
Date: 2025-08-06
Context: Book/context if applicable
*/




#include <stdio.h>
#define MAXLINE 1000        // Maximum input line size

int getline(char line[], int maxline);      // Returns length of line
void copy(char to[], char from[]);

int main()
{
    // Variable declarations for tracking line lengths and storage
    int len;                // Current line length
    int max;                // Maximum length seen so far
    char line[MAXLINE];     // Current input line
    char longest[MAXLINE];  // Longest line saved here

    // Initialize max and process each input line to find the longest
    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    // Print the longest line if one was found
    if (max > 0) {                      // There was a line
        printf("%s", longest);          // %s means print a string
    }
    return 0;
}

int getline(char s[], int lim)
{
    // Variable declarations for character input and index
    int c, i;

    // Read characters into s until limit, EOF, or newline
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    // If newline encountered, add it to the string
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

}
