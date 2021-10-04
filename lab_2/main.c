#include <stdio.h>

int first() {
    int a, d;
    double b;
    char c;
    puts("1 - int, 2 - double, 3 - char");
    scanf("%d", &d);
    if (d == 1) {
        scanf("%d", &a);

        printf("int %d\n", a);
        printf("%d\n", a);

        scanf("%d", &a);

        printf("int %d\n", a);
        printf("%d\n", a);

        scanf("%d", &a);

        printf("int %d\n", a);
        printf("%d\n", a);

        scanf("%d", &a);

        printf("int %d\n", a);
        printf("%d\n", a);
    }
    if (d == 2) {
        scanf("%lf", &b);

        printf("double %.3lf\n", b);
        printf("%.3lf\n", b);

        scanf("%lf", &b);

        printf("double %.10e\n", b);
        printf("%.10e\n", b);

        scanf("%lf", &b);

        printf("double %.9lf\n", b);
        printf("%.9lf\n", b);

        scanf("%lf", &b);

        printf("double %.17e\n", b);
        printf("%.17e\n", b);
    }
    if (d == 3) {
        fflush(stdin);

        scanf("%c", &c);

        printf("char %c\n", c);
        printf("%c\n", c);

        fflush(stdin);

        scanf("%c", &c);

        printf("char %c\n", c);
        printf("%c\n", c);
    }
    return 0;
}

int second() {
    double i, j;
    signed int k;
    scanf("%5lf%*1lf%3lf%*1lf%d", &i, &j, &k);
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBAi = %3.2lf j = %.2lf k = %+d\xBA\n", i, j, k);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    return 0;
}

int main() {
    int number;
    puts("first task - 1, second task - 2");
    scanf("%d", &number);
    if (number == 1) {
        first();
    }
    if (number == 2) {
        second();
    }
    return 0;
}
