#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void printer(Records* records);

void adder(Records* records) {
    add_record(records, record_input());
}

void editor(Records* records) {
    if (records->size == 0) {
        return;
    }
    int index;
    puts("input number of record you want to edit:");
    scanf("%d", &index);
    fflush(stdin);
    Record record = {};
    if (!(index < 0 || index > records->size)) {
        record = record_input();
    }
    replace_record(records, record, index - 1);
}

void deleter(Records* records) {
    if (records->size == 0) {
        return;
    }
    int index;
    puts("input number of record you want to delete:");
    scanf("%d", &index);
    fflush(stdin);
    delete_record(records, index - 1);
}

void searcher(Records* records) {
    if (records->size == 0) {
        puts("you have no records");
        return;
    }
    char author[20];
    puts("input authors surname:");
    input_string(author, 20);
    Records searched = search_record(records, author, 0, NULL, AUTHOR);
    if (searched.size == 0) {
        puts("records not found");
        return;
    }
    printer(&searched);
}

void printer(Records* records) {
    print_records(records);
}

void task(Records* records) {
    int user_choice;
    puts("1 - task 1, 2 - task 2");
    scanf("%d", &user_choice);
    fflush(stdin);
    if (user_choice == 1) {
        char author[20];
        puts("input authors surname:");
        input_string(author, 20);
        int year;
        puts("input year:");
        scanf("%d", &year);
        fflush(stdin);
        Records searched = search_record(records, NULL, year, NULL, YEAR);
        searched = search_record(&searched, author, 0, NULL, AUTHOR);
        print_records(&searched);
    }
    if (user_choice == 2) {
        char subject[20];
        puts("input subject:");
        input_string(subject, 20);
        Records searched = search_record(records, NULL, 0, subject, SUBJECT);
        puts("the share of books with this topic is:");
        printf("%lf\n", (double) searched.size / records->size);
    }
}

void saver(FILE* file, Records records) {
    serialize_records(&records, file);
}

int main() {
    FILE* file = NULL;
    Records records;
    records = new_records(NUMBER_OF_RECORDS);
    char path[20] = {0};
    while (1) {
        int user_choice;
        system("cls");
        printf("working with file: ");
        if (strlen(path) != 0) {
            puts(path);
        } else {
            puts("file is not opened");
        }
        printf("0 - open or create file, 1 - add, 2 - edit, 3 - delete, 4 - search, 5 - print, 6 - task, 7 - exit and save\n");
        scanf("%d", &user_choice);
        fflush(stdin);
        if (user_choice == 0) {
            Records temp_records;
            puts("input path:");
            input_string(path, 20);
            file = fopen(path, "rb");
            clear_records(&records);
            if (file == NULL) {
                file = fopen(path, "w+b");
                puts("new file created");
                waiting_input();
            }
            temp_records = deserialize_records(file);
            int i;
            for (i = 0; i < temp_records.size; i++) {
                add_record(&records, temp_records.array[i]);
            }
            fclose(file);
        }
        if (file == NULL && user_choice != 7) {
            puts("file is not opened");
            waiting_input();
            continue;
        }
        if (user_choice == 1) {
            system("cls");
            adder(&records);
            waiting_input();
        }
        if (user_choice == 2) {
            system("cls");
            printer(&records);
            editor(&records);
            waiting_input();
        }
        if (user_choice == 3) {
            system("cls");
            printer(&records);
            deleter(&records);
            waiting_input();
        }
        if (user_choice == 4) {
            system("cls");
            searcher(&records);
            waiting_input();
        }
        if (user_choice == 5) {
            system("cls");
            printer(&records);
            waiting_input();
        }
        if (user_choice == 6) {
            system("cls");
            task(&records);
            waiting_input();
        }
        if (user_choice == 7) {
            break;
        }
    }
    file = fopen(path, "wb");
    saver(file, records);
    fclose(file);
    delete_records(&records);
    return 0;
}
