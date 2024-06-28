#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/abonent.h"

void increment_size(struct abonent** arr, int *num_elements)
{
  (*num_elements)++;
  struct abonent* temp = realloc(*arr, *num_elements * sizeof(struct abonent));
  if (temp == NULL) {
      perror("Failed to reallocate memory");
      exit(EXIT_FAILURE);  
  }
  *arr = temp;
}

int add_abonent(struct abonent** abonents, int* size, 
                char name[STR_SIZE], char second_name[STR_SIZE], 
                char tel[STR_SIZE]) {
  increment_size(abonents, size); 
  struct abonent* abonent = &(*abonents)[(*size) - 1];

  strcpy(abonent->name, name);
  strcpy(abonent->second_name, second_name);
  strcpy(abonent->tel, tel);
  return 0;
}

void move_to_end(struct abonent* abonents, int index , int *size) {
  struct abonent deleted_abonent = abonents[index];

  for (int i = index; i < *size - 1; i++) {
    abonents[i] = abonents[i + 1]; 
  }

  abonents[*size - 1] = deleted_abonent;
  (*size)--;
}

void delete_abonents_by_name(struct abonent* abonents, int *size, char name[STR_SIZE]) {
  for (int i = 0; i < *size; i++) {
    if (strcmp(abonents[i].name, name) == 0) {
      move_to_end(abonents, i, size);
    }  
  } 
}

void find_abonents_by_name(struct abonent* abonents, int size, char name[STR_SIZE]) {
  for (int i = 0; i < size; i++) {
    if (strcmp(abonents[i].name, name) == 0) {
      print_abonent(abonents[i]);
    }
  }
}

void print_abonent(struct abonent abonent) {
  printf("___Abonent___\n");
  printf("Abonent name: %s\n", abonent.name);
  printf("Abonent second_name: %s\n", abonent.second_name);
  printf("Abonent tel: %s\n", abonent.tel);
  printf("\n");
}

void print_all_abonents(struct abonent* abonents, int size) {
  for (int i = 0; i < size; i++) {
    print_abonent(abonents[i]);
  }
}
