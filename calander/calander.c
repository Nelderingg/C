#include <stdio.h>
#include <stdbool.h>
int days_in_month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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

void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add) {
    while (days_left_to_add > 0) {
        // Adjust for leap year in February
        if (*mm == 2 && is_leap_year(*yy)) {
            days_in_month[2] = 29;
        } else {
            days_in_month[2] = 28;
        }

        int days_left_in_month = days_in_month[*mm] - *dd;

        if (days_left_to_add >= days_left_in_month) {
            // Move to the next month
            days_left_to_add -= (days_left_in_month + 1);
            *dd = 1;
            *mm += 1;

            // If the month goes beyond December, move to the next year
            if (*mm > 12) {
                *mm = 1;
                *yy += 1;
            }
        } else {
            *dd += days_left_to_add;
            days_left_to_add = 0;
        }
    }
}

int main() {
  int mm;
  int dd;
  int yy;
  int days_to_add;
  printf("enter month day and year in form mm dd yy \n");
  scanf("%d" "%d" "%d", &mm, &dd, &yy);
  printf("enter number of days to add \n");
  scanf("%d", &days_to_add);

  add_days_to_date(&mm, &dd, &yy, days_to_add);

  printf("%d %d %d", mm, dd, yy); 
}
