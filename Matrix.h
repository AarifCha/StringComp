#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <string>

template <class Type>

class Matrix
{
private:
    int num_rows, num_cols;
    std::vector<std::vector<Type> > mat;
    
public:

    Matrix(int num_rows, int num_cols, Type s);

    int get_num_rows() const {return num_rows;} 
    int get_num_cols() const {return num_cols;}

    std::vector<Type>& operator[] (int row){ return mat[row]; }
    const std::vector<Type>& operator[] (int row) const { return mat[row]; }

    friend Matrix<int> operator+(Matrix<int> const& left, Matrix<int> const& right);
    friend Matrix<double> operator+(Matrix<double> const& left, Matrix<double> const& right);

    void printMatrix() const;
    std::string MatrixString() const;

};

#endif