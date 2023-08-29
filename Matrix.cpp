#include "Matrix.h"

// Constructor:
template <class Type>
Matrix<Type>::Matrix(int num_rows, int num_cols, Type s) : num_rows(num_rows), num_cols(num_cols)
{
    std::vector< std::vector<Type> > vec( num_rows , std::vector<Type> (num_cols, s));
    mat = vec;
}

template <class Type>
Matrix<Type>& Matrix<Type>::operator=(const Matrix<Type>& matrix)
{
    this->~Matrix();
    this->num_rows = matrix.get_num_rows();
    this->num_cols = matrix.get_num_cols();

    std::vector< std::vector<Type> > vec( this->num_rows , std::vector<Type> (this->num_cols, matrix[0][0]));
    mat = vec;

    for(int i = 0; i < this->num_rows; i++)
        for(int j = 0; j < this->num_cols; j++)
            this->mat[i][j] = matrix[i][j];
    
    return *this;

}

// Arithmatic Operator Override:

    // Addition:
template <class Type>
Matrix<Type> operator+(Matrix<Type> const& left, Matrix<Type> const& right)
{
    if(left.get_num_rows() != right.get_num_rows() || left.get_num_cols() != right.get_num_cols())
        throw std::invalid_argument("The arrays are not the same size.");
    
    Matrix<Type> Res(left.get_num_rows(), left.get_num_cols(),0);
    for(int i = 0; i < Res.get_num_rows(); i++)
        for(int j = 0; j < Res.get_num_cols(); j++)
            Res[i][j] = left[i][j] + right[i][j];

    return Res;
}

    //Subtraction:
template <class Type>
Matrix<Type> operator-(Matrix<Type> const& left, Matrix<Type> const& right) 
{ 
    if(left.get_num_rows() != right.get_num_rows() || left.get_num_cols() != right.get_num_cols())
        throw std::invalid_argument("The arrays are not the same size.");
    
    Matrix<Type> Res(left.get_num_rows(), left.get_num_cols(),0);
    for(int i = 0; i < Res.get_num_rows(); i++)
        for(int j = 0; j < Res.get_num_cols(); j++)
            Res[i][j] = left[i][j] - right[i][j];

    return Res;
}

    // Multiplication:
template <class Type>
Matrix<double> operator*(double const& a, Matrix<Type> const& right)
{
    Matrix<double> Res(right.get_num_rows(), right.get_num_cols(),0);
    for(int i = 0; i < Res.get_num_rows(); i++)
        for(int j = 0; j < Res.get_num_cols(); j++)
            Res[i][j] = a*right[i][j];

    return Res;
}

template <class Type>
Matrix<double> operator*(Matrix<Type> const& left, double const& a) { return a * left; }

    // Division:
template <class Type>
Matrix<double> operator/(Matrix<Type> const& left, double const& a) { return 1/a * left; }

// Printing Methods:
template <class Type>
std::ostream& operator<<(std::ostream& os, const Matrix<Type>& matrix)
{
    if( matrix.get_num_rows() <= 5 && matrix.get_num_cols() <=5 )    
    {
        for(int i = 0; i < matrix.get_num_rows(); i++)
        {
            os<<"| ";
            for(int j = 0; j < matrix.get_num_cols()-1; j++)
            {
                os<< matrix[i][j] << "\t";
            }
            os<<matrix[i][matrix.get_num_cols()-1]<<" |"<<std::endl;
        }
    }
    else
    {
        for(int i = 0; i < 5; i++)
        {
            os<<"| ";
            for(int j = 0; j < 5; j++)
            {
                os<< matrix[i][j] << "\t";
            }
            os<<". . . |"<<std::endl;
        }
        os<<"| .\t.\t.\t.\t.\t.     |"<<std::endl;
        os<<"| .\t.\t.\t.\t.\t .    |"<<std::endl;
        os<<"| .\t.\t.\t.\t.\t  .   |"<<std::endl<<std::endl;
        os<<"The matrix is too large!"<<std::endl;
    }

    return os;
}

// Casting:
template <class Type>
Matrix<int> Matrix<Type>::double_to_int()
{
    Matrix<int> temp(this->num_rows, this->num_cols, 0);
    for(int i = 0; i < this->num_rows; i++)
        for(int j = 0; j < this->num_cols; j++)
            temp[i][j] = int(this->mat[i][j]);
    return temp;
}