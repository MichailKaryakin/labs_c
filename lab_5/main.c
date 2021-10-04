#include <stdio.h>
#include <math.h>

#define CONST_X 4
#define PRECISE 1e-4

unsigned long long int fact(int x) {
    if (x < 2) {
        return 1;
    }
    return x * fact(x - 1);
}

double func(int n) {
    return (double) (n + 1) / (double) fact(n + 2) * pow(CONST_X, n + 1);
}

int main() {
    int n = 0;
    double sum = 0;
    double current_result = 0, previous_result = 0;
    while (1) {
        current_result = func(n);
        sum += current_result;
        printf("%2d %9lf %9lf\n", n, current_result, sum);
        if (fabs(current_result - previous_result) <= PRECISE) {
            break;
        }
        previous_result = current_result;
        ++n;
    }
    puts("final results: ");
    printf("n = %d\n", n);
    printf("sum = %lf", sum);
    return 0;
}