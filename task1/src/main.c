#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/abonent.h"

void menu(struct abonent** abonents, int* size);

void print_options(); 

int read_option(); 

void read_string(char str[STR_SIZE], char *prompt);

int call_function_by_option(struct abonent** abonents, int* size, int option);

int read_values_and_add_abonent(struct abonent** abonents, int* size);

int delete_abonents(struct abonent* abonents, int* size); 

int find_abonents(struct abonent* abonents, int* size);

void print_abonents(struct abonent* abonents, int* size);

void init_array(struct abonent* abonents, int* size);

void flush_stdin();

int main(void) {
  int size = 0;
  struct abonent* abonents = (struct abonent*) calloc(size, sizeof(struct abonent));

  menu(&abonents, &size);
  free(abonents);
  return 0;
}

void menu(struct abonent** abonents, int* size) {
  int option;
  while (1) {
    print_options();
    option = read_option();
    
    int result = call_function_by_option(abonents, size, option);

    if (result == -1) {
      return;
    }
    if (result == -2) {
      printf("Wrong option\n\n");
    }
  }
}

void print_options() {
  printf("___MENU___\n");
  printf("1) Add abonent\n");
  printf("2) Delete abonent\n");
  printf("3) Find abonent by name\n");
  printf("4) Print all abonents\n");
  printf("5) Exit\n");
}

int read_option() {
  int option;
  int result;

  printf("Enter option: ");

  result = scanf("%d", &option);

  if (result != 1 || option < 1 || option > 5) {
      option = -1; 
  }

  flush_stdin();  
  return option;
}

int call_function_by_option(struct abonent** abonents, int* size, int option) {
  switch (option) {
    case 1:
      return read_values_and_add_abonent(abonents, size);
    case 2:
      return delete_abonents(*abonents, size);
    case 3:
      return find_abonents(*abonents, size);
    case 4:
      print_abonents(*abonents, size);
      return 0; 
    case 5:
      return -1; 
    default:
      return -2;
  }
}

int read_values_and_add_abonent(struct abonent** abonents, int* size) {
  char name[STR_SIZE];
  char second_name[STR_SIZE];
  char tel[STR_SIZE];

  read_string(name, "Enter name: "); 
  read_string(second_name, "Enter second name: ");
  read_string(tel, "Enter tel: ");

  if (add_abonent(abonents, size, name, second_name, tel) == -1) {
    printf("Array of abonents is full\n");
  }
  printf("\n");
  return 1;
}

int delete_abonents(struct abonent* abonents, int* size) {
  char name[STR_SIZE];

  read_string(name, "Enter name: "); 
  
  printf("\n");
  delete_abonents_by_name(abonents, size, name);
  printf("\n");

  return 1;
}

int find_abonents(struct abonent* abonents, int* size) {
  char name[STR_SIZE];
  
  read_string(name, "Enter name: "); 
  
  printf("\n");
  find_abonents_by_name(abonents, *size, name);
  printf("\n");

  return 1;
}

void print_abonents(struct abonent* abonents, int* size) {
  printf("\n");
  print_all_abonents(abonents, *size); 
  printf("\n");
}

void flush_stdin() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void read_string(char str[STR_SIZE], char *prompt) {
  while (1) {
    printf("%s", prompt);
    if (fgets(str, STR_SIZE, stdin) == NULL) {
      printf("Invalid input\n");
    }
    if (str[strlen(str) - 1] == '\n') {
      str[strlen(str) - 1] = '\0';
      break;
    }
    printf("Too long string\n");
    flush_stdin(); 
  }

}
