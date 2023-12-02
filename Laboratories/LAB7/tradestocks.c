#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include "tradestocks.h"

float* trade_game(int numPlayers, float tradeHistory[]) {
    srand((unsigned int)time(NULL));
    
    float wealths[numPlayers];
    float valuesOftocks[numPlayers];

    for (int i = 0; i < numPlayers; i++) {
        wealths[i] = 100;
        valuesOftocks[i] = 0;

        for (int j = 0; j < TRDAYS; ++j) {
            char operations[] = {'B', 'S'};
            int size = sizeof(operations) / sizeof(operations[0]);
            int randomIndex = rand() % size;
            char operation = operations[randomIndex];

            if (operation == 'S') {
                float soldStock = fmod(rand(), valuesOftocks[i] + 1);
                if (valuesOftocks[i] >= soldStock) {
                    wealths[i] += soldStock;
                    valuesOftocks[i] -= soldStock;
                }
            }
            else if (operation == 'B') {
                float boughtStock = fmod(rand(), tradeHistory[j] + 1);
                if (wealths[i] >= boughtStock) {
                    wealths[i] -= boughtStock;
                    valuesOftocks[i] += boughtStock;
                }
            }
        }
    }

    for (int k = 0; k < numPlayers; ++k) {
        wealths[k] += valuesOftocks[k];
    }

    float *result = malloc(numPlayers * sizeof(float));
    for (int k = 0; k < numPlayers; ++k) {
        result[k] = valuesOftocks[k] * tradeHistory[TRDAYS - 1];
    }
    return result;
}


void bubble_sort(float array[], int length) {
    for (int step = 0; step < length - 1; ++step) {
        int swapped = 0;

        for (int i = 0; i < length - step - 1; ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0) {
            break;
        }
    }
    printf("A sorted list of players' wealth\n");
    for (int i = 0; i < length; ++i) {
        printf("%f  ", array[i]);
    }
    float max = array[0];
    float min = array[0];
    for (int j = 0; j < length; ++j) {
        if (max < array[j]) {
            max = array[j];
        }
        if (min > array[j]) {
            min = array[j];
        }
    }
    printf("\nRichest player account : %f, Poorest player account: %f \n", max, min);
}
