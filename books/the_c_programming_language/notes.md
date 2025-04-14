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


