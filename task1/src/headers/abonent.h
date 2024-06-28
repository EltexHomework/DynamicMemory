#ifndef ABONENT_H
#define ABONENT_H

#define STR_SIZE 10

struct abonent {
  char name[STR_SIZE];
  char second_name[STR_SIZE];
  char tel[STR_SIZE];
};

void increment_size(struct abonent** arr, int* num_elements);
int add_abonent(struct abonent** abonents, int* size, char name[STR_SIZE], char second_name[STR_SIZE], char tel[STR_SIZE]);
void delete_abonents_by_name(struct abonent* abonents, int *size, char name[STR_SIZE]);
void find_abonents_by_name(struct abonent* abonents, int size, char name[STR_SIZE]);
void print_abonent(struct abonent abonent);
void print_all_abonents(struct abonent* abonents, int size);

#endif // !ABONENT_H
