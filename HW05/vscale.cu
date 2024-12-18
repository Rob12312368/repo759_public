#include <iostream>
#include <cuda.h>
#include "vscale.cuh"


__global__ void vscale(const float *a, float *b, unsigned int n){
    unsigned int index = blockIdx.x * blockDim.x + threadIdx.x;
    if(index < n)
        b[index] *= a[index];
}