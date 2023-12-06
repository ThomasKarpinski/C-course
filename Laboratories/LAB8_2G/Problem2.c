#include <stdio.h>

void reverseArray(int* array, int arraysize) {
    int* start = array;
    int* end = array + arraysize - 1;

    while (start < end) {
        // Swap elements pointed by start and end
        int temp = *start;
        *start = *end;
        *end = temp;

        // Move pointers to the next and previous elements
        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    reverseArray(arr, size);

    printf("\nReversed Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
