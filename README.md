# rstd

## Introduction

RStd is a C++ general utility (static) library that is intended to speed up the process of development by taking care of a lot of boiler plate code.


## Using RStd

RStd is designed to be easy to use and all functionality of the library can be accessed using only the following code:

`````cpp

#include <RStd/RStd.h>
using namespace RStd;

`````

## Console Utilities

RStd provides quick console utilities:

`````cpp

println("Hello, World!");


print("Enter your name: ");
string name = Console::read();

`````

## File Utilities

RStd provides quick file utilities for testing and non-error checking situations:

`````cpp

FileUtils::write("foo.txt", "Hello, World!");

string contents = FileUtils::read("foo.txt");

println(contents);

`````

