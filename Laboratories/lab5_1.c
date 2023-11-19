#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*Program calculate an integral by summing
User enters the interval a,b and the quantity of summs - N
Next step is that user gives the degree of polynomial function and gives coefficients to the array
Created polynomial in func_to_integrate is passed to the integral_func*/

double integral_func(double a, double b, int N, int degree, double coefficients[]);
double func_to_integrate(double x, int degree, double coefficients[]);

int main(void) {
    double a, b;    //defying the interval
    int N, degree;

    printf("Enter the lower limit a: ");
    scanf("%lf", &a);

    printf("Enter the upper limit b: ");
    scanf("%lf", &b);

    printf("Enter the degree of the polynomial function: ");
    scanf("%d", &degree);

    double coefficients[degree + 1]; //array with coefficients

    printf("Enter the coefficients of the polynomial function in descending order:\n");
    for (int i = degree; i >= 0; --i) {
        printf("Coefficient for x^%d: ", i);
        scanf("%lf", &coefficients[i]); //User enters coeficients as many times as the value of degree + 1
    }

    printf("Enter the N of sum: ");
    scanf("%d", &N);

    double integral = integral_func(a, b, N, degree, coefficients); //declaring the veriable that holds the result
    printf("Result of the integral: %lf\n", integral);

    return 0;
}

double integral_func(double a, double b, int N, int degree, double coefficients[]) {
    double suma = 0.0;
    double delta_x = (b - a) / N;

    for (double i = 0; i < N; ++i) {
        double m = a + (i - 0.5) * delta_x;
        suma += func_to_integrate(m, degree, coefficients) * delta_x;   // User's function take calculated m as an argument
    }

    return suma;
}

double func_to_integrate(double x, int degree, double coefficients[]) {
    double function = 0.0;

    for (int i = degree; i >= 0; --i) {
        function += coefficients[i] * pow(x, i);
    }

    return function;
}