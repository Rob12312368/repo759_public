#include <iostream>
#include <random>
#include <chrono>
#include "convolution.h"

using std::chrono::high_resolution_clock;
using std::chrono::duration;

int main(int argc, char* argv[]){
    size_t n = std::stoul(argv[1]);
    size_t m = std::stoul(argv[2]);
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
        image[i] = distrib_image(gen);
    }

    std::uniform_real_distribution<> distrib_mask(-1.0, 1.0);

    for (size_t i = 0; i < m * m; i++)
    {
        mask[i] = distrib_mask(gen);
    }

    start = high_resolution_clock::now();
    convolve(image, output, n, mask, m);
    end = high_resolution_clock::now();

    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);
    std::cout << duration_sec.count() << "\n";
    std::cout << output[0] << "\n";
    std::cout << output[n*n-1] << "\n";

    delete [] image;
    delete [] mask;
    delete [] output;

}

