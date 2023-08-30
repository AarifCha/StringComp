#include "Matrix.h"

// Constructor:
template <class Type>
Matrix<Type>::Matrix() : num_rows(1), num_cols(1)
{
    std::vector<std::vector<Type>> vec(num_rows, std::vector<Type>(num_cols, 0));
    mat = vec;
}

template <class Type>
Matrix<Type>::Matrix(int num_rows, int num_cols, Type s) : num_rows(num_rows), num_cols(num_cols)
{
    std::vector<std::vector<Type>> vec(num_rows, std::vector<Type>(num_cols, s));
    mat = vec;
}

template <class Type>
Matrix<Type> &Matrix<Type>::operator=(const Matrix<Type> &matrix)
{
    this->~Matrix();
    this->num_rows = matrix.get_num_rows();
    this->num_cols = matrix.get_num_cols();

    std::vector<std::vector<Type>> vec(this->num_rows, std::vector<Type>(this->num_cols, matrix[0][0]));
    mat = vec;

    for (int i = 0; i < this->num_rows; i++)
        for (int j = 0; j < this->num_cols; j++)
            this->mat[i][j] = matrix[i][j];

    return *this;
}

// Arithmatic Operator Override:

// Addition:
template <class Type>
Matrix<Type> operator+(Matrix<Type> const &left, Matrix<Type> const &right)
{
    if (left.get_num_rows() != right.get_num_rows() || left.get_num_cols() != right.get_num_cols())
        throw std::invalid_argument("The arrays are not the same size.");

    Matrix<Type> Res(left.get_num_rows(), left.get_num_cols(), 0);
    for (int i = 0; i < Res.get_num_rows(); i++)
        for (int j = 0; j < Res.get_num_cols(); j++)
            Res[i][j] = left[i][j] + right[i][j];

    return Res;
}

// Subtraction:
template <class Type>
Matrix<Type> operator-(Matrix<Type> const &left, Matrix<Type> const &right)
{
    if (left.get_num_rows() != right.get_num_rows() || left.get_num_cols() != right.get_num_cols())
        throw std::invalid_argument("The arrays are not the same size.");

    Matrix<Type> Res(left.get_num_rows(), left.get_num_cols(), 0);
    for (int i = 0; i < Res.get_num_rows(); i++)
        for (int j = 0; j < Res.get_num_cols(); j++)
            Res[i][j] = left[i][j] - right[i][j];

    return Res;
}

// Multiplication:
template <class Type>
Matrix<double> operator*(double const &a, Matrix<Type> const &right)
{
    Matrix<double> Res(right.get_num_rows(), right.get_num_cols(), 0);
    for (int i = 0; i < Res.get_num_rows(); i++)
        for (int j = 0; j < Res.get_num_cols(); j++)
            Res[i][j] = a * right[i][j];

    return Res;
}

template <class Type>
Matrix<double> operator*(Matrix<Type> const &left, double const &a) { return a * left; }

// Division:
template <class Type>
Matrix<double> operator/(Matrix<Type> const &left, double const &a) { return 1 / a * left; }

// Printing Methods:
template <class Type>
std::ostream &operator<<(std::ostream &os, const Matrix<Type> &matrix)
{
    if (matrix.get_num_rows() <= 5 && matrix.get_num_cols() <= 5)
    {
        for (int i = 0; i < matrix.get_num_rows(); i++)
        {
            os << "| ";
            for (int j = 0; j < matrix.get_num_cols() - 1; j++)
            {
                os << matrix[i][j] << "\t";
            }
            os << matrix[i][matrix.get_num_cols() - 1] << " |" << std::endl;
        }
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            os << "| ";
            for (int j = 0; j < 5; j++)
            {
                os << matrix[i][j] << "\t";
            }
            os << ". . . |" << std::endl;
        }
        os << "| .\t.\t.\t.\t.\t.     |" << std::endl;
        os << "| .\t.\t.\t.\t.\t .    |" << std::endl;
        os << "| .\t.\t.\t.\t.\t  .   |" << std::endl
           << std::endl;
        os << "The matrix is too large!" << std::endl;
    }

    return os;
}

// Casting:
template <class Type>
Matrix<int> Matrix<Type>::double_to_int()
{
    Matrix<int> temp(this->num_rows, this->num_cols, 0);
    for (int i = 0; i < this->num_rows; i++)
        for (int j = 0; j < this->num_cols; j++)
            temp[i][j] = int(this->mat[i][j]);
    return temp;
}

template <class Type>
double Matrix<Type>::det()
{
    // This uses Doolittle LU Decomposition to generate A = LU pair
    // where L and U are lower and upper triangular matrices respectively.
    // Which then det(A) = det(L)det(U) or det(U) since the diagonal of
    // L is all 1.
    Matrix<double>* LU = dl_LU_decomp(*this);
    Matrix<double>  U = LU[1];
    double det = 1;

    for(int i=0; i<this->num_rows; i++)
        det *= U[i][i];

    delete LU;

    return det;
}

template <class Type>
Matrix<double>* dl_LU_decomp( const Matrix<Type> matrix )
{
    Matrix<double>* res = new Matrix<double>[2];

    Matrix<double> L(matrix.get_num_rows(),matrix.get_num_cols(),0);
    Matrix<double> U(matrix.get_num_rows(),matrix.get_num_cols(),0);

    double sum = 0;

    for (int i=0; i<matrix.get_num_rows(); i++)
    {
        // Upper Triangular Matrix
        for (int j=i; j<matrix.get_num_rows(); j++)
        {
            // Calculating the L_{i,k}U_{k,j} term
            sum = 0;
            for (int k=0; k<i; k++)
                sum += L[i][k] * U[k][j];

            U[i][j] = matrix[i][j] - sum;
        }

        //Lower Triangular Matrix
        for (int j=i; j<matrix.get_num_rows(); j++)
        {
            if (i==j)
                L[j][i] = 1;

            sum = 0;
            for (int k=0; k<i; k++)
                sum += L[j][k] * U[k][i];
            
            L[j][i] = (matrix[j][i] - sum)/U[i][i];
        }
    }

    res[0] = L; res[1] = U;

    return res;
}