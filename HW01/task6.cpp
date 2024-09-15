#include <iostream>

int main() {
    long long int n;
    std::cin >> n;
    for (long long int i=0; i<=n; i++)
    {
        std::cout << i << " ";
    }
    std :: cout << '\n';
    for (long long int i=n; i>=0; i--)
    {
        std::cout << i << " ";
    }
    
}