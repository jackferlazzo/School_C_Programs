/***************************************************************************
*
* Programmers and Purdue Email Addresses:
* 1. tlirette@purdue.edu
* 2. jferlazz@purdue.edu
* 3. albarkat@purdue.edu
*
* Lab #: 8
*
* Academic Integrity Statement:
*
* We have not used source code obtained from any other unauthorized source,
* either modified or unmodified. Neither have we provided access to our code
* to another. The effort we are submitting is our own original work.
*
* Day, Time, Location of Lab: Friday, 2:30 PM, HAMP 3144
*
* Program Description: Given a user entered range of decimal values, find the
* smallest number number that has the largest change in odd and even digits when 
* comparing the decimal value to its octal
*
***************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int input1(void);
int input2(int);
int getOctal(int);
int evenChange(int,int);
int oddChange(int,int);
int OctalAdd(int, int);
int getLargestOddDecimal(int,int);
int getLargestEvenDecimal(int,int);
void printResults(int,int,int,int,int,int);

int main(void)
{
  //LOCAL DECLARATIONS
  int startVal; //the first decimal value of the range
  int endVal; //the last decimal value of the range
  int largeOddDecimal; //decimal with the largest odd digit change from decimal to octal
  int largeEvenDecimal; //decimal with the largest even digit change form decimal to octal 
  int largeOddOctal; //the octal value of largeOddDecimal
  int largeEvenOctal; //the octal value of largeEvenDecimal
  int largeOddChange; //the difference of the number of odd digits between a decimal and octal number
  int largeEvenChange; //the difference of number of even digits between a decimal and octal number

  //EXECUTABLE STATEMENTS

  //Gets user inputs for range of values
  startVal = input1(); 
  endVal = input2(startVal);

  //Find the smallest decimal value with the largest digit change (even and odd) 
  largeOddDecimal = getLargestOddDecimal(startVal,endVal);
  largeEvenDecimal = getLargestEvenDecimal(startVal,endVal);

  //Finds the Octal equivalent of the found decimal values
  largeOddOctal = getOctal(largeOddDecimal);
  largeEvenOctal = getOctal(largeEvenDecimal);

  //Finds the change in number odd and even digit from the found Octal and Decimal Number
  largeOddChange = oddChange(largeOddDecimal,largeOddOctal);
  largeEvenChange = evenChange(largeEvenDecimal,largeEvenOctal);
  
  //Outputs data
  printResults(largeOddChange, largeOddDecimal, largeOddOctal, largeEvenChange , largeEvenDecimal, largeEvenOctal);

  return(0);
}

/***************************************************************************
*
* Function Information
*
* Name of Function: input1
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. NA
*
* Function Description: This function takes user input on a non-negative base10
* integer value. If the value is not non-negative an error message is thrown and
* the user is reprompted
*
***************************************************************************/

int input1()
{
  int base10Input; //Base 10 number enter by the user
  do
  {
    if(base10Input < 0)
    {
      printf("\nError! The decimal value provided should be non-negative.\n\n");
    }
    printf("Enter starting decimal value -> ");
    scanf("%d", &base10Input);
  } while (base10Input < 0);
  return(base10Input);
}

/***************************************************************************
*
* Function Information
*
* Name of Function: input2
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. int startVal //value to start search
*
* Function Description: This function takes user input on a non-negative base10
* integer value. If the value is not greater than the first user entered value an error 
* message is thrown and the user is reprompted
*
***************************************************************************/

int input2(int startVal)
{
  int base10Input; //Base 10 number enter by the user
  base10Input = startVal + 1; //Set an inital value to avoid the error message initally
  do
  {
    if(base10Input <= startVal)
    {
      printf("\nError! The ending value provided should be greater than %d.\n\n",startVal);
    }
    printf("Enter ending decimal value -> ");
    scanf("%d", &base10Input);
  } while (base10Input <= startVal);
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
  oct = 0; //octal number
  digit = 0; //digit of the octal number
  
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
* Function Description: Returns the octal digit that will be added to the current octal 
* value of the getOctal function
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
* Name of Function: getLargestOddDecimal
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. int num1 // The smallest number to check the odd decimal change of
* 2. int num2 // The largest number to check the odd decimal change of
*
* Function Description: Returns the decimal value of the number with the greater odd 
* digit change between decimal and octal
*
***************************************************************************/

int getLargestOddDecimal(int num1,int num2)
{
  int storeChange = 0; //stores the largest change in decimal odds
  int storeNum = num1; //stores the number with largest change in decimal odds
  int i; //iterator for for loop

  for(i = num1;i <= num2;i++) //for numbers between num1 and num2 inclusive
  {
    if(abs(oddChange(i,getOctal(i))) > storeChange) //if this numbers change is greater
    {
      storeChange = abs(oddChange(i,getOctal(i))); //change values to number
      storeNum = i;
    }
  }
  
  return(storeNum); //return value
}

/***************************************************************************
*
* Function Information
*
* Name of Function: getLargestEvenDecimal
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. int num1 // The smallest number to check the even decimal change of
* 2. int num2 // The largest number to check the even decimal change of
*
* Function Description: Returns the decimal value of the number with the greater even
* digit change between decimal and octal
*
***************************************************************************/

int getLargestEvenDecimal(int num1,int num2)
{
  int storeChange = 0; //stores the largest change in decimal evens
  int storeNum = num1; //stores the number with largest change in decimal evens
  int i; //iterator for for loop

  for(i = num1;i <= num2;i++) //for numbers between num1 and num2 inclusive
  {
    if(abs(evenChange(i,getOctal(i))) > storeChange) //if this numbers change is greater
    {
      storeChange = abs(evenChange(i,getOctal(i))); //change values to number
      storeNum = i; 
    }
  }
  
  return(storeNum); //return value
}

/***************************************************************************
*
* Function Information
*
* Name of Function: printResults
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. int oddChange //value of largest change in odd decimals
* 2. int decimal1 //decimal value of number with greatest odd change
* 3. int octal1 //octal value of number with greatest odd change
* 4. int evenChange //value of largest change in even decimals
* 5. int decimal2 //decimal value of number with greatest even change
* 6. int octal2 //octal value of number with greatest even change
*
* Function Description: Prints the decimal numbers with the largest odd and even digit 
* changes, their corresponding octal equivalent numbers, and the change in odd/even 
* digits between the decimal and octal numbers.
*
***************************************************************************/

void printResults(int oddChange, int decimal1, int octal1, int evenChange, int decimal2, int octal2)
{
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-Change-Decimal-=-Octal-");
  printf("\nLargest odd digit change: %7d %7d %7d", oddChange, decimal1, octal1);
  printf("\nLargest even digit change: %6d %7d %7d\n", evenChange, decimal2, octal2);
}
