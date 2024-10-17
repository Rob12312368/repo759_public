#include <iostream>
#include "msort.h"
#include <chrono>
#include <random>
using std::chrono::high_resolution_clock;
using std::chrono::duration;
int main(int argc, char* argv[]){
    size_t n = std::stoul(argv[1]);
    size_t t = std::stoul(argv[2]);
    size_t ts = std::stoul(argv[3]);

    int* arr = new int[n];
    
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, std::milli> duration_sec;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(-1000, 1000);

    for(size_t i = 0; i < n; i++)
    {
        arr[i] = distrib(gen);
    }


       // Disable dynamic adjustment
    omp_set_nested(1);
    omp_set_num_threads(t); 
    start = high_resolution_clock::now();
    msort(arr, n, ts);
    end = high_resolution_clock::now();

    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);   
    std::cout << arr[0] << "\n";
    std::cout << arr[n-1] << "\n";
    std::cout << duration_sec.count() << "\n";


    delete [] arr;
}