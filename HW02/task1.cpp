#include <iostream>
#include <random>
#include <chrono>
#include "scan.h"

using std::chrono::high_resolution_clock;
using std::chrono::duration;

int main(int argc, char* argv[]){
    size_t n = std::stoul(argv[1]);
    float* arr = new float[n];
    float* output = new float[n];

    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, std::milli> duration_sec;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<> distrib(-1.0, 1.0);

    for (size_t i = 0; i < n; i++)
    {
        arr[i] = distrib(gen);
    }
    
    start = high_resolution_clock::now();
    scan(arr, output, n);
    end = high_resolution_clock::now();

    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);
    std::cout << duration_sec.count() << "\n";
    std::cout << output[0] << "\n";
    std::cout << output[n-1] << "\n";

    delete[] arr;
    delete[] output;
}

