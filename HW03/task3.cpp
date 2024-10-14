#include <iostream>
#include "msort.h"
int main(){
    int a[6] = {5,4,3,2,-1,0};

    msort(a, 5, 2);

    for(int&t : a){
        std::cout << t;
    }

}