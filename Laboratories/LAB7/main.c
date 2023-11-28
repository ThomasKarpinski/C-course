#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tradestocks.c"
#include "tradestocks.h"

int main() {
    int JulTemp[31];
    for(int i = 0; i < 31; i++) {
        JulTemp[i] = 18 + rand() % (28 - 18 + 1);
    }
    printTemperature(JulTemp, sizeof(JulTemp) / sizeof(JulTemp[0]));

    int value1 = 50;
    int value2;
    int *intPtr = &value1;

    printf("The value of the object pointed to by intPtr is %d\n", *intPtr);
    value2 = *intPtr;
    printf("The value of value2 is %d\n", value2);

    printf("The address of value1 is %p\n", &value1);
    printf("The address stored in intPtr is %p\n", intPtr);
    printf("Is the value printed the same as value1's address? %s\n", intPtr == &value1 ? "Yes" : "No");

    return 0;
}