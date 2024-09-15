#include <iostream>
#include <stdio.h>
int main(int argc, char *argv[]) {
    long long int n = std::stoll(argv[1]);
    for (long long int i=0; i<=n; i++)
    {
        printf("%lld ", i);
    }
    std :: cout << '\n';
    for (long long int i=n; i>=0; i--)
    {
        std::cout << i << " ";
    }

    return 0;
}