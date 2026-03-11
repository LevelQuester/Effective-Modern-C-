cmake_minimum_required(VERSION 3.10)

project(Matrix CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(MatrixTest src/Main.cpp src/Matrix.cpp src/MatrixWithLabel.cpp)