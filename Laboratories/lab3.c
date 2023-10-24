#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    exercise_1();
    exercise_2();
    
    int number;
    printf("Please enter your number: ");
    scanf("%d", &number);
    int result = sum_cubes(number);
    if (result == number){
        printf("Your number %d is Armstrong number.", number);
    }
    else {
        printf("Your number %d is not Armstrong number\n", number);
        printf("because the sum of the cubes of the digits of the number is %d.", result);
    }

    exercise_4();

    return 0;
}

void exercise_1() {
/*Output is the grade based on the score*/
int score;
printf("Please indicate the result of the test: ");
scanf("%d", &score);    //We get value from user

switch (score)
{
case 0 ... 59:
    printf("Oh poorly, this time you get an F.\n");
    break;
case 60 ... 69:
    printf("It could have been better, you get a D.\n");
    break;
case 70 ... 79:
    printf("Not bad, C.\n");
    break;
case 80 ... 89:
    printf("Pretty well, B\n");
    break;
case 90 ... 99:
    printf("Awesome, you're getting an A.\n");
    break;
case 100:
    printf("You are amazing, A+.\n");
    break;

default:
    printf("You have entered an incorrect value.\n");
}
}

void exercise_2() {
int a;
int b;
int c;
printf("give the first side: "); 
scanf("%d", &a);
printf("give the second side:");
scanf("%d", &b);
printf("give the third side:");
scanf("%d", &c);
if (a+b>c && a+c>b && b+c>a)
{printf("It is possible to create a triangle.");}
else
{
printf("It is not possible to form a triangle.");
}
}

int sum_cubes(int a) {
    int w = 0;
    int i = 0;
    int sum = 0;
    while (a > 0) {
        w = a % 10; //extracting a digit from a whole number
        i = pow(w,3); //raise to the third power the digit currently under consideration
        sum += i; //adding number to the sum after raising it
        a /= 10; //dividing a number by 10 integrally to move to the next digit
    }
    return sum;
}


void exercise_4() {
int consumption;
printf("Enter Your consumption in kWh\n");
scanf("%d", &consumption);

if (0 < consumption < 2000){
    int price_1 = consumption*0.96;
    printf("Annual bill is: %d", price_1);
}
else if (200 <= consumption < 5000){
    int price_2 = consumption*1.55;
    printf("Annual bill is: %d", price_2);
}
else if (consumption >= 5000){
    int price_3 = consumption*2.30;
    printf("Annual bill is: %d", price_3);
}
else {
    printf("You have entered an incorrect value.\n");
}
}