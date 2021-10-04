#include <stdio.h>
#include <limits.h>

#define NUMBER_OF_STRINGS 5

int first() {
    int array[20];
    int i;
    int number_of_elements;
    int new_number_of_elements;
    puts("input number of elements");
    scanf("%d", &number_of_elements);
    puts("input elements");
    for (i = 0; i < number_of_elements; i++) {
        scanf("%d", array + i);
    }
    puts("input data: ");
    for (i = 0; i < number_of_elements; i++) {
        printf("%d ", array[i]);
    }
    puts("");
    int max = 0, min = INT_MAX;
    int* min_pointer;
    int* max_pointer;
    for (i = 0; i < number_of_elements; i++) {
        if (*(array + i) < min) {
            min = *(array + i);
            min_pointer = array + i;
        }
        if (*(array + i) > max) {
            max = *(array + i);
            max_pointer = array + i;
        }
    }
    int* temp;
    if (min_pointer > max_pointer) {
        temp = max_pointer;
        max_pointer = min_pointer;
        min_pointer = max_pointer;
    }
    new_number_of_elements = number_of_elements - (max_pointer - min_pointer - 1);
    int* current_pointer;
    int* current_replace_pointer = min_pointer + 1;
    for (current_pointer = max_pointer; current_pointer < array + number_of_elements; current_pointer++) {
        *current_replace_pointer = *current_pointer;
        current_replace_pointer++;
    }
    puts("output data: ");
    for (i = 0; i < new_number_of_elements; i++) {
        printf("%d ", *(array + i));
    }
    return 0;
}

int second() {
    char array[5][80] = {{"When the music's over"},
                         {"When the music's over, yeah"},
                         {"When the music's over turn out the lights!!"},
                         {"Turn out the lights!!!!"},
                         {"Turn out the lights, yeah"}};
    int i, k;
    puts("input data: ");
    for (i = 0; i < NUMBER_OF_STRINGS; i++) {
        for (k = 0; array[i][k] != '\0'; k++) {
            printf("%c", array[i][k]);
        }
        puts("");
    }
    int max_length = 0;
    int length = 0;
    for (i = 0; i < NUMBER_OF_STRINGS; i++) {
        for (k = 0; array[i][k] != '\0'; k++) {
            length++;
        }
        if (length > max_length) {
            max_length = length;
        }
        length = 0;
    }
    int length_of_the_shift[NUMBER_OF_STRINGS];
    for (i = 0; i < NUMBER_OF_STRINGS; i++) {
        for (k = 0; array[i][k] != '\0'; k++) {
            length++;
        }
        length_of_the_shift[i] = (max_length - length) / 2;
        length = 0;
    }
    char* last_char_address;
    char* current_shift_char;
    for (i = 0; i < NUMBER_OF_STRINGS; i++) {
        for (k = 0; array[i][k] != '\0'; k++) {
            last_char_address = &array[i][k];
        }
        for (current_shift_char = last_char_address; current_shift_char >= &array[i][0]; current_shift_char--) {
            *(last_char_address + length_of_the_shift[i]) = *current_shift_char;
            last_char_address--;
        }
        for (k = 0; k < length_of_the_shift[i]; k++) {
            array[i][k] = ' ';
        }
    }
    puts("output data: ");
    for (i = 0; i < NUMBER_OF_STRINGS; i++) {
        for (k = 0; array[i][k] != '\0'; k++) {
            printf("%c", array[i][k]);
        }
        puts("");
    }
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
