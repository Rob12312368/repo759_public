#include <iostream>
#include <omp.h>
#include "matmul.h"
#include <chrono>
#include <random>

using std::chrono::high_resolution_clock;
using std::chrono::duration;


int main(int argc, char * argv[]){
    //size_t n = std::stoul(argv[1]);
    size_t n = 1024;
    //size_t t = std::stoul(argv[2]);
    size_t t = 3;
    size_t arrSize = n * n;

    float* A = new float[arrSize];
    float* B = new float[arrSize];
    float* C = new float[arrSize];

    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, std::milli> duration_sec;


    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<> distrib(-1.0, 1.0);
    for(size_t i = 0 ; i < arrSize; i++)
    {
        //A[i] = distrib_mask(gen);
        //B[i] = distrib_mask(gen);
        A[i] = 1;
        B[i] = 1;
        C[i] = 0;
    }
    int available_threads = omp_get_max_threads();
    std::cout << "Maximum available threads: " << available_threads << std::endl;

    omp_set_dynamic(0);         // Disable dynamic adjustment
    omp_set_num_threads(t); 
    start = high_resolution_clock::now();
    mmul(A, B, C, n);
    end = high_resolution_clock::now();
    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);
    std::cout << C[0] << "\n";
    std::cout << C[arrSize - 1] << "\n";
    std::cout << duration_sec.count() << "\n";
    
}