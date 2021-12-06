/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. jferlazz@purdue.edu
*
*  Homework #: 6
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
*  This program takes user input on a list of 10 years and a desired day of the week to
*  start at. This program then finds which months of the first year start on the desired day
*  then the program checks the next year and new "desired day" is one more than the previous
*  (if over 6 it goes back to 0). This continues until all 10 years have been check
*
***************************************************************************/

#include <stdio.h>

#define MONTHS 12 //Months in a year
#define YEARS 10 //Number of inputted years

//Global Declarations
void printApplicableMonths(int[], int);
void monthCheck(int, int);
int monthStartDay(int, int, int, int);
int leapYearCheck(int);
int dayOfWeekLastYear(int);
void inputYears(int[]);
int inputDay(void);
void printDay(int);
void printMonth(int);
void output(int[], int);

int main(void) 
{
  //Local Declaration
  int years[YEARS]; //List of 10 user inputted years
  int desiredDay; //Desired day of the week number the user wishes to start on

  //Executable Statements

  //Takes input from the user
  inputYears(years);
  desiredDay = inputDay();

  //Outputs data
  output(years, desiredDay);

  return 0;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: printApplicableMonths
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int months[] \\list of month starting days for a given year
*    2. int desiredDay \\The desired day of the week being checked
*
*  Function Description: This function checks which months in a year begin with the
*  desired day
*
***************************************************************************/
void printApplicableMonths(int months[], int desiredDay)
{
  int count; //incrimentor for the for loop
  int prints; //tracks the number of prints

  prints = 0;

  for(count = 0; count < MONTHS; count++) //goes through each month
  {
    if(months[count] == desiredDay) //If the month starts on the desired day
    {
      printf(" ");
      printMonth(count + 1); //the loop goes from 0-11, but month go from 1-12
      prints++; //tracks the number of time a month is printed
    }
  }
  if (prints == 0) //if no months meet the test case
  {
    printf(" None");
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: monthCheck
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int year \\The year whose months are being checked
*    2. int desiredDay \\The desired day of the week being checked
*
*  Function Description: This function checks which months in a year begin with the
*  desired day
*
***************************************************************************/

void monthCheck(int year, int desiredDay)
{
  int months[MONTHS]; //list to track the starting day of each month
  int count; //incrimentor for the for loop
  int yearStartDay; //start day of the current year
  int isLeapYear; //whether the year is a leap year or not

  isLeapYear = leapYearCheck(year);
  yearStartDay = dayOfWeekLastYear(year) + 1;

  for (count = 0; count < MONTHS; count++) //loops through each month
  {
    //the loop goes from 0-11, but month go from 1-12 hence count + 1
    months[count] = monthStartDay(year, count + 1, yearStartDay, isLeapYear);
  }
  printApplicableMonths(months, desiredDay); //Sub function that prints applicable months
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: monthStartDay
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int year \\The year whose months are being checked
*    2. int month \\The month being checked (1 for January, 2 for February, etc)
*    3. int yearStartDay \\The day of the week which the year starts on
*    4. int isLeapYear \\Whether or not a year is a leapYear (0 if no, 1 if yes)
*
*  Function Description: This function checks which months in a year begin with the
*  desired day
*
***************************************************************************/

int monthStartDay(int year, int month, int yearStartDay, int isLeapYear)
{
  int totalDays; //days into the yeah the month being checked starts on
  int monthStartDay; //day of the week the month starts on

  totalDays = 0;
  //switch conditional to determine how many days into the year a given month starts on
  //Higher case numbers include the addition from other months before it
  switch (month)
  {
    case 12:
        totalDays += 30;
    case 11:
        totalDays += 31;
    case 10:
        totalDays += 30;
    case 9:
        totalDays += 31;
    case 8:
        totalDays += 31;
    case 7:
        totalDays += 30;
    case 6:
        totalDays += 31;
    case 5:
        totalDays += 30;
    case 4:
        totalDays += 31;
    case 3:
        totalDays += 28 + isLeapYear;
    case 2:
        totalDays += 31; //30 since it starts on the first day so 31 - 1 = 30
    case 1:
        break;
  }

  //Math to find the months start day
  monthStartDay = yearStartDay + (totalDays % 7);
  monthStartDay = monthStartDay % 7; //makes sure the number is from 0-6
  
  return(monthStartDay);
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
*    1. int year \\The year being checked
*
*  Function Description: This function checks if a year is a leap year or not
*  returns a 1 if yes and 0 if no
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
*  Name of Function: inputYear
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int years[] \\list of year values that will be filled with user input
*
*  Function Description: This function allows the user to input 10 years to a list called
*  years these values are passed back by address
*
***************************************************************************/

void inputYears(int years[])
{
  int count; //incrimentor for the for loop
  
  printf("Enter 10 years [1700 - 2100] -> ");
  
  for (count = 0; count < YEARS; count++)
  {
    scanf("%d", &years[count]);
  }
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

int inputDay(void)
{
  int day; //user each day of the week

  day = 0;
  do
  {
    if(day < 0 || day > 6)
    {
      printf("\nError! Day of the week must be 0 to 6.\n\n");
    }
    printf("Enter day of the week -> ");
    scanf("%d", &day);
  } while (day < 0 || day > 6);
  return(day);
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
*    1. int years[] \\List of 10 years to be evaluated
*    2. int day \\user entered desired day
*
*  Function Description: This function begins to produce output as outlined in the lab, it calls
*  subfunctions to produce output and excute computations as well
*
***************************************************************************/

void output(int years[], int day)
{
  int count; //incrimentor for the for loop
  
  printf("\nDesired day of the week: ");
  printDay(day);
  printf("\n");
  
  for(count = 0; count < YEARS; count++)
  {
    printf("Months in %d starting on ", years[count]);
    printDay(day);
    printf(":");

    monthCheck(years[count], day);
    printf("\n");
    
    day++; //for checking the next day for the next year
    day = day % 7; //makes sure the day is from 0-6
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: printDay
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    2. int day \\The weekday that should be printed
*
*  Function Description: This function prints the weekday that corrisponds to the
*  sent in number 0 for sunday, 1 for monday ... 6 for Saturday
*
***************************************************************************/

void printDay(int day)
{
  //switch conditional to print a given day
  switch (day)
  {
    case 0: 
      printf("Sunday");
      break;
    case 1: 
      printf("Monday");
      break;
    case 2: 
      printf("Tuesday");
      break;
    case 3: 
      printf("Wednesday");
      break;
    case 4: 
      printf("Thursday");
      break;
    case 5: 
      printf("Friday");
      break;
    case 6: 
      printf("Saturday");
      break;
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: printMonth
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    2. int month \\The month that should be printed
*
*  Function Description: This function prints a month based on the sent in month number
*  1 for January, 2 for February ... 12 for December
*
***************************************************************************/

void printMonth(int month)
{
  //switch conditional to print a given month
  switch (month)
  {
    case 1: 
      printf("January");
      break;
    case 2: 
      printf("February");
      break;
    case 3: 
      printf("March");
      break;
    case 4: 
      printf("April");
      break;
    case 5: 
      printf("May");
      break;
    case 6: 
      printf("June");
      break;
    case 7: 
      printf("July");
      break;
    case 8: 
      printf("August");
      break;
    case 9: 
      printf("September");
      break;
    case 10: 
      printf("October");
      break;
    case 11: 
      printf("November");
      break;
    case 12: 
      printf("December");
      break;
  }
}