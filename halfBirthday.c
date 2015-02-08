#include <stdio.h>

int day_of_year( int year, int month, int day);
void month_day( int year, int yearday, int *pmonth, int *pday);
//This program calculates the exact day when you turn half a year old

static char daytab[2][13] = {
      {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
      {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
   };

int main()
{
   int birthmonth = 0;
   int birth_day = 0;
   int year = 2015;

   printf("\nWould you like to know when you turn half a year older? \n");
   printf("Well, then...\n");
   printf("Enter your birth month here: ");
   scanf("%d", &birthmonth);
   printf("And your birth day over here: ");
   scanf("%d", &birth_day);

   int halfb = 0;
   int doy = day_of_year( year, birthmonth, birth_day );
   month_day( year, (183+doy), &birthmonth, &halfb);

   printf ("The day of your birhtday is the day number %d\n", doy);
   printf ("Your half birthday would be in exactly half a year from your day\nTherefore, your halfbirth is 183 days after or say month: %d day: %d\n\n", birthmonth, halfb);
}

void month_day( int year, int yearday, int *pmonth, int *pday)
{
   int i,leap;
   leap = (year%4 == 0 && year%100 != 0) || year%400 ==0;
   for ( i = 1; yearday > daytab[leap][i]; i++)
      yearday -= daytab[leap][i];
   *pmonth = i;
   *pday = yearday;
}

int day_of_year( int year, int month, int day)
{
   int i, leap;
   leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
   for (i = 1; i < month; i++)
      day += daytab[leap][i];
   return day;
}
