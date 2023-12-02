#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tradestocks.h"

#define TRDAYS 500
#define PLAYERNR 3

int main(void) {
    srand((unsigned int)time(NULL));

    float history[TRDAYS];
    history[0] = 13.9;
    
    float max = history[0];
    float min = history[0];

    for (int i = 1; i < TRDAYS + 1; ++i) {
        float arbitrary_number = rand() % 21 + 90;
        history[i] = arbitrary_number * history[i - 1] / 100;

        if (max < history[i]) {
            max = history[i];
        }
        if (min > history[i]) {
            min = history[i];
        }
    }

    printf("Max value: %f, Min value: %f \n", max, min);

    float *wealthOfPlayers = trade_game(PLAYERNR, history);
    for (int j = 0; j < PLAYERNR; ++j) {
        printf("Player: %d, Wealth: %f \n", j + 1, wealthOfPlayers[j]);
    }

    bubble_sort(wealthOfPlayers, PLAYERNR);

    free(wealthOfPlayers);
    
    return 0;
}
