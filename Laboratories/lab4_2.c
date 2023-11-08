#include <stdio.h>

int main() {
    double i;
    for(i = 50; i <= 200; i += 10){
        double celsius;
        celsius = (5.0 / 9.0) * (i - 32);
        printf("%lf ", i) + printf("%lf\n", celsius);
    }

    return 0;
}