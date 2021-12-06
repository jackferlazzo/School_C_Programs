/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. jferlazz@purdue.edu
*  2. armst100@purdue.edu
*  3. oakinley@purdue.edu
*
*  Lab #: 6
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
*  This program calculates the orthocenter, circumcenter, the nine point circle center
*  of a triangle created by 3 user entered points. It then determines whether or not the
*  nine point circle is inside or outside the triangle by comparing triangle areas
*
***************************************************************************/
#include <stdio.h>
#include <math.h>

//Global Decloration
double input(int, int); //input function

double orthoCenter_x(double, double, double, double, double, double); //Calculates x-coordinate of orthocenter

double orthoCenter_y(double, double, double, double, double, double, double); //Calculates y-coordinate of orthocenter

double average(double, double); // takes the average of two values

//finds the center point of a circle using 3 points on the circle and results are passed by address
void getCircleCenters(double, double, double, double, double, double, double *, double *); 

double tri_area (double, double, double, double, double, double); //Calculates area of triangle with three defined points

int insideTriangle(double, double, double, double); //If statement checking points inside the triangle or not 

void output(double, double, double, double, double, double, int); //Output function that displays coordinates of orthocenter, circumcenter, and nine-point circle center. Also displays whether nine-point circle center is outside the user input triangle.

int main(void) 
{
  //Local Declaration 
  
  double xCord1; //x-cooridate of point 1
  double yCord1; //y-cooridate of point 1
  double xCord2; //x-cooridate of point 2
  double yCord2; //y-cooridate of point 2
  double xCord3; //x-cooridate of point 30
  double yCord3; //y-cooridate of point 3
  double circumX; //X-coordinate of the circumcenter
  double circumY; //Y-coordinate of the circumcenter
  double ninePointCenterX; //X-coordinate of the nine point circle
  double ninePointCenterY; //X-coordinate of the nine point circle
  double orthx; //X-coordinate of the orthocenter
  double orthy; //Y-coordinate of the orthocenter
  double altx1; //X-coordinate of midpoint between coordinate 1 and orthocenter
  double alty1; //Y-coordinate of midpoint between coordinate 1 and orthocenter
  double altx2; //X-coordinate of midpoint between coordinate 2 and orthocenter
  double alty2; //Y-coordinate of midpoint between coordinate 2 and orthocenter
  double altx3; //X-coordinate of midpoint between coordinate 3 and orthocenter
  double alty3; //Y-coordinate of midpoint between coordinate 3 and orthocenter
  double tri_AB; //Area of triangle formed by points coordinates 1, 2, and nine point circle center
  double tri_BC; //Area of triangle formed by points coordinates 2, 3, and nine point circle center
  double tri_CA; //Area of triangle formed by points coordinates 1, 3, and nine point circle center
  double tri_ABC; //Area of triangle formed by points 1, 2, and 3
  int inside; //variable to determine if the nine point circle is inside the triangle
  
  //Executable Statements
  xCord1 = input('x', 1); //Input of the coordinate x1 point 
  yCord1 = input('y', 1); //Input of the cooridate y1 point
  xCord2 = input('x', 2); //Input of the coordinate x2 point
  yCord2 = input('y', 2); //Input of the coordinate y2 point 
  xCord3 = input('x', 3); //Input of the coordinate x3 point
  yCord3 = input('y', 3); //Input of the coordinate y3 point

  //x and y coordinates of the orthocenter of the triangle formed by 3 points
  orthx = orthoCenter_x(xCord1, yCord1, xCord2, yCord2, xCord3, yCord3);
  orthy = orthoCenter_y(orthx, xCord1, yCord1, xCord2, yCord2, xCord3, yCord3);
  
  //x and y coordinates of the midpoints between each vertext and the orthocenter (along triangle altitudes)
  altx1 = average(xCord1, orthx);
  alty1 = average(yCord1, orthy);
  altx2 = average(xCord2, orthx);
  alty2 = average(yCord2, orthy);
  altx3 = average(xCord3, orthx);
  alty3 = average(yCord3, orthy);
  
  //Finds Circumcenter Points
  getCircleCenters(xCord1, xCord2, xCord3, yCord1, yCord2, yCord3, &circumX, &circumY);

  //Finds center of the nine point circle
  getCircleCenters(altx1, altx2, altx3, alty1, alty2, alty3, &ninePointCenterX, &ninePointCenterY);
  
  //Calculate areas of triangles formed by outer triangle points and nine point circle center
  tri_AB = tri_area(xCord1, yCord1, xCord2, yCord2, ninePointCenterX, ninePointCenterY);
  tri_BC = tri_area(xCord2, yCord2, xCord3, yCord3, ninePointCenterX, ninePointCenterY);
  tri_CA = tri_area(xCord3, yCord3, xCord1, yCord1, ninePointCenterX, ninePointCenterY);
  
  //Calculate area of main triangle from input points
  tri_ABC = tri_area(xCord1, yCord1, xCord2, yCord2, xCord3, yCord3);

  //Returns T/F whether nine point circle center is inside main triangle or outside
  inside = insideTriangle(tri_AB, tri_BC, tri_CA, tri_ABC);

  output(orthx, orthy, circumX, circumY, ninePointCenterX, ninePointCenterY, inside);

  return 0;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: input
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int desiredChar // This is the desired type of coorinate either x or y
*    2. int pointNum // This is the desired point number either point 1, 2, 3
*
*  Function Description: This function takes user input for a desired x or y coorinate
*  for either point 1 (A), 2 (B), or 3 (C)
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
*  the distance between the representing a side of the triangle using the center
*  formula distance = sqrt((X2 - X1)^2 + (Y2 - Y1)^2)
*
***************************************************************************/
double distance(double xCord1, double yCord1, double xCord2, double yCord2) //input of the coordinates to find the distance 
{
  //distance = sqrt((X2 - X1)^2 + (Y2 - Y1)^2)
  return(sqrt(pow(xCord2 - xCord1, 2) + pow(yCord2 - yCord1, 2))); 
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: orthoCenter_x
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double xCord1 // This x-coordinate of the 1st point
*    2. double yCord1 // This y-coordinate of the 1st point
*    3. double xCord2 // This x-coordinate of the 2nd point
*    4. double yCord2 // This y-coordinate of the 2nd point
*    5. double xCord3 // This x-coordinate of the 3rd point
*    6. double yCord3 // This y-coordinate of the 3rd point
*
*  Function Description: This function use of the inputs to calculate the x 
*  value of orthocenter
*
***************************************************************************/
double orthoCenter_x(double xCord1, double yCord1, double xCord2, double yCord2, double xCord3, double yCord3)
{
  double ortho_x; //x-coordinate of the orthocenter

  ortho_x = xCord3 * ((xCord1 - xCord2) / (yCord2 - yCord1)) - xCord1 * ((xCord2 - xCord3) / (yCord3 - yCord2)) + yCord1 - yCord3;

  ortho_x /= (xCord1 - xCord2) / (yCord2 - yCord1) - (xCord2 - xCord3) / (yCord3 - yCord2); // x orthocenter equation 

  return(ortho_x);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: orthoCenter_y
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double xCord1 // This x-coordinate of the 1st point
*    2. double yCord1 // This y-coordinate of the 1st point
*    3. double xCord2 // This x-coordinate of the 2nd point
*    4. double yCord2 // This y-coordinate of the 2nd point
*    5. double xCord3 // This x-coordinate of the 3rd point
*    6. double yCord3 // This y-coordinate of the 3rd point
*
*  Function Description: This function finds x coordinate of the orthocenter
*
***************************************************************************/
double orthoCenter_y(double ortho_x, double xCord1, double yCord1, double xCord2, double yCord2, double xCord3, double yCord3)
{
  double ortho_y; //y coordinate of the orthocenter

  ortho_y = ((xCord2 - xCord3) / (yCord3 - yCord2)) * (ortho_x - xCord1) + yCord1; // equation to find relating part 

  return(ortho_y);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: avergage
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double val1 // value of points to find the center point 
*    2. double val2 // value of points to find the center point 
*
*  
*  Function Description: This function find the average of two points to find the center point 
*
***************************************************************************/
double average(double val1, double val2)
{
  return((val1 + val2) / 2); //finds the average of the points 
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getCircleCenters
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double cordX1 // This x-coordinate of the 1st point
*    2. double cordX2 // This x-coordinate of the 2nd point
*    3. double cordX3 // This x-coordinate of the 3rd point
*    4. double cordY1 // This y-coordinate of the 1st point
*    5. double cordY2 // This y-coordinate of the 2nd point
*    6. double cordY3 // This y-coordinate of the 3rd point
*    7. double *centerX // x value of the circle center passed by address 
*    8. double *centerY // y value of the circle center passed by address 
*
*  Function Description: This function calculates the center of any circle given
*  3 points, using coordinates and the slopes between coordinates
*
***************************************************************************/
void getCircleCenters(double cordX1, double cordX2, double cordX3, double cordY1, double cordY2, double cordY3, double *centerX, double *centerY)
{
  double deltaY1; //distance between the 2nd and 1st y-cord
  double deltaX1; //distance between the 2nd and 1st x-cord
  double deltaY2; //distance between the 3rd and 2nd y-cord
  double deltaX2; //distance between the 3rd and 2nd x-cord
  double slope1; //slope between points 1 and 2
  double slope2; //slope between points 2 and 3
  
  //Calculates deltas
  deltaY1 = cordY2 - cordY1;
  deltaX1 = cordX2 - cordX1;
  deltaY2 = cordY3 - cordY2;
  deltaX2 = cordX3 - cordX2;
  
  //Calculates Slope
  slope1 = deltaY1 / deltaX1;
  slope2 = deltaY2 / deltaX2;

  //Calculates x point of the center, and passes it by address back to the called function 
  *centerX = (slope1 * slope2 * (cordY1 - cordY3) + slope2 * (cordX1 + cordX2) - slope1 * (cordX2 + cordX3));
  *centerX /= (2 * (slope2 - slope1));
  //Calculates y point of the center, and passes it by address back to the called function 
  *centerY = -1 * (*centerX - (cordX1 + cordX2) / 2) / slope1 + (cordY1 + cordY2) / 2;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: tri_area
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double xCord1// This x-coordinate of the 1st point
*    2. double yCord1// This y-coordinate of the 1st point
*    3. double xCord2// This x-coordinate of the 2nd point
*    4. double yCord2// This y-coordinate of the 2nd point
*    5. double xCord3// This x-coordinate of the 3rd point
*    6. double yCord3// This y-coordinate of the 3rd point
*
*  Function Description: This function calculates the area of a triangle formed by three input coordinates.
*
***************************************************************************/
double tri_area (double xCord1, double yCord1, double xCord2, double yCord2, double xCord3, double yCord3) 
{
  double area; //area of the triangle
  
  area = (xCord1 * (yCord2 - yCord3) + xCord2 * (yCord3 - yCord1) + xCord3 * (yCord1 - yCord2)) / 2;
  
  return(fabs(area)); //ensures the area is positive
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: insideTriangle
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. double tri_AB // side length AB of triangle 
*    2. double tri_BC // side length BC of triangle
*    3. double tri_CA //side length CA of triangle
*    4. double tri_ABC // side lenght of the triangle ABC
*
*  Function Description: This function find whether the nine point circle
*  is inside the triangle (returning a 1) or outside (returning a 0)
*
***************************************************************************/
int insideTriangle(double tri_AB, double tri_BC, double tri_CA, double tri_ABC)
{
  double sum; //sum of 3 smaller triangles
  int insideValue; //value return (1 if inside the triangle 0 if not)
  
  sum = tri_AB + tri_BC + tri_CA;
  
  if (sum <= tri_ABC + .001 && sum >= tri_ABC - .001) //thereshold of .001
  {
    insideValue = 1;
  }
  else
  {
    insideValue = 0;
  }
  return(insideValue);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double orthx // orthocenter of x 
*    2. double orthy // orthocenter of y 
*    3. double circumX //circumcenter of x 
*    4. double circumY //circumcenter of y
*    5. double ninePointCenterX // the nine point of the center for x 
*    6. double ninePointCenterY // the nine point of the center for y
*    7. int inside // the area of the triangle in relation to being in or out 
*
*  Function Description: Outputs the desired values as outlined by the lab
*
***************************************************************************/
void output(double orthx, double orthy, double circumX, double circumY, double ninePointCenterX, double ninePointCenterY, int inside)
{
  printf("\nCoordinates of orthocenter: %.2lf, %.2lf\n", orthx, orthy);
  printf("Coordinates of circumcenter: %.2lf, %.2lf\n", circumX, circumY);
  if(inside == 1)
  {
    printf("The nine point circle center: %.2lf, %.2lf is inside of the triangle.\n", ninePointCenterX, ninePointCenterY);
  }
  else
  {
    printf("The nine point circle center: %.2lf, %.2lf is outside of the triangle.\n", ninePointCenterX, ninePointCenterY);
  }
}
