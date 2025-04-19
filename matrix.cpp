#include <iostream>
#include "matrix.h"

Matrix::Matrix(int row, int columns){
    //cout << "rows: " << row << endl;
    //cout << "columns: " << columns << endl;
    m_rows = row;            
    m_columns = columns;
    matrix = new int*[row];
    for (int i = 0; i < row; i++){
        matrix[i] = new int[columns];
    }

    // initialize the matrix to all zeros
    for (int i = 0; i < row; i++){
        for (int j = 0; j < columns; j++){
            matrix[i][j] = 0;
        }
    }


}

Matrix::~Matrix(){
    for (int i = 0; i < m_rows; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
    
    m_rows = 0;
    m_columns = 0;

}


void Matrix::fillMatrix(int row, int column, int value){
    matrix[row][column] = value;
}

void Matrix::printMatrix(){
    for (int i = 0; i < m_rows; i++){
        for (int j = 0; j < m_columns; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
        
    }
    
}

Matrix Matrix::scalarMultiplication(int scalar){
    // Varible result
    Matrix result(m_rows, m_columns);

    for (int i = 0; i < m_rows; i++){
        for (int j = 0; j < m_columns; j++){
            result.matrix[i][j] = matrix[i][j] * scalar;
        }
        
    }
    return result;
        
}

Matrix Matrix::addMatrix(const Matrix& other){
    
    Matrix result(m_rows, m_columns);
    for (int i = 0; i < m_rows; ++i)
        for (int j = 0; j < m_columns; ++j)
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];

    return result;
}

Matrix Matrix::transpose()  {

    Matrix result(m_columns, m_rows);
    for (int i = 0; i < m_rows; ++i)
        for (int j = 0; j < m_columns; ++j)
            result.matrix[j][i] = matrix[i][j];
    return result;
}

Matrix Matrix::multiply(const Matrix& other)  {
    Matrix result(m_rows, other.m_columns);
    for (int i = 0; i < m_rows; ++i)
        for (int j = 0; j < other.m_columns; ++j)
            for (int k = 0; k < m_columns; ++k)
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
    return result;
}









