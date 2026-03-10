#ifndef MATRIX_H
#define MATRIX_H

#include <initializer_list>
#include <iostream>

class Matrix {
private:
    int N;
    int M;
    double *data;

    int indexAt(int const row, int const column) const;

public:
    Matrix();
    Matrix(int n, int m);
    Matrix(std::initializer_list<std::initializer_list<double>> list);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept;
    Matrix operator-() const;
    double& operator()(int row, int column) const;
    ~Matrix();

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};

#endif