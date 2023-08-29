#include <iostream>
#include <vector>
#include "Matrix.h"

int main()
{
    Matrix<int> A1(3,3,1);
    Matrix<int> A2(3,3,2);

    Matrix<int> A3 = A1+A2;

//    std::cout << A2.MatrixString() <<std::endl;
//    std::cout << A3.MatrixString();

//    A2.printMatrix();

    return 0;
}