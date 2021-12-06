/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. jferlazz@purdue.edu
*  2. armst100@purdue.edu
*  3. oakinley@purdue.edu
*
*  Lab #: 5
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
*  This program calculates the area of four quadrilaterals formed by a triangle 
*  made by three points defined by the user, and the inradii of that triangle. The 
*  program then outputs these calculations as outlined in the lab.
*
***************************************************************************/
#include <stdio.h>
#include <math.h>

//Global Decloration
double input(int, int); //input function
double distance(double, double, double, double); //Calculates the distance between points
double perimeter(double, double, double); //Calculates the perimeter
double inCenterCord(double, double, double, double, double, double, double);
double inRadiusLength(double, double, double, double);
double getAngle(double, double);
double getArea(double, double, double);
//Output
void output(double, double, double, double, double, double); //Output of all vairables 
void degreesMinSec(double, double, double);

int main(void) 
{
  //Local Declarations
  double xCord1; //x-cooridate of point 1
  double yCord1; //y-cooridate of point 1
  double xCord2; //x-cooridate of point 2
  double yCord2; //y-cooridate of point 2
  double xCord3; //x-cooridate of point 3
  double yCord3; //y-cooridate of point 3
  double side1; //Triangle side oppisite point 1
  double side2; //Triangle side oppisite point 2
  double side3; //Triangle side oppisite point 3
  double Perimeter; //the perimeter of the triangle
  double inCenterX; //x coordinate of the incenter circle
  double inCenterY; //y coordinate of the incenter circle
  double inRadius; //radius of the circle inside the user entered triange
  double distanceAI; //distance from angle A to the incenter
  double distanceBI; //distance from angle B to the incenter
  double distanceCI; //distance from angle C to the incenter
  double angleA; //angle of point A of the large triangle 
  double angleB; //angle of point B of the large triangle 
  double angleC; //angle of point C of the large triangle 
  double areaA; //area of small triangle stemming from point A
  double areaB; //area of small triangle stemming from point B
  double areaC; //area of small triangle stemming from point C

  //Executable Statements
  xCord1 = input('x', 1); //Input of the coordinate x1 point 
  yCord1 = input('y', 1); //Input of the cooridate y1 point
  xCord2 = input('x', 2); //Input of the coordinate x2 point
  yCord2 = input('y', 2); //Input of the coordinate y2 point 
  xCord3 = input('x', 3); //Input of the coordinate x3 point
  yCord3 = input('y', 3); //Input of the coordinate y3 point

  side1 = distance(xCord2, yCord2, xCord3, yCord3); // side1 distance 
  side2 = distance(xCord1, yCord1, xCord3, yCord3); //side2 distance
  side3 = distance(xCord1, yCord1, xCord2, yCord2); //side3 distance

  Perimeter = perimeter(side1, side2, side3);
  
  //x and y coordinates of the incenter circle calculate by inCenterCord function
  inCenterX = inCenterCord(side1, side2, side3, xCord1, xCord2, xCord3, Perimeter);
  inCenterY = inCenterCord(side1, side2, side3, yCord1, yCord2, yCord3, Perimeter);

  //radius of the circle inside the triangle
  inRadius = inRadiusLength(side1, side2, side3, Perimeter);

  //Finds the distance between angles and incenter
  distanceAI = distance(xCord1, yCord1, inCenterX, inCenterY);
  distanceBI = distance(xCord2, yCord2, inCenterX, inCenterY);
  distanceCI = distance(xCord3, yCord3, inCenterX, inCenterY);

  //Finds the degrees of each angle
  angleA = getAngle(distanceAI, inRadius);
  angleB = getAngle(distanceBI, inRadius);
  angleC = getAngle(distanceCI, inRadius);
  
  //Finds the area of each section
  areaA = getArea(distanceAI, inRadius, angleA);
  areaB = getArea(distanceBI, inRadius, angleB);
  areaC = getArea(distanceCI, inRadius, angleC);
  
  //Output
  output(angleA, angleB, angleC, areaA, areaB, areaC);

  return 0;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: input
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int desiredChar // This is the desired type of coorinate either x or y
*    2. int pointNum // This is the desired point number either point 1, 2, 3
*
*  Function Description: This function takes user input for a desired x or y coorinate
*  for either point 1, 2, or 3
*
***************************************************************************/
double input(int desiredChar, int pointNum)
{
  double coordinate; //user input for coordinate either x or y
  
  //prints a statement that is custom tailored to the desired coorinate
  printf("Enter %c coordinate #%d -> ", desiredChar, pointNum);
  scanf("%lf", &coordinate);
  return(coordinate);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: distance
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double xCord1 // This x-coordinate of the 1st point
*    2. double yCord1 // This y-coordinate of the 1st point
*    3. double xCord2 // This x-coordinate of the 2nd point
*    4. double xCord2 // This x-coordinate of the 2nd point
*
*  Function Description: This function takes 2 points x and y cooridates and finds
*  the distance between the representing a side of the triangle using the distance
*  formula distance = sqrt((X2 - X1)^2 + (Y2 - Y1)^2)
*
***************************************************************************/
double distance(double xCord1, double yCord1, double xCord2, double yCord2)
{
  //distance = sqrt((X2 - X1)^2 + (Y2 - Y1)^2)
  return(sqrt(pow(xCord2 - xCord1, 2) + pow(yCord2 - yCord1, 2))); 
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: perimeter
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double side1 // side length between points opposite point 1
*    2. double side2 // side length between points opposite point 2
*    3. double side3 // side length between points opposite point 3
*
*  Function Description: This function calculates the perimeter of a triangle
*  by adding its three side lengths.
*
***************************************************************************/
double perimeter(double side1, double side2, double side3)
{
  return(side1 + side2 + side3); //find the perimeter of the large trianlge 
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inCenterCord
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double side1 // side length between points opposite point 1 (a)
*    2. double side2 // side length between points opposite point 2 (b)
*    3. double side3 // side length between points opposite point 3 (c)
*    4. double cord1 // This x or y-coordinate of the 1st point (Ax or Ay)
*    5. double cord2 // This x or y-coordinate of the 2nd point (Bx or By)
*    6. double cord3 // This x or y-coordinate of the 3rd point (Cx or Cy)
*    7. double Perimeter //This is the perimeter of the triangle (p)
*
*  Function Description: This function calculates either the x or y cooridate of the
*  incenter circle O using the formula Ox = (a Ax + b Bx + c Cx) / p or
*  Oy = (a Ay + b By + c Cy) / p
*
***************************************************************************/
double inCenterCord(double side1, double side2, double side3, double cord1, double cord2, double cord3, double Perimeter)
{
  //Ox = (a Ax + b Bx + c Cx) / p or Oy = (a Ay + b By + c Cy) / p
  return(((side1 * cord1) + (side2 * cord2) + (side3 * cord3)) / Perimeter);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inRediusLength
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double side1 // side length between points opposite point 1 (a)
*    2. double side2 // side length between points opposite point 2 (b)
*    3. double side3 // side length between points opposite point 3 (c)
*    4. double Perimeter //This is the perimeter of the triangle (2s)
*
*  Function Description: This function calculates the radius of the incenter circle
*  inside the triangle using r = K / s where s is the semi-perimeter, 1/2(a + b + c),
*  and K is Heron's Formula which is K = sqrt(s(s - a)(s - b)(s - c))
*
***************************************************************************/
double inRadiusLength(double side1, double side2, double side3, double Perimeter)
{
  double semiPerimeter; //The semi-perimeter used in Heron's Formula which is 1/2 the perimeter
  double HeronsVal; //This is the value K found in Heron's Formula
  
  semiPerimeter = Perimeter / 2; // 1/2(a + b + c)

  //K = sqrt(s(s - a)(s - b)(s - c))
  HeronsVal = sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3));

  return(HeronsVal / semiPerimeter); //r = K / s

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getAngle
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double length //length between the desired angle and the inCenter point
*    2. double inRadius //Length of the inRadius
*
*  Function Description: This function uses trigonmetry to calculate an internal
*  angle of a triangle using the inRadius and the length between the inCenter and
*  the desired angle
*
***************************************************************************/
double getAngle(double length, double inRadius)
{
  return(2 * (asin(inRadius / length)) * (180 / M_PI)); // finds the angle of the each of the major points (A,B,C) on the triangle 
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getArea
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double length //length between the desired angle and the inCenter point
*    2. double inRadius //Length of the inRadius
*    3. double angle //The angle corresponding to the desired section (A, B, or C)
*
*  Function Description: This function calculates the area of 2 identical right triangles
*  in each area section in order to find the total area of the section
*
***************************************************************************/
double getArea(double length, double inRadius, double angle)
{
  return(inRadius * length * sin(M_PI * (90 - (angle / 2)) / 180)); //finds the area of each of the smaller triangles in the large triangle by using the angle 
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double angleA
*    2. double angleB
*    3. double angleC
*    4. double areaA
*    5. double areaB
*    6. double areaC
*  Function Description: This function outputs the vairables that we found and declared earlier in the code 
***************************************************************************/

void output(double angleA, double angleB, double angleC, double areaA, double areaB, double areaC)
{
  double minsA; // minuets vairable A
  double secsA; // seconds vairable A
  double minsB; // minuets vairable B
  double secsB; // seconds vairable B
  double minsC; // minuets vairable C 
  double secsC; // seconds vairable C

  //Use to remove extra decimals due to floating point error round
  angleA = (int)(angleA * 1000000 + .5);
  angleA = (double) angleA / 1000000;
  angleB = (int)(angleB * 1000000 + .5);
  angleB = (double) angleB / 1000000;
  angleC = (int)(angleC * 1000000 + .5);
  angleC = (double) angleC / 1000000;

  // conversion of the a output to minuets 
  minsA = ((angleA - (int)angleA) * 60); // conversion of the a output to minutes
  secsA = ((minsA - (int)(minsA)) * 60); // conversion of the a output to seconds 
  minsB = ((angleB - (int)angleB) * 60); // conversion of the b output to minuets 
  secsB = ((minsB - (int)(minsB)) * 60); // conversion of the b output to seconds 
  minsC = ((angleC - (int)angleC) * 60); // conversion of the c output to minuets 
  secsC = ((minsC - (int)(minsC)) * 60); // conversion of the c output to seconds
  
  printf("Internal triangle angles: %d° %d\' %.2lf\", %d° %d\' %.2lf\", %d° %d\' %.2lf\"", (int)angleA, (int)minsA, secsA, (int)angleB, (int)minsB, secsB, (int)angleC, (int)minsC, secsC);
  printf("\nArea of quadrilaterals: %.2lf, %.2lf, %.2lf\n",areaA, areaB, areaC);
} 