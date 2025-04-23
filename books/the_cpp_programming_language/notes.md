# Notes from "The C++ Programming Language" by Bjarne Stroustrup

<img src="images/1744359541209.png" alt="alt text" width="250px">

<details>
<summary>Book Resources</summary>

- [Book Resources](https://www.stroustrup.com/4th.html)

</details>

## The Basics  

A *declaration* is a statement that introduces a name into a program. It specifies a type for the named entity:
- A *type* defines a set of possible values and a set of operations (for an object)
- An *object* is some memory that holds a value of some type
- A *value* is a set of bits interpreted according to a type
- A *variable* is a named object

Notations for expression initialization:
```cpp
int i1 = 7.2;      // Implicit conversion from double to int
int i2{7};         // Corrected: Removed narrowing conversion
int i3 {7};        // Allows for spaces in initialization
int i4{7.2};       // error: floating-point integer narrowing conversion
int i5 = {7};      // Corrected: Fixed syntax error
```

- Use the general `{}`-list form when in doubt with initialization; it saves you from conversions thatlose information (narrowing conversions).

- When defining a variable, you don't need to state its type explicitly when the compiler can deduce it. Use `auto` for type deduction:
```cpp
auto b = true;     // a bool
auto ch = 'x';     // a char
auto i = 123;      // an int
auto d = 1.2;      // a double
auto z = sqrt(y);  // z has type of whatever sqrt(y) returns
```

- Using `auto` helps avoid redundancy with long type names and makes the code easier to read.
- `auto` is important in generic programming where the exact type of the object can be hard for the programmer to know.

### Constants
- C++ supports two notions of immutability:
    - `const` (constant): meaning routhly "I promise not to change this value". Used primarily to specify interfaces, so that data can be passed to functions without fear of it being changed.
    - `constexpr` (constant expression): meaning "to be evaluated at compile time". Used primarily to specify constants, to allow placement of data in read-only memory (where it is unlikely to be corrupted), and for performance.
    
```cpp
const int dmv = 17;                         // dmv is a named constant
int var = 17;                               // var is not a constant
constexpr double max1 = 1.4*square(dmv);    // OK if square(17) is a constant expression
constexpr double max2 = 1.4*square(var);    // error: var is not a constant expression
const double max3 = 1.4*square(var);        // OK, may be evaluated at run time
double sum(const vector<double>&);          // sum will not modify its argument
vector<double> v {1.2, 3.4, 4.5};           // v is not a constant
const double s1 = sum(v);                   // OK: evaluated at run time
constexpr double s2 = sum(v);               // error: sum(v) not constant expression; cannot be evaluated at compile time
```

- For a function to be usable in a *constant expression*, i.e., an expression evaluated by the compiler, it must be defined `constexpr`.
- `constexpr` statements must be simple: just a `return` statement computing a value.
```cpp
constexpr double square(double x) { return x*x; } 
```
- `constexpr` functions can have non-`constexpr` parameters, but the result is not a constant expression. C++ allows for this so that you don't have to define the same function twice, once for `constexpr` and once for non-`constexpr`.
- Places where `constexpr` are used: array bounds, case labels, some template arguments, constants declared using `constexpr`.

