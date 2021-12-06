/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. jferlazz@purdue.edu
*
*  Homework #: 5
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
*  This program takes user input on the desired each and the week occurence they
*  want to analyize and outputs the start of the week and end of the week
*  in date format and outputs a calendar with the desired week
*
***************************************************************************/

#include <stdio.h>

//Global Decloration
int inputYear(void);
int inputOccurrence(void);
int dayOfWeekLastYear(int);
int dayInYear(int);
int monthCalc(int, int, int*);
int leapYearCheck(int);
void output(int, int, int, int, int, int, int, int);
void dateOutput(int, int, int, int);
int findsYear2(int, int);
int findStartDay(int);
int findDayInMonth(int, int);
int incrimentDay(int, int);

int main(void) 
{
  //Local Declaration
  int year1; //user entered year
  int year2; //year at the end of the week
  int occurrence; //occurrence number of that day that year
  int lastDay; //Day of the week that last year ended on
  int totalDays; //number of days into the year the desired day is
  int monthVal1; //The month of the start of the week 1 is January 2 is febuary etc
  int monthVal2; //The month of the end of the week
  int dayOfMonth1; //The day in the month of the start of the week
  int dayOfMonth2; //The day in the month of the end of the week
  int isLeapYear; //1 if it is a leap year, 0 if not
  int startDay; //The day of the week the week starts at

  //Executable statements

  //Prompts user for input
  year1 = inputYear();
  occurrence = inputOccurrence();
  
  //Calculates important day related values
  lastDay = dayOfWeekLastYear(year1);
  startDay = findStartDay(lastDay);
  totalDays = dayInYear(occurrence);

  //Leap year check
  isLeapYear = leapYearCheck(year1);

  //Finds if the day at the end of the week is in another year or not
  year2 = year1 + findsYear2(isLeapYear, totalDays);

  //Calculates important month related values
  monthVal2 = monthCalc(isLeapYear, totalDays, &dayOfMonth2);
  monthVal1 = monthCalc(isLeapYear, totalDays - 6, &dayOfMonth1);

  //Outputs data
  output(startDay, monthVal1, monthVal2, dayOfMonth1, dayOfMonth2, isLeapYear, year1, year2);
  
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
*  Name of Function: incrementdatMo
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int dayOfMonth //Day to incriment
*    2. int daysInMonth //The number of days in the month
*
*  Function Description: This function incriments the date and resets it to 1
*  if it occurs in a new month
*
***************************************************************************/
int incrementDate(int dayOfMonth, int daysInMonth)
{
  int newDay; //New day after incriment
  newDay = dayOfMonth + 1;
  
  if (newDay > daysInMonth) //If the new day is in another month
  {
    newDay = 1;
  }

  return(newDay);
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
int dayInYear(int occurrence)
{
  int totalDays; //number of days into the year
  
  totalDays = (occurrence) * 7; //Each week is 7 days

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
*  Name of Function: findsYear2
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int isLeapYear whether or not the year entered by the user is a leap year or not
*    2. int totalDays how many days into the entered year the desired day is calculated by dayInYear
*
*  Function Description: This function calculates if the end of the week occurs in another year return
*  1 (true) if it does and 0 (false) if it does not
*
***************************************************************************/
int findsYear2(int isLeapYear, int totalDays)
{
  return(totalDays > 365 + isLeapYear);
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
*  this takes into account if the day occurs on another year
*
***************************************************************************/
int monthCalc(int isLeapYear, int totalDays, int *dayOfMonth)
{
  int monthVal; //The month of the desired data 1 is January 2 is febuary etc
  
  if (totalDays <= 31) //January
  {
    *dayOfMonth = totalDays;
    monthVal = 1;
  }
  else if (totalDays <= 59 + isLeapYear && !(isLeapYear)) //Febuary not on leap year
  {
    *dayOfMonth = totalDays - 31;
    monthVal = 2;
  }
  else if (totalDays <= 59  + isLeapYear && isLeapYear) //Febuary on leap year
  {
    *dayOfMonth = totalDays - 31;
    monthVal = 2;
  }
  else if (totalDays <= 90  + isLeapYear) //March
  {
    *dayOfMonth = totalDays - (59 + isLeapYear);
    monthVal = 3;
  }
  else if (totalDays <= 120  + isLeapYear) //April
  {
    *dayOfMonth = totalDays - (90 + isLeapYear);
    monthVal = 4;
  }
  else if (totalDays <= 151  + isLeapYear) //May
  {
    *dayOfMonth = totalDays - (120 + isLeapYear);
    monthVal = 5;
  }
  else if (totalDays <= 181  + isLeapYear) //June
  {
    *dayOfMonth = totalDays - (151 + isLeapYear);
    monthVal = 6;
  }
  else if (totalDays <= 212  + isLeapYear) //July
  {
    *dayOfMonth = totalDays - (181 + isLeapYear);
    monthVal = 7;
  }
  else if (totalDays <= 243  + isLeapYear) //August
  {
    *dayOfMonth = totalDays - (212 + isLeapYear);
    monthVal = 8;
  }
  else if (totalDays <= 273  + isLeapYear) //September
  {
    *dayOfMonth = totalDays - (243 + isLeapYear);
    monthVal = 9;
  }
  else if (totalDays <= 304  + isLeapYear) //October
  {
    *dayOfMonth = totalDays - (273 + isLeapYear);
    monthVal = 10;
  }
  else if (totalDays <= 334  + isLeapYear) //November
  {
    *dayOfMonth = totalDays - (304 + isLeapYear);
    monthVal = 11;
  }
  else if (totalDays <= 365  + isLeapYear) //December
  {
    *dayOfMonth = totalDays - (334 + isLeapYear);
    monthVal = 12;
  }
  else //The date occurs in another year
  {
    *dayOfMonth = totalDays - (365 + isLeapYear);
    monthVal = 1; //January of next year
  }
  
  return(monthVal);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: findStartDay
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int lastDay //The day of the week that last year ended on
* 
*  Function Description: This function calculates what day of the week the start of 
*  the desired week occurs on
*
***************************************************************************/
int findStartDay(int lastDay)
{
  return((lastDay + 1) % 7); //Dates must only occur from 0 (Sunday) to 6 (Saturday)
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: findDayInMonth
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int month //The month the date occurs on
*    2. int isLeapYear //Whether or not the year is a leap year
* 
*  Function Description: This function calculates how many days are in the month
*  within which the first day of the week occurs, used if the week carrys over
*  into another month
*
***************************************************************************/
int findDayInMonth(int month, int isLeapYear)
{
  int days; //The number of days in the desired month

  if(isLeapYear && month == 2) //Febuary During a leapYear
  {
    month = 13;
  }

  switch(month)
  {
    case 1: //January
    case 3: //March
    case 5: //May
    case 7: //July
    case 8: //August
    case 10: //October
    case 12: //December
      days = 31;
      break;

    case 2: //Febuary during a non leap year
      days = 28;
      break;

    case 4: //April
    case 6: //June
    case 9: //September
    case 11: //November
      days = 30;
      break;

    case 13: //Febuary During a leapYear
      days = 29;
      break;
  }
  return(days);
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
*    1. int startDay //The day of the week within the week starts
*    2. int monthVal1 //The month which the beginning of the week starts
*    3. int monthVal2 //The month which the beginning of the week ends
*    4. int dayOfMonth1 //the day the start of the week occurs in its month (like 3 for January 3rd)
*    5. int dayOfMonth2 //the day the end of the week occurs in its month (like 9 for January 9th)
*    6. int isLeapYear //whether or not the year 1 is a leap year
*    7. int year1 //The year which the start of the week is in
*    8. int year2 //The year which the end of the week is in
*
*  Function Description: This function uses conditional statements and loops to output calculated
*  values as outlined in the homework description
*
***************************************************************************/
void output(int startDay, int monthVal1, int monthVal2, int dayOfMonth1, int dayOfMonth2, int isLeapYear, int year1, int year2)
{
  int count; //Used for the pretest loop to track iterations
  int currentDay; //Used to track the current day of the week in the calendar to print
  int statementsPrinted; //Keeps track of how many dates have been printed on the calendar
  int daysInMonth; //Number of days in month 1

  //Prints week start and end dates
  printf("\nStart of week: ");
  dateOutput(startDay, monthVal1, dayOfMonth1, year1); //Start of the week

  printf("End of week: ");
  dateOutput(startDay + 6, monthVal2, dayOfMonth2, year2); //End of the week
  
  printf("\n\n");

  //Outputs Calendar Heading
  switch(monthVal1)
  {
    case 1:
      printf("%16s\n","January");
      break;
    case 2:
      printf("%16s\n","Febuary");
      break;
    case 3:
      printf("%16s\n","March");
      break;
    case 4:
      printf("%16s\n","April");
      break;
    case 5:
      printf("%16s\n","May");
      break;
    case 6:
      printf("%16s\n","June");
      break;
    case 7:
      printf("%16s\n","July");
      break;
    case 8:
      printf("%16s\n","August");
      break;
    case 9:
      printf("%16s\n","September");
      break;
    case 10:
      printf("%16s\n","October");
      break;
    case 11:
      printf("%16s\n","November");
      break;
    case 12:
      printf("%16s\n","December");
      break;
  }
  
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-\nSun Mon Tue Wed Thu Fri Sat\n");

  currentDay = startDay; 
  daysInMonth = findDayInMonth(monthVal1, isLeapYear);
  
  count = 0;
  statementsPrinted = 0;

  //First row of the calendar
  while(count < 7)
  {
    if(currentDay == count)
    {
      //Single digit dates are center aligned
      if(dayOfMonth1 < 10)
      {
        printf(" %d ", dayOfMonth1);
      }
      //Double digit dates are right aligned
      else
      {
        printf(" %d", dayOfMonth1);
      }
      dayOfMonth1 = incrementDate(dayOfMonth1, daysInMonth);
      
      //Keeps track that a date was printed
      statementsPrinted++;

      //If a date is printed incriment the next day of the week to print it
      currentDay++; 
    }
    else //Digit is not to be printed (empty calendar spot)
    {
      printf("   ");
    }
    if(count != 6) //No extra space needed at the end
    {
      printf(" ");
    }
    
    count++;
  }

  if(statementsPrinted != 7) //If second calendar row is not require
  {
    printf("\n");
  }
  //Only 7 date should be printed so this second loop prints the remaining 
  //required dates in the 2nd row of the calendar unless a 2nd row is not
  //required

  while(statementsPrinted < 7) 
  {
    //Single digit dates are center aligned
    if(dayOfMonth1 < 10)
    {
      printf(" %d  ", dayOfMonth1);
    }
    //Double digit dates are right aligned
    else
    {
      printf(" %d ", dayOfMonth1);
    }
    
    dayOfMonth1 = incrementDate(dayOfMonth1, daysInMonth);
    statementsPrinted++;
  }

  printf("\n");
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: dateOutput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int day //The day of the week which the date is on
*    2. int month //The month which the date is in
*    3. int dayOfMonth ///the day which the date occurs in its month (like 3 for January 3rd)
*    4. int year //the year the date is in
*
*  Function Description: This function uses 2 switch statements to output a date to
*  assist the output function
*
***************************************************************************/
void dateOutput(int day, int month, int dayOfMonth, int year)
{
  switch(day) //Day of the week
  {
    case 0:
      printf("Sunday ");
      break;
    case 1:
      printf("Monday ");
      break;
    case 2:
      printf("Tuesday ");
      break;
    case 3:
      printf("Wednesday ");
      break;
    case 4:
      printf("Thursday ");
      break;
    case 5:
      printf("Friday ");
      break;
    case 6:
      printf("Saturday ");
      break;
  }
  
  switch(month) //Month
  {
    case 1:
      printf("January ");
      break;
    case 2:
      printf("Febuary ");
      break;
    case 3:
      printf("March ");
      break;
    case 4:
      printf("April ");
      break;
    case 5:
      printf("May ");
      break;
    case 6:
      printf("June ");
      break;
    case 7:
      printf("July ");
      break;
    case 8:
      printf("August ");
      break;
    case 9:
      printf("September ");
      break;
    case 10:
      printf("October ");
      break;
    case 11:
      printf("November ");
      break;
    case 12:
      printf("December ");
      break;
  }
  
  //Finishes off the date formatting
  printf("%d, %d\n", dayOfMonth, year);
}