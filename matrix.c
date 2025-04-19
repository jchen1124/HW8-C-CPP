#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int **matrix;
    int m_rows;
    int m_columns;
} Matrix;

Matrix createMatrix(int rows, int columns){
    Matrix m;
    m.m_rows = rows;
    m.m_columns = columns;
    // Allocated memory
    m.matrix = (int **)malloc(m.m_rows * sizeof(int *));
    for (int i = 0; i < m.m_rows; i++)
    {
        m.matrix[i] = (int *)malloc(m.m_columns * sizeof(int));
        // Initalize everything to zero
        for (int j = 0; j < m.m_columns; j++)
        {
            m.matrix[i][j] = 0;
        }
    }

    return m;
}

void deallocateMatrix(Matrix *m){
    for (int i = 0; i < m->m_rows; i++)
    {
        // Free the memory
        free(m->matrix[i]);
    }
    free(m->matrix);
    // m->matrix = NULL;
    m->m_rows = 0;
    m->m_columns = 0;
}

void fillMatrix(Matrix *m, int row, int column, int value){
    m->matrix[row][column] = value;
}

void printMatrix(Matrix *m){
    for (int i = 0; i < m->m_rows; i++)
    {
        for (int j = 0; j < m->m_columns; j++)
        {
            printf("%d" "%s", m->matrix[i][j], " ");
        }
        printf("\n");
    }
}

Matrix scalarMultiplication(Matrix* m, int scalar){
    //New matrix
    Matrix result = createMatrix(m->m_rows, m->m_columns);

    for (int i = 0; i < m->m_rows; i++){
        for (int j = 0; j < m->m_columns; j++){
            result.matrix[i][j] = m->matrix[i][j] * scalar;
        }
        
    }
    return result;
    

}

Matrix addMatrix(Matrix* a, Matrix* b){
    //condition check 
    if(a->m_rows != b->m_rows || a->m_columns != b->m_columns){
        fprintf(stderr, "Error: Matrix dimensions do not match for addition.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result = createMatrix(a->m_rows, a->m_columns);

    for (int i = 0; i < a->m_rows; i++){
        for (int j = 0; j < a->m_columns; j++){
            result.matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
        
    }
    return result;
    
}

Matrix transpose(Matrix* m){
    Matrix result = createMatrix(m->m_columns, m->m_rows);

    for (int i = 0; i < m->m_rows; i++){
        for (int j = 0; j < m->m_columns; j++){
            result.matrix[j][i] = m->matrix[i][j];
        }
        
    }
    return result;
    
}

Matrix multiply(Matrix* a, Matrix* b){

    // The number of columns in A has to match the numbr of rows in b
    if(a->m_columns != b->m_rows){
        fprintf(stderr, "Error: Matrix dimensions do not match for addition.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result = createMatrix(a->m_rows, b->m_columns);

    for (int i = 0; i < a->m_rows; i++){
        for (int j = 0; j < b->m_columns; j++){
            for (int x = 0; x < a->m_columns; x++){
                result.matrix[i][j] += a->matrix[i][x] * b->matrix[x][j];
            }
            
        }
        
    }
    return result;
    
}

int main(){

    // Testing

    Matrix A = createMatrix(2, 2);

    fillMatrix(&A, 0, 0, 6);
    fillMatrix(&A, 0, 1, 4);
    fillMatrix(&A, 1, 0, 8);
    fillMatrix(&A, 1, 1, 3);

    Matrix B = createMatrix(2, 3);
    fillMatrix(&B, 0, 0, 1);
    fillMatrix(&B, 0, 1, 2);
    fillMatrix(&B, 0, 2, 3);
    fillMatrix(&B, 1, 0, 4);
    fillMatrix(&B, 1, 1, 5);
    fillMatrix(&B, 1, 2, 6);

    //printMatrix(&A);

    //printf("\n");

    // Creating a 2x3 matrix
    Matrix C = createMatrix(2, 3);
    fillMatrix(&C, 0, 0, 2);
    fillMatrix(&C, 0, 1, 4);
    fillMatrix(&C, 0, 2, 6);
    fillMatrix(&C, 1, 0, 1);
    fillMatrix(&C, 1, 1, 3);
    fillMatrix(&C, 1, 2, 5);

    Matrix scalarB = scalarMultiplication(&B, 3);
    Matrix cTranspose = transpose(&C);
    Matrix product = multiply(&scalarB, &cTranspose);
    Matrix result = addMatrix(&A, &product);

    printMatrix(&result);





    
}
