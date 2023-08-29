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

// Copy Constructor:
    Matrix<Type>& operator=(const Matrix<Type>& t);
    Matrix( const Matrix<Type>& matrix ) { *this = matrix;}

// Arithimatic Operators Override:
    // Addition:
    template <class U>
    friend Matrix<U> operator+(Matrix<U> const& left, Matrix<U> const& right);

    //Subtraction:
    template <class U>
    friend Matrix<U> operator-(Matrix<U> const& left, Matrix<U> const& right);

    // Multiplication:
    template <class U>
    friend Matrix<double> operator*(double const& a, Matrix<U> const& right);
    template <class U>
    friend Matrix<double> operator*(Matrix<U> const& left, double const& a);

    // Division:
    template <class U>
    friend Matrix<double> operator/(Matrix<U> const& left, double const& a);

// Printing Methods:
    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& dt);

// Casting:
    Matrix<int> double_to_int();

// Destructors:
    ~Matrix()
    {
        num_rows = 0; num_cols = 0;
        for(int i = 0; i < this->num_rows; i++)
            std::vector<Type>().swap(mat[i]);
        std::vector< std::vector<Type> >().swap(mat);
    }

    void operator delete(void* ptr) { ::operator delete(ptr);}
};
#endif