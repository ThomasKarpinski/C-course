#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double integral_func(double a, double b, double N);
double func_to_integrate(double x);

int main(void) {
    double a;
    printf("Enter the lower limit a ");
    scanf("%lf", &a);
    double b;
    printf("Enter the upper limit b ");
    scanf(" %lf", &b);
    double N;
    printf("Enter the N of sum ");
    scanf(" %lf", &N);

    double integral = integral_func(a, b, N);
    printf("%lf", integral);

    return 0;
}

double integral_func(double a, double b, double N){


    double suma;
    double delta_x = (b - a) / N;
    for ( double i = 0; i < N; ++i)
    {
        double m = a + (i - 0.5) * delta_x;
        suma += func_to_integrate(m) * delta_x;
    }
    
    return suma;
}

double func_to_integrate(double x)
{

    double function = x * x * x + x * x - 4;
    return function;
    
}