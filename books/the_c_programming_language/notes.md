# The C Programming Language

<img src="images/1743857546096.png" alt="alt text" width="250px">

<!-- omit in toc -->
## Contents

- [References](#references)
- [1. A Tutorial Introduction](#1-a-tutorial-introduction)
  - [1.2 Variables and Arithmetic Expressions](#12-variables-and-arithmetic-expressions)
  - [1.3 The `for` Statement](#13-the-for-statement)
  - [1.4 Symbolic Constants](#14-symbolic-constants)
  - [1.5 Character Input and Output](#15-character-input-and-output)
    - [1.5.1 File Copying](#151-file-copying)
    - [1.5.2 Character Counting](#152-character-counting)
    - [1.5.3 Line Counting](#153-line-counting)
    - [1.5.4 Word Counting](#154-word-counting)
  - [1.6 Arrays](#16-arrays)
- [2. Types, Operators, and Expressions](#2-types-operators-and-expressions)
  - [Data Types and Sizes](#data-types-and-sizes)

## References

Character Constants:

| Name            | Abbreviation | Escape Sequence |
| --------------- | ------------ | --------------- |
| newline         | NL (LF)      | `\n`            |
| horizontal tab  | HT           | `\t`            |
| vertical tab    | VT           | `\v`            |
| backspace       | BS           | `\b`            |
| carriage return | CR           | `\r`            |
| formfeed        | FF           | `\f`            |
| audible alert   | BEL          | `\a`            |
| backslash       | \            | `\\`            |
| question mark   | ?            | `\?`            |
| single quote    | ’            | `\'`            |
| double quote    | "            | `\"`            |
| octal number    | ooo          | `\ooo`          |
| hex number      | hh           | `\xhh`          |

Format Specifiers for the `printf()` function:

| Format | Description                                                        |
| ------ | ------------------------------------------------------------------ |
| %d     | print as decimal integer                                           |
| %6d    | print as decimal integer, at least 6 characters wide               |
| %f     | print as floating point                                            |
| %6f    | print as floating point, at least 6 characters wide                |
| %.2f   | print as floating point, 2 characters after decimal point          |
| %6.2f  | print as floating point, at least 6 wide and 2 after decimal point |

 
## 1. A Tutorial Introduction

The Hello, World! example:

```c
#include <stdio.h>

main()
{
    printf("hello, world\n");
}
```
[`hello.c`](./ch01/hello_world/hello.c)

### 1.2 Variables and Arithmetic Expressions

Temperature conversion using integer variables:

```c
main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;

    while (fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3d\t%6d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```
[`1-temp-integer.c`](./ch01/temperature/1-temp-integer.c)

Things to note:
- The `main()` function does not have a return type. In C, the default return type is `int`, so it is better to declare it as `int main()`.
- The `printf()` function is used to print formatted output. The format string specifies how the output should be formatted.
- The `%d` format specifier is used for integers, and `%f` is used for floating-point numbers.
- The expression `5 * (fahr - 32) / 9` performs integer division, which may lead to loss of precision. To avoid this, you can use floating-point arithmetic.

Temperature conversion using floating-point variables:

```c
main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    printf("Fahrenheit to Celsius Conversion Table\n");
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```
[`2-temp-float.c`](./ch01/temperature/2-temp-float.c)

Using the `printf()` function:

| Format | Description                                                        |
| ------ | ------------------------------------------------------------------ |
| %d     | print as decimal integer                                           |
| %6d    | print as decimal integer, at least 6 characters wide               |
| %f     | print as floating point                                            |
| %6f    | print as floating point, at least 6 characters wide                |
| %.2f   | print as floating point, 2 characters after decimal point          |
| %6.2f  | print as floating point, at least 6 wide and 2 after decimal point |

### 1.3 The `for` Statement

Temperature conversion using the `for` statement:

```c
int main()
{
    int fahr;
    for (fahr = 0; fahr <= 300; fahr += 20)
    {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}
```
[`4-temp-conversion-for.c`](./ch01/temperature/4-temp-conversion-for.c)

Things to note:
- The choice between `while` and `for` is aribrary, based on which seems clearer.
- The `for` statement is usually appropriate for loops in which the initialization and increment are single statements and logically related.

### 1.4 Symbolic Constants

Use `#define` to define symbolic constants:

```
#define <name> <replacement text>
```
Things to note:
- The replacement text can be any sequence of characters, including numbers, letters, and punctuation.

Temperature conversion using symbolic constants:

```c
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}
```
[6-temp-using-defines.c](./ch01/temperature/6-temp-using-defines.c)

### 1.5 Character Input and Output

- A *text stream* is a sequence of characters divided into lines; each line consists of zero or more characters followed by a newline.
- `getchar()` and `putchar()` are the simplest library functions for reading and writing characters.
- `getchar()` reads the next character from the input stream and returns it as an `int`. It returns `EOF` when the end of the file is reached.
- `putchar()` writes a character (converted to an unsigned char) to the output stream and returns it as an `int`. It returns `EOF` if an error occurs.

#### 1.5.1 File Copying

In the following program, `c` is declared as an `int` so that it can accommodate the value of `EOF`, which is typically defined as -1. If `c` were declared as a `char`, it would not be able to hold the value of `EOF`, and the program would not work correctly.

```c
#include <stdio.h>

int main() {
    int c;                        // Variable to store each character read from input

    c = getchar();                // Read the first character from input
    while (c != EOF) {            // Loop until End Of File (EOF) is encountered
        putchar(c);               // Output the character to standard output
        c = getchar();            // Read the next character from input
    }
}
```

[`1_char.c`](./ch01/file_copying/1_char.c)

Expressions return a value. The expression `c = getchar()` returns the value of `c` after the assignment is made.

The following code demonstrates reading input until EOF and printing the final value of `c`:

```c
#include <stdio.h>

// Declare main function and variable for input character
int main() {
    int c;

    // Read characters from input until EOF is encountered
    while ((c = getchar()) != EOF) {
    }

    // Print the value of c after EOF is reached
    printf("The value of c is: %2d", c);
}
```
[`1-6e.c`](./ch01/file_copying/1-6e.c)

**Output:**  
<img src="images/1745314287089.png" alt="alt text" width="300px">


#### 1.5.2 Character Counting

The following program counts the number of characters in the input:

```c
#include <stdio.h>

int main() {
    long nc = 0;                     // Initialize character count to zero
    while (getchar() != EOF) {       // Loop until EOF is encountered
        ++nc;                        // Increment character count
        printf("%ld\n", nc);         // Print the current character count. `ld` is used for long integers.
    }
}
```
[`1_character_count.c`](./ch01/character_counting/1_character_count.c)

Things to note:
- The program accumulates the count in a variable `nc` of type `long` instead of `int` to avoid overflow for large inputs.
- The conversion specifier `%ld` is used to print long integers.

The following program stores bigger counts using a double (double precision float):

```c
#include <stdio.h>

int main() {
    double nc = 0;                   // Initialize character count to zero
    for (nc = 0; getchar() != EOF; ++nc) {
        // Increment character count for each input character
    }
    printf("%.0f\n", nc);            // Print the total character count without decimals
}
```
[`2_character_count.c`](./ch01/character_counting/2_character_count.c)

**Note:**  
- The body of this loop is empty because all the work is done in the `for` statement.

#### 1.5.3 Line Counting 

The next program counts input lines.

```c
int main() {
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}
```
[1_line_count.c](./ch01/line_counting/1_line_count.c)

**Output:**  

<img src="images/1746008322765.png" alt="alt text" width="350px">

**Note:**  
- A character written between single quotes is called a *character constant*.
- A character constant represents an integer value equal to the numeric value of the character in the machine's character set.
- In this example, `'\n'` is the newline character constant, which has a value of 10 in ASCII.

**Exercise 1-8**: Write a program to count blanks, tabs, and newlines.

<details>
<summary>My Solution</summary>

```c
int main() {
    // Declare variables for character input and counters
    int character, blanks, tabs, newlines;

    // Initialize counters
    blanks = tabs = newlines = 0;

    // Process input and count blanks, tabs, and newlines
    while((character = getchar()) != EOF) {
        if (character == ' ')
            blanks++;
        if (character == '\t')
            tabs++;
        if (character == '\n')
            newlines++;
    }

    // Output the results
    printf("Here are the results: \n");
    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);
}
```
[`ex1_8_character_count.c`](./ch01/_exercises/ex1_8_character_count.c)

**Output:**

<img src="images/1746009564114.png" alt="alt text" width="350px">

</details>

**Exercise 1-9:** Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

<details>
<summary>My Solution</summary>

```c
#include <stdio.h>

// Declare main function and variables for character input and blank counting
int main() {
    int c;
    int blanks;

    // Initialize blank counter and process input character by character
    blanks = 0;
    while ((c = getchar()) != EOF)
    {
        // Check for blank characters and count consecutive blanks
        if (c == ' ') {
            blanks++;
        } else {
            // Output a single blank if blanks were counted, then output the non-blank character and reset counter
            if (blanks > 0) {
                putchar(' ');
            }
            putchar(c);
            blanks = 0;
        }
    }
}
```
[`ex1_9_squeeze_blanks.c`](./ch01/_exercises/ex1_9_squeeze_blanks.c)

**Output:**

<img src="images/1746011214329.png" alt="alt text" width="250px">

</details>


**Exercise 1-10:** Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.

<details>
<summary>My Solution</summary>

```c
#include <stdio.h>

int main()
{
    int character;

    /* Process input characters until EOF is encountered */
    while ((character = getchar()) != EOF)
    {
        /* Handle tab character */
        if (character == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        /* Handle backspace character */
        else if (character == '\b')
        {
            putchar('\\');
            putchar('b');
        }
        /* Handle backslash character */
        else if (character == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        /* Output all other characters without modification */
        else
        {
            putchar(character);
        }
    }
}
```
[`ex1-10.c`](./ch01/_exercises/ex1-10.c)

**Output:**  

Confirm by echoing a string with tabs and backspaces:  

<img src="images/1746780630889.png" alt="alt text" width="550px">

Then send the string to a text file and pipe it to the program:

<img src="images/1746780948634.png" alt="alt text" width="550px">

**Note:** The program prints backspaces, tabs, and backslashes as `\b`, `\t`, and `\\` respectively. 

</details>

#### 1.5.4 Word Counting

The following program is a bare-bones version of the UNIX program `wc` (word count). 

```c
#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */

int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
        {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t')     // Evaluates left to right. Stops as soon as truth or falsehood is known.
        {
            state = OUT;
        } else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
```
[`word_count.c`](./ch01/word_counting/word_count.c)

```bash
echo "This is the first line of text." > lines.txt
echo "Counting words can be very useful." >> lines.txt
echo "Each sentence should be on its own line." >> lines.txt
echo "Word count tools help analyze text easily." >> lines.txt
echo "How many words are in this line?" >> lines.txt

cat lines.txt | ./word_count
```
**Output:** First column is the number of lines, second is the number of words, and third is the number of characters.
<img src="images/1746782932605.png" alt="alt text" width="550px">

**Exercise 1-11:** How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?

Use a text file and pipe it to the program. Test with:
- Empty lines
- Lines with only whitespace
- Lines with a mix of tabs, spaces, and newlines
- Very long lines
- Unicode characters

**Exercise 1-12:** Write a program that prints its input one word per line.

```c
int main()
{
    int c;

    // Read characters until EOF and print each word on a new line.
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            putchar('\n');
        }
        else if (c == '\n') {
            // No action needed for newlines
        }
        else if (c == '.') {
            putchar('\n');
            putchar(c);
        }
        else {
            putchar(c);
        }
    }
}
```
[`echo_input.c`](/books/the_c_programming_language/ch01/word_counting/ex1-12/echo_input.c)

<img src="images/1747906023996.png" alt="alt text" width="550px">

<img src="images/1751191169739.png" alt="alt text" width="300px">


### 1.6 Arrays

The following program counts the number of occurrences of each digit, whitespace character (blank, tab, newline), and all other characters.

```c
#include <stdio.h>

int main()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    // Initialize counters
    nwhite = nother = 0;

    // Initialize digit count array
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;

    // Process input characters
    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    // Output results
    printf("digits = ");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", whitespace = %d, other = %d\n", nwhite, nother);
}
```
[`count_occurrences.c`](./ch01/arrays/count_occurrences.c)

<img src="images/1751193129386.png" alt="alt text" width="550px">

<img src="images/1751193157171.png" alt="alt text" width="550px">

**Note:** By definition, chars are just small integers, so char variables and constants are identical ints in arithmetic expressions.

**Exercise 1-13:** Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.

(in pogress)


## 2. Types, Operators, and Expressions

- Don't begin variable names with an underscore; names with underscores are reserved for library routines.

### Data Types and Sizes

Here are the data types from K&R C:
- `char`
- `int`
- `float`
- `double`

You can specify qualifiers for some types:

```c
short int sh;
long int counter;
```

Each compiler is free to choose its appropriate sizes for these types. `short` is often 16 bits, `int` is almost universally 32 bits, and `long` is at least 32 bits.

<blockquote>
<strong>Note:</strong> A Windows `long` is 32 bits and a Linux/macOS `long` is 64 bits.
</blockquote>
