/*****************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. jferlazz@purdue.edu
*  2. armst100@purdue.edu
*  3. oakinley@purdue.edu
*   
*  Lab #: 3
*
*  Academic Integrity Statement:  
*   
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*  Day, Time, Location of Lab: Friday, 2:30pm, HAMP 3144
*
*  Program Description:  
*  
*  This program allows the user to selec whether a regular polygon is inscribed
*  inside of a circle or the circle is inscribed inside of a regular polygon and 
*  calculates the circle radius, circle area, polygon area, and the side length
*  given user inputted number of polygon sides and apothem length
*********************************************************************************/
#include <stdio.h>
#include <math.h>

int main(void) 
{
  //Local Declarations

  double circleArea; //Calculated area of the circle
  double radius_1; //radius of circle for selection 1
  double radius_2; //radius of circle for selection 2
  double radius; //Calculated radius of the circle
  double polySide; //number of sides of polygon
  double sideLength; //side length of polygon
  int selection; //user shape selection; 1 is polygon inside circle 2, vice versa
  double apothem; //user input apothem of polygon
  double polyArea; //area of polygon

  //Executable Statements

  printf("1. Polygon inside of circle\n");
  printf("2. Circle inside of polygon\n");
  printf("Select your option -> ");
  scanf("%d", &selection);
  printf("Enter number of polygon sides -> ");
  scanf("%lf", &polySide);
  printf("Enter length of polygon apothem -> ");
  scanf("%lf", &apothem);

  //Calculated side length and area of polygon (Not determined by selection)
  sideLength = 2 * apothem * tan(M_PI / polySide);
  polyArea = (sideLength * polySide * apothem) / 2;

  //Calculates radius for either situation and displays based on selection using modulus and division evaluation
  radius_1 = apothem / cos(M_PI / polySide);
  radius_2 = apothem;
  radius = (selection % 2) * (radius_1) + (selection / 2) * (radius_2);
  circleArea = M_PI * pow(radius, 2);

  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Circle Radius:%17.2lf\n",radius);
  printf("Circle Area:%19.2lf\n", circleArea);
  printf("Polygon Side Length:%11.2lf\n", sideLength);
  printf("Polygon Area:%18.2lf\n", polyArea);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  return (0);
}
