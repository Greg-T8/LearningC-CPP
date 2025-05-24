# Notes from "The C++ Programming Language" by Bjarne Stroustrup

<img src="images/1744359541209.png" alt="alt text" width="250px">

<details>
<summary>Book Resources</summary>

- [Book Website](https://www.stroustrup.com/4th.html)

</details>

<!-- omit in toc -->
## Contents

- [2. A Tour of C++ Basics](#2-a-tour-of-c-basics)
  - [2.2 The Basics](#22-the-basics)
    - [2.2.2 Types, Variables, and Arithmetic](#222-types-variables-and-arithmetic)
    - [2.2.3 Constants](#223-constants)
    - [2.2.4 Tests and Loops](#224-tests-and-loops)
    - [2.2.5 Pointers, Arrays, and Loops](#225-pointers-arrays-and-loops)
  - [2.3 User-Defined Types](#23-user-defined-types)
    - [2.3.1 Structures](#231-structures)
    - [2.3.2 Classes](#232-classes)
    - [2.3.3 Enumerations](#233-enumerations)
    - [2.4 Modularity](#24-modularity)
      - [2.4.1 Separate Compilation](#241-separate-compilation)
      - [2.4.2 Namespaces](#242-namespaces)
      - [2.4.3 Error Handling](#243-error-handling)


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

Instead of copying values into `x`, you can refer to each element of `v` directly:
```cpp
void increment()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto& x:v) // x is a reference to each element of v
        ++x; // increment each element
    // ...
}
```
In a declaration, `&` means "reference to". A reference is similar to a pointer, except that you don't need to prefix `*` to access the value referred to by the reference. Also, a reference cannot be made to refer to a different object after it has been initialized.

When used in declarations, operators (such as `&`, `*`, and `[]`) are called *declarator operators*:

```cpp
T a[n];        // T[n]: array of n Ts
T* p;          // T*: pointer to T
T& r;          // T&: reference to T
T f(A);        // T(A): function taking argument of type A returning a result of type T
```

We try to ensure that a pointer always points to a valid object, so that dereferencing it is valid. When we don't have an object to point to, or if we need to represent "no object available" (e.g. for an end of a list), we give the pointer the value `nullptr` ("the null pointer").

There is only one `nullptr` by all pointer types:
```cpp
double* pd = nullptr;
Link<Record>* lst = nullptr;  // pointer to a Link to a Record
int x = nullptr;              // error: nullptr is a pointer, not an integer
```

It is a good idea to check that a pointer argument actually points to something:
```cpp
int count_x(char* p, char x)
{
    if (p == nullptr) return 0;
    int count = 0;
    for (; *p != 0; ++p)
    if (*p == x) ++ count;
    return count;
}
```
Note how you can move a pointer to point to the next element in an array by incrementing it, and that you can leave out the initializer in the `for` statement.

The definition of `count_x` assumesthat `char*` is a C-style string, i.e., the pointer points to a sequence of characters terminated by a null character `'\0'`. 

In older code, `0` or `NULL` is typically used instead of `nullptr`. However, using `nullptr`  elminates potential confusion between integers (such as `0` and `NULL`) and pointers (such as `nullptr`).


### 2.3 User-Defined Types

Built-in types are those that are built from the fundamental types (`int`, `char`, `double`, etc.), the `const` modifer, and the declarator operators (`*`, `&`, `[]`, and `()`).

These built-in types are rich but deliberately low level, as they are intended to reflect the capabilities of conventional computer hardware. However, these built-in types don't provide the programmer with high-level facilities to conveniently write advanced applications.

Instead, C++ augments the built-in types and operations with a set of *abstract mechanisms* out of which the programmer can build high-level facilities.

Types built out of the built-in types using C++'s abstract mechanisms are called *user-defined types*. They are referred to as classes and enumerations.

#### 2.3.1 Structures

The first step in building a new type is to organize its elements into a data structure:

```cpp
struct Vector {
    int sz;
    double* elem;
};
```
A variable of type `Vector` can be declared like this:
```cpp
Vector v;
```
But this is not useful, as `v`'s `elem` pointer doesn't point to anything. To be useful, you must give it some elements to point to:
```cpp
void vector_init(Vector& v, int s)
{
    v.elem = new double[s]; // allocate an array of doubles
    v.sz = s;
}
```

- `v`'s `elem` member gets a pointer produced by the `new` operator and `v`'s `sz` member gets the number of elements in the array.
- The `&`in `Vector&` indicates that we pass `v` by non-`const` reference; that way, `vector_init` can modify the vector passed to it.

A simple use of `Vector` looks like this:
```cpp
double read_and_sum(int s)
{
    Vector v;
    vector_init(v, s); // allocate s elements for v
    for (int i=0; i != s; ++i)
        cin >> v.elem[i]; // read into v.elem[i]
    double sum = 0;
    for (int i=0; i != s; ++i)
        sum += v.elem[i]; // sum the elements
    return sum;
}
```

We use `.` (dot) to access `struct` members through a name (and through a reference) and `->` to access `struct` members through a pointer.
```cpp
void f(Vector v, Vector& rv, Vector* pv)
{
    int i1 = v.sz;  // accessing a member through a name
    int i2 = rv.sz; // accessing a member through a reference
    int i3 = pv->sz; // accessing a member through a pointer
}
```
This means:
- `v` is passed by value → a copy of a Vector object is made.
- `rv` is passed by reference → no copy is made, it refers directly to the original Vector.
- `pv` is passed by pointer → you receive a pointer to a Vector (you must dereference it to access members).

| Parameter    | Access            | Copy? | Syntax   | Notes                                               |
| :----------- | :---------------- | :---- | :------- | :-------------------------------------------------- |
| `Vector v`   | Local copy        | Yes   | `v.sz`   | Changing `v` only changes the copy                  |
| `Vector& rv` | Original object   | No    | `rv.sz`  | Changes affect the original                         |
| `Vector* pv` | Pointer to object | No    | `pv->sz` | Changes affect the original (pointer must be valid) |

#### 2.3.2 Classes

Structs and classes are similar in that they allow you to separate operations from data. Classes are more powerful than structs because they enable you to model a "real type". 

A real type is a type that:
* **Hides its internal representation** from users
* **Provides a clear, consistent interface**
* **Allows safe future changes** to how data is represented internally

This is important because early in C and old C++ (pre-classes), a `struct` was just a simple **bag of public data** — no hiding, no safety, no real abstraction.

A class is defined to have a set of *members*, which can be data, function, or type members.

The interface is defined by the *public* members of the class, and *private* members are accessible only through the interface.

```cpp
class Vector {
public:
    Vector(int s) : elem{new double[s]}, sz{s} {}   // construct a Vector
    double& operator[](int i) { return elem[i]; }   // element access: subscripting
    int size() { return sz; }

private:
    double* elem;   // pointer to the elements
    int sz;         // the number of elements
};
```

You can define a variable of type `Vector` like this:
```cpp
Vector v(6);
```

In this sense, `Vector` is a "handle" containing a pointer to the elements (`elem`) and the size of the vector (`sz`). 

```cpp
#include <iostream>

class Vector {
public:
    Vector(int s) : elem{new double[s]}, sz{s} {}   // construct a Vector
    double& operator[](int i) { return elem[i]; }   // element access: subscripting
    int size() { return sz; }

private:
    double* elem;   // pointer to the elements
    int sz;         // the number of elements
};

double read_and_sum(int s)
{
    Vector v(s);
    for (int i = 0; i != v.size(); ++i) {
        std::cin >> v[i];
    }
    double sum = 0;
    for (int i = 0; i != v.size(); ++i) {
        sum += v[i];
    }
    return sum;
}

int main()
{
    std::cout << read_and_sum(5);
}
```
**Note:**  
- The constructor `Vector()` replaces the `vector_init()` function used in the previous example.
- Unlike the `vector_init()` function, the constructor guarantees that the `Vector` object is fully initialized when it is created.

#### 2.3.3 Enumerations

C++ supports a simple form of a user-defined type called an *enumeration*, which is a set of named integer constants.

```cpp
enum class Color { red, green, blue }; 
enum class Traffic_light { red, yellow, green }; 
Color col = Color::red;
Traffic_light light = Traffic_light::red;
```
**Note:**  
- Enumerators (e.g., `red`) are in the scope of their `enum class`, so `Color::red` and `Traffic_light::red` can be different.
- Enumerations are used to represent small sets of integer values and are intended to make code more readable and less error-prone instead of using plain integers.
- The `class` after the `enum` prevents accidental misuses of constants:

```cpp
Color x = red; // error: which red?
Color y = Traffic_light::red; // error: that red is not a Color
Color z = Color::red; // OK: this red is a Color
```

By default, an `enum class` has only assignment, initialization, and comparisons defined. However, you can define your own operators:

```cpp
Traffic_light& operator++(Traffic_light& t)
{
    switch (t) {
        case Traffic_light::green: return t  = Traffic_light::yellow;
        case Traffic_light::yellow: return t = Traffic_light::red;
        case Traffic_light::red: return t    = Traffic_light::green;
    }
}

Traffic_light next = ++light;
```

#### 2.4 Modularity

A C** program consists of functions, user-defined types, class hierarchies, and templates. The key to managing this is to define the interactions among those parts. The first and foremost step is to distinguish between the *interface* and its *implementation*.

A *declaration* specifies all that's needed to use a function or type:

```cpp
double sqrt(double);            // Declaration

class Vector {
public:
    Vector(int s);              // Declaration of constructor
    double& operator[](int i);  // Declaration of subscript operator
    int size();                 // Declaration of size function
private:
    double* elem;
    int sz;
};
```

Elsewhere, you define the implementation: 

```cpp
double sqrt(double d)
{
    // ..algorithm as found in math textbook..
}

Vector::Vector(int s) : elem{new double[s]}, sz{s}
{
}

double& Vector::operator[](int i) // definition of subscript operator
{
    return elem[i];
}

int Vector::size()  // definition of size member function
{
    return sz;
}
```

**Note:** You must define `Vector`'s functions, but not `sqrt()` because it is defined in the standard library.

##### 2.4.1 Separate Compilation

Separate compilation is where user code sees only declarations of the types and functions used. The definitions are in separate source files and compiled separately. Such separation can be used to minimize compile times and to strictly enforce separation of logically distinct parts of a program (thus minimizing the chance of errors).

A library is often a collection of separately compiled code fragments (e.g. functions).

Typically, we place declarations that specify the interface to a module in a file with a name indicating its intended use:

```cpp
// Vector.h

class Vector {
public:
    Vector(int s);
    double& operator[](int i);
    int size();
private:
    double* elem;
    int sz;
};
```

Then users will include that header file to access that interface:

```cpp
#include "Vector.h"     // get Vector's interface
#include <cmath>        // get the standard-library math function interface including sqrt()
using namespace std;    // makd std members visible

double sqrt_sum(Vector& v)
{
    double sum = 0;
    for (int i = 0; i != v.size(); ++i) 
        sume += sqrt(v[i]);
    return sum;
}
```

The `.cpp` file providing the implementation of `Vector` will also include the `.h` file providing its interface:

```cpp
// Vector.cpp

#include "Vector.h"     // get Vector's interface

Vector::Vector(int s) : elem{new double[s]}, sz{s}
{
}

double& Vector::operator[](int i)
{
    return elem[i];
}

int Vector::size()
{
    return sz;
}
```

Here's how the code fragments work together:

![](./images/20250524-codeseparation.svg)

Code separation is very important. The best approach is to maximize modularity, represent that modularity logically through language features, and then exploit the modularity through files for effective separate compilation.

##### 2.4.2 Namespaces

Namespaces are a mechanism for expressing that some declarations belong together and that their names shouldn't clash with other names.

```cpp
namespace My_code {
    class complex { /* ... */ };
    complex sqrt(complex);
    // ...
    int main(); // scoped to My_code namespace
}

int My_code::main()
{
    complex z{1, 2};
    auto z2 = sqrt(z);
    std::cout << '{' << z2.real() << ',' << z2.imag() << "}\n";
    // ...
};

int main()
{
    return My_code::main();  // Qualifying the call to My_code's main function
}
```

To gain access to the names in a namespace, you can use the `using` directive:

```cpp
using namespace My_code;
```

##### 2.4.3 Error Handling

One effect of this modularity and the use of libraries is that the point where a run-time error can be detected is separated from the point where it can be handled.

###### 2.4.3.1 Exceptions

What ought to be done when an error occurs?
- The writer/implementer doesn't know what the user would like to have done.
- The user cannot consistently detect the problem.

The solution is to detect the error and then transfer control to a handler that can deal with the error:

```cpp
double& Vector::operator[](int i)
{
    if (i < 0 || size() <= i) throw out_of_range{"Vector::operator[]"};
    return elem[i];
}
```

The `throw` transfers control to a handler for exceptions of type `out_of_range` in some function that directly or indirectly called `Vector::operator[]`.

The implementation unwinds the function call stack as needed to get back to the context of that caller:

```cpp
void f(Vector& v)
{
    // ...
    try { // exceptions are handled by the handler defined below
        v[v.size()] = 7; // try to access beyond the end of v
    }
    catch (out_of_range& e) { // oops: out_of_range error
        // ... handle range error ...
    }
    // ...
}
```

The `out_of_range` type is defined in the standard library (in `<stdexcept>`).

###### 2.4.3.2 Invariants

An *invariant* is a condition that is always true at a particular point in a program.

It is the job of a constructor to establish the invariant for its class (so that the member functions can rely on it) and for the member functions to make sure the invariant holds when they exit.

```cpp
Vector v(-27);  // will cause chaos because the invariant is not established
```

```cpp
Vector::Vector(int s)
{
    if (s < 0) throw length_error{};    // establish the invariant
    elem = new double[s];
    sz = s;
}
```

```cpp
void test()
{
    // Make sure the invariant holds
    try {
        Vector v(-27);
    }
    catch (std::length_error) {
        // handle negative size
    }
    catch (std::bad_alloc) {    // if `new` can't find memory to allocate `length_error`
        // handle memory exhaustion
    }
}
```

The notion of invariants is central to the design of classes, and preconditions serve a similar role in the design of functions. Invariants
- help us to understand precisely what we want
- force us to be specific; that gives us a better chance of getting our code correct

###### 2.4.3.3 Static Assertions





















        

    