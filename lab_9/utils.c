#include "utils.h"

void array_shift(int* array, int begin, int end, int shift_count) {
    int i;
    if (shift_count > 0) {
        for (i = end; i >= begin; i--) {
            array[i + shift_count] = array[i];
        }
    }
    if (shift_count < 0) {
        for (i = begin; i <= end; i++) {
            array[i + shift_count] = array[i];
        }
    }
}





