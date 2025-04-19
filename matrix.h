#include <iostream>
using namespace std;

#ifndef MATRIX_H
#define MATRIX_H


class Matrix{

    public:
    Matrix(int rows, int columns);
    ~Matrix();
    Matrix(const Matrix& rhs);

    void fillMatrix(int row, int column, int value);
    void printMatrix();

    // Functions type matrix to return a new matrix object
    Matrix scalarMultiplication(int scalar);
    Matrix addMatrix(const Matrix& other);
    Matrix transpose();
    Matrix multiply(const Matrix& other);
    


    private:
    int** matrix;
    int m_rows;
    int m_columns;


};




#endif
