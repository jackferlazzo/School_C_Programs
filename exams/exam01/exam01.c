
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. jferlazz@purdue.edu
*
*  Lab #: Exam 1
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
*
*  This program takes user input on what type of calculation should be done with 1
*  Being for an inscribed triangle, 2 for an inscribed square, and any other number for circle inscribed
*  in a polygon with that number of sides. The user also enters the area of the figure (circle for 1 and 2
*  and a polygon for 3) and the program calculates the apothem/radius and area of the inscribed figure
***************************************************************************/
#include <stdio.h>
#include <math.h>

int main(void) 
{
  //Local Declarations

  int userSideInput; //Option number entered by the user
  int factor1; //Factor 1 if a triangle is inscribed inside the circle it will equal 1 if not it will equal 0
  int factor2; //Factor 2 if a square is inscribed inside the circle it will equal 1 if not it will equal 0
  int factor3; //Factor 3 if the circle is inscribed inside a polygon it will equal 1 if not it will equal 0
  int sideNumber; //Number of sides in the desired polygon where inscribed or circumscribed
  double figureArea; //Area of the outside figure
  double figureRadiusOrApothem; //radius or apothem of the outside figure
  double inscribedArea; //Area of the inscribed figure
  double inscribedRadiusOrApothem; //radius or apothem of the inside figure

  //Executable Statements

  printf("Enter desired option -> ");
  scanf("%d", &userSideInput); //user input for desided option
  printf("Enter area of figure -> ");
  scanf("%lf", &figureArea); //user input for the outside figure's area

  //Calculates factors that correspond to user option input
  factor1 = 1 / userSideInput; //If user input = 1, then factor 1 = 1 if not factor 1 = 0
  factor2 = (2 / userSideInput) * (1 - factor1); //If user input = 2, then factor 2 = 1 if not factor 2 = 0
  factor3 = (1 - factor1) * (1 - factor2); //If user input > 2, then factor 3 = 1 if not factor 3 = 0

  //Number of sides of the polygon whether inscibed or not
  sideNumber = (factor1 * 3) + (factor2 * 4) + (factor3 * userSideInput); 
  
  //Calculates the length of the outside figures radius (if factor3 = 1) or apothem (if factor1 or factor2 = 1)
  figureRadiusOrApothem = sqrt(figureArea / M_PI) * (1 - factor3); 
  figureRadiusOrApothem += sqrt(figureArea / (sideNumber * tan(M_PI / sideNumber))) * (factor3); //Split to multiple lines

  //Calculates the length of the inside figures radius (if factor1 or factor2 = 1) or apothem (if factor3 = 1)
  inscribedRadiusOrApothem =  figureRadiusOrApothem * (factor3); 
  inscribedRadiusOrApothem += figureRadiusOrApothem * cos(M_PI / sideNumber) * (1 - factor3); //Split to 2 lines

  //Calculates the area of the inside figure, circle (if factor3 = 1) and polygon (if factor1 and factor2 = 1)
  inscribedArea = (M_PI * pow(inscribedRadiusOrApothem, 2)) * (factor3);  
  inscribedArea += ((inscribedRadiusOrApothem * tan(M_PI / sideNumber)) * sideNumber * inscribedRadiusOrApothem) * (1 - factor3); //Split to 2 lines

  //Display Output
  
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Radius/Apothem of figure with area given:%10.1lf\n", figureRadiusOrApothem);
  
  //If factor1 = 1 the character T is print, if factor2 = 1 character S is printed, and if factor3 = 1 character C is printed
  printf("Area of inscribed figure [%c]: %.1lf\n", (factor1 * 84) + (factor2 * 83) + (factor3 * 67), inscribedArea); 

  return(0);
}
