#include <stdio.h>
#include <stdlib.h>

int file_size(FILE* file) {
    int file_size = 0;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return file_size;
}

int task(FILE* file) {
    int size = file_size(file);
    int* array = malloc(size * sizeof(int));
    int i = 0;
    int prev_is_space = 0;
    while (1) {
        int current_symbol;
        current_symbol = fgetc(file);
        if (current_symbol == EOF) {
            break;
        }
        if (!prev_is_space || current_symbol != ' ') {
            array[i] = current_symbol;
            i++;
        }
        prev_is_space = (current_symbol == ' ');
    }
    fclose(file);
    file = fopen("file.txt", "w");
    int k = 0;
    for (k = 0; k < i; k++) {
        fputc(array[k], file);
    }
    return 0;
}

int main() {
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        puts("file is not opened");
    } else {
        task(file);
        fclose(file);
    }
    return 0;
}

