#include <iostream>
#include <vector>
#include "Matrix.h"
#include "Matrix.cpp"

int main()
{
    Matrix<int> A1(2,2,1);
    Matrix<int> A2(3,3,2);
    Matrix<double> *B = new Matrix<double>(2,2,1.5);
    *B = A1/2;

    Matrix<int> A3 = (A2+A2);

    std::cout << A1 << std::endl;
    std::cout << A3 << std::endl;
    std::cout << B->double_to_int() << std::endl;
    std::cout << *B << std::endl;

    delete B;
    return 0;
}