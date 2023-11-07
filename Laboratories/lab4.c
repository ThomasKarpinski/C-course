#include <stdio.h>

int main() {
    int rows = 8, i, space, k = 0;

    for (i = 1; i <= rows; ++i) {
        for (space = 1; space <= (rows - i); ++space) {
            printf("  ");
        }
        
        while (k != (2 * i - 1)) {
            printf("# ");
            ++k;
        }
        
        k = 0;
        printf("\n");
    }

    int degrees_F;
    scanf("%d", &degrees_F);
    
    return 0;
}