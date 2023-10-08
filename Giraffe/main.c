#include <stdio.h>
#include <stdlib.h>

void arrays() {
    int luckyNumbers[] ={4, 8, 15, 16, 23, 42};
    luckyNumbers[1] = 6;
    printf("%d\n", luckyNumbers[1]);

    int numbers[10];
    numbers[0] = 22;
    numbers[1] = 445;
    printf("%d %d", numbers[0], numbers[1]);
}

int max(int num1, int num2, int num3) {
    int result;
    if(num1 >= num2 && num1 >= num2) {
        result = num1;
    }
    else if(num2 >= num1 && num2 >= num3) {
        result = num2;
    }
    else {
        result = num3;
    }
    return result;
}

int main()
{
    /* char name[] = "Peter";
    printf("%s\n", name);
    */

    /*int age;
    scanf("%d", &age);
    printf("%d", age);*/

    somePoem();

    //arrays();

    //printf("%d", max(4, 9, 12));

    return 0;
}
