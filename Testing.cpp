#include <iostream>
#include <vector>
#include "Matrix.h"
#include "Matrix.cpp"

int main()
{
    Matrix<int> A1(3,3,1);
    Matrix<int> A2(3,3,2);

    Matrix<double> A3 = (2*A2);

    std::cout << A2.MatrixString() <<std::endl;
    std::cout << A3.MatrixString();

//    A1.printMatrix();
    std::cout<<"Hello World!";

 //   A1.~Matrix(); A2.~Matrix(); A3.~Matrix(); 
    return 0;
}