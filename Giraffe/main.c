#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct Student
{
    char name[50];
    char major[50];
    int age;
    double gpa;
};


int main()
{

    //arrays();

    //printf("%d", max(4, 9, 12));

    struct Student student1;
    student1.age = 22;
    student1.gpa = 3.2;
    strcpy(student1.name, "Jim");
    strcpy(student1.major, "Business");

    printf("%s", student1.gpa);


    return 0;
}
