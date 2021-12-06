/*****************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. jferlazz@purdue.edu
*  2. armst100@purdue.edu
*  3. oakinley@purdue.edu
*   
*  Lab #: 1
*
*  Academic Integrity Statement:  
*   
*       We have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have we provided access
*       to our code to another. The effort we are submitting
*       is our own original work.
*  
*  Lab Division and Section: Friday, 2:30pm, HAMP 3144
*
*  Program Description: With a given radius of a circle, this algorim
*  calculates the area of that circle along with the length of a side
*  and area of a regular pentagon inscribed in the circle
*
*********************************************************************************/
#include <stdio.h>
#include <math.h>
#define PI 3.1416

int main(void)
{
  //Local Declorations  
  float radius; //radius of the circle given by the user
  float circleArea; //the area of that circle
  float pentagonSide; //side length of the inscribed pentagon
  float pentagonArea; //the area of the inscribed pentagon
  //Statements 
  printf("Please enter the value of the radius -> ");
  scanf("%f", &radius);

  pentagonSide = 2 * radius * sin(PI / 5); //Finds the side length of the pentagon
  circleArea = PI * pow(radius, 2); //Calculates the area of the circle
  pentagonArea = 5 * pentagonSide * .5 * sqrt(pow(radius, 2) - pow((pentagonSide * .5), 2)); //Finds the area of the inscribed pentagon
   
  printf("\nCircle Area: %.2f\n", circleArea);
  printf("Pentagon side: %.2f\n", pentagonSide);
  printf("Pentagon area: %.2f\n", pentagonArea);

  return(0);
}
