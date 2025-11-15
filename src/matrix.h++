#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <cstddef>
#include <cstdint>
#include <random>
#include <thread>
#include <random>
#include <cmath>




using namespace std;

using namespace std;

namespace matrix {

    template < typename T>
    class Matrix {  
        private:
            vector<T> elements;
            size_t rows;
            size_t cols;

        public:

        Matrix(void) {
        } 
        Matrix(size_t rows, size_t cols) {
            this->rows = rows;
            this->cols = cols;
            this->elements.resize(this->rows * this->cols);
        }
        Matrix(size_t rows, size_t cols, vector<T> elements) {
            this->rows = rows;
            this->cols = cols;
            this->elements = elements;
        }


        size_t get_rows(void) {
            return this->rows;
        }
        size_t get_cols(void) {
            return this->cols;
        }

        T& at(size_t row, size_t col) {
            return elements[row * this->cols + col];
        }


        Matrix operator+(Matrix &rhs) {
            Matrix result(this->rows, this->cols);
            for(size_t i = 0; i < this->rows * this->cols; i++) {
                result.elements[i] = this->elements[i] + rhs.elements[i];
            }
            return result;
        }
        Matrix operator-(Matrix &rhs) {
            Matrix result(this->rows, this->cols);
            for(size_t i = 0; i < this->rows * this->cols; i++) {
                result.elements[i] = this->elements[i] - rhs.elements[i];
            }
            return result;
        }
        Matrix operator*(Matrix &rhs) {
            Matrix result(this->rows, this->cols);
            for(size_t i = 0; i < this.rows; i++) {
                for(size_t j = 0; j < rhs.cols; j++) {

                    T sum = 0;
                    for(size_t k = 0; k < this.cols; k++) {
                        sum += this.at(j, k) * rhs.at(k, j);
                    }
                    this.at(i, k) = sum;
                }
            }
            return result;
        }
        Matrix operator%(Matrix &rhs) { //Hadamard product
            Matrix result(this->rows, this->cols);
            for(size_t i = 0; i < this->rows * this->cols; i++) {
                result.elements[i] = this->elements[i] * rhs.elements[i];
            }
            return result;
        }

        void set(Matrix<float> input) {
            this->elements = input;
            return;
        }

        void bias(T bias) {
            for(T& element : this->elements){
                element += bias;
            }
            return;
        }

        void scale(T scale) {
            for(T& element : this->elements){
                element *= scale;
            }
            return;
        }

        Matrix<T> activate(T (*activationFunction)(T)) {
            Matrix<T> result(this->rows, this->cols);
            for(T &element : result->elements) {
                element = activationFunction(element);
            }
            return result;
        }

        void activate_in_place(T (*activationFunction)(T)) {
            for(T &element : this->elements) {
                element = activationFunction(element);
            }
            return;
        }

        Matrix<T> convolve(Matrix &kernel) {
            Matrix result(0,0);

            return result;
        }

        void convolve_in_place(Matrix &kernel) {
            for(size_t i = 0; i < this->rows * this->cols; i++) {
                T sum = 0;
                for(size_t j = 0; j < kernel.rows * kernel.cols; j++) {
                    sum += this.at((i + j) / this->rows, i + j) * kernel.at(j / this->rows, j);
                }
                this.at(i / this->rows, i) = sum;
            }
            return;
        }

        void average_pool(size_t rows, size_t cols) {
            for(size_t i = 0; i < this->rows * this->cols; i++) {
                T sum = 0;
                for(size_t j = 0; j < rows * cols; j++) {
                    sum += this.at((i + j) / this->rows, i + j);
                }
                this.at(i / this->rows, i) = sum / (rows * cols);
            }
            return;
        }

        void max_pool(size_t rows, size_t cols) {
            for(size_t i = 0; i < this->rows * this->cols; i++) {
                T currentMax = this.at(i / this->rows, i);
                for(size_t j = 0; j < rows * cols; j++) {
                    if(this.at((i + j) / this->rows, i + j) > currentMax) {
                        currentMax = this.at((i + j) / this->rows, i + j);
                    }
                }
                this.at(i / this->rows, i) = currentMax;
            }
            return;
        }

        void relu(void) {
            for(T& element : this->elements){
                if(0 > element) {
                    element = 0;
                }
            }
            return;
        }

        void kaming_uniform_initialisation(double fanIn) {
            double limit = sqrt((double)6 / fanIn);

            random_device rd;
            mt19937 gen(rd());
            uniform_real_distribution<T> dist(-limit, limit);

            for(T &element : this->elements) {
                element = dist(gen);
            }

            return;
        }


        T max(void) {
            T currentMax = this->elements[0];
            for(T element : this->elements) {
                if(element > currentMax) {
                    currentMax = element;
                }
            }
            return currentMax;
        }

        T min(void) {
            T currentMin = this->elements[0];
            for(T element : this->elements) {
                if(currentMin > element) {
                    currentMin = element;
                }
            }
            return currentMin;
        }
    };
}









#endif