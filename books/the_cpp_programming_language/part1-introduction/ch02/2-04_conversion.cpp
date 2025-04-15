/*
 * Program: Conversion and Truncation of Types
 * Context: Chapter 2, "The C++ Programming Language" by Bjarne Stroustrup
 * Author: Greg Tate
 * Date: 2023-10-07
 *
 * Synopsis:
 * This program demonstrates type conversion in C++ by adding a double and an int,
 * and then converting the result back to an int, showcasing truncation.
 */

#include <iostream>

int main() {
    std::cout << "Demonstrating conversation (and truncating) of double to int:\n";
    double d = 2.2;
    int i = 7;
    d = d + i;
    std::cout << "Result of double + int: " << d << "\n";
    i = d * i;
    std::cout << "Result of double to int conversion: " << i << "\n";
}