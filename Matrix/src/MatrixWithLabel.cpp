#include "MatrixWithLabel.h"

std::string MatrixWithLabel::getLabel() {
    return label;
}

void MatrixWithLabel::setLabel(std::string newLabel) {
    label = std::move(newLabel);
}

MatrixWithLabel::MatrixWithLabel(std::string newLabel, int numberOfRows, int numberOfColumns)
        : Matrix(numberOfRows, numberOfColumns), label(std::move(newLabel)) {}

MatrixWithLabel::MatrixWithLabel(std::string newLabel, std::initializer_list<std::initializer_list<double>> list)
        : Matrix(list), label(std::move(newLabel)) {}

MatrixWithLabel::MatrixWithLabel(const MatrixWithLabel &other) : MatrixWithLabel(other.label, other.numberOfRows, other.numberOfColumns) {
    for (int i=0; i<numberOfRows*numberOfColumns;i++) {
        data[i] = other.data[i];
    }
}

MatrixWithLabel::MatrixWithLabel(MatrixWithLabel &&other) noexcept :
Matrix(std::move(other)), label(std::move(other.label)) {}

MatrixWithLabel& MatrixWithLabel::operator=(const MatrixWithLabel &other) {
    if (this != &other) {
        static_cast<Matrix&>(*this) = other;
        label = other.label;
    }
    return *this;
}

MatrixWithLabel& MatrixWithLabel::operator=(MatrixWithLabel &&other) noexcept {
    if (this != &other) {
        static_cast<Matrix&>(*this) = std::move(other);
        label = other.label;
    }
    return *this;
}


