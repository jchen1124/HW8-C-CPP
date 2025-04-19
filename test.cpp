// Test file for the c++ version

#include "matrix.h"

int main(){
    Matrix A(2,2);
    A.fillMatrix(0, 0, 6);
    A.fillMatrix(0, 1, 4);
    A.fillMatrix(1, 0, 8);
    A.fillMatrix(1, 1, 3);

    // This a test to check for an error case
//    Matrix A(3,2);  // Error case: Dimensions don't match with 2x2 product
//     A.fillMatrix(0, 0, 6);
//     A.fillMatrix(0, 1, 4);
//     A.fillMatrix(1, 0, 8);
//     A.fillMatrix(1, 1, 3);
//     A.fillMatrix(2, 0, 1);
//     A.fillMatrix(2, 1, 9);



   Matrix B(2, 3);
   B.fillMatrix(0, 0, 1);
   B.fillMatrix(0, 1, 2);
   B.fillMatrix(0, 2, 3);
   B.fillMatrix(1, 0, 4);
   B.fillMatrix(1, 1, 5);
   B.fillMatrix(1, 2, 6);

   //B.printMatrix(2,3);

   Matrix C(2, 3);
   C.fillMatrix(0, 0, 2);
   C.fillMatrix(0, 1, 4);
   C.fillMatrix(0, 2, 6);
   C.fillMatrix(1, 0, 1);
   C.fillMatrix(1, 1, 3);
   C.fillMatrix(1, 2, 5);

   //C.printMatrix(2,3);

   Matrix scaledB = B.scalarMultiplication(3);
   Matrix transposeC = C.transpose();
   Matrix product = scaledB.multiply(transposeC);
   Matrix D = A.addMatrix(product);

   //B.printMatrix(2,3);
   D.printMatrix();




}