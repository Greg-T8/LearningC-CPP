# Notes from "The C++ Programming Language" by Bjarne Stroustrup

<img src="images/1744359541209.png" alt="alt text" width="250px">

<details>
<summary>Book Resources</summary>

- [Book Resources](https://www.stroustrup.com/4th.html)

</details>

## 2. A Tour of C++ Basics  

### 2.2 The Basics

A Hello World program in C++:
```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, World!\n";
}
```
- `#include <iostream>`: This is a preprocessor directive that tells the compiler to include the standard input-output stream library, which is necessary for using `std::cout`.

#### 2.2.2 Types, Variables, and Arithmetic

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

#### 2.2.3 Constants
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

#### 2.2.4 Tests and Loops

Here is a simple function that prompts the user and returns a Boolean indicating a response:

```cpp
bool accept()
{
    cout << "Do you want to continue? (y/n)\n";
    char answer = 0;
    cin >> answer;
    if (answer == 'y') return true;
        return false;
}
```

- The `<<` operator is called "put to".
- The `>>` operator is called "get from".

Here is a modified version that allows for taking an 'n':

```cpp
bool accept2()
{
    cout << "Do you want to continue? (y/n)\n";
    char answer = 0;
    cin >> answer;
    switch (answer) {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            cout << "I'll take that as a 'no'\n";
            return false;
    }
}
```

Here is an example that gives the user a few tries to enter a valid response:

```cpp
bool accept3()
{
    int tries = 1;
    while (tries < 4) {
        cout << "Do you want to continue? (y/n)\n";
        char answer = 0;
        cin >> answer;
        switch (answer) {
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                cout << "Sorry, I don't understand that.\n";
                ++tries;
        }
    }
    cout << "I'll take that as a 'no'\n";
    return false;
}
```
    
#### 2.2.5 Pointers, Arrays, and Loops

An array of elements of type `char` can be declared as follows:
```cpp
char v[6]; // Array of 6 characters
```
A pointer can be declared like this:
```cpp
char* p; // Pointer to a character
```
In declarations, `[]` means "array of" and `*` means "pointer to". 

A pointer variable can hold the address of an object of the appropriate type:
```cpp
char* p = &v[3]; // p points to the 4th element of v
char x = *p;     // *p is the object that p points to
```

In an expression, prefix unary `*` means "contents of" and prefix unary `&` means "address of". This can be illustrated with the following example:

![](./images/20250501-ch02-pointer_reference.svg)

The following code copies ten elements from one array to another:
```cpp
void copy_fct()
{
    int v1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v2[10];
    for (auto i=0; i != 10; ++i)
        v2[i] = v1[i]; // copy element by element
}
```

The following code uses a range-`for`-statement:
```cpp
void print()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto x:v)
        cout << x << '\n'; // print each element
    for (auto x:{10, 21, 32, 43, 54, 65}
        cout << x << '\n'; // print each element
}
```


        

    