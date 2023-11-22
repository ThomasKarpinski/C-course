#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TRDAYS 500
#define PLAYERNR 3

float* trade_game(int numPlayers, float tradeHistory[]);
void bubble_sort(float array[], int length);

int main(void) {
    srand((unsigned int)time(NULL));

    float history[TRDAYS];
    history[0] = 13.9;
    
    float max = history[0];
    float min = history[0];

    for (int i = 1; i < TRDAYS + 1; ++i)
    {
        float arbitrary_number = rand() % 21 + 90;
        history[i] = arbitrary_number * history[i - 1] / 100;
        //printf("Day: %d, Value: %f \n", i, history[i-1]);

        if (max < history[i])
        {
            max = history[i];
        }
        if (min > history[i])
        {
            min = history[i];
        }
        
        
    }

    printf("Max value: %f, Min value: %f \n", max, min);

    float *wealthOfPlayers = trade_game(PLAYERNR, history);
    for (int j = 0; j < PLAYERNR; ++j)
    {
        float result = wealthOfPlayers[j];
        printf("Player: %d, Wealth: %f \n", j + 1, wealthOfPlayers[j]);
    }

    bubble_sort(wealthOfPlayers, PLAYERNR);

    free(wealthOfPlayers);
    
    return 0;
}

float* trade_game(int numPlayers, float tradeHistory[]){
    
    srand((unsigned int)time(NULL));
    
    float wealths[numPlayers];
    float valuesOftocks[numPlayers];

    /*For each player*/
    for (int i = 0; i < numPlayers; i++) {
        wealths[i] = 100;
        valuesOftocks[i] = 0;

        /*We go through every day of operation on a stock market*/
        for (int j = 0; j < TRDAYS; ++j)
        {
            char operations[] = {'B', 'S'};
            int size = sizeof(operations) / sizeof(operations[0]);
            int randomIndex = rand() % size;
            char operation = operations[randomIndex];

            if (operation == 'S')    //case player sell a stock
            {
                float soldStock = fmod(rand(), valuesOftocks[i] + 1);
                if (valuesOftocks[i] >= soldStock)
                {
                    wealths[i] += soldStock;
                    valuesOftocks[i] -= soldStock;
                }

            }
            else if (operation == 'B')   //case player buy a stock
            {
                float boughtStock = fmod(rand(), tradeHistory[j] + 1);
                if (wealths[i] >= boughtStock)
                {
                    wealths[i] -= boughtStock;
                    valuesOftocks[i] += boughtStock;
                }
                
            }
            

        }
        
    }
    /*At the end we add the value of stocks
    to value of money for each player*/
    for (int k = 0; k < numPlayers; ++k)
    {
        wealths[k] += valuesOftocks[k];
    }
    
    // Return a pointer to the array
    float *result = malloc(numPlayers * sizeof(float));
    for (int k = 0; k < numPlayers; ++k) {
        result[k] = wealths[k];
    }
    return result;
    
}

void bubble_sort(float array[], int length){

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
    if (max < array[j])
        {
            max = array[j];
        }
        if (min > array[j])
        {
            min = array[j];
        }
  }
  printf("\nRichest player account : %f, Poorest player account: %f \n", max, min);
}
