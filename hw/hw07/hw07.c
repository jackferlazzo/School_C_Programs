/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. jferlazz@purdue.edu
*
*  Homework #: 7
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
*  This program takes input on whether the user would like to sort data based on
* how long in the number sequence 1 is reached (option 1) and the first power of 
* two value in that number sequence (option 2), and sorts a list of up to 35 based
* on that option. The program then output as outlined in the lav
*
***************************************************************************/

#include <stdio.h>

#define SIZE 35

int inputOption(void);
void inputNums(int[]);
void sortArray(int, int[]);
void sortSubArray(int[], int, int);
int nextNumber(int);
int powerValue(int);
int countValue(int);
int isPowerOfTwo(int);
void output(int[], int, int);

int main(void) 
{
  int option; //1 for sort by count 2 for sort by power of 2
  int nums[SIZE]; //array of inputted values

  //Takes user input
  option = inputOption();
  inputNums(nums);
  
  sortArray(option, nums);
  
  return 0;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputOption
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. NA
*
*  Function Description: This function takes user input on the type of sort the user
*  would like to do. 1 for sorting by count, 2 for sorting by power of 2
*
***************************************************************************/
int inputOption(void)
{
  int input; //user inputted option
  do 
  {
    printf("Enter sorting option (1) count or (2) power of two -> ");
    scanf("%d", &input);
    if(input != 1 && input != 2)
    {
      printf("\nError! Enter option 1 or 2 only!\n\n");
    }
  } while (input != 1 && input != 2);
  
  return(input);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputNums
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int[] nums //list of user inputted data
*
*  Function Description: This function takes user input on numbers to be sorted up to 35
*  integer values
*
***************************************************************************/
void inputNums(int nums[])
{
  int count; //incrimentor for the for loop
  int store; //int the current number being scanned
  
  store = 0;

  printf("Enter up to 35 integer values -> ");
  
  for (count = 0; count < 35 && store >= 0; count++)
  {
    scanf("%d", &nums[count]);
    store = nums[count];
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: sortArray
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*     1. int option //type of sorting 1 for count, 2 for power of 2
*     2. int[] nums //list of user entered numbers
*    
*
*  Function Description: This function complies the list of numbers into a new array
*  and calls the sortsubarray function to sort the array
*
***************************************************************************/
void sortArray(int option, int nums[])
{
  int sortedList[SIZE]; //array of sorted numbers
  int count; //incrimentor
  int size; //size of the array

  size = 0;

  for (count = 0; count < 35 && nums[count] != -1; count++)
  {
    sortedList[count] = nums[count];
    size++;
  }
  sortSubArray(sortedList, size, option);

  output(sortedList, size, option);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: sortSubArray
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*     1. int[] input //array of integer values
*     2. int size //size of the array
*     3. int option //type of sorting 1 for count, 2 for power of 2
*    
*
*  Function Description: This function conducts selection sort on the sent in
*  array using values from  either the powerValue function and the countValue function
*
***************************************************************************/
void sortSubArray(int input[], int size, int option)
{
  int small; //current smallest number
  int temp; //store temperary data so it doesn't get erased
  int current; //current index being looked at
  int step; //incrimention for the inner loop

  for (current = 0; current < size - 1; current++)
  {
    small = current;
    if(option == 1)
    {
      for (step = current + 1; step < size; step++)
      {
        if(countValue(input[step]) < countValue(input[small]))
        {
          small = step;
        }
        else if(countValue(input[step]) == countValue(input[small]) && input[step] < input[small])
        {
          small = step;
        }
      }
      temp = input[current];
      input[current] = input[small];
      input[small] = temp;
    }
    else
    {
      for (step = current + 1; step < size; step++)
      {
        if(powerValue(input[step]) < powerValue(input[small]))
        {
          small = step;
        }
        else if(powerValue(input[step]) == powerValue(input[small]) && input[step] < input[small])
        {
          small = step;
        }
      }
      temp = input[current];
      input[current] = input[small];
      input[small] = temp;
    }
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: powerValue
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*     1. int value //the number you wish to find the power of 2 value of
*    
*
*  Function Description: This function finds out what the power of 2 value of a 
*  number is
***************************************************************************/
int powerValue(int value)
{
  while (isPowerOfTwo(value) != 1)
  {
    value = nextNumber(value);
  }
  return(value);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: countValue
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*     1. int value //the number you wish to find the count value of
*    
*
*  Function Description: This function finds out what the count value of a 
*  number is
***************************************************************************/
int countValue(int value)
{
  int number; //the number of times until 1 is reached
  number = 0;

  while(value != 1)
  {
    value = nextNumber(value);
    number++;
  }

  return(number);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: nextNumber
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*     1. int value //the number you wish to the new number in the sequence of
*    
*
*  Function Description: This function finds out what the next number in the sequence
*  is if the number is even divide it by 2 and if odd multiply by 3 and add 1
***************************************************************************/
int nextNumber(int value)
{
  int output; //the next number in the sequence
  if(value % 2 == 0)
  {
    output = value / 2;
  }
  else
  {
    output = value * 3 + 1;
  }
  return(output);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: isPowerOfTwo
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*     1. int value //the number you wish to find if it is a power of 2 or not
*    
*
*  Function Description: This function finds out if a value is a power of 2 or not (1 if it is 0 if not)
***************************************************************************/
int isPowerOfTwo(int value)
{
  int output; //if the number is a power of 2 (1) or not (1)
  output = 1;
  while(value > 1)
  {
    if (value % 2 != 0)
    {
      output = 0;
    }
    value /= 2;
  }
  return(output);
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
*     1. int[] nums //array of sorted numbers
*     2. int size //size of the array
*     3. int option //type of sorting 1 for count, 2 for power of 2
*    
*
*  Function Description: This function outputs the data as outlined in the lab
***************************************************************************/
void output(int nums[], int size, int option)
{
  int count; //incrimentor for the for the loop

  printf("\nSort data by ");

  if(option == 1)
  {
    printf("count:");
  }
  else
  {
    printf("power of two:");
  }

  for(count = 0; count < size; count++)
  {
    printf(" %d", nums[count]);
  }
  printf("\n");
}