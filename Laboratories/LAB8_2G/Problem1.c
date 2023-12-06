#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swapFloats(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    srand(time(NULL));

    float num1 = (float)rand()/(float)(RAND_MAX) * 0.10;
    float num2 = (float)rand()/(float)(RAND_MAX) * 0.10;

    printf("Before Swap: num1 = %.4f, num2 = %.4f\n", num1, num2);

    swapFloats(&num1, &num2);

    printf("After Swap: num1 = %.4f, num2 = %.4f\n", num1, num2);

    return 0;
}
