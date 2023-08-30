#include <iostream>
#include <vector>
#include "Matrix.h"
#include "Matrix.cpp"

int main()
{
   /* Matrix<int> A1(2,2,1);
    Matrix<int> A2(3,3,2);
    Matrix<double> *B = new Matrix<double>(2,2,1.5);
    *B = A1/2;
    Matrix<int> B2(A2-A2);

    Matrix<int> A3 = (A2+A2);

    std::cout << A1 << std::endl;
    std::cout << A3 << std::endl;
    std::cout << B->double_to_int() << std::endl;
    std::cout << *B << std::endl;

    delete B; */

    Matrix<int> A(4,4,0);
    A[0][0] =  2; A[0][1] = -1; A[0][2] = -2; A[0][3] = 1;
    A[1][0] = -11; A[1][1] =  6; A[1][2] =  3; A[1][3] = 3;
    A[2][0] = -4; A[2][1] = -2; A[2][2] =  8; A[2][3] = -2;
    A[3][0] = 1; A[3][1] = 11; A[3][2] =  -5; A[3][3] = 3;

    std::cout<<A.det()<<std::endl;

    return 0;
}