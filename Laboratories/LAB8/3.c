#include <stdio.h>
#define N 5

// Function to calculate binomial coefficient C(n, k)
int binomialCoeff(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

// Function to print Pascal's Triangle up to n rows
void printPascalsTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", binomialCoeff(i, j));
        }
        printf("\n");
    }
}

int main() {
    printPascalsTriangle(N);

    return 0;
}
