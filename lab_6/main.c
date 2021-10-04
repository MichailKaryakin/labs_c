#include <stdio.h>
#include <stdlib.h>

int first() {
    int i, k = 0;
    int array[20];
    int array_2[20];
    puts("input elements");
    for (i = 0; i < 20; i++) {
        scanf("%d", &array[i]);
    }
    for (i = 0; i < 20; i++) {
        if (array[i] % 10 == 3) {
            array_2[k] = array[i];
            ++k;
        }
    }
    for (i = 0; i < k; i++) {
        printf("%d ", array_2[i]);
    }
    return 0;
}

int second() {
    int i;
    double array[1820];
    int size;
    puts("input number of elements");
    scanf("%d", &size);
    for (i = 0; i < size; i++) {
        array[i] = rand();
    }
    int k;
    double t;
    for (i = 0; i < size; i++) {
        k = i + 1;
        while (k > 0) {
            if (array[k] > array[k - 1]) {
                t = array[k - 1];
                array[k - 1] = array[k];
                array[k] = t;
            }
            --k;
        }
    }
    for (i = 0; i < size; i++) {
        printf("%.2lf\n", array[i]);
    }
    return 0;
}

int third() {
    int array[9][10];
    int x, i, k;
    puts("input x");
    scanf("%d", &x);
    puts("input array elements");
    for (i = 0; i < 9; i++) {
        for (k = 0; k < 10; k++) {
            scanf("%d", &array[i][k]);
        }
    }
    for (i = 0; i < 9; i++) {
        for (k = 0; k < 10; k++) {
            if (array[i][k] == x) {
                if (k == 2) {
                    printf("%d ", i);
                }
                continue;
            }
            else {
                break;
            }
        }
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
