#include <cuda.h>
#include <iostream>
#include <random>
__global__ void compute(int* dA, int myrand){

    dA[blockIdx.x * blockDim.x + threadIdx.x] = myrand * threadIdx.x + blockIdx.x;
}
int main(int argc, char* argv []){
    

    int* dA;
    int hA[16];

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<> distrib(5.0, 10.0);

    cudaMalloc((void**)&dA, sizeof(int) * 16);
    cudaMemset(dA, 0, sizeof(int) * 16);


    compute<<<2, 8>>>(dA, distrib(gen));

    cudaMemcpy(hA, dA, sizeof(int) * 16, cudaMemcpyDeviceToHost);
    for(int i = 0; i < 16; i++)
        printf(" %d", hA[i]);

    cudaFree(dA);
    return 0;
}