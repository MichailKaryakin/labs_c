#include <stdio.h>
#include <string.h>

int is_punctuation_mark(char c) {
    if (c == '"' || c == ',' || c == '.' || c == ';' || c == ':' ||
        c == '-' || c == '?' || c == '!' || c == ')' || c == '(') {
        return 1;
    }
    return 0;
}

int first() {
    char str[80];
    char new_str[80];
    int size, i, k = 0;
    puts("input string");
    fflush(stdin);
    gets(str);
    size = strlen(str);
    for (i = 0; i < size; i++) {
        if (!is_punctuation_mark(str[i])) {
            new_str[k] = str[i];
            ++k;
        }
    }
    for (i = 0; i < size; i++) {
        if (is_punctuation_mark(str[i])) {
            new_str[k] = str[i];
            ++k;
        }
    }
    puts("input data: ");
    for (i = 0; i < size; i++) {
        printf("%c", str[i]);
    }
    puts("\noutput data: ");
    for (i = 0; i < size; i++) {
        printf("%c", new_str[i]);
    }
    return 0;
}

void check_word_and_print(char str_array[6][80], int i, int k, int begin_of_word, int cur_space) {
    if (str_array[i][begin_of_word] == str_array[i][cur_space - 1]) {
        for (k = begin_of_word; k < cur_space; k++) {
            printf("%c", str_array[i][k]);
        }
        printf(" ");
    }
}

int second() {
    char str_array[6][80];
    int count_of_lines, i, k;
    puts("input count of lines");
    scanf("%d", &count_of_lines);
    puts("input strings");
    for (i = 0; i < count_of_lines; i++) {
        fflush(stdin);
        gets(str_array[i]);
    }
    int begin_of_word = 0, cur_space;
    puts("input data: ");
    for (i = 0; i < count_of_lines; i++) {
        for (k = 0; str_array[i][k] != '\0'; k++) {
            printf("%c", str_array[i][k]);
        }
        puts("");
    }
    puts("output data: ");
    for (i = 0; i < count_of_lines; i++) {
        for (k = 0; str_array[i][k] != '\0'; k++) {
            if (str_array[i][k] == ' ' || is_punctuation_mark(str_array[i][k])) {
                cur_space = k;
                check_word_and_print(str_array, i, k, begin_of_word, cur_space);
                begin_of_word = k + 1;
            }
        }
        cur_space = k;
        check_word_and_print(str_array, i, k, begin_of_word, cur_space);
        begin_of_word = 0;
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