#include "msort.h"
#include <omp.h>
#include <algorithm>

// Helper function to merge two sorted subarrays
void merge(int* arr, int* temp, std::size_t left, std::size_t mid, std::size_t right) {
    std::size_t i = left, j = mid, k = left;

    while (i < mid && j < right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i < mid) {
        temp[k++] = arr[i++];
    }

    while (j < right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i < right; ++i) {
        arr[i] = temp[i];
    }
}

// Parallel merge sort function using OpenMP tasks
void parallel_merge_sort(int* arr, int* temp, std::size_t left, std::size_t right, std::size_t threshold) {
    if (right - left <= threshold) {
        std::sort(arr + left, arr + right); // Use std::sort for small segments
        return;
    }

    std::size_t mid = left + (right - left) / 2;

    #pragma omp task shared(arr, temp) if(right - left > threshold)
    {
        parallel_merge_sort(arr, temp, left, mid, threshold);
    }

    #pragma omp task shared(arr, temp) if(right - left > threshold)
    {
        parallel_merge_sort(arr, temp, mid, right, threshold);
    }

    #pragma omp taskwait
    merge(arr, temp, left, mid, right);
}

// Main msort function as defined in the msort.h
void msort(int* arr, const std::size_t n, const std::size_t threshold) {
    int* temp = new int[n];

    #pragma omp parallel
    {
        #pragma omp single
        {
            parallel_merge_sort(arr, temp, 0, n, threshold);
        }
    }

    delete[] temp;
}