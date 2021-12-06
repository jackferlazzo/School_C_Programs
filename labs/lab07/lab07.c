/***************************************************************************
*
* Programmers and Purdue Email Addresses:
* 1. tlirette@purdue.edu
* 2. jferlazz@purdue.edu
* 3. albarkat@purdue.edu
*
* Lab #: 7
*
* Academic Integrity Statement:
*
* We have not used source code obtained from any other unauthorized source,
* either modified or unmodified. Neither have we provided access to our code
* to another. The effort we are submitting is our own original work.
*
* Day, Time, Location of Lab: Friday, 2:30 PM, HAMP 3144
*
* Program Description: This program allows the user to input a desired base10 integer
* the program check to make sure the input in non-negative and if it is not it throws an
* error message and reprompts the user. This base10 number is then converted to a base8 number
* and tracks the changes in even and odd digits, the program then outputs these desired values
* to the user as desired by the lab
*
***************************************************************************/

#include <stdio.h>
#include <math.h>

int input(void);
int evenChange(int,int);
int oddChange(int,int);
int getOctal(int);
int OctalAdd(int, int);
void output(int,int,int);

int main(void) 
{
  //LOCAL DECLARATIONS
  int base10; //The base 10 value entered by the user
  int base8; //the base 8 version of the base 10 number
  int evenChangeVal; //difference in even digits between base 10 and 8
  int oddChangeVal; //difference in odd digits between base 10 and 8

  //EXECUTABLE STATEMENTS
  base10 = input(); //gets input
  
  //converts to base 8 from base 10
  base8 = getOctal(base10); 
 
  //find even and odd digit changes
  evenChangeVal = evenChange(base10, base8); 
  oddChangeVal = oddChange(base10, base8);

  //output data
  output(base8, oddChangeVal, evenChangeVal);
  return 0;
}

/***************************************************************************
*
* Function Information
*
* Name of Function:
*
* Function Return Type:
*
* Parameters (list data type, name, and comment one per line):
* 1. NA
*
* Function Description: This function takes user input on a non-negative base10
* integer value. If the value is not non-negative an error message is thrown and
* the user is reprompted
*
***************************************************************************/

int input()
{
  int base10Input; //Base 10 number enter by the user
  do
  {
    if(base10Input < 0)
    {
      printf("\nError! The decimal value provided should be non-negative.\n\n");
    }
    printf("Enter decimal value -> ");
    scanf("%d", &base10Input);
  } while (base10Input < 0);
  return(base10Input);
}

/***************************************************************************
*
* Function Information
*
* Name of Function: evenChange
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. int base10 //number given in base10
* 2. int base8 //number given in base8
*
* Function Description: Finds the difference in even digits 
* between a base 10 number and a base 8 number
*
***************************************************************************/

int evenChange(int base10, int base8)
{
  int hold10; //iterator for base10 even digit finder
  int hold8; //iterator for base8 even digit finder
  int numEven10; //number of even digits in base 10 number
  int numEven8; //number of odd digits in base 8 number
  int valRemainder; //remainder used for both values

  //set intial conditions
  hold10 = base10;
  hold8 = base8;
  numEven10 = 0;
  numEven8 = 0;
  
  while(hold10 > 0) //while there are digits left
  {
    valRemainder = hold10 % 10; //find the first digit in hold
    if(valRemainder % 2 == 0) //if even increase even by 1
    {
      numEven10 = numEven10 + 1;
    }
    hold10 = hold10 / 10; //remove right most digit
  }

  while(hold8 > 0) //while there are digits left
  {
    valRemainder = hold8 % 8; //find the first digit in hold
    if(valRemainder % 2 == 0) //if even increase even by 1
    {
      numEven8 = numEven8 + 1;
    }
    hold8 = hold8 / 10; //remove right most digit
  }
  
  return(numEven10 - numEven8); //return difference
}

/***************************************************************************
*
* Function Information
*
* Name of Function: oddChange
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. int base10 //number given in base10
* 2. int base8 //number given in base8
*
* Function Description: Finds the difference in odd digits 
* between a base 10 number and a base 8 number
*
***************************************************************************/

int oddChange(int base10, int base8)
{
  int hold10; //value to hold base 10 iterator
  int hold8; //value to hold base 8 iterator
  int numOdd10; //number of odd digits in base10
  int numOdd8; //number odd digits in base8
  int valRemainder; //remainder for both valuyes

  //set intial conditions
  hold10 = base10; 
  hold8 = base8;
  numOdd10 = 0;
  numOdd8 = 0; 
  
  while(hold10 > 0) //while there are digits left
  {
    valRemainder = hold10 % 10; //find the first digit in hold
    if(valRemainder % 2 == 1) //if odd increase even by 1
    {
      numOdd10 = numOdd10 + 1;
    }
    hold10 = hold10 / 10; //remove right most digit
  }

  while(hold8 > 0) //while there are digits left
  {
    valRemainder = hold8 % 8; //find the first digit in hold
    if(valRemainder % 2 == 1) //if odd increase even by 1
    {
      numOdd8 = numOdd8 + 1;
    }
    hold8 = hold8 / 10; //remove right most digit
  }
  
  return(numOdd10 - numOdd8); //return difference
}

/***************************************************************************
*
* Function Information
*
* Name of Function: getOctal
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. int base10 //the initial decimal number
*
* Function Description: Returns the octal value given a decimal number
*
***************************************************************************/
int getOctal(int base10)
{
  int digit; //the decimal place of each digit in the number
  int remainder; //the remainder of the decimal number divided by 8 (1 for ones place, 2 for tens place, etc.)
  int oct; //the current octal value
  
  //set intial conditions
  oct = 0;
  digit = 0;
  
  while(base10 != 0)
  {
    remainder = base10 % 8;
    base10 /= 8;
    digit++;
    oct += OctalAdd(remainder, digit);
  }
  return(oct);
}

/***************************************************************************
*
* Function Information
*
* Name of Function: OctalAdd
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. int remainder //the remainder of the decimal number divided by 8
* 2. int digit //the decimal place of each digit in the number (1 for ones place, 2 for tens place, etc.)
*
* Function Description: Returns the octal digit that will be added to the current octal value of the getOctal function
*
***************************************************************************/
int OctalAdd(int remainder, int digit)
{
  int newOct; //the digit being added on to the current octal value
  newOct = remainder * pow(10, digit - 1);
  return(newOct);
}

/***************************************************************************
*
* Function Information
*
* Name of Function: output
*
* Function Return Type: void
*
* Parameters (list data type, name, and comment one per line):
* 1. int base8 //the number given converted to base8
* 2. int oddChange //the difference between odd digits for both numbers
* 3. int evenChange // the difference between even digits for both numbers
*
* Function Description: Outputs data in a formated function for program
*
***************************************************************************/
void output(int base8, int oddChange, int evenChange)
{
  printf("\nOctal equivalent: %d\n", base8);

  if(oddChange > 0)
  {
    printf("Odd digit change: +%d",oddChange);
  }
  else
  {
    printf("Odd digit change: %d", oddChange);
  }
  
  if(evenChange > 0)
  {
    printf("\nEven digit change: +%d\n",evenChange);
  }
  else
  {
    printf("\nEven digit change: %d\n", evenChange);
  }
  
}
