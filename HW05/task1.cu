#include <cuda.h>
#include <iostream>



__global__ void factorial(){
    int start = 1;
    for(int i = 0; i < threadIdx.x ; i++){
        start *= (i+2);
    }
    printf("%d!=%d\n", threadIdx.x+1, start);
}

int main(){

    factorial<<<1, 8>>>();
    cudaDeviceSynchronize();

}
