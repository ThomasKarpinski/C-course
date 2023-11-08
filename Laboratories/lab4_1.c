#include <stdio.h>

int main() {
    int n = 8; // Number of rows

    for (int i = 1; i <= n; i++) {
        // Print spaces before the first set of hashtags
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }

        // Print the first set of hashtags
        for (int j = 0; j < i; j++) {
            printf("#");
        }

        // Print spaces between the first and second set of hashtags
        for (int j = 0; j < 2; j++) {
            printf(" ");
        }

        // Print the second set of hashtags
        for (int j = 0; j < i; j++) {
            printf("#");
        }

        printf("\n"); // Move to the next line
    }

    return 0;
}