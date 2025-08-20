<!-- omit in toc -->
# 3. A Tour of C++ Abstraction Mechanisms
- [3.1 Introduction](#31-introduction)
- [3.2 Classes](#32-classes)
  - [3.2.1 Concrete Types](#321-concrete-types)
    - [3.2.1.1 An Arithmetic Type](#3211-an-arithmetic-type)
    - [3.2.1.2 A Container](#3212-a-container)

## 3.1 Introduction

This chapter introduces C++ features for abstraction and resource management without going into detail. It shows how to define and use user-defined types, focusing on concrete classes, abstract classes, and class hierarchies. Templates are presented as a way to parameterize types and algorithms with other types and algorithms. Computations on both built-in and user-defined types appear as functions, which can be generalized into template functions or function objects. These features support object-oriented and generic programming.

The following two chapters provide examples of standard-library facilities and their usage. This chapter assumes you have prior programming experience. If not, it is recommended to first read a textbook such as *Programming: Principles and Practice Using C++* \[Stroustrup, 2009]. Even with prior experience, the language or style you know may differ greatly from what is presented here. If this quick overview feels unclear, skip ahead to the more systematic explanations starting in Chapter 6.

As in Chapter 2, this overview presents C++ as a unified language rather than separating features by origin. It does not mark which parts come from C, C++98, or C++11. That historical information can be found in §1.4 and Chapter 44.

## 3.2 Classes

The core feature of C++ is the class. A class is a user-defined type that represents a concept within a program. Whenever a design includes a useful concept or entity, it should be modeled as a class so the idea exists directly in the code, not just in our head, in documentation, or in comments.

Programs built from a well-chosen set of classes are much easier to understand and maintain than those relying only on built-in types. Libraries themselves are often collections of classes. Nearly all C++ features beyond basic types, operators, and statements exist to help define or use classes more effectively. By “better,” we mean classes that are correct, efficient, elegant, easy to use, maintain, and reason about.

Most programming techniques depend on designing and implementing specific kinds of classes. Because programmer needs and preferences vary widely, C++ offers broad support for class design. This chapter focuses on three key kinds: concrete classes (§3.2.1), abstract classes (§3.2.2), and classes in hierarchies (§3.2.4). A remarkable number of useful classes fall into these categories, while many others are variations or combinations of these basic forms.

### 3.2.1 Concrete Types

Concrete classes are designed to behave like built-in types. For example, a complex number type or an infinite-precision integer works much like an `int`, though with its own semantics and operations. Likewise, `vector` and `string` resemble arrays but offer safer and more consistent behavior.

The key property of a concrete type is that its representation is part of its definition. In many cases—such as `vector`—this representation may just be one or more pointers to data stored elsewhere, but every object still contains that representation. This enables efficient use of time and space. Specifically, concrete types allow us to:

* place objects on the stack, in static memory, or inside other objects (§6.4.2)
* refer to objects directly, not just through pointers or references
* initialize objects fully and immediately using constructors (§2.3.2)
* copy objects (§3.3)

The representation can be private and accessible only through member functions, as in `Vector`. Still, it is present in each object, meaning that significant representation changes require recompilation. This tradeoff is worthwhile for types that rarely change, since local variables benefit from the clarity and efficiency of concrete classes.

To improve flexibility, a concrete class may store much of its data in dynamic memory while keeping only a handle inside the class object itself. This is how `vector` and `string` are implemented—they serve as resource handles with carefully designed interfaces.

#### 3.2.1.1 An Arithmetic Type

The “classic user-defined arithmetic type” is `complex`:

```cpp
class complex {
    double re, im;                                  // representation: two doubles
public:
    complex(double r, double i) : re{r}, im{i} {}   // construct from two scalars, using list-form initilization
    complex(double r) : re{r}, im{0} {}             // construct from one scalar
    complex() : re{0}, im{0} {}                     // default constructor {0,0}

    double real() const { return re; }              // const specifier means this function does not modify the object
    void real(double d) { re = d; }

    double imag() const { return im; }
    void imag(double d) { im = d; }

    // Introducing the operator keyword 
    complex& operator+=(complex z) { re += z.re; im += z.im; return *this; }   
    complex& operator-=(complex z) { re -= z.re; im -= z.im; return *this; }

    complex& operator*=(complex);                   // defined elsewhere
    complex& operator/=(complex);                   // defined elsewhere
};
```

This simplified version of the standard-library `complex` (§40.4) defines only the operations that need direct access to its representation. The design is conventional and efficient, partly because of compatibility with Fortran conventions. Efficiency requires inlining simple operations like constructors, `+=`, and accessors. In C++, functions defined inside a class are inlined by default. The default constructor `complex()` ensures no variables of this type remain uninitialized. The `const` specifier on `real()` and `imag()` means those functions do not modify the object.

Many useful operations don’t need direct access to the representation, so they can be defined outside the class:

```cpp
complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a -= b; }
complex operator-(complex a) { return { -a.real(), -a.imag() }; }   // unary minus
complex operator*(complex a, complex b) { return a *= b; }
complex operator/(complex a, complex b) { return a /= b; }
```

Here, parameters are passed by value, creating local copies. This allows modification inside the function without affecting the caller’s objects, and the modified copy is returned as the result. Equality operators are straightforward:

```cpp
bool operator==(complex a, complex b) {                     // Parameters passed by value, creating local copies
    return a.real() == b.real() && a.imag() == b.imag();
}

bool operator!=(complex a, complex b) {
    return !(a == b);                                       // Modified copy is returned as the result
}
```

Additional operations like `sqrt(complex)` can also be defined.

Usage example:

```cpp
void f(complex z) {
                                                // List initialization picks the best-matching constructor
    complex a {2.3};                            // calls complex(double) with r=2.3, sets im=0
    complex b {1 / a};                          // The compiler automatically converts 1 to temporary complex{1.0,0.0}
    complex c {a + z * complex{1, 2.3}};        

    if (c != b)
        c = -(b / a) + 2 * b;
}
```

The compiler translates operator expressions into function calls. For instance, `c != b` becomes `operator!=(c, b)`, and `1 / a` becomes `operator/(complex{1}, a)`. Operator overloading should be used sparingly and in line with conventional meaning. 

C++ fixes the syntax, so you cannot invent new operators (e.g., a unary `/`), nor can you change how operators work for built-in types.

#### 3.2.1.2 A Container

A container is an object that holds a collection of elements. Vector is a container type because it stores such collections. As defined in §2.3.2, Vector is a reasonable container for doubles: it’s simple, maintains a useful invariant (i.e. consistent relationship between its members), provides range-checked access (§2.4.3.1), and has size() for iteration.

Its flaw is that it allocates memory with new but never deallocates it. This is dangerous because C++ provides only an optional garbage collector (§34.5). In many environments, a collector isn’t available, and even when it is, developers often prefer precise control over resource cleanup (§13.6.4) for logical or performance reasons. To fix this, a destructor must release any memory allocated by the constructor.

```cpp
class Vector {
private:
    double* elem;                                       // points to an array of sz doubles
    int sz;
public:
    Vector(int s) : elem{new double[s]}, sz{s}          // constructor: acquire memory. new double returns a pointer to the first element of the array
    {
        for (int i = 0; i != s; ++i) elem[i] = 0;       // initialize elements
    }
    ~Vector() { delete[] elem; }                        // destructor: free memory

    double& operator[](int i);                          // & returns a reference to the i-th element. A reference
    int size() const;
};
```

> Tomorrow:  circle back to double& above

A destructor’s name is the class name prefixed with `~`. It complements the constructor: the constructor allocates memory on the free store (heap), and the destructor frees it. Users of Vector don’t manage this directly; they just create and use objects as with built-in types.

```cpp
void fct(int n)
{
    Vector v(n);
    // ... use v ...
    {
        Vector v2(2*n);
        // ... use v and v2 ...
    }   // v2 destroyed here
    // ... use v ...
}   // v destroyed here
```

Vector follows the same rules of naming, scope, allocation, and lifetime as built-in types like int or char (§6.4). Error handling has been omitted here (§2.4.3).

The constructor/destructor pair is central to many C++ techniques. This pattern, Resource Acquisition Is Initialization (RAII), ensures resources are acquired in a constructor and released in a destructor. It prevents “naked new” and “naked delete” in user code, keeping memory management inside well-designed abstractions. This reduces errors and helps avoid resource leaks (§5.2, §13.3).
