# The C Programming Language

<img src="images/1743857546096.png" alt="alt text" width="250px">

## Types, Operators, and Expressions

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

### Character Input and Output

- A *text stream* is a sequence of characters divided into lines; each line consists of zero or more characters followed by a newline.
- `getchar()` and `putchar()` are the simplest library functions for reading and writing characters.
- `getchar()` reads the next character from the input stream and returns it as an `int`. It returns `EOF` when the end of the file is reached.
- `putchar()` writes a character (converted to an unsigned char) to the output stream and returns it as an `int`. It returns `EOF` if an error occurs.

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

See [`1_char.c`](./ch01/file_copying/1_char.c) for the complete code.

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
Output:  
<img src="images/1745314287089.png" alt="alt text" width="300px">

See [`1-6e.c`](./ch01/file_copying/1-6e.c) for the complete code.

#### Character Counting


