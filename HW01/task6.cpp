#include <iostream>

int main(int argc, char *argv[]) {
    long long int n = std::stoll(argv[0]);
    for (long long int i=0; i<=n; i++)
    {
        std::cout << i << " ";
    }
    std :: cout << '\n';
    for (long long int i=n; i>=0; i--)
    {
        std::cout << i << " ";
    }
    return 0;
}