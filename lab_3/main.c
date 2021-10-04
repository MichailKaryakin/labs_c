#include <stdio.h>
#include <math.h>

#define CONST_A 2
#define CONST_B 3

double function(double x) {
    return pow((CONST_B * x * pow(sin(2 * x), 2) + exp(-2 * x) * (x + CONST_A)) / (CONST_A + sqrt(CONST_B * x)), 0.25);
}

int first() {
    double x;
    scanf("%lf", &x);
    if (CONST_A + sqrt(CONST_B * x) != 0 &&
        (CONST_B * x * pow(sin(2 * x), 2) + exp(-2 * x) * (x + CONST_A)) / (CONST_A + sqrt(CONST_B * x)) >= 0) {
        printf("x = %.2lf f = %.2lf", x, function(x));
    } else {
        puts("the value you entered does not correspond to the DL");
    }
    return 0;
}

int second() {
    double x, f;
    scanf("%lf", &x);
    f = (-1 > x) ? exp(x) : (x >= 1) ? x : 1;
    printf("x = %.2lf f = %.2lf", x, f);
    return 0;
}

int third() {
    double x, y;
    puts("input coordinates");
    scanf("%lf%lf", &x, &y);
    if (x > 0 && y > 0) {
        if (x < 6 && y < 4) {
            if (y > pow(x, 2)) {
                printf("the point is in zone %d", 1);
            } else {
                printf("the point is in zone %d", 2);
            }
        } else {
            if (y > pow(x, 2)) {
                printf("the point is in zone %d", 3);
            } else {
                printf("the point is in zone %d", 4);
            }
        }
    } else if (x == 0) {
        puts("the point is on the x axis");
    } else if (y == 0) {
        puts("the point is on the y axis");
    } else {
        puts("the point is outside the scope of the definition");
    }
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
