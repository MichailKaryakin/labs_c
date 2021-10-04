#include <stdio.h>
#include "tech_part.h"

const int n = 50;

double a, b, low_lim, high_lim;

int main() {
    if (n >= 7) {
        puts("введите a, b, нижнюю границу и верхнюю границу");
        scanf("%lf%lf%lf%lf", &a, &b, &low_lim, &high_lim);
        printf("%lf", algorithm_implementation(f, low_lim, high_lim, a, b, n));
        return 0;
    }
}
