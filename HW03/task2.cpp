#include <iostream>
#include <omp.h>
#include "convolution.h"
#include <chrono>
#include <random>

using std::chrono::high_resolution_clock;
using std::chrono::duration;


int main(int argc, char * argv[]){
    size_t n = std::stoul(argv[1]);
    size_t t = std::stoul(argv[2]);
    size_t m = 3;
    float* image = new float [n*n];
    float* mask = new float [m*m];
    float* output = new float [n*n];

    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, std::milli> duration_sec;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<> distrib_image(-10.0, 10.0);

    for (size_t i = 0; i < n * n; i++)
    {
        image[i] = distrib_image(gen);;
    }

    std::uniform_real_distribution<> distrib_mask(-1.0, 1.0);

    for (size_t i = 0; i < m * m; i++)
    {
        mask[i] = distrib_mask(gen);;
    }

    omp_set_dynamic(0);         // Disable dynamic adjustment
    omp_set_num_threads(t); 
    start = high_resolution_clock::now();
    convolve(image, output, n, mask, m);
    end = high_resolution_clock::now();

    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);
    std::cout << output[0] << "\n";
    std::cout << output[n*n-1] << "\n";
    std::cout << duration_sec.count() << "\n";

    delete [] image;
    delete [] mask;
    delete [] output;
}