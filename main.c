#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
  char firstName[100];
  char userName[100];
  char passWord[100];
};

void registration() {
  struct user u1;
  FILE *fptr1;
  char filename[100];
  system("clear");
  printf("============================================\n");
  printf("\t\t\t\t Registration Menu \t\t\t\t\n");
  printf("============================================\n");

  printf("The Input Should be more than 5 characters to 100 characters\n ");
  printf("\n");

  printf("Enter Your FirstName : ");
  scanf("%s", u1.firstName);

  printf("Enter Your UserName : ");
  scanf("%s", u1.userName);

  printf("Enter Your Password : ");
  scanf("%s", u1.passWord);

  strcpy(filename, u1.userName);

  fptr1 = fopen(strcat(filename, ".txt"), "w");

  // writing struct values to file
  fwrite(&u1, sizeof(struct user), 1, fptr1);

  if (!fwrite == NULL) {
    printf("You are successfully registered !!");
    fclose(fptr1);
  } else {
    printf("Error occurred Please Try again ");
  }
}

void login() {
  struct user u1;
  FILE *fptr2;
  char stored_userName[100];
  char stored_passWord[100];
  char filename[100];

  system("clear"); printf("============================================\n");
  printf("\t\t\t\t Login Menu \t\t\t\t\n");
  printf("============================================\n");
  
  
  printf("\nUsername :\t");
  scanf("%s", stored_userName);
  printf("Password:\t");
  scanf("%s", stored_passWord);
  strcpy(filename, stored_userName);
  fptr2 = fopen(strcat(filename, ".txt"), "r");
  if (fptr2 == NULL) {
    printf("\nAccount number not registered");
  } else {
    fread(&u1, sizeof(struct user), 1, fptr2);
    fclose(fptr2);
  }
  if (!strcmp(stored_passWord, u1.passWord)) {
    printf("\nWelcome %s", u1.userName);
  
  }
  else {
    printf("Your Username Or Password Is Invalid : ");
  }
  
}

int main(void) {
  int choice = 0;
  do {

    printf("============================================\n");
    printf("\t\t\t\t\t Menu \t\t\t\t\n");
    printf("============================================\n");
    printf("What You Want To Do?\n");
    printf("1. Register \n");
    printf("2. login\n");
    printf("============================================\n");
    printf(">> ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      registration();
      break;

    case 2:
      login();
      break;

    default:
      printf("Invaild Input Please Try Again !! ");
    }
  } while (0);

  return 0;
}