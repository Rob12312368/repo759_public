#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include "matmul.h"

void zeroC(double* arr, size_t n){
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
}

using std::chrono::high_resolution_clock;
using std::chrono::duration;

int main(int argc, char* argv[]){
    size_t side = 1024;
    size_t arrsize = side * side;
    
    double* A = new double [arrsize];
    double* B = new double [arrsize];
    double* C = new double [arrsize];

    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, std::milli> duration_sec;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<> distrib_mask(-1.0, 1.0);

    for (size_t i = 0; i < arrsize; i++)
    {
        A[i] = distrib_mask(gen);
        B[i] = distrib_mask(gen);
    }

    const std::vector<double> A_vector(A, A + arrsize);
    const std::vector<double> B_vector(B, B + arrsize);


    std::cout << side << "\n";

    start = high_resolution_clock::now();
    mmul1(A, B, C, side);
    end = high_resolution_clock::now();
    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);
    std::cout << duration_sec.count() << "\n";
    std::cout << C[arrsize - 1] << "\n";

    zeroC(C, arrsize);

    start = high_resolution_clock::now();
    mmul2(A, B, C, side);
    end = high_resolution_clock::now();
    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);
    std::cout << duration_sec.count() << "\n";
    std::cout << C[arrsize - 1] << "\n";

    zeroC(C, arrsize);

    start = high_resolution_clock::now();
    mmul3(A, B, C, side);
    end = high_resolution_clock::now();
    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);
    std::cout << duration_sec.count() << "\n";
    std::cout << C[arrsize - 1] << "\n";

    zeroC(C, arrsize);

    start = high_resolution_clock::now();
    mmul4(A_vector, B_vector, C, side);
    end = high_resolution_clock::now();
    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);
    std::cout << duration_sec.count() << "\n";
    std::cout << C[arrsize - 1] << "\n";

    delete [] A;
    delete [] B;
    delete [] C;



}