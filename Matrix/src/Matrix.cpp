#include "Matrix.h"

int Matrix::indexAt(int const row, int const column) const {
    return M*row + column;
}

Matrix::Matrix() : N(0), M(0), data(nullptr) {
    std::cout << "default constructor\n";
}

Matrix::Matrix(int n, int m) : N(n), M(m), data(new double[n*m]) {
    std::cout << "constructor of " << n << " of " << m << " matrix\n";
    for (int i=0; i<N*M;i++) {
        data[i] = 0.0;
    }
}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list) : N(list.size()), M(0){
    std::cout << "constructor of initializer_list\n";
    for (auto row : list) {
        M = std::max(M, (int)row.size());
    }
    data = new double[N*M];

    for (int i=0; i<N;i++) {
        auto row = *(list.begin() + i);
        for (int j=0; j<M;j++) {
            if (j < row.size()) {
                data[indexAt(i, j)] = *(row.begin() + j);
            }
            else {
                data[indexAt(i, j)] = 0;
            }
        }
    }
}

Matrix::Matrix(const Matrix& other) : N(other.N), M(other.M) {
    std::cout << "copy constructor\n";
    data = new double[N*M];
    for (int i=0; i<N*M;i++) {
        data[i] = other.data[i];
    }
}

Matrix::Matrix(Matrix&& other) noexcept : N(other.N), M(other.M) {
    std::cout << "move constructor\n";
    this->data = other.data;

    other.data = nullptr;
    other.N = 0;
    other.M = 0;
}

Matrix& Matrix::operator=(const Matrix &other) {
    std::cout << "copy assignment operator\n";

    if (this != &other) {
        auto newData = new double[N*M];

        for (int i = 0; i<N*M;i++) {
            newData[i] = other.data[i];
        }
        delete[] data;

        data = newData;
        N = other.N;
        M = other.M;
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&other) noexcept {
    std::cout << "move assignment operator\n";
    if (this != &other) {
        delete[] data;
        data = other.data;
        N = other.N;
        M = other.M;

        other.data = nullptr;
        other.N = 0;
        other.M = 0;
    }
    return* this;
}

Matrix::~Matrix() {
    std::cout << "destructor\n";
    delete[] data;
}

Matrix Matrix::operator-() const {
    Matrix negativeMatrix(*this);

    for (int i=0; i<negativeMatrix.N * negativeMatrix.M;i++) {
        negativeMatrix.data[i] *= -1;
    }

    return negativeMatrix;
}

double& Matrix::operator()(int row, int column) const{
    return this->data[indexAt(row, column)];
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix){
    for (int i=0; i<matrix.N;i++) {
        for (int j=0; j<matrix.M;j++) {
            os << matrix(i, j) << " ";
        }
        os << "\n";
    }

    return os;
}


