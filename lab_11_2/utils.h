#ifndef LAB_11_2_BASE_H
#define LAB_11_2_BASE_H

#define NUMBER_OF_RECORDS 100

typedef struct Record {
    char author[20];
    char title[20];
    char publisher[20];
    int year;
    char subject[20];
} Record;

typedef struct Records {
    Record* array;
    int size;
} Records;

typedef enum SearchedField {
    AUTHOR = 1,
    YEAR,
    SUBJECT
} SearchedField;

void waiting_input();

void array_shift(Record* array, int begin, int end, int shift_count);

int file_size(FILE* file);

void input_string(char* buf, int count);

void serialize(Record record, FILE* file);

Record deserialize(FILE* file);

void record_print(Record rec, int index);

Record record_input();

Records new_records(int size);

void add_record(Records* records, Record record);

void print_records(Records* records);

void serialize_records(Records* records, FILE* file);

Records deserialize_records(FILE* file);

void replace_record(Records* records, Record record, int num);

void delete_record(Records* records, int num);

Records search_record(Records* records, const char* author, int year, const char* subject, SearchedField field);

void clear_records(Records* records);

void delete_records(Records* records);

#endif //LAB_11_2_BASE_H
