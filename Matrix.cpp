#include "Matrix.h"

// Constructor:
template <class Type>
Matrix<Type>::Matrix(int num_rows, int num_cols, Type s) : num_rows(num_rows), num_cols(num_cols)
{
    std::vector<std::vector<Type> > vec( num_rows , std::vector<Type> (num_cols, s));
    mat = vec;
}

// Operator Override:
    // Arithmatic:
Matrix<int> operator+(Matrix<int> const& left, Matrix<int> const& right)
{
    if(left.get_num_rows() != right.get_num_rows() || left.get_num_cols() != right.get_num_cols())
        throw std::invalid_argument("The arrays are not the same size.");
    
    Matrix<int> Res(left.get_num_rows(), left.get_num_cols(),0);
    for(int i = 0; i < Res.get_num_rows(); i++)
        for(int j = 0; j < Res.get_num_cols(); j++)
            Res[i][j] = left[i][j] + right[i][j];

    return Res;
}

Matrix<double> operator+(Matrix<double> const& left, Matrix<double> const& right)
{
    if(left.get_num_rows() != right.get_num_rows() || left.get_num_cols() != right.get_num_cols())
        throw std::invalid_argument("The arrays are not the same size.");
    
    Matrix<double> Res(left.get_num_rows(), left.get_num_cols(),0);
    for(int i = 0; i < Res.get_num_rows(); i++)
        for(int j = 0; j < Res.get_num_cols(); j++)
            Res[i][j] = left[i][j] + right[i][j];

    return Res;
}

Matrix<double> operator*(double const& a, Matrix<int> const& right)
{
    Matrix<double> Res(right.get_num_rows(), right.get_num_cols(),0);
    for(int i = 0; i < Res.get_num_rows(); i++)
        for(int j = 0; j < Res.get_num_cols(); j++)
            Res[i][j] = a*right[i][j];

    return Res;
}

Matrix<double> operator*(double const& a, Matrix<double> const& right)
{
    Matrix<double> Res(right.get_num_rows(), right.get_num_cols(),0);
    for(int i = 0; i < Res.get_num_rows(); i++)
        for(int j = 0; j < Res.get_num_cols(); j++)
            Res[i][j] = a*right[i][j];

    return Res;
}

// Printing Methods:
template <class Type>
std::string Matrix<Type>::MatrixString() const
{
    std::string temp = "";

    for(int i = 0; i < this->num_rows; i++)
    {
        for(int j = 0; j < this->num_cols; j++)
        {
            temp += std::to_string(this->mat[i][j]) + " ";
        }
        temp += "\n";
    }
    return temp;
}

template <class Type>
void Matrix<Type>::printMatrix() const
{
    for(int i = 0; i < this->num_rows; i++)
    {
        for(int j = 0; j < this->num_cols; j++)
        {
            std::cout<<(std::to_string(this->mat[i][j]) + " ");
        }
        std::cout<<std::endl;
    }
}

// Casting:
template <class Type>
Matrix<int> Matrix<Type>::double_to_int()
{
    Matrix<int> temp(this->num_rows, this->num_cols, 0);
    for(int i = 0; i < this->num_rows; i++)
        for(int j = 0; j < this->num_cols; j++)
            temp[i][j] = this->mat[i][j];
    return temp;
    // The original is not deleted so make sure to delete the
    // original copy if not used again, i.e.:
    // Matrix<int> int_Mat = double_Mat.double_to_int();
    // double_Mat.~Matrix();
}