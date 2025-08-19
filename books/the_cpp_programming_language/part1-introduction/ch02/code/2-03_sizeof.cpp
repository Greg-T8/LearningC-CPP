/*
 * Program: Sizeof Fundamental Types
 * Context: Chapter 2, "The C++ Programming Language" by Bjarne Stroustrup
 * Author: Greg Tate
 * Date: April 14, 2025
 *
 * Synopsis:
 * This program demonstrates the use of the `sizeof` operator to display
 * the sizes of fundamental C++ types such as bool, char, int, float, and double.
 */

#include <iostream>

int main() {
    std::cout << "Size chart of C++ fundamental types:\n";
    std::cout << "bool: " << sizeof(bool) << " byte\n";
    std::cout << "char: " << sizeof(char) << " byte\n";
    std::cout << "int: " << sizeof(int) << " bytes\n";
    std::cout << "float: " << sizeof(float) << " bytes\n";
    std::cout << "double: " << sizeof(double) << " bytes\n";
}