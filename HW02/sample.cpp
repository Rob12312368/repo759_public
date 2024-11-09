#include <vector>


int main(){
int arrsize = 10;
double* A = new double[arrsize]; // Dynamic array

// Create vectord
std::vector<double> A_vector(arrsize);

// Initialize array A with some values
for (int i = 0; i < arrsize; ++i) {
    A[i] = i * 1.0;  // Example values
    A_vector[i] = A[i];
}


// Clean up dynamic memory
delete[] A;
}

