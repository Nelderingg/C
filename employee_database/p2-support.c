#define _GNU_SOURCE		//strcasestr is a nonstandard GNU extension, 
//we need this line while serching for matching last name
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2-support.h"



void create_record (char ID[], char first_name[],char last_name[], char email[], double salary, date hire_date, struct DataBase *db)// specify parameters. Clues are in the initalize function.
{
  int new_addition = db->total + 1;
  //define function. Clues are in the initalize function
  strcpy(db->emp[new_addition].ID,ID);
  strcpy(db->emp[new_addition].first_name, first_name);
  strcpy(db->emp[new_addition].last_name,last_name);
  strcpy(db->emp[new_addition].email,email);
  db->emp[new_addition].salary = salary;
  db->emp[new_addition].hire_date.day = hire_date.day; 
  db->emp[new_addition].hire_date.month = hire_date.month; 
  db->emp[new_addition].hire_date.year = hire_date.year; 
  //do not forget to increase total number of employees in the database
  db->total++;
}


void print_title ()// you can keep this fuction or remove if needed
{
  printf ("No. ID    Name          Email        Salary     Hire Date\n");
  printf ("--- ----- ------------- ------------ ---------- --/--/----\n");

}


//fix save function. Save array into file: database_updated in the same format with the 
//database file.
void save (dataBase_ptr db)// this function is for saving the database into a text file
{
  FILE *dbfu;
  dbfu = fopen ("database_updated", "w");//open an Std IO file to write into
  if (dbfu == NULL)
  {
    printf ("File cannot be created");
    return;
  }
  for (int i = 0; i < db->total; i++)
  {
    fprintf(dbfu,"%s" ,db->emp[i].ID);
    fprintf(dbfu,"%s", db->emp[i].first_name);
    fprintf(dbfu,"%s", db->emp[i].last_name);
    fprintf(dbfu,"%s", db->emp[i].email);
    fprintf(dbfu,"%lf", db->emp[i].salary);
    fprintf(dbfu,"%d", db->emp[i].hire_date.day);
    fprintf(dbfu,"%d", db->emp[i].hire_date.month);
    fprintf(dbfu,"%d", db->emp[i].hire_date.year);
  }

  fclose (dbfu);//close file after writing
  return;

}

//*********** ADDITIONAL FUNCTIONS ************************************************************************
// scp elderingn@compile.vcu.edu:/home/elderingn/project2/p2-support.c /Users/nathaneldering/Downloads/cmsc257/project2

void display_helper(dataBase_ptr db, int i)
{
  char full_name[nameSIZE * 3];
  strcpy(full_name, " ");

  printf("%s", "   ");
  printf("%s", db->emp[i].ID);

  //printf("%s", " ");

  strcat(full_name, db->emp[i].first_name);
  strcat(full_name, " ");
  strcat(full_name, db->emp[i].last_name);

  printf("%.14s", full_name);
  for(int j = strlen(full_name); j < 14; j++)
  {
    if(j < 14)
    {
      printf("%s", " ");
    }
  }

  printf("%s", " ");

  printf("%.12s", db->emp[i].email);
    for(int k = strlen(db->emp[i].email); k < 12; k++)
  {
    if(k < 12)
    {
      printf("%s", " ");
    }
  }

  printf("%s", " $");

  printf("%9.2f", db->emp[i].salary);

  printf("%s", " ");

  if(db->emp[i].hire_date.month < 10)
  {
  printf("%s", "0");
  printf("%d", db->emp[i].hire_date.month);
  }
  else
  {
    printf("%d", db->emp[i].hire_date.month);
  }

  printf("%s", "/");

  if(db->emp[i].hire_date.day < 10)
  {
    printf("%s", "0");
    printf("%d", db->emp[i].hire_date.day);
    
  }
  else
  {
    printf("%d", db->emp[i].hire_date.day);

  }

  printf("%s", "/");

  printf("%d\n", db->emp[i].hire_date.year);
}

int compar(const void * one, const void * two)
{
  return 0; 
}

void sort_by_ID(dataBase_ptr db)
{
  char temp[6];
  for(int i = 0; i < db->total - 1; i++)
  {
    for(int j = 0; j < db->total - 1; j++)
    { 
      if(strcmp(db->emp[j].ID, db->emp[j+1].ID) > 0)
      { 
        strcpy(temp, db->emp[j].ID);
        strcpy(db->emp[j].ID, db->emp[j+1].ID);
        strcpy(db->emp[j+1].ID, temp);
      }
    }
  }
}

void sort_by_HireDate(dataBase_ptr db)
{
  qsort(db, db->total, sizeof(int), compar);

}

void display_employee(dataBase_ptr db){
  int count = 0;
  printf ("No. ID    Name          Email        Salary     Hire Date\n");
  printf ("--- ----- ------------- ------------ ---------- --/--/----\n");
  //loop through all employees
  for(int i = 1; i <= db->total; i++){
  printf("%d", i-1);
  //print off all information for each employee 
  display_helper(db, i); 
  count++;
  }

}

void search_by_ID(dataBase_ptr db)
{
  //obtain ID number to search for
  printf("%s\n", "enter ID to search");
  //initialize variable to hold ID
  char ID_to_search[idSIZE*2];
  //get input from keybaord and set equal to variable
  scanf("%s", ID_to_search);
  //loop through database search for employee
  //when found print off all information for employee and end 
  for (int i =0; i < db->total; i++)
  {
    if(strcmp(db->emp[i].ID, ID_to_search) == 0)
    {
      printf("%d", i - 1);
      display_helper(db, i);
      //printf("%s", db->emp[i].ID);
      //printf("%s", " ");
      //printf("%.13s", db->emp[i].first_name);
      //printf("%s", " ");
      //printf("%.13s", db->emp[i].last_name);
      //printf("%s", " ");
      //printf("%s", db->emp[i].email);
      //printf("%s", " ");
      //printf("%s", "$");
      //printf("%-9.2f",  db->emp[i].salary);
      //printf("%s", " ");
      //printf("%d", db->emp[i].hire_date.day);
      //printf("%s", "/");
      //printf("%d",  db->emp[i].hire_date.month);
      //printf("%s", "/");
      //printf("%d\n", db->emp[i].hire_date.year);
    }
  }
}

void search_by_LastName(dataBase_ptr db)
{
  //obtain last name number to search for
  printf("%s\n", "enter last name to search");
  //initialize variable to hold last name
  char last_name_to_search[nameSIZE*2];
  int count = 0;
  //get input from keybaord and set equal to variable
  scanf("%s", last_name_to_search);
  //loop through database search for employee
  //when found print off all information for employee and end 

  printf("%s", last_name_to_search);
  for(int i = 0; i < strlen(last_name_to_search); i++)
  {
    int check = 0;

    for(int j = 0; j < strlen(last_name_to_search); j++)
    {
      if(strcmp(&db->emp[i].last_name[j], &last_name_to_search[j]) != 0)
      {
        check = 1;
      }
      if(check != 1)
      {
        display_helper(db, i);
      }
    }
    
  }
}

void delete_by_ID(dataBase_ptr db)
{
  //obtain ID number to search for and delte
  printf("%s\n", "enter ID to delete");
  //initialize variable to hold ID
  char ID_to_search_and_delete[idSIZE*2];
  //get input from keybaord and set equal to variable
  scanf("%s", ID_to_search_and_delete);
  sort_by_ID(db);
  //loop through database search for employee
  //when found set all employee information to null and end 
  for (int i =0; i < db->total; i++)
  {
    if(strcmp(db->emp[i].ID,ID_to_search_and_delete) == 0)
    {
      for(int j = i; j < db->total - 1; j++)
      {
        db->emp[j] = db->emp[j+1];
      }
    }
  }
  db->total = db->total - 1;
}

//*********** ADDITIONAL FUNCTIONS ************************************************************************


void display_menu (struct DataBase *db)
{
  int input = 0;
  while (input != 8)
  {
    puts
      ("\n**************************************************************");
    printf
      (  "********** Employee Database - Total Employees: %03d **********\n", db->total);
      //you need to fix this line so that total employees in the database is printed
    puts
      ("**************************************************************\n");
    puts ("Choose one of the menu options below:");
    puts ("1. Sort by ID");
    puts ("2. Sort by Hire Date");
    puts ("3. Display all employees");
    puts ("4. Search employees by ID");
    puts ("5. Search employees by Last Name");
    puts ("6. Delete employee by ID");
    puts ("7. Save");
    puts ("8. Exit");

    scanf ("%d", &input);

    switch (input)
    {
      case 1:
        //call the function you defined for sorting by ID
        sort_by_ID(db);
        break;
      case 2:
        //call the function you defined for sorting by Hire Date
        sort_by_HireDate(db);
        break;
      case 3:
        //call the function you defined for displaying employees
        display_employee(db);
        break;
      case 4:
        //call the function you defined for searching employees by ID
        search_by_ID(db);
        break;
      case 5:
        //call the function you defined for searching employees by Last Name
        search_by_LastName(db);
        break;
      case 6:
        //call the function you defined for deleting employee by ID
        delete_by_ID(db);
        break;
      case 7:
        save (db);
        break;
      case 8:
        //free all allocated memory
        free(db->emp);
        free(db);
        printf("Bye!\n");
        break;

    }
  }

}
