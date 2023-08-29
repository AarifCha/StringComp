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
    std::vector< std::vector<Type> > mat;
    
public:

// Constructors:
    Matrix(int num_rows, int num_cols, Type s);

// Getters:
    int get_num_rows() const { return num_rows; } 
    int get_num_cols() const { return num_cols; }

// Setters and Getters Operators Override:
    std::vector<Type>& operator[] (int row){ return mat[row]; }
    const std::vector<Type>& operator[] (int row) const { return mat[row]; }

// Arithimatic Operators Override:
    // Addition:
    friend Matrix<int> operator+(Matrix<int> const& left, Matrix<int> const& right);
    friend Matrix<double> operator+(Matrix<double> const& left, Matrix<double> const& right);

    // Multiplication:
    friend Matrix<double> operator*(double const& a, Matrix<int> const& right);
    friend Matrix<double> operator*(double const& a, Matrix<double> const& right);
    friend Matrix<double> operator*(Matrix<int> const& left, double const& a);
    friend Matrix<double> operator*(Matrix<double> const& left, double const& a);

    // Division:
    friend Matrix<double> operator/(Matrix<int> const& left, double const& a);
    friend Matrix<double> operator/(Matrix<double> const& left, double const& a);

    //Subtraction:
    friend Matrix<double> operator-(Matrix<double> const& left, Matrix<double> const& right);
    friend Matrix<int> operator-(Matrix<int> const& left, Matrix<int> const& right);

// Printing Methods:
    void printMatrix() const;
    std::string MatrixString() const;

// Casting:
    Matrix<int> double_to_int();

// Destructors:
    ~Matrix()
    {
        for(int i = 0; i < this->num_rows; i++)
            std::vector<Type>().swap(mat[i]);
        std::vector< std::vector<Type> >().swap(mat);
    }
    
    void operator delete(void* ptr) { ::operator delete(ptr);}
};
#endif