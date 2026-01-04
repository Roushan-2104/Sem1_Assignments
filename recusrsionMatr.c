#include <stdio.h>


// Recursive function to find the number of ways to parenthesize n matrices.
 
long long countMatrixMultiplicationWays(int n) {
    // Base Case: If there is 1 matrix, there is only 1 way (no multiplication needed).
    // If n is 2, there is 1 way: (AB).
    if (n <= 2) {
        return 1;
    }

    long long totalWays = 0;

    // Iterate through every possible split point k
    // Split the chain into two parts: size k and size n-k
    for (int k = 1; k < n; k++) {
        totalWays += countMatrixMultiplicationWays(k) * countMatrixMultiplicationWays(n - k);
    }

    return totalWays;
}

int main() {
    int n;

    printf("Enter the number of matrices: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    // Call the recursive function
    long long ways = countMatrixMultiplicationWays(n);

    printf("Number of ways to multiply %d matrices: %lld\n", n, ways);

    return 0;
}