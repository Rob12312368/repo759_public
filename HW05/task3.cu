#include <iostream>
#include <cuda.h>
#include <random>
#include "vscale.cuh"

int main(int argc, char* argv []){
    unsigned int n = std::stoi(argv[1]);

    cudaEvent_t startEvent, stopEvent;
    cudaEventCreate(&startEvent);
    cudaEventCreate(&stopEvent);
    

    float* ha = new float[n];
    float* hb = new float[n];
    float* da;
    float* db;
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<float> distrib_a(-10.0, 10.0);
    std::uniform_real_distribution<float> distrib_b(0.0, 1.0);

    for(unsigned int i = 0; i < n ; i++){
        ha[i] = distrib_a(gen);
        hb[i] = distrib_b(gen);
    }

    cudaMalloc((void**)&da, sizeof(float) * n);
    cudaMalloc((void**)&db, sizeof(float) * n);
    cudaMemcpy(da, ha, sizeof(float) * n, cudaMemcpyHostToDevice);
    cudaMemcpy(db, hb, sizeof(float) * n, cudaMemcpyHostToDevice);

    cudaEventRecord(startEvent, 0);
    vscale<<<1, 16>>>(da, db, n);
    cudaEventRecord(stopEvent, 0);
    cudaEventSynchronize(stopEvent);
    float elapsedTime;
    cudaEventElapsedTime(&elapsedTime, startEvent, stopEvent);

    cudaMemcpy(hb, db, sizeof(float) * n, cudaMemcpyDeviceToHost);
    std::cout << elapsedTime << "\n" << hb[0] << "\n" << hb[n-1];

    

    cudaEventDestroy(startEvent);
    cudaEventDestroy(stopEvent);
    cudaFree(da);
    cudaFree(db);
    delete[] ha;
    delete[] hb;


}