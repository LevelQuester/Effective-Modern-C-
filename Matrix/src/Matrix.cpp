#include "Matrix.h"

int Matrix::indexAt(int const row, int const column) const {
    return numberOfColumns*row + column;
}

Matrix::Matrix() : numberOfRows(0), numberOfColumns(0), data(nullptr) {
    std::cout << "default constructor\n";
}

Matrix::Matrix(int numberOfRows, int numberOfColumns) : numberOfRows(numberOfRows), numberOfColumns(numberOfColumns), data(new double[numberOfRows*numberOfColumns]) {
    std::cout << "constructor of " << numberOfRows << " of " << numberOfColumns << " matrix\n";
    for (int i=0; i<numberOfRows*numberOfColumns;i++) {
        data[i] = 0.0;
    }
}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list) : numberOfRows(list.size()), numberOfColumns(0){
    std::cout << "constructor of initializer_list\n";
    for (auto row : list) {
        numberOfColumns = std::max(numberOfColumns, (int)row.size());
    }
    data = new double[numberOfRows*numberOfColumns];

    for (int i=0; i<numberOfRows;i++) {
        auto row = *(list.begin() + i);
        for (int j=0; j<numberOfColumns;j++) {
            if (j < row.size()) {
                data[indexAt(i, j)] = *(row.begin() + j);
            }
            else {
                data[indexAt(i, j)] = 0;
            }
        }
    }
}

Matrix::Matrix(const Matrix& other) : numberOfRows(other.numberOfRows), numberOfColumns(other.numberOfColumns) {
    std::cout << "copy constructor\n";
    data = new double[numberOfRows*numberOfColumns];
    for (int i=0; i<numberOfRows*numberOfColumns;i++) {
        data[i] = other.data[i];
    }
}

Matrix::Matrix(Matrix&& other) noexcept : numberOfRows(other.numberOfRows), numberOfColumns(other.numberOfColumns) {
    std::cout << "move constructor\n";
    this->data = other.data;

    other.data = nullptr;
    other.numberOfRows = 0;
    other.numberOfColumns = 0;
}

Matrix& Matrix::operator=(const Matrix &other) {
    std::cout << "copy assignment operator\n";

    if (this != &other) {
        auto newData = new double[numberOfRows*numberOfColumns];

        for (int i = 0; i<numberOfRows*numberOfColumns;i++) {
            newData[i] = other.data[i];
        }
        delete[] data;

        data = newData;
        numberOfRows = other.numberOfRows;
        numberOfColumns = other.numberOfColumns;
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&other) noexcept {
    std::cout << "move assignment operator\n";
    if (this != &other) {
        delete[] data;
        data = other.data;
        numberOfRows = other.numberOfRows;
        numberOfColumns = other.numberOfColumns;

        other.data = nullptr;
        other.numberOfRows = 0;
        other.numberOfColumns = 0;
    }
    return* this;
}

Matrix::~Matrix() {
    std::cout << "destructor\n";
    delete[] data;
}

Matrix Matrix::operator-() const {
    Matrix negativeMatrix(*this);

    for (int i=0; i<negativeMatrix.numberOfRows * negativeMatrix.numberOfColumns;i++) {
        negativeMatrix.data[i] *= -1;
    }

    return negativeMatrix;
}

double& Matrix::operator()(int row, int column) const{
    return this->data[indexAt(row, column)];
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix){
    for (int i=0; i<matrix.numberOfRows;i++) {
        for (int j=0; j<matrix.numberOfColumns;j++) {
            os << matrix(i, j) << " ";
        }
        os << "\n";
    }

    return os;
}


