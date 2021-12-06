/***************************************************************************
*
* Programmers and Purdue Email Addresses:
* 1. tlirette@purdue.edu
* 2. jferlazz@purdue.edu
* 3. albarkat@purdue.edu
*
* Lab #: 11
*
* Academic Integrity Statement:
*
* We have not used source code obtained from any other unauthorized source,
* either modified or unmodified. Neither have we provided access to our code
* to another. The effort we are submitting is our own original work.
*
* Day, Time, Location of Lab: Friday, 2:30 PM, HAMP 3144
*
* Program Description: This program takes a user inputted array of values and the size of
* that array of values, it then sorts the array while maintaining even and odd numbers in the
* same indices as the original array of values. THe program then outputs this list in a
* formatted manner as outlined in the lab
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int inputSize(void);
void inputList(int*, int);
void printFinal(int* , int);
void sortArray(int* , int);

int main(void) 
{
  //Local Declarations
  int *data; //array which stores data
  int size; //size of array

  //Executable Statements
  
  //inputs
  size = inputSize(); 
  data = (int*)malloc(sizeof(int) * size);
  inputList(data, size); 

  //calculations
  sortArray(data, size);

  //Output
  printFinal(data, size);
  return 0;
}

/***************************************************************************
*
* Function Information
*
* Name of Function: inputSize
*
* Function Return Type: int
*
* Parameters (list data type, name, and comment one per line):
* 1. NA
*
* Function Description:  This function allows the user to input the desired size of an array
*
***************************************************************************/
int inputSize()
{
  int size; //user inputted size of the array

  printf("Enter data set size -> ");
  scanf("%d", &size);

  return(size);
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
* 1. int* input //input data
* 2. int size //size of array
*
* Function Description: Sorts an array based on given criteria for lab.  
*
***************************************************************************/

void sortArray(int *input, int size)
{
  int insideCount; //iterator for most inside loop
  int innerCount; //iterator for outer loop
  int outerCount; //iterator for inner loop
  int hold; //holds value for exchanging values

  for(outerCount = 0; outerCount < size ; outerCount++) //for every value in array starting from top
  {
    for(innerCount = 0; innerCount < size; innerCount++) //for every other value in the array
    {
      for(insideCount = 0; insideCount < size; insideCount++)
      {
        if(( * (input + insideCount) > * (input + innerCount)) && ( * (input + innerCount) % 2 == * (input + insideCount) % 2)) //if the value after it is smaller switch the two values
        {
          hold = * (input + innerCount);
          * (input + innerCount) = * (input + insideCount);
          * (input + insideCount) = hold;
        }
      }
    }
  }
}

/***************************************************************************
*
* Function Information
*
* Name of Function: inputList
*
* Function Return Type: void
*
* Parameters (list data type, name, and comment one per line):
* 1. int* data //integer array
* 2. int size //size of integer array
*
* Function Description: User inputs array of integers
*
***************************************************************************/
void inputList(int* data, int size)
{
  int count; //array index

  printf("Enter %d integer values -> ", size);

  for(count = 0; count < size; count++)
  {
    scanf("%d", data + count);
  }
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
* 1. int* data //final sorted array
* 2. int size //size of the sorted array
*
* Function Description: Prints output array in formatted manner
*
***************************************************************************/
void printFinal(int *data, int size)
{
  int i; //array index
  printf("\nFinal data set order: ");
  for(i = 0; i < size; i++)
  {
    printf("%d ", * (data + i));
  } 

  printf("\n");
}
