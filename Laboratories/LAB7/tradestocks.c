#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tradestocks.h"

void printTemperature(int arr[], int size) {
    float sum = 0, median;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    float mean = sum / size;

    // Find median
    qsort(arr, size, sizeof(int), compare);
    if (size % 2 == 0) {
        median = (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        median = arr[size / 2];
    }

    // Calculate standard deviation
    float stdDev = 0;
    for (int i = 0; i < size; i++) {
        stdDev += pow(arr[i] - mean, 2);
    }
    stdDev = sqrt(stdDev / size);

    printf("The mean temperature is %.2f DEG Celsius\n", mean);
    printf("The median temperature is %.2f DEG Celsius\n", median);
    printf("The standard deviation is %.2f DEG Celsius\n", stdDev);
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
