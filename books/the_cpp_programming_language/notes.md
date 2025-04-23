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
int i1 = 7.2;   // Implicit conversion from double to int
int i2{7};      // Corrected: Removed narrowing conversion
int i3 {7};     // Allows for spaces in initialization
int i4{7.2};    // error: floating-point integer narrowing conversion
int i5 = {7};   // Corrected: Fixed syntax error
```

- Use the general `{}`-list form when in doubt with initialization; it saves you from conversions thatlose information (narrowing conversions).


