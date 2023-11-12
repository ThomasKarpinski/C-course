#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double integral_func(double a, double b, double N);
double func_to_integrate(double x, int degree);

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

    /*int degree;
    printf("Enter the degree of polynomial function ");
    scanf("%d", &degree);*/

    double suma;
    double delta_x = (b - a) / N;
    for ( double i = 0; i < N; ++i)
    {
        double m = a + (i - 0.5) * delta_x;
        suma += (pow(2*m,3)+pow(m, 2)+3*(m)) * delta_x;
    }
    
    return suma;
}

double func_to_integrate(double x, int degree)
{

    double polynomial_func;

    for ( double i = 0; i <= degree; i++)
    {
        
        polynomial_func += (pow(x, i));
    }
    return polynomial_func;
    
}