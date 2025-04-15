/*
 * Program: Variable Initialization
 * Context: Chapter 2, "The C++ Programming Language" by Bjarne Stroustrup
 * Author: Greg Tate
 * Date: 2023-10-07
 *
 * Synopsis:
 * This program demonstrates different ways to initialize variables in C++,
 * including implicit conversions and errors caused by narrowing conversions.
 */

#include <iostream>

int main() {
    std::cout << "Demonstrating initialization of variables:\n";
    int i1 = 7.2;   // Implicit conversion from double to int
    int i2{7};      // Corrected: Removed narrowing conversion
    int i3 = {7};   // Corrected: Fixed syntax error
}