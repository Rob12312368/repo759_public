#include <iostream>
#include <random>
#include "convolution.h"
int main(int argc, char* argv[]){
    size_t n = std::stoul(argv[1]);
    size_t m = std::stoul(argv[2]);
    float* image = new float [n*n];
    float* mask = new float [m*m];
    float* output = new float [n*n];

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

    convolve(image, output, n, mask, m);

    for (size_t i = 0; i < n * n; i++)
    {
        std::cout << output[i] << " ";
    }
    delete [] image;
    delete [] mask;
    delete [] output;

}

