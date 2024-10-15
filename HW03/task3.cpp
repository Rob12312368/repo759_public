#include <iostream>
#include "msort.h"
int main(){
    int a[5] = {5,4,3,2,-1};

    msort(a, 5, 2);
    std::cout << "here";
    for(int&t : a){
        std::cout << t;
    }

}