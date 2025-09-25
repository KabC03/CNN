#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <cstddef>
#include <cstdint>
#include <random>
#include <thread>




using namespace std;


/*
TODO:
    - NOTE: Keep CPU based

    - Convolution
    - Bias
    - Scalar multiplication
    - Activate
    - Max, min and average values
*/


namespace matrix {

    template <T>
    class Matrix {  
        private:    
        size_t rows;
        size_t cols;
        vector<T> data;
        
        public:
        Matrix(size_t rows, size_t cols) {
            this->rows = rows;
            this->cols = cols;
        }

        T *operator[](size_t row) const {
            return &data[row * this.cols]
        }
        Matrix operator+(const Matrix<T>& rhs) const {
            Matrix result(this->rows, this->cols);
            for(size_t i = 0; i < this.rows * this.cols; i++) {
                result.data[i] = this->data[i] + rhs.data[i];
            }
            return result;
        }
        Matrix operator-(const Matrix<T>& rhs) const {
            Matrix result(this->rows, this->cols);
            for(size_t i = 0; i < this.rows * this.cols; i++) {
                result.data[i] = this->data[i] - rhs.data[i];
            }
            return result;
        }
        Matrix operator|(const Matrix<T>& rhs) const { //Hadamard
            Matrix result(this->rows, this->cols);
            for(size_t i = 0; i < this.rows * this.cols; i++) {
                result.data[i] = this->data[i] * rhs.data[i];
            }
            return result;
        }
        Matrix operator*(const Matrix<T>& rhs) const {

            Matrix result(rows, rhs.cols);
            for(size_t i = 0; i < rows; i++) {
                for(size_t j = 0; j < rhs.cols; j++) {

                    result[i][j] = 0;
                    for(size_t k = 0; k < cols; k++) {
                        result[i][j] += this[i][k] * rhs[k][j];
                    }
                }
            }
            return result;
        }
        Matrix activate(T (*activationFunction)(T arg)) const {
            Matrix result(rows, cols);
            for(size_t i = 0; i < this.rows * this.cols; i++) {
                result.data[i] = activationFunction(this->data[i])
            }
            return result;
        }
    };
}









#endif