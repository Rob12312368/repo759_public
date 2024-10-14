#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <algorithm>
int main(int argc, char** argv) {
    int a[5] = {5,4,3,2,1};

    std::sort(a+2, a+5);

    for(int& t:a){
        std::cout << t;
    }
}
