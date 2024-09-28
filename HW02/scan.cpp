#include <iostream>
#include <vector>
#include "scan.h"

void scan(const float *arr, float *output, std::size_t n){
    for (size_t i = 0; i < n; i++)
    {
        output[i] = arr[i];
        if (i >= 1)
        {
            output[i] += output[i-1];
        }
    }
}
