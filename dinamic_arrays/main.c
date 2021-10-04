#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
    int size;
    int cap;
    int* data;
} Array;

Array NewArray(int cap) {
    Array mas;
    mas.cap = cap;
    mas.size = 0;
    mas.data = (int*) malloc(mas.cap * sizeof(int));
    return mas;
}

void Add(Array* mas, int new_val) {
    int j;
    mas->size++;
    if (mas->size < mas->cap) {
        mas->data[mas->size] = new_val;
    } else {
        int* new_mas = (int*) malloc((int) (mas->cap * 2) * sizeof(int));
        for (j = 0; j < mas->size - 1; ++j) {
            new_mas[j] = mas->data[j];
        }
        free(mas->data);
        mas->data = new_mas;
        mas->cap = (int) (mas->cap * 2);
        mas->data[mas->size - 1] = new_val;
    }
}

int four() {
    int i;
    Array mas = NewArray(2);
    Add(&mas, 100);
    Add(&mas, 24);
    Add(&mas, 42);
    Add(&mas, 12);
    Add(&mas, 100);
    Add(&mas, 42);
    Add(&mas, 21);
    Add(&mas, 100);

    for (i = 0; i < mas.size; ++i) {
        printf("%d ", mas.data[i]);
    }

    return 0;
}

int main() {
    four();
    return 0;
}
