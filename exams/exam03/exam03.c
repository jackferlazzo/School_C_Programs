/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. jferlazz@purdue.edu
*
*  Lab #: Exam 3
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Friday, 2:30 PM, HAMP 3144
*
*  Program Description:
*  This program allows the user to input a list of up to 20 non-negative integers
*  (user ends -1 to end the list early). The user than inputs what type of number system
*  they would like to convert the decimal odd numbers and the even numbers to (2 being binary, 8 being octal etc)
*  the program than outputs the new lists of numbers as outlined in the lab
*  
***************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 20 //maximum size of the input array

int inputOddBase();
int inputEvenBase();
void inputNums(int[]);
int getNewNum(int,int); 
int ConvertAdd(int,int);
int countOdds(int[]);
int countEvens(int[]);
void convertArray(int[], int, int, int, int);
void printArrays(int[], int[], int, int, int, int);
void printBaseType(int);

int main(void) 
{
  //Local Declarations
  int decimal[SIZE]; //stores input decimal values
  int oddBase; //The number system used for odd numbers
  int evenBase; //The number system used for even numbers
  int evenNums; //number of even numbers
  int oddNums; //number of odd numbers

  //Executable Statements

  //User inputs
  oddBase = inputOddBase();
  evenBase = inputEvenBase();
  inputNums(decimal);

  //Counter Function (count number of odd or even numbers)
  evenNums = countEvens(decimal);
  oddNums = countOdds(decimal);

  //Converts and Outputs Data
  convertArray(decimal, oddNums, evenNums, oddBase, evenBase);

  return 0;
}

/***************************************************************************
*
* Function Information
*
* Name of Function: inputOddBase
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. NA
*
* Function Description: This function takes user input what number system odd numbers
* should be converted to (2 for binary, 8 for octal etc)
*
***************************************************************************/

int inputOddBase()
{
  int oddBase; //counter variable for the for loop to scan in values

  do
  {
    printf("Enter base for odd numbers -> ");
    scanf("%d", &oddBase);
    if(oddBase < 2 || oddBase > 9)
    {
      printf("\nError! Base must be in the range from 2 to 9.\n\n");
    }
  } while (oddBase < 2 || oddBase > 9);
  return(oddBase);
}

/***************************************************************************
*
* Function Information
*
* Name of Function: inputEvenBase
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. NA
*
* Function Description: This function takes user input what number system even numbers
* should be converted to (2 for binary, 8 for octal etc)
*
***************************************************************************/

int inputEvenBase()
{
  int evenBase; //counter variable for the for loop to scan in values
  evenBase = 0; //Intial value set to st
  do
  {
    printf("Enter base for even numbers -> ");
    scanf("%d", &evenBase);
    if(evenBase < 2 || evenBase > 9) //must be betwen 2 and 9
    {
      printf("\nError! Base must be in the range from 2 to 9.\n\n");
    }
  } while(evenBase < 2 || evenBase > 9);
  return(evenBase);
}

/***************************************************************************
*
* Function Information
*
* Name of Function: inputNums
*
* Function Return Type: Void
*
* Parameters (list data type, name, and comment one per line):
* 1. int decimals[] //This is the list of decimal values inputted by the user
*
* Function Description: This function takes user input on up to 20 non-negative decimal values,
* and stores them in an array. If the user would like to end number inputs early they merely
* need to type -1
*
***************************************************************************/

void inputNums(int decimals[])
{
  int count; //counter variable for the for loop to scan in values
  int input; //value entered by the user

  count = 0;

  printf("Enter up to 20 integer values -> ");
  do
  {
    scanf("%d", &input);
    decimals[count] = input;
    count++;
  } while(input != -1 && count < 20);
}

/***************************************************************************
*
* Function Information
*
* Name of Function: getNewNum
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. int base10 //the initial decimal number
* 2. int targetBase //The number system you wish to form the new number from
* ie Binary (2) , octal (8), etc
*
* Function Description: Returns the new number system value given a decimal number
* and the desired number system
*
***************************************************************************/

int getNewNum(int base10, int targetBase)
{
  int digit; //the decimal place of each digit in the number
  int remainder; //the remainder of the decimal number divided by 8 (1 for ones place, 2 for tens place, etc.)
  int newNum; //the new number post conversion
  
  //set intial conditions
  newNum = 0; //new number
  digit = 0; //digit of the the new number
  
  while(base10 != 0)
  {
    remainder = base10 % targetBase;
    base10 /= targetBase;
    digit++;
    newNum += ConvertAdd(remainder, digit);
  }
  return(newNum);
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
  int newDigit; //the digit being added on to the current octal value
  newDigit = remainder * pow(10, digit - 1);
  return(newDigit);
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
  
  count = 0;

  numEvens = 0; //initial value
  while(decimal[count] != -1 && count < 20) //if number is even add 1 to numEven
  {
    if(decimal[count] % 2 == 0)
    {
      numEvens++;
    }
    count++;
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

  count = 0;

  numOdds = 0; //initial value
  while(decimal[count] != -1 && count < 20) //if number is even add 1 to numOdds
  {
    if(decimal[count] % 2 == 1)
    {
      numOdds++;
    }
    count++;
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
* 4. int oddBase //the number system the odd numbers must be converted to 2 for binary 8 for octal etc
* 5. int evenBase //the number system the even numbers must be converted to 2 for binary 8 for octal etc
*
* Function Description: Converts the decimal array's odd numbers and even numbers to an
* array numbers in the desired number system
*
***************************************************************************/

void convertArray(int decimal[], int numOdd, int numEven, int oddBase, int evenBase)
{
  int oddArray[numOdd]; //array of odd number converted to the desired number system
  int evenArray[numEven]; //array of even number converted to the desired number system
  int oddIndex; //iterator for odd index
  int evenIndex; //iterator for even index
  int count; //array index

  oddIndex = 0; //initial values
  evenIndex = 0;
  count = 0;

  while(decimal[count] != -1 && count < 20) // all values in decimal except the -1
  {
    if (decimal[count] % 2 == 1) //if number is odd set binary to value
    {
      //stores the binary number in the correct index then iterates the binary index counter
      oddArray[oddIndex] = getNewNum(decimal[count], oddBase);
      oddIndex++;
    }
    else if (decimal[count] % 2 == 0) //else set octal to value
    {
      //stores the octal number in the correct index then iterates the octal index counter
      evenArray[evenIndex] = getNewNum(decimal[count], evenBase);
      evenIndex++;
    }
    count++; //Incriments the index
  }
  printArrays(oddArray, evenArray, numEven, numOdd, evenBase, oddBase); //print arrays
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
* 5. int evenBase //the number system the even numbers must be converted to 2 for binary 8 for octal etc
* 4. int oddBase //the number system the odd numbers must be converted to 2 for binary 8 for octal etc
*
* Function Description: Prints new number system arrays in a formatted mannor
*
***************************************************************************/

void printArrays(int oddArray[], int evenArray[], int numEven, int numOdd, int evenBase, int oddBase)
{
  int count; //array index
  
  printf("\n");
  printBaseType(oddBase);
  printf("values: ");
  
  if(numOdd != 0) //if there are values
  {
    for (count = 0; count < numOdd; count++) //print each
    {
      printf("%d ", oddArray[count]);
    }
  }
  else //else print none
  {
    printf("None");
  }
  
  printf("\n");
  printBaseType(evenBase);
  printf("values: ");
  
  if(numEven != 0) //if there are values
  {
    for (count = 0; count < numEven; count++) //print each
    {
      printf("%d ", evenArray[count]);
    }
  }
  else // else print none
  {
    printf("None");
  }
  
  printf("\n");
  
}

/***************************************************************************
*
* Function Information
*
* Name of Function: printBaseType
*
* Function Return Type: void
*
* Parameters (list data type, name, and comment one per line):
* 1. int base //The number base whose indentifer you wish to print
*
* Function Description: This function prints out the proper base indentifer given a
* sent in number system 2 for Binary, 8  for Octal etc.
*
***************************************************************************/

void printBaseType (int base)
{
  switch (base)
  {
    case 2:
      printf("Binary ");
      break;
    case 3:
      printf("Ternary ");
      break;
    case 4:
      printf("Quaternary ");
      break;
    case 5:
      printf("Quinary ");
      break;
    case 6:
      printf("Senary ");
      break;
    case 7:
      printf("Septenary ");
      break;
    case 8:
      printf("Octal ");
      break;
    case 9:
      printf("Nonary ");
      break;
  }
}
