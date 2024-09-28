#include <iostream>
#include <random>
#include "matmul.h"
#include <vector>
void zeroC(double* arr, size_t n){
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
}
int main(int argc, char* argv[]){
    size_t side = 1024;
    size_t arrsize = side * side;
    
    double* A = new double [arrsize];
    double* B = new double [arrsize];
    std::vector<double>* A_vector = new std::vector<double>(arrsize, 1.0);
    std::vector<double>* B_vector = new std::vector<double>(arrsize, 1.0);
    double* C = new double [arrsize];
    for (size_t i  = 0; i < arrsize; i++)
    {
        A[i] = 1.0;
        B[i] = 1.0;
    }

    mmul1(A, B, C, side);
    std::cout << C[arrsize - 1];
    zeroC(C, arrsize);
    mmul2(A, B, C, side);
    std::cout << C[arrsize - 1];
    zeroC(C, arrsize);
    mmul3(A, B, C, side);
    std::cout << C[arrsize - 1];
    zeroC(C, arrsize);
    mmul4(*A_vector, *B_vector, C, side);
    std::cout << C[arrsize - 1];

    delete [] A;
    delete [] B;
    delete [] C;
    delete A_vector;
    delete B_vector;



}