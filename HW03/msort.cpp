
#include <algorithm>  // For std::sort
#include "msort.h"
#include <iostream>
void mymerge(int* l_arr, int* r_arr, size_t l_size, size_t r_size){
    int* tmparr = new int [l_size+r_size];
    size_t l = 0, r = 0, i = 0;
    while (l < l_size and r < r_size){
        if (l_arr[l] <= r_arr[r]){
            tmparr[i] = l_arr[l];
            l++;
        }
        else{
            tmparr[i] = r_arr[r];
            r++;
        }
        i++;
    }

    while(l < l_size)
    {
        tmparr[i] = l_arr[l];
        i++;
        l++;
    }
    while(r < r_size)
    {
        tmparr[i] = r_arr[r];
        i++;
        r++;
    }
    for(size_t j = 0; j < l_size + r_size; j++){
        l_arr[j] = tmparr[j];
    }
    delete [] tmparr;
    return;

}

void mergesort(int* arr, const std::size_t n, const std::size_t threshold){
    if (n < threshold){
        std::sort(arr, arr+n);
        return;
    }
    if (n%2 == 0){
        #pragma omp task firstprivate(n)
        mergesort(arr, n/2, threshold);
        #pragma omp task firstprivate(n)
        mergesort(arr + n/2, n/2, threshold);
        #pragma omp taskwait
        mymerge(arr, arr+n/2, n/2, n/2);
    }
    else{
        #pragma omp task firstprivate(n)
        mergesort(arr, n/2, threshold);
        #pragma omp task firstprivate(n)
        mergesort(arr + n/2, n - n/2, threshold);
        #pragma omp taskwait
        mymerge(arr, arr + n/2, n/2, n - n/2);
    }
}

void msort(int* arr, const std::size_t n, const std::size_t threshold){
    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            mergesort(arr, n, threshold);
        }
    }

}