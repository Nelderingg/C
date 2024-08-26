#include <stdio.h>
#include <stdbool.h>
int days_in_month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add){
  int days_left_in_month;
  while(days_left_to_add > 0){
    days_left_in_month = days_in_month[*mm] - *dd;
    
  }
}

bool is_leap_year(int year){
  if(year % 4 != 0){
    return false;
  }
  else if(year % 4 == 0){
    if(year % 100 == 0){
      if(year % 400 == 0){
        return true;
      }
      else{
        return false;
      }
    }
    else{
      return true;
    }
  }
}

int main() {
  int year;
  printf("enter year between 1800 and 10000 \n");
  scanf("%d", &year);
  if(is_leap_year(year)){
    printf("%d is a leap year \n", year);
  }
  else{
    printf("%d is not a leap year \n", year);
  }
}
