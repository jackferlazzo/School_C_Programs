/***************************************************************************
*
* Programmers and Purdue Email Addresses:
* 1. tlirette@purdue.edu
* 2. jferlazz@purdue.edu
* 3. albarkat@purdue.edu
*
* Lab #: 9
*
* Academic Integrity Statement:
*
* We have not used source code obtained from any other unauthorized source,
* either modified or unmodified. Neither have we provided access to our code
* to another. The effort we are submitting is our own original work.
*
* Day, Time, Location of Lab: Friday, 2:30 PM, HAMP 3144
*
* Program Description: Program that given twenty non-negative decimal integer values 
* as input converts all odd numbers into binary and even numbers into octal.
*
***************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 20 //size of the input array

void input(int[]);
int getOctal(int); 
int getBinary(int);
int ConvertAdd(int,int);
int countOdds(int[]);
int countEvens(int[]);
void binaryArray(int[]);
void convertArray(int[], int, int);
void printArrays(int[], int[], int, int);

int main(void) 
{
  int decimal[SIZE]; //stores input decimal values
  int binarySize; //stores number of binary numbers to be output
  int octalSize; //stores number of octal numbers to be output

  input(decimal); //gets input
  binarySize = countOdds(decimal); //calculate values
  octalSize = countEvens(decimal);
  convertArray(decimal, binarySize, octalSize); //outputs data
  
  return 0;
}

/***************************************************************************
*
* Function Information
*
* Name of Function: input
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. int decimals[] //This is the list of decimal values inputted by the user
*
* Function Description: This function takes user input on 20 non-negative decimal values,
* and stores them in an array
*
***************************************************************************/

void input(int decimals[])
{
  int count; //counter variable for the for loop to scan in values
  printf("Enter 20 integer values -> ");
  for (count = 0; count < 20; count++)
  {
    scanf("%d", &decimals[count]);
  }
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
    oct += ConvertAdd(remainder, digit);
  }
  return(oct);
}

/***************************************************************************
*
* Function Information
*
* Name of Function: ConvertAdd
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. int remainder //the remainder of the decimal number divided by base
* 2. int digit //the decimal place of each digit in the number (1 for ones place, 2 for tens place, etc.)
*
* Function Description: Returns the digit that will be added to the current value when converting to another number storage method
*
***************************************************************************/

int ConvertAdd(int remainder, int digit)
{
  int newOct; //the digit being added on to the current octal value
  newOct = remainder * pow(10, digit - 1);
  return(newOct);
}

/***************************************************************************
*
* Function Information
*
* Name of Function: getBinary
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. int base10 //the initial decimal number
*
* Function Description: Returns the binarhy value given a decimal number
*
***************************************************************************/

int getBinary(int base10)
{
  int digit; //the decimal place of each digit in the number
  int remainder; //the remainder of the decimal number divided by 8 (1 for ones place, 2 for tens place, etc.)
  int bin; //the current octal value
  
  //set intial conditions
  bin = 0; //octal number
  digit = 0; //digit of the octal number
  
  while(base10 != 0)
  {
    remainder = base10 % 2;
    base10 /= 2;
    digit++;
    bin += ConvertAdd(remainder, digit);
  }
  return(bin);
}

/***************************************************************************
*
* Function Information
*
* Name of Function: countEvens
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. int[] decimal //decimal values in an array
*
* Function Description: Returns the number of even numbers in the decimal array
*
***************************************************************************/

int countEvens(int decimal[])
{
  int count; //Incrimentor for the for loop
  int numEvens; //number of even numbers

  numEvens = 0; //initial value
  for(count = 0; count < 20; count++) //if number is even add 1 to numEven
  {
    if(decimal[count] % 2 == 0)
    {
      numEvens++;
    }
  }
  return(numEvens); //return
}

/***************************************************************************
*
* Function Information
*
* Name of Function: countOdds
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. int[] decimal //decimal values in an array
*
* Function Description: Returns the number of odd numbers in the decimal array
*
***************************************************************************/

int countOdds(int decimal[])
{
  int count; //Incrimentor for the for loop
  int numOdds; //number of odd numbers

  numOdds = 0; //initial value
  for(count = 0; count < 20; count++) //if number is even add 1 to numOdds
  {
    if(decimal[count] % 2 == 1)
    {
      numOdds++;
    }
  }
  return(numOdds); //return values
}

/***************************************************************************
*
* Function Information
*
* Name of Function: convertArray
*
* Function Return Type: void
*
* Parameters (list data type, name, and comment one per line):
* 1. int[] decimal //decimal values
* 2. int numOdd //number of odd number in decimal
* 3. int numEven //number of even numbers in decimal
*
* Function Description: Converts the decimal array's odd numbers into an array of
* binary numbers and the decimal array's even numbers into an array of octal numbers
*
***************************************************************************/

void convertArray(int decimal[], int numOdd, int numEven)
{
  int binary[numOdd]; //binary values array
  int octal[numEven]; //octal values array
  int binaryIndex; //iterator for binary index
  int octalIndex; //iterator for octal index
  int count; //array index

  binaryIndex = 0; //initial values
  octalIndex = 0;
  for (count = 0; count < 20; count++) //for all values in decimal
  {
    if (decimal[count] % 2 == 1) //if number is odd set binary to value
    {
      //stores the binary number in the correct index then iterates the binary index counter
      binary[binaryIndex] = getBinary(decimal[count]);
      binaryIndex++;
    }
    else //else set octal to value
    {
      //stores the octal number in the correct index then iterates the octal index counter
      octal[octalIndex] = getOctal(decimal[count]);
      octalIndex++;
    }
  }
  printArrays(binary, octal, numEven, numOdd); //print arrays
}

/***************************************************************************
*
* Function Information
*
* Name of Function: printArrays
*
* Function Return Type: void
*
* Parameters (list data type, name, and comment one per line):
* 1. int[] binary //binaryIndex values
* 2. int[] octal //octal values
* 3. int numEven //number of even numbers in the decimal array
* 4. int numOdd //number of odd numbers in the decimal array
*
* Function Description: Prints binary and octal arrays in a formatted mannor
*
***************************************************************************/

void printArrays(int binary[], int octal[], int numEven, int numOdd)
{
  int count; //array index
  printf("Binary values: ");
  
  if(numOdd != 0) //if there are values
  {
    for (count = 0; count < numOdd; count++) //print each
    {
      printf("%d ", binary[count]);
    }
  }
  else //else print none
  {
    printf("None");
  }
  
  printf("\nOctal values: ");
  
  if(numEven != 0) //if there are values
  {
    for (count = 0; count < numEven; count++) //print each
    {
      printf("%d ", octal[count]);
    }
  }
  else // else print none
  {
    printf("None");
  }
  
  printf("\n");
  
}
