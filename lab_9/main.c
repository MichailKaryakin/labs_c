#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void first_task(int* array) {
    int i;
    int zero_count = 0;
    for (i = 0; i < SIZE; i++) {
        if (array[i] == 0) {
            array_shift(array, zero_count, i - 1, 1);
            array[zero_count] = 0;
            zero_count++;
        }
    }
}

int find_col_max_areth_value(int** array, int rows, int cols) {
    int current_row_index, current_col_index;
    int desired_col;
    double max_arith_value = 0, sum = 0, count_of_elements = 0;
    for (current_col_index = 0; current_col_index < cols; current_col_index++) {
        for (current_row_index = 0; current_row_index < rows; current_row_index++) {
            if (array[current_row_index][current_col_index] >= 0) {
                sum += array[current_row_index][current_col_index];
                count_of_elements++;
            }
        }
        if (sum / count_of_elements > max_arith_value) {
            max_arith_value = sum / count_of_elements;
            desired_col = current_col_index;
        }
        sum = 0;
        count_of_elements = 0;
    }
    return desired_col;
}

void second_task(int** array, int** array2, int rows, int cols) {
    int current_row_index;
    int desired_col = find_col_max_areth_value(array, rows, cols);
    for (current_row_index = 0; current_row_index < rows; current_row_index++) {
        array_shift(array[current_row_index], desired_col + 1, SIZE_ROW - 1, -1);
    }
    int i, k;
    for (i = 0; i < SIZE_ROW; i++) {
        for (k = 0; k < SIZE_COLUMNS - 1; k++) {
            array2[i][k] = array[i][k];
        }
    }
}

int main() {
    puts("1 - first task, 2 - second task");
    int number;
    scanf("%d", &number);
    if (number == 1) {
        int array[SIZE];
        int i;
        for (i = 0; i < SIZE; i++) {
            scanf("%d", &array[i]);
        }
        first_task(array);
        for (i = 0; i < SIZE; i++) {
            printf("%d", array[i]);
        }
    }
    if (number == 2) {
        int** array = malloc(SIZE_ROW * sizeof(int*));
        int i, k;
        for (i = 0; i < SIZE_ROW; i++) {
            array[i] = malloc(SIZE_COLUMNS * sizeof(int));
        }
        printf("input array: %d * %d\n", SIZE_ROW, SIZE_COLUMNS);
        for (i = 0; i < SIZE_ROW; i++) {
            for (k = 0; k < SIZE_COLUMNS; k++) {
                scanf("%d", &array[i][k]);
            }
        }
        int** new_array = malloc(SIZE_ROW * sizeof(int*));
        for (i = 0; i < SIZE_ROW; i++) {
            new_array[i] = malloc((SIZE_COLUMNS - 1) * sizeof(int));
        }
        second_task(array, new_array, SIZE_ROW, SIZE_COLUMNS);
        for (i = 0; i < SIZE_ROW; i++) {
            for (k = 0; k < SIZE_COLUMNS - 1; k++) {
                printf("%d ", new_array[i][k]);
            }
            puts("");
        }
        for (i = 0; i < SIZE_ROW; i++) {
            free(array[i]);
        }
        free(array);
        for (i = 0; i < SIZE_ROW; i++) {
            free(new_array[i]);
        }
        free(new_array);
    }
    return 0;
}

