#include <stdio.h>
#define N 4

void printSumRepresentation(int n, int* buffer, int length, int currentSum);

int main() {

    printf("\nAll possible representations of %d as the sum of non-zero natural numbers:\n", N);
    int buffer[N]; // Buffer to store the current representation
    printSumRepresentation(N, buffer, 0, 0);

    return 0;
}

void printSumRepresentation(int n, int* buffer, int length, int currentSum) {
    // Base case: if the current sum equals the target value
    if (currentSum == n) {
        // Print the current representation
        for (int i = 0; i < length; ++i) {
            printf("%d", buffer[i]);
            if (i < length - 1) {
                printf(" + ");
            }
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= n - currentSum; ++i) {
        buffer[length] = i;
        printSumRepresentation(n, buffer, length + 1, currentSum + i);
    }
}
