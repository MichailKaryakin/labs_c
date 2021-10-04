#include <math.h>

double f(double x, double a, double b) {
    return x / (sqrt(pow(a, 2) + b * pow(x, 2)));
}

double algorithm_implementation(double (* f)(double, double, double), double c, double d, double a, double b, int n) {
    double h = (d - c) / n;
    double sum = (f(c, a, b) + f(d, a, b)) / 2.0;

    double x = c + h;
    int i;
    for (i = 1; i < n - 1; i++) {
        sum = sum + f(x, a, b);
        x = x + h;
    }

    return h * sum;
}
