# HW8 - C VS C++

## Author
Jason Chen<br>
CMSC 313 - MW 2:30 - 3:45

## Purpose Of Software 
The purpose of this software is to demonstrate the implementation of the basic matrix manipulation in both C and C++. It includes operations like scalar multiplication, matrix addition, transpose and matrix multiplication.

## Files
### Matrix.h
- Contains the class declaration for the Matrix class
- Defines the public and private member functions and variables used for matrix operations.

### Matrix.cpp
- Implements the member functions declared in Matrix.h, such as scalar multiplication, addition, transpose, and multiplication.
- Manages dynamic memory allocation and deallocation.

### Test.cpp
- Contains the main function to test and demonstrate the functionality of the Matrix class.
- Runs examples for various matrix operations and prints the results.

### Matrix.c
- The C version of the Matrix library program
- Contains matrix operations similar to the one in the Matrix.cpp file
- Contains the main function to test different matrix operations.

### makefile
- 

## Build Instructions (How to use the library)
- First, create a matrix and give it dimensions
    - Ex. Matrix A(2, 2) (This will create a 2x2 matrix labeled Matrix A)

- Next, Fill in the matrix by entering the index and the value you want to put at that index
    - Ex. A.fillMatrix(0, 0, 6) (At index 0,0 you will fill it with a 6)

- After you fill it, you can call functions to perform any matrix operations

## Testing Methodology
- Edge Case Testing - Testing matrix operations like adding and multiplying with matrix of different dimensions.

- Manual Test Cases:
    - Specific matrices were hardcoded into main.cpp to test individual operations like addition, scalar multiplication, transpose, and matrix multiplication.
    -  Known input-output pairs were used to verify correctness.

