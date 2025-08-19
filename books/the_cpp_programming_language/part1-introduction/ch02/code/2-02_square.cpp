/*
 * Program: Square Calculation
 * Context: Chapter 2.2 from "The C++ Programming Language" by Bjarne Stroustrup
 * Author: Greg Tate
 * Date: April 14, 2025
 * Synopsis: This program defines a function to calculate the square of a number
 *           and prints the result for a given input.
 */

#include <iostream>
using namespace std;

double square(double x) {
    return x * x;
}

void print_square(double x) {
    cout << "The square of " << x << " is " << square(x) << "\n";
}

int main() {
    print_square(2);
}