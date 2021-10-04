#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void waiting_input() {
    puts("input any symbol to continue:");
    getchar();
}

void array_shift(Record* array, int begin, int end, int shift_count) {
    int i;
    if (shift_count > 0) {
        for (i = end; i >= begin; i--) {
            array[i + shift_count] = array[i];
        }
    }
    if (shift_count < 0) {
        for (i = begin - shift_count; i <= end; i++) {
            array[i + shift_count] = array[i];
        }
    }
}

int file_size(FILE* file) {
    int file_size = 0;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return file_size;
}

void input_string(char* buf, int count) {
    fgets(buf, count, stdin);
    buf[strlen(buf) - 1] = '\0';
}

void serialize(Record record, FILE* file) {
    fwrite(&record, sizeof(record), 1, file);
}

Record deserialize(FILE* file) {
    Record record;
    fread(&record, sizeof(record), 1, file);
    return record;
}

void record_print(Record rec, int index) {
    printf("\xBA%-5d%-20s%-20s%-20s%-20d%-20s\xBA", index, rec.author, rec.title, rec.publisher, rec.year, rec.subject);
}

Record record_input() {
    Record rec;
    fflush(stdin);
    puts("input author:");
    input_string(rec.author, 20);
    puts("input title:");
    input_string(rec.title, 20);
    puts("input publisher:");
    input_string(rec.publisher, 20);
    puts("input subject:");
    input_string(rec.subject, 20);
    puts("input year:");
    char year_str[20];
    int year;
    while (1) {
        input_string(year_str, 20);
        year = atoi(year_str);
        if (year == 0) {
            puts("incorrect input, try again");
            continue;
        }
        break;
    }
    rec.year = year;
    return rec;
}

Records new_records(int size) {
    Records records;
    records.array = malloc(size * sizeof(Record));
    records.size = 0;
    return records;
}

void add_record(Records* records, Record record) {
    records->array[records->size] = record;
    records->size++;
}

void print_table_up_line() {
    int i;
    printf("\xC9");
    for (i = 0; i < 105; i++) {
        printf("\xCD");
    }
    printf("\xBB");
    puts("");
}

void print_table_middle_line() {
    int i;
    printf("\xCC");
    for (i = 0; i < 105; i++) {
        printf("\xCD");
    }
    printf("\xB9");
    puts("");
}

void print_table_down_line() {
    int i;
    printf("\xC8");
    for (i = 0; i < 105; i++) {
        printf("\xCD");
    }
    printf("\xBC");
    puts("");
}

void print_records(Records* records) {
    if (records->size == 0) {
        puts("you have no records");
        return;
    }
    int i;
    puts("here is your list:");
    print_table_up_line();
    printf("\xBA%-5s%-20s%-20s%-20s%-20s%-20s\xBA\n", "  #", "       author", "       title", "     publisher",
           "        year", "      subject");
    print_table_middle_line();
    for (i = 0; i < records->size; i++) {
        record_print(records->array[i], i + 1);
        puts("");
    }
    print_table_down_line();
}

void serialize_records(Records* records, FILE* file) {
    int i;
    for (i = 0; i < records->size; i++) {
        serialize(records->array[i], file);
    }
}

Records deserialize_records(FILE* file) {
    int i;
    int size = file_size(file) / (int) sizeof(Record);
    Records from_file = new_records(size);
    for (i = 0; i < size; i++) {
        add_record(&from_file, deserialize(file));
    }
    return from_file;
}

void replace_record(Records* records, Record record, int index) {
    if (index < 0 || index > records->size) {
        puts("there is no such record");
        return;
    }
    records->array[index] = record;
    puts("edit successful");
}

void delete_record(Records* records, int index) {
    if (index < 0 || index > records->size) {
        puts("there is no such record");
        return;
    }
    array_shift(records->array, index, records->size - 1, -1);
    records->size--;
    puts("delete successful");
}

Records search_record(Records* records, const char* author, int year, const char* subject, SearchedField field) {
    int i;
    int count = 0;
    for (i = 0; i < records->size; i++) {
        Record* temp = &records->array[i];
        if (field == AUTHOR) {
            if (!strncmp(temp->author, author, 20)) {
                count++;
            }
        } else if (field == YEAR) {
            if (temp->year > year) {
                count++;
            }
        } else if (field == SUBJECT) {
            if (!strncmp(temp->subject, subject, 20)) {
                count++;
            }
        }
    }
    Records filtered = new_records(count);
    for (i = 0; i < records->size; i++) {
        Record* temp = &records->array[i];
        if (field == AUTHOR) {
            if (!strncmp(temp->author, author, 20)) {
                add_record(&filtered, records->array[i]);
            }
        } else if (field == YEAR) {
            if (temp->year > year) {
                add_record(&filtered, records->array[i]);
            }
        } else if (field == SUBJECT) {
            if (!strncmp(temp->subject, subject, 20)) {
                add_record(&filtered, records->array[i]);
            }
        }
    }
    return filtered;
}

void clear_records(Records* records) {
    records->size = 0;
}

void delete_records(Records* records) {
    free(records->array);
    records->size = 0;
}
