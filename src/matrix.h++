#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <cstddef>
#include <cstdint>
#include <random>
#include <type_traits>
#include <thread>




using namespace std;


/*
TODO:
    - NOTE: Keep CPU based

    - Addition, subtraciton, Hadamard product, multiplication
    - Convolution
    - Bias
    - Scalar multiplication
    - Activate
    - Max, min and average values
*/


namespace matrix {

    template <typename T>
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



    };
}









#endif