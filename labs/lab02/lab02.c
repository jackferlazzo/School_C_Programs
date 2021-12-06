/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. oakinley@purdue.edu
*  2. jferlazz@purdue.edu
*  3. armst100@purdue.edu
*
*  Lab #: 2
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
*  This program is given the radius of an intercircle by the user, and the program finds the
*  area of this intercirlce, the side length and area of the hexagon it is inscribed in, the 
*  area of the larger circle the hexagon is incribed in and then the side length and area of the 
*  pentagon the larger circle is inscribed in
***************************************************************************/

#include <stdio.h>
#include <math.h>

int main(void) 
{
  //Local Declarations

  double sRadius; // small circle radius
  double sArea; // small circle area
  double lRadius; // large circle radius
  double lArea; // large circle area
  double hexSide; // side length of hexagon
  double hexArea; // area of hexagon
  double pentSide; // side length of pentagon
  double pentArea; // area of pentagon

  //Executable Statements

  printf("Enter the radius of the small circle -> ");
  scanf("%lf", &sRadius);

  sArea = M_PI * pow(sRadius, 2); //calculates the area of the small circle
  hexSide = ((2 * sRadius) / sqrt(3)); //calculates the side length of the hexagon
  hexArea = (((3 * sqrt(3)) / 2) * pow(hexSide,2)); //calculates the area of the hexagon
  lRadius = ((2 * sRadius) / sqrt(3)); //calculates the radius of the larger circle
  lArea = M_PI * pow(lRadius, 2); //calculates the area of the large circle
  pentSide = 2 * lRadius * tan(M_PI / 5); //calculates the side length of the pentagon
  pentArea = 5 * pentSide * .5 * pentSide / (2 * tan(M_PI / 5)); //calculates the are of the pentagon

  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Area of small circle: %13.2lf\n", sArea);
  printf("Hexagon side length: %14.2lf\n", hexSide);
  printf("Area of hexagon: %18.2lf\n", hexArea);
  printf("Area of large circle: %13.2lf\n", lArea);
  printf("Pentagon side length: %13.2f\n", pentSide);
  printf("Area of pentagon: %17.2lf\n", pentArea);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return(0);
}
