#include <stdio.h>
#include <math.h>

int first() {
    int k, i, sum = 0;
    puts("input number");
    scanf("%d", &k);
    int t = k;
    for (i = 1; t != 0; i++) {
        int numi = t % 10;
        sum += numi;
        t /= 10;
    }
    if (k % sum == 0) {
        puts("yes");
    } else {
        puts("no");
    }
    return 0;
}

int second() {
    int number, digit, result = 0;
    puts("input N");
    scanf("%d", &number);
    while (number != 0) {
        digit = number % 10;
        result *= 10;
        result += digit;
        number /= 10;
    }
    printf("%d", result);
    return 0;
}

int third() {
    const double a = 2.1, b = 1.2;

    double xmin, xmax;
    puts("\ninput min and max");
    scanf("%lf %lf", &xmin, &xmax);
    int numberofpoints;
    puts("input number of points");
    scanf("%d", &numberofpoints);
    double step = (xmax - xmin) / numberofpoints;

    double x;
    int i = 0;
    double array[2][numberofpoints];

    for (x = xmin; x <= xmax; x += step) {
        array[0][i] = x;
        array[1][i] = (x < 2 ? sin(a * x) - cos(b * x) : x > 4 ? 1 + a * log10(exp(x)) : cos(x) / sin(x));
        i += 1;
    }

    int count = i;

    printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
    printf("\xB3   %c   \xB3   %c   \xB3\n", 120, 102);
    printf("\xC3\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4\n");
    for (i = 0; i < count; i++){
        printf("\xB3 %.3lf \xB3 %.3lf \xB3\n", array[0][i], array[1][i]);
    }
    printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

    return 0;
}

int main() {
    int number;
    puts("first task - 1, second task - 2, third task - 3");
    scanf("%d", &number);
    if (number == 1) {
        first();
    }
    if (number == 2) {
        second();
    }
    if (number == 3) {
        third();
    }
    return 0;
}
