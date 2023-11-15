#include <stdio.h>
#include <math.h>

/*Program finds the root of the function defined by user */

float function_to_find_root(float x) {
    // Replace this with any function that has a root in the chosen interval
    return x * x * x + x * x - 4;
}

float bisection_method(float a, float b, int N) {
    if (function_to_find_root(a) * function_to_find_root(b) > 0) {
        printf("Error: The function values at the interval endpoints do not have opposite signs.\n");
        return NAN; // Not-a-Number to represent an error
    }

    float c;

    for (int i = 0; i < N; ++i) {
        c = (a + b) / 2;
        if (function_to_find_root(c) == 0.0) {
            break;  // Exact root found
        } else if (function_to_find_root(c) * function_to_find_root(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    return c;
}

int main() {
    float a = 0.0;
    float b = 3.0;
    int N = 20;

    float root = bisection_method(a, b, N);

    if (!isnan(root)) {
        printf("Root found at x = %f\n", root);
        printf("Function value at the root: %f\n", function_to_find_root(root));
    }

    return 0;
}