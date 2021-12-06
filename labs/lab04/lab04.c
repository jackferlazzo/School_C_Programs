/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. jferlazz@purdue.edu
*  2. armst100@purdue.edu
*  3. oakinley@purdue.edu
*
*  Lab #: 4
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
*  This program calculates the side lengths of a triangle formed by 3 x-y coordinates  *  given by the user, as well as the location of the incenter between these points.
*
***************************************************************************/
#include <stdio.h>
#include <math.h>

//Global Declarations 
int inputX1(void); //input 1
int inputY1(void); //input 2
int inputX2(void); //input 3
int inputY2(void); //input 4
int inputX3(void); //input 5
int inputY3(void); //input 6 
void output(double,double,double,double,double); //Output 
double calcDistance(int,int,int,int); //General function to calculate distance 
double inCenterPoint(double,double,double,int,int,int); //General function to calculate both in centers 

int main(void) // Main function 
{
  //Local Declarations
  
  int xPoint1; //point 1 x-value
  int xPoint2; //point 2 x-value 
  int xPoint3; //point 3 x-value
  int yPoint1; //point 1 y-value
  int yPoint2; //point 2 y-value
  int yPoint3; //point 3 y-value
  
  double distanceOneTwo; //distance between point 1 and 2
  double distanceTwoThree; //distance between point 2 and 3 
  double distanceThreeOne;  //distance between point 3 and 1
  
  double inCenterX; //x-value of the incenter point
  double inCenterY; //y-value of the incenter point 
  //Executable Statements
  
  xPoint1 = inputX1(); // relate x1 to input x1 
  yPoint1 = inputY1(); // relate y1 to input y2 
  xPoint2 = inputX2(); // relate x2 to input x2 
  yPoint2 = inputY2(); // relate y2 to input y2 
  xPoint3 = inputX3(); // relate x3 to input x3
  yPoint3 = inputY3(); // relate y3 to input y3 

  // Calculation of distances between each point
  distanceOneTwo = calcDistance(xPoint1,xPoint2,yPoint1,yPoint2);
  distanceTwoThree = calcDistance(xPoint2,xPoint3,yPoint2,yPoint3);
  distanceThreeOne = calcDistance(xPoint3,xPoint1,yPoint3,yPoint1);
  
  //Calculation of each incenter point 
  inCenterX = inCenterPoint(distanceTwoThree, distanceThreeOne, distanceOneTwo, xPoint1, xPoint2, xPoint3);
  inCenterY = inCenterPoint(distanceTwoThree, distanceThreeOne, distanceOneTwo, yPoint1, yPoint2, yPoint3);

  //Outputs desired values
  output(distanceOneTwo,distanceTwoThree,distanceThreeOne,inCenterX, inCenterY);
  return (0);
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputX1
*
*  Function Return Type: Int
*
*  Parameters (list data type, name, and comment one per line):
*    1. NA
*
*  Function Description: This function takes input on point 1's x-value and
*  returns this input
*
***************************************************************************/

int inputX1()
{
  int xPoint1; //user input for x value of point 1
  printf("Enter X coordinate #1 -> ");
  scanf("%d", &xPoint1);
  return(xPoint1);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputX2
*
*  Function Return Type: Int
*
*  Parameters (list data type, name, and comment one per line):
*    1. NA
*
*  Function Description: This function takes input on point 2's x-value and
*  returns this input
*
***************************************************************************/

int inputX2()
{
  int xPoint2; //user iput for x value of point 2
  printf("Enter X coordinate #2 -> ");
  scanf("%d", &xPoint2);
  return(xPoint2);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputX3
*
*  Function Return Type: Int
*
*  Parameters (list data type, name, and comment one per line):
*    1. NA
*
*  Function Description: This function takes input on point 3's x-value and
*  returns this input
*
***************************************************************************/

int inputX3()
{
  int xPoint3; //user input for x value of point 3
  printf("Enter X coordinate #3 -> ");
  scanf("%d", &xPoint3);
  return(xPoint3);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputY1
*
*  Function Return Type: Int
*
*  Parameters (list data type, name, and comment one per line):
*    1. NA
*
*  Function Description: This function takes input on point 1's y-value and
*  returns this input
*
***************************************************************************/

int inputY1()
{
  int yPoint1; //user input for y value of point 1
  printf("Enter Y coordinate #1 -> ");
  scanf("%d", &yPoint1);
  return(yPoint1);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputY2
*
*  Function Return Type: Int
*
*  Parameters (list data type, name, and comment one per line):
*    1. NA
*
*  Function Description: This function takes input on point 2's y-value and
*  returns this input
*
***************************************************************************/

int inputY2()
{
  int yPoint2; // user input for y value of point 2
  printf("Enter Y coordinate #2 -> ");
  scanf("%d", &yPoint2);
  return(yPoint2);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputY3
*
*  Function Return Type: Int
*
*  Parameters (list data type, name, and comment one per line):
*    1. NA
*
*  Function Description: This function takes input on point 3's y-value and
*  returns this input
*
***************************************************************************/

int inputY3()
{
  int yPoint3; // user input for y value of point 3
  printf("Enter Y coordinate #3 -> ");
  scanf("%d", &yPoint3);
  return(yPoint3);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcDistance
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int x1 this is the x value of the first point
*    2. int x2 this is the x value of the second point
*    3. int y1 this is the y value of the first point
*    4. int y2 this is the y value of the first point
*
*  Function Description: This function uses the distance formula to calculate
*  the distance between to sent in points and return this calculated value as
*  a double
*
***************************************************************************/

double calcDistance(int x1, int x2, int y1, int y2)
{
  return(sqrt(pow(x2 - x1, 2) + pow(y2 - y1,2)));
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inCenterPoint
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1. double sideOpp1 this is the length of the side oppisite point 1 so the 
*         distance between point 2 to 3
*    2. double sideOpp2 this is the length of the side oppisite point 2 so the 
*         distance between point 3 to 1
*    3. double sideOpp3 this is the length of the side oppisite point 1 so the 
*         distance between point 1 to 2
*    4. int coordinate1 this is the coordinate of point 1 whether it be the x or y 
*         coordinate
*    5. int coordinate2 this is the coordinate of point 2 whether it be the x or y 
*         coordinate
*    6. int coordinate3 this is the coordinate of point 3 whether it be the x or y 
*         coordinate
*
*  Function Description: This function calculates either the x or y cooridinate of the 
*  circle's incenter depending whether x coordinates or y coordinates are sent in. 
*  To calculate the incenter coordinate the formula
*  ((ax1 + bx2 + cx3) / (a + b + c), (ay1 + by2 + cy3) / (a + b + c)) was used, 
*  a being sideOpp1, b being sideOpp2,*  c being sideOpp3, x1 and y1 being coordinate 1,
*  x2 and y2 being coordinate 2, and x3 and y3 being coordinate 3,
*
***************************************************************************/

double inCenterPoint(double sideOpp1, double sideOpp2, double sideOpp3, int coordinate1, int coordinate2,int coordinate3)
{
  double sumOfSides = sideOpp1 + sideOpp2 + sideOpp3; //sum of all side lengths
  double topEvaluation = ((sideOpp1 * coordinate1) + (sideOpp2 * coordinate2) + (sideOpp3 * coordinate3)); //ax1 + bx2 + cx3 or ay1 + by2 + cy3
  return(topEvaluation / sumOfSides); //finishes off formula
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inCenterPoint
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double distanceOneTwo this is the distance between point 1 and 2
*    2. double distanceTwoThree this is the distance between point 2 and 3
*    3. double distanceThreeOne this is the distance between point 3 and 1
*    4. double inCenterX this is the x coorinate of the incenter point
*    5. double inCenterY this is the y coorinate of the incenter point
*
*  Function Description: This function outputs the desired values as specified 
*  in the lab
*
***************************************************************************/
void output(double distanceOneTwo, double distanceTwoThree,double distanceThreeOne,double inCenterX, double inCenterY)
{
  printf("\nDistance from point 1 to point 2: %.2lf",distanceOneTwo);
  printf("\nDistance from point 2 to point 3: %.2lf",distanceTwoThree);
  printf("\nDistance from point 3 to point 1: %.2lf",distanceThreeOne);
  printf("\nLocation of incenter: %.2lf, %.2lf\n", inCenterX, inCenterY);
}