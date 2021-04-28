#include <stdio.h>
#include <stdlib.h>

int firstweekday(int year)
{
    int day;
    day = (((year - 1)*365) + ((year-1)/4) - ((year-1)/100) + ((year)/400)+1) % 7;
    return day;
}

int main()
{
   system("Color 3F");

   int year,month,day,daysInMonth,weekDay=0,firstday;

   printf("\n\tEnter your desired year   \n\t\t : ");
   scanf("%d",&year);

   char *months[] = {"January~~",
                     "February~",
                     "March~~~~",
                     "April~~~~",
                     "May~~~~~~",
                     "June~~~~~",
                     "July~~~~~",
                     "August~~~",
                     "September",
                     "October~~",
                     "November~",
                     "December~"};

   int monthDay[] = {31,28,31,30,31,30,31,31,30,31,30,31};

   if((year%4 == 0 && year%100 != 0)|| year%400 == 0)
       monthDay[1]=29;

   firstday = firstweekday(year);

   for( month=0 ; month<12 ; month++ )
   {
      daysInMonth=monthDay[month];
      printf("\n\n~~~~~~~~~~~~~~~%s~~~~~~~~~~~~~~~~~~~\n",months[month]);
      printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

      for( weekDay=0 ; weekDay<firstday ; weekDay++)
        printf("     ");

      for(day=1 ; day<=daysInMonth ; day++)
      {
          printf("%5d",day);
          if(++weekDay>6)
          {
              printf("\n");
              weekDay=0;
          }
          firstday=weekDay;
      }
   }
   printf("\n\n\n\t\t\t@Sushant_Gaurav\n\n\n\n\n\n");
   return 0;
}
