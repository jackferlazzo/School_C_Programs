/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. jferlazz@purdue.edu
*
*  Homework #: 4
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Friday, 2:30pm, HAMP 3144
*
*  Program Description:
*
*  This program takes user input on a desired year, the day of the weel, and the occurrence
*  number that day occurs on, it then calculates what month and day of the month that day occurs on
*  and outputs it as outlined in the homework description
*
***************************************************************************/
#include <stdio.h>

//Global Decloration
int inputYear(void); //Year input function
int inputDay(void); //day of week input function
int inputOccurrence(void); //Occurrence number input function
int dayOfWeekLastYear(int); //Determines the last weekday of the previous year
int dayInYear(int, int, int); //Determines the amount of days into the year that entered day is on that number of occurrence
int monthCalc(int, int, int*); //Determines the month and the day of the month that the desired day is in
int leapYearCheck(int); //Checks to see if the year is a leap year or not
void output(int, int, int, int, int); //Outputs desired values as outlined in the homework

int main(void) 
{
  //Local Declaration
  int year; //user entered year
  int day; //user entered day of the week
  int occurrence; //occurrence number of that day that year
  int lastDay; //Day of the week that last year ended on
  int totalDays; //number of days into the year the desired day is
  int monthVal; //The month of the desired data 1 is January 2 is febuary etc
  int dayOfMonth; //The day in the month of the desired day
  int isLeapYear; //1 if it is a leap year, 0 if not

  //Executable Statements

  //Prompts user for input
  year = inputYear();
  day = inputDay();
  occurrence = inputOccurrence();
  
  //Calculates important day related values
  lastDay = dayOfWeekLastYear(year);
  totalDays = dayInYear(lastDay, day, occurrence);

  //Leap year check
  isLeapYear = leapYearCheck(year);

  //Calculates important month related values
  monthVal = monthCalc(isLeapYear, totalDays, &dayOfMonth);

  //Outputs desired values
  output(year, occurrence, day, dayOfMonth, monthVal);

  return 0;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputYear
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. NA
*
*  Function Description: This function allows the user to input the desired
*  year
*
***************************************************************************/
int inputYear()
{
  int year; //user input for the year
  
   //prints a statement to prompts for the year number
  printf("Enter Year Number -> ");
  scanf("%d", &year);
  
  return(year);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputDay
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. NA
*
*  Function Description: This function allows the user to input the desired
*  day of the week
*
***************************************************************************/
int inputDay()
{
  int day; //user input for the day of the week
  
   //prints a statement to prompts for the day of the week
  printf("Enter day of week number -> ");
  scanf("%d", &day);
  
  return(day);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputYear
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. NA
*
*  Function Description: This function allows the user to input the desired
*  occurrence number
*
***************************************************************************/
int inputOccurrence()
{
  int occurrence; //user input for the occurrence number
  
  //prints a statement to prompt for occurences
  printf("Enter occurrence number -> ");
  scanf("%d", &occurrence);
  
  return(occurrence);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: dayOfWeekLastYear
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int year the desired year entered by the user
*
*  Function Description: This function calculates the weekday the last year ended on
*
***************************************************************************/
int dayOfWeekLastYear(int year)
{
  return(((year - 1) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: dayInYear
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int lastDay the weekday the last year ended on
*    2. int day the weekday of the desired day
*    3. int occurrence the desired occurrence of the day
*
*  Function Description: This function calculates how many days the desire weekday
*  on the desired year and occurence is into the year (example if the day is 50 days into
*  the year 50 is returned)
*
***************************************************************************/
int dayInYear(int lastDay, int day, int occurrence)
{
  int totalDays; //number of days into the year
  
  if(lastDay < day)
  {
    totalDays = day - lastDay;
  }
  else if (lastDay == day)
  {
    totalDays = 7;
  }
  else
  {
    totalDays = 7 - (lastDay - day);
  }
  
  totalDays += (occurrence - 1) * 7;

  return(totalDays);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: leapYearCheck
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int year the desired year enter by the user
*
*  Function Description: This function checks to see if the entered year is a leap
*  year or not (returns 1 (true) if it is, 0 (false) if not) a leap year is a year divisable by 4
*  and if the year is divisable by 100 it must also be divisable by 400
*
***************************************************************************/
int leapYearCheck(int year)
{
  int isLeapYear; //1 is a leap year 0 if not
  
  if(year % 4 == 0)
  {
    if(year % 100 == 0)
    {
      if(year % 400 == 0)
      {
        isLeapYear = 1; //Century leap years that are divisable by 400 ie 2000 (is a leap year)
      }
      else
      {
        isLeapYear = 0; //Turn of the centurys not divisable by 400 ie 1900 (is NOT a leap year)
      }
    }
    else
    {
      isLeapYear = 1; //normal leap years not at the beginning of a century ie 2004
    }
  }
  else
  {
    isLeapYear = 0; //not a leap year
  }
  
  return(isLeapYear);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: monthCalc
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int isLeapYear whether or not the year entered by the user is a leap year or not
*    2. int totalDays how many days into the entered year the desired day is calculated by dayInYear
*    3. int *dayOfMonth the day of the month the desired day is on (1-31) passed by address
*
*  Function Description: This function calculates what month the desired day in is and returns it
*  it also calculates the day in that month the desired date occurs and passes that back by address
*
***************************************************************************/
int monthCalc(int isLeapYear, int totalDays, int *dayOfMonth)
{
  int monthVal; //The month of the desired data 1 is January 2 is febuary etc
  
  if (totalDays <= 31)
  {
    *dayOfMonth = totalDays;
    monthVal = 1;
  }
  else if (totalDays <= 59 + isLeapYear && !(isLeapYear))
  {
    *dayOfMonth = totalDays - 31;
    monthVal = 2;
  }
  else if (totalDays <= 59  + isLeapYear && isLeapYear)
  {
    *dayOfMonth = totalDays - 31;
    monthVal = 2;
  }
  else if (totalDays <= 90  + isLeapYear)
  {
    *dayOfMonth = totalDays - (59 + isLeapYear);
    monthVal = 3;
  }
  else if (totalDays <= 120  + isLeapYear)
  {
    *dayOfMonth = totalDays - (90 + isLeapYear);
    monthVal = 4;
  }
  else if (totalDays <= 151  + isLeapYear)
  {
    *dayOfMonth = totalDays - (120 + isLeapYear);
    monthVal = 5;
  }
  else if (totalDays <= 181  + isLeapYear)
  {
    *dayOfMonth = totalDays - (151 + isLeapYear);
    monthVal = 6;
  }
  else if (totalDays <= 212  + isLeapYear)
  {
    *dayOfMonth = totalDays - (181 + isLeapYear);
    monthVal = 7;
  }
  else if (totalDays <= 243  + isLeapYear)
  {
    *dayOfMonth = totalDays - (212 + isLeapYear);
    monthVal = 8;
  }
  else if (totalDays <= 273  + isLeapYear)
  {
    *dayOfMonth = totalDays - (243 + isLeapYear);
    monthVal = 9;
  }
  else if (totalDays <= 304  + isLeapYear)
  {
    *dayOfMonth = totalDays - (273 + isLeapYear);
    monthVal = 10;
  }
  else if (totalDays <= 334  + isLeapYear)
  {
    *dayOfMonth = totalDays - (304 + isLeapYear);
    monthVal = 11;
  }
  else
  {
    *dayOfMonth = totalDays - (334 + isLeapYear);
    monthVal = 12;
  }
  
  return(monthVal);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int year the desired year entered by the user
*    2. int occurrence the desired occurrence of the day
*    3. int day The day of the week the desired day is on
*    4. int dayOfMonth the day the desired month occurs in the month (like 3 for January 3rd)
*    5. int monthVal the month the desired day occurs in (ie 2 for Febuary)
*
*  Function Description: This function uses conditional statements to output calculated
*  values as outlined in the homework description
*
***************************************************************************/
void output(int year, int occurrence, int day, int dayOfMonth, int monthVal)
{
  printf("\nDesired Occurence #%d of ", occurrence);
  
  if(day == 0) //Sunday
  {
    printf("Sunday in %d: ", year);
  }
  else if(day == 1) //Monday
  {
    printf("Monday in %d: ", year);
  }
  else if(day == 2) //Tuesday
  {
    printf("Tuesday in %d: ", year);
  }
  else if(day == 3) //Wednesday
  {
    printf("Wednesday in %d: ", year);
  }
  else if(day == 4) //Thursday
  {
    printf("Thursday in %d: ", year);
  }
  else if(day == 5) //Friday
  {
    printf("Friday in %d: ", year);
  }
  else //Saturday
  {
    printf("Saturday in %d: ", year);
  }

  if(monthVal == 1) //January
  {
    printf("January %d\n", dayOfMonth);
  }
  else if(monthVal == 2) //Febuary
  {
    printf("Febuary %d\n", dayOfMonth);
  }
  else if(monthVal == 3) //March
  {
    printf("March %d\n", dayOfMonth);
  }
  else if(monthVal == 4) //April
  {
    printf("April %d\n", dayOfMonth);
  }
  else if(monthVal == 5) //May
  {
    printf("May %d\n", dayOfMonth);
  }
  else if(monthVal == 6) //June
  {
    printf("June %d\n", dayOfMonth);
  }
  else if(monthVal == 7) //July
  {
    printf("July %d\n", dayOfMonth);
  }
  else if(monthVal == 8) //August
  {
    printf("August %d\n", dayOfMonth);
  }
  else if(monthVal == 9) //September
  {
    printf("September %d\n", dayOfMonth);
  }
  else if(monthVal == 10) //October
  {
    printf("October %d\n", dayOfMonth);
  }
  else if(monthVal == 11) //November
  {
    printf("November %d\n", dayOfMonth);
  }
  else //December
  {
    printf("December %d\n", dayOfMonth);
  }
}
