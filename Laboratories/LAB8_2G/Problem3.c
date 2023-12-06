#include <stdio.h>

int* findMaxValue(int* array, int arraysize) {
    int* maxPtr = array;

    for (int i = 1; i < arraysize; i++) {
        if (*(array + i) > *maxPtr) {
            maxPtr = array + i;
        }
    }

    return maxPtr;
}

int main() {
    int arr[] = {3, 7, 2, 8, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    int* maxPtr = findMaxValue(arr, size);

    printf("\nMax Value: %d\n", *maxPtr);

    return 0;
}
