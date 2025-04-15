# Program: Generalized Makefile for Chapter 2 Programs
# Context: Chapter 2 from "The C++ Programming Language" by Bjarne Stroustrup
# Author: Greg Tate
# Date: April 14, 2025
# Synopsis: This Makefile automatically compiles all C++ source files in the
#           current directory and provides a clean target to remove compiled files.

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic
SOURCES = $(wildcard *.cpp)
TARGETS = $(SOURCES:.cpp=)

all: $(TARGETS)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)
