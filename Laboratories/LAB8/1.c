#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 60

void reverseArray(int *inputArray, int leftIndex, int right);

int main(void){
    int array[N];

    srand(time(0));

    int size = sizeof(array) / sizeof(array[0]);

    printf("oryginal array\n");

    for (int i = 0; i < size; ++i)
    {
        int randomNumber = rand() % 100; //Numbers betweem 0 and 100
        array[i] = randomNumber;
        printf("%d ", randomNumber);
    }
    printf("\nnew array\n");
    
    reverseArray(array, 0, N - 1);

    for (int i = 0; i < N; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}

void reverseArray(int *inputArray, int leftIndex, int rightIndex){
    if (leftIndex >= rightIndex) {
        return;
    }

    // Swap the elements at leftIndex and rightIndex
    int temp = inputArray[leftIndex];
    inputArray[leftIndex] = inputArray[rightIndex];
    inputArray[rightIndex] = temp;

    // Recursively reverse the remaining subarray
    reverseArray(inputArray, leftIndex + 1, rightIndex - 1);
}