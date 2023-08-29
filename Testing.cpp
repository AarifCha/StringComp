#include <iostream>
#include <vector>
#include "Matrix.h"
#include "Matrix.cpp"

int main()
{
    Matrix<int> A1(126,126,1);
    Matrix<int> A2(3,3,2);
    Matrix<double> *B = new Matrix<double>(2,2,1);
    *B = A2/2;

    Matrix<int> A3 = (A2-A2);

    std::cout << A2.MatrixString() << std::endl;
    std::cout << A3.MatrixString() << std::endl;
    std::cout << B->double_to_int().MatrixString() << std::endl;

//    A1.printMatrix();

    delete B;
    return 0;
}