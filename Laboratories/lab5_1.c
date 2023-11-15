#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*Program calculate an integral by summing.
User enters the interval and N number of summs
User also defying function to integrade in func_to_intergrade*/

double integral_func(int a, int b, int N);
double func_to_integrate(double x);

int main(void) {
    double a;
    printf("Enter the lower limit a ");
    scanf("%d", &a);
    double b;
    printf("Enter the upper limit b ");
    scanf(" %d", &b);
    double N;
    printf("Enter the N of sum ");
    scanf(" %d", &N);

    double integral = integral_func(a, b, N);
    printf("%lf", integral);

    return 0;
}

double integral_func(int a, int b, int N){
/*function responsible for calculating the integral*/

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

    double function = x * x * x + x * x - 4; // defying the arbitrary function
    return function;
    
}