#include <iostream>
#include "convolution.h"

void convolve(const float *image, float *output, std::size_t n, const float *mask, std::size_t m){
    size_t half = (m - 1) / 2;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            float tmpsum = 0;
            for (size_t k = 0; k < m; k++)
            {
                for (size_t l = 0; l < m; l++)
                {
                    size_t o = i - half + k;
                    size_t p = j - half + l;
                    if (o >= 0 && o < n && p >= 0 && p < n)
                    {
                        tmpsum += image[o*n + p] * mask[k*m + l];
                    }
                    else if (o >= 0 && o < n)
                    {
                        tmpsum += mask[k*m + l];
                    }
                    else if (p >= 0 && p < n)
                    {
                        tmpsum += mask[k*m + l];
                    }
                }
            }
            output[i*n + j] = tmpsum;
        }
    }
}