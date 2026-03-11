#ifndef MATRIX_MATRIXWITHLABEL_H
#define MATRIX_MATRIXWITHLABEL_H

#include "Matrix.h"
#include <string>


class MatrixWithLabel : public Matrix{
private:
    std::string label;

public:
    using Matrix::Matrix;

    MatrixWithLabel(std::string newLabel, int numberOfRows, int numberOfColumns);
    MatrixWithLabel(std::string newLabel, std::initializer_list<std::initializer_list<double>> list);

    MatrixWithLabel(const MatrixWithLabel& other);
    MatrixWithLabel(MatrixWithLabel&& other) noexcept;

    MatrixWithLabel& operator=(const MatrixWithLabel& other);
    MatrixWithLabel& operator=(MatrixWithLabel&& other) noexcept;


    std::string getLabel();
    void setLabel(std::string newLabel);


};

#endif