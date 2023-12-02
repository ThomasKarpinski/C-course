#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printTemperature(int arr[], int size);
int compare(const void *a, const void *b);

int main() {
    int JulTemp[31];
    for (int i = 0; i < 31; i++) {
        JulTemp[i] = 18 + rand() % (28 - 18 + 1);
    }
    printTemperature(JulTemp, sizeof(JulTemp) / sizeof(JulTemp[0]));

    return 0;
}

void printTemperature(int arr[], int size) {
    float sum = 0, median;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    float mean = sum / size;

    // Find the median for the whole month
    qsort(arr, size, sizeof(int), compare);
    if (size % 2 == 0) {
        median = (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        median = arr[size / 2];
    }

    // Calculate the standard deviation
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
