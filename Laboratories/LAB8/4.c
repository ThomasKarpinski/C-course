#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

// Function to generate a sorted array of N integers
void generateSortedArray(int arr[]) {
    arr[0] = 0; // First element is 0
    srand(time(NULL));
    for (int i = 1; i < N; i++) {
        arr[i] = arr[i - 1] + rand() % 10; // Assign each element as the previous element plus a pseudorandom number
    }
}

int binarySearch(int arr[], int low, int high, int x) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;

        // If the element is smaller than mid, then it can only be present in the left subarray
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        // Else the element can only be present in the right subarray
        return binarySearch(arr, mid + 1, high, x);
    }

    // Element is not present in array
    return -1;
}

int main() {
    int arr[N];
    generateSortedArray(arr);

    // Print the generated sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Randomly pick an element from the array to search
    int searchElement = arr[rand() % N];

    // Perform binary search
    int result = binarySearch(arr, 0, N - 1, searchElement);

    // Print the result
    if (result != -1) {
        printf("Element %d found at index %d.\n", searchElement, result);
    } else {
        printf("Element %d not found in the array.\n", searchElement);
    }

    return 0;
}
