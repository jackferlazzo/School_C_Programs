/***************************************************************************
*
* Programmers and Purdue Email Addresses:
* 1. tlirette@purdue.edu
* 2. jferlazz@purdue.edu
* 3. albarkat@purdue.edu
*
* Lab #: 10
*
* Academic Integrity Statement:
*
* We have not used source code obtained from any other unauthorized source,
* either modified or unmodified. Neither have we provided access to our code
* to another. The effort we are submitting is our own original work.
*
* Day, Time, Location of Lab: Friday, 2:30 PM, HAMP 3144
*
* Program Description: Program that given up to twenty non-negative decimal integer values 
* as input separates the odd and even numbers and sorts them representively. Then the program conduct modulus 
* division on each element of the sorted list, the resulting values are the indices of the number
* which are added together in a summation. The sorted list and this summation are then output as outlined in
* the lab
*
***************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 20

void inputNums(int[]);
void separateArray(int, int, int[]);
int evenOddArraySize(int[], int);
void printOutput(int[], int, int);
int sumOfArray(int, int[]);
void combineArrays(int, int, int[], int[]);
void sortArray(int[], int);

int main(void) 
{
  int values[SIZE]; //Inputted list of values
  int oddSize; //Number of odd number
  int evenSize; //Number of even numbers

  //User inputs a list of numbers
  inputNums(values);
  
  //Finds the number of odd and even numbers in the array respectively
  oddSize = evenOddArraySize(values, 1);
  evenSize = evenOddArraySize(values, 0);

  //separates the array into an even and odd array
  separateArray(oddSize, evenSize, values);
  
  return(0);
}

/***************************************************************************
*
* Function Information
*
* Name of Function: inputNums
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

void inputNums(int decimals[])
{
  int count; //counter variable for the for loop to scan in values
  int store; //stores last input

  store = 0;
  printf("Enter 20 integer values -> ");
  for (count = 0; count < 20 && store >= 0; count++)
  {
    scanf("%d", &decimals[count]);
    store = decimals[count];
  }
}
/***************************************************************************
*
* Function Information
*
* Name of Function: evenOddArraySize
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. int[] input //data
* 2. int evenOdd // desired test criteria 0 if even 1 if odd
*
* Function Description: Gets number of even or odd values in an array
*
***************************************************************************/
int evenOddArraySize(int input[], int evenOdd)
{
  int store; //number of either odd or even numbers
  int i; //incrimentor for the while loop
  
  i = 0;
  store = 0;

  while(i < 20 && input[i] != -1) //while we havent reached the end
  {
    if(evenOdd && input[i] % 2 == 1) //if odd check
    {
      store++; //increment
    }
    else if(!evenOdd && input[i] % 2 == 0) //if even check
    {
      store++; //increment
    }
    i++; //iterate
  }

  return store;
}

/***************************************************************************
*
* Function Information
*
* Name of Function: sortArray
*
* Function Return Type: void
*
* Parameters (list data type, name, and comment one per line):
* 1. int[] input //values of array to be sorted 
* 2. int size //size of array to be sorted
*
* Function Description: Sorts an array in acsending order
*
***************************************************************************/

void sortArray(int input[], int size)
{
  int innerCount; //iterator for outer loop
  int outerCount; //iterator for inner loop
  int hold; //holds value for exchanging values

  for(outerCount = size - 1; outerCount >= 0 ; outerCount--) //for every value in array starting from top
  {
    for(innerCount = 0; innerCount < outerCount; innerCount++) //for every value up to that
    {
      if(input[innerCount + 1] < input[innerCount]) //if the value after it is smaller switch the two values
      {
        hold = input[innerCount];
        input[innerCount] = input[innerCount + 1];
        input[innerCount + 1] = hold;
      }
    }
  }
}

/***************************************************************************
*
* Function Information
*
* Name of Function: separateArray
*
* Function Return Type: void
*
* Parameters (list data type, name, and comment one per line):
* 1. int oddSize //number of odd numbers
* 2. evenSize //Number of even numbers
* 3. int [] values // user entered numbers
*
* Function Description: This function separates the array of numbers
* into an array of even numbers and an array of even numbers
* passing this lists off to the combineArrayFunction
*
***************************************************************************/

void separateArray(int oddSize, int evenSize, int values[])
{
  int oddValues[oddSize]; //array of odd values
  int evenValues[evenSize]; //array of even values
  int count; //incrimentor/index
  int oddIndex; //current index for the odd array
  int evenIndex; //current index for the even array
  
  oddIndex = 0;
  evenIndex = 0;
  
  for (count = 0; count < (oddSize + evenSize); count++)
  {
    if(values[count] % 2 == 0)
    {
      evenValues[evenIndex] = values[count];
      evenIndex++;
    }
    else
    {
      oddValues[oddIndex] = values[count];
      oddIndex++;
    }
  } 

  combineArrays(oddSize, evenSize, oddValues, evenValues);
}

/***************************************************************************
*
* Function Information
*
* Name of Function: sumOfArray
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. int size //size of array
* 2. int[] values //values contained in array
*
* Function Description: conduct modulus division on each element of the sorted list, the resulting
* values are the indices of the number which are added together in a summation
*
***************************************************************************/

int sumOfArray(int size, int values[])
{
  int count; //array index
  int sum; //sum of array indices

  sum = 0;
  
  for(count = 0; count < size; count++)
  {
    sum += values[values[count] % size];
  }

  return(sum);
}

/***************************************************************************
*
* Function Information
*
* Name of Function: combineArrays
*
* Function Return Type: void
*
* Parameters (list data type, name, and comment one per line):
* 1. int oddSize //size of odd array
* 2. int evenSize //size of even array
* 3. int oddValues[] //array of only odd integers
* 4. int evenValues[] //array of only even integers
*
* Function Description: Constructs the sorted array of odd/even integers while maintaining a clear separation between
* odd and even numbers
*
***************************************************************************/

void combineArrays(int oddSize, int evenSize, int oddValues[], int evenValues[])
{
  int count; //sorted array index
  int sortedValues[evenSize + oddSize]; //sorted array
  int evenIndex; //even array index
  int oddIndex; //odd array index
  int arraySize; //sorted array size
  
  sortArray(oddValues, oddSize);
  sortArray(evenValues, evenSize);

  arraySize = oddSize + evenSize;
  evenIndex = 0;
  oddIndex = 0;

  for(count = 0; count < arraySize; count++)
  {
    if(count < evenSize)
    {
      sortedValues[count] = evenValues[evenIndex];
      evenIndex++;
    }
    else
    {
      sortedValues[count] = oddValues[oddIndex];
      oddIndex++;
    }
  }

  printOutput(sortedValues, sumOfArray(arraySize, sortedValues), arraySize);
}

/***************************************************************************
*
* Function Information
*
* Name of Function: printOutput
*
* Function Return Type: void
*
* Parameters (list data type, name, and comment one per line):
* 1. int sortedArray[] //the sorted array with both odd and even 
* 2. int sum //sum of indexes of modulus of array
* 3. int size //size of sorted array.
*
* Function Description: Outputs data in a formatted manner 
*
***************************************************************************/
void printOutput(int sortedArray[], int sum, int size)
{
  int i; //array index
  printf("\nSorted array: ");
  for(i = 0; i < size; i++)
  {
    printf("%d ", sortedArray[i]);
  } 
  printf("\nCalculated sum: %d\n", sum);
}