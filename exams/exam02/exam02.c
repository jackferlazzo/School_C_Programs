/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. jferlazz@purdue.edu
*
*  Lab #: Exam 2
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
*  The user enters 3 desired point for a triangle, and the program calculates the coordinates of
*  the triangles's orthocenter, the internal angles of the internal triangle with the largest outside
*  side length, and the triangle type (equilateral, isosceles, or scalene) and angle type (acute, right or obtuse)
*  of said inter triangle
*  
***************************************************************************/

#include <stdio.h>
#include <math.h>

double inputXCord(int); //xCord input function
double inputYCord(void); //yCord input function
double orthoCenter(double, double, double, double, double, double); //Calculates x or y-coordinate of orthocenter
double distance(double, double, double, double); //Calculates the distance between points
double findAngle(double, double, double); //Finds an angle of the triangle using vector math
void insideCords(double, double, double, double, double, double, double, double, double, double*, double*, double*, double*); //finds the cords of the largest internal triangle
int sideType(double, double, double); //checks for side type of the triangle 1 for equilateral, 2 for isosceles, 3 for scalene
int angleType(double); //checks for the angle type of the triangle, 1 for acute, 2 for right, and 3 for obtuse using the largest angle
void output(double, double, double, double, double); //Outputs desired values as outlined in the lab

int main(void) 
{
  //Local Declaration
  double xCord1; //x coordinate of the first point
  double yCord1; //y coordinate of the first point
  double xCord2; //x coordinate of the second point
  double yCord2; //y coordinate of the second point
  double xCord3; //x coordinate of the third point
  double yCord3; //y coordinate of the third point
  double orthx; //X-coordinate of the orthocenter
  double orthy; //Y-coordinate of the orthocenter
  double side1; //Triangle side oppisite point 1
  double side2; //Triangle side oppisite point 2
  double side3; //Triangle side oppisite point 3
  double angleA; //finds the angle at point 1 (outside triange)
  double angleB; //finds the angle at point 2 (outside triange)
  double angleC; //finds the angle at point 3 (outside triange)
  double inAngleA; //finds the angle at point 1 (inside triangle)
  double inAngleB; //finds the angle at point 2 (inside triangle)
  double inAngleC; //finds the angle at point 3 (inside triangle)
  double insideSide1; //The first side of the inside triange
  double insideSide2; //The second side of the inside triange
  double insideSide3; //The third side of the inside triange
  double insideX2; //The x component of the 2nd point of the inside triange
  double insideX3; //The x component of the 3rd point of the inside triange
  double insideY2; //The y component of the 2nd point of the inside triange
  double insideY3; //The y component of the 3rd point of the inside triange

  //Executable Statements

  //User Inputs
  xCord1 = inputXCord(1);
  yCord1 = inputYCord();
  xCord2 = inputXCord(2);
  yCord2 = inputYCord();
  xCord3 = inputXCord(3);
  yCord3 = inputYCord();

  //Calculates the length of the triangle's outside sides
  side1 = distance(xCord2, yCord2, xCord3, yCord3); 
  side2 = distance(xCord1, yCord1, xCord3, yCord3);
  side3 = distance(xCord1, yCord1, xCord2, yCord2);

  //Calculates the angles of the outside triangle
  angleA = findAngle(side2, side3, side1);
  angleB = findAngle(side3, side1, side2);
  angleC = findAngle(side1, side2, side3);

  //Calcalutes the orthocenter of the triangle
  orthx = orthoCenter(xCord1, xCord2, xCord3, angleA, angleB, angleC);
  orthy = orthoCenter(yCord1, yCord2, yCord3, angleA, angleB, angleC);

  //Finds the coordinates of the largest inside triangle
  insideCords(side1, side2, side3, xCord1, xCord2, xCord3, yCord1, yCord2, yCord3, &insideX2, &insideX3, &insideY2, &insideY3);
  
  //Calculates the length of each side of the inside triangle using the inside coordinates and the orthocenter
  insideSide1 = distance(insideX2, insideY2, insideX3, insideY3);
  insideSide2 = distance(orthx, orthy, insideX3, insideY3);
  insideSide3 = distance(orthx, orthy, insideX2, insideY2);

  //Calculates each angle of the inside triangle
  inAngleA = findAngle(insideSide2, insideSide3, insideSide1);
  inAngleB = findAngle(insideSide3, insideSide1, insideSide2);
  inAngleC = findAngle(insideSide1, insideSide2, insideSide3);
  
  //Outputs calculated values as outlined in the lab
  output(inAngleA, inAngleB, inAngleC, orthx, orthy);

  return 0;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputXCord
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int number the point number (like 1 for point 1)
*
*  Function Description: This function prompts the user and allows the user 
*  to input the desired x-coordinate
*
***************************************************************************/
double inputXCord(int number)
{
  double xCord; //user input for the xCord
  
  //prints a statement to prompts for the year number
  printf("Enter point #%d -> ", number);
  scanf("%lf ", &xCord);
  
  return(xCord);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputYCord
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. NA
*
*  Function Description: This function allows the user 
*  to input the desired y-coordinate
*
***************************************************************************/
double inputYCord()
{
  double yCord; //user input for the yCord
  
  //scans the 2nd number for yCord on the same line so no prompt print statement is needed
  scanf("%lf", &yCord);
  
  return(yCord);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: orthoCenter
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double cord1 This coordinate of the 1st point
*    2. double cord2 This coordinate of the 2nd point
*    3. double cord3 This coordinate of the 3rd point
*    4. double angleA The first angle of the triangle
*    5. double angleB The second angle of the triangle
*    6. double angleC The third angle of the triangle
*
*  Function Description: This function calculates a coordinate value of orthocenter 
*  either x or y
*  Formula: x = (x1 * tan(A) + x2 * tan(B) + x3 * tan(C)) / (tan(A) + tan(B) + tan(C))
*  x can be interchanged with y for the y varient
*
***************************************************************************/
double orthoCenter(double cord1, double cord2, double cord3, double angleA, double angleB, double angleC)
{
  double val1; //(x1 * tan(A) + x2 * tan(B) + x3 * tan(C)) (can be interchanged with y)
  double val2; //(tan(A) + tan(B) + tan(C)) (can be interchanged with y)

  //Use (M_PI / 180) to convert from degrees to radian to use in tan function
  val1 = cord1 * tan(angleA * (M_PI / 180)) + cord2 * tan(angleB * (M_PI / 180)) + cord3 * tan(angleC * (M_PI / 180));
  val2 = tan(angleA * (M_PI / 180)) + tan(angleB * (M_PI / 180)) + tan(angleC * (M_PI / 180)); 
  return(val1 / val2);
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
*  Name of Function: findAngle
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double sideA length of the 1st side
*    2. double sideB length of the 2nd side
*    3. double sideC length of the 3rd side
*
*  Function Description: This function finds an angle of the triangle using the law of cosines
*  Formulas: C = cos-1((a^2 + b^2 - c^2) / (2ab)), A = cos-1((b^2 + c^2 - a^2) / (2bc))
*  B = cos-1((c^2 + a^2 - b^2) / (2ca))
***************************************************************************/
double findAngle(double sideA, double sideB, double sideC)
{
  //180 / M_PI converts radian output to degrees
  return((180 / M_PI) * acos((sideA * sideA + sideB * sideB - (sideC * sideC)) / (2.0 * sideA * sideB)));
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: insideCords
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double side1 length of the 1st side
*    2. double side2 length of the 2nd side
*    3. double side3 length of the 3rd side
*    4. double xCord1 user enter x coordinate of the 1st point
*    5. double xCord2 user enter x coordinate of the 2nd point
*    6. double xCord3 user enter x coordinate of the 3rd point
*    7. double yCord1 user enter y coordinate of the 1st point
*    8. double yCord2 user enter y coordinate of the 2nd point
*    9. double yCord3 user enter y coordinate of the 3rd point
*    10. double *insideX2 x component of the 2nd point of the inside triangle passed by address
*    11. double *insideX3 x component of the 3rd point of the inside triangle passed by address
*    12. double *insideY2 y component of the 2nd point of the inside triangle passed by address
*    13. double *insideY3 y component of the 3rd point of the inside triangle passed by address
*
*  Function Description: This function finds the coordinates of the inside triangle by checking
*  which inner triangle has the largest outside side and sets the appropriate values to the inside
*  triangle coordinates
***************************************************************************/
void insideCords(double side1, double side2, double side3, double xCord1, double xCord2, double xCord3, double yCord1, double yCord2, double yCord3, double *insideX2, double *insideX3, double *insideY2, double *insideY3)
{
  //if side 1 is largest
  if (side1 >= side3 && side1 >= side2)
  {
    *insideX2 = xCord2;
    *insideX3 = xCord3;
    *insideY2 = yCord2;
    *insideY3 = yCord3;
  }
  //if side 2 is largest
  else if (side2 >= side3)
  {
    *insideX2 = xCord1;
    *insideX3 = xCord3;
    *insideY2 = yCord1;
    *insideY3 = yCord3;
  }
  else //if side 3 is the largest
  {
    *insideX2 = xCord1;
    *insideX3 = xCord2;
    *insideY2 = yCord1;
    *insideY3 = yCord2;
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: sideType
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. double angleA the 1st angle of the triangle
*    2. double angleB the 2nd angle of the triangle
*    3. double angleC the 3rd angle of the triangle
*
*  Function Description: This function determines what type of triangle a triangle is given
*  that triangle's passed in angle values, 1 is return for an equilateral, 2 for an isosceles, 
*  3 for scalene
* 
***************************************************************************/
int sideType(double angleA, double angleB, double angleC)
{
  int triangleType; //type of triangle that is returned 1 for equilateral, 2 for isosceles, 3 for scalene
  if((angleA + .001 >= angleB && angleA - .001 <= angleB) && (angleC + .001 >= angleB && angleC - .001 <= angleB)) //Angles are all equal within an acceptable range
  {
    triangleType = 1;
  }
  else if((angleA + .001 >= angleB && angleA - .001 <= angleB) || (angleC + .001 >= angleB && angleC - .001 <= angleB) || (angleC + .001 >= angleA && angleC - .001 <= angleA))
  {
    triangleType = 2;
  }
  else
  {
    triangleType = 3;
  }
  
  return(triangleType);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: sideType
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. double maxAngle the largest angle of the triangle being evaluated
*
*  Function Description: This function determines what type of triangle a triangle is given
*  that triangle's passed in angle values, 1 is for acute (<90) , 2 for right (90), and
*  3 is for obtuse (>90)
* 
***************************************************************************/
int angleType(double maxAngle)
{
  int angleType; //type of angled triangle 1 for acute (<90), 2 for right (90), and 3 for obtuse (>90)
  if(maxAngle <= 90.001 && maxAngle >= 89.999) //right triangle using the error bound of .001
  {
    angleType = 2;
  }
  else if(maxAngle > 90) //obtuse
  {
    angleType = 3;
  }
  else //acute
  {
    angleType = 1;
  }
  return(angleType);
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
*    1. double angleA the first angle of the inside triangle
*    2. double angleB The second angle of the inside triangle
*    3. double angleC The third angle of the inside triangle
*    4. orthX the x component of the orthocenter
*    5. orthY the y component of the orthocenter
*
*  Function Description: This function outputs desided values using conditional statement in
*  the format outlined in the lab description
* 
***************************************************************************/
void output(double angleA, double angleB, double angleC, double orthX, double orthY)
{
  double maxAngle; //largest angle in the triangle used to check for angle type

  //To prevent the printing of -0.00 .001 error is applied to  orth coordinates
  if(orthX >= -.001 && orthX <= .001)
  {
    orthX = 0.0;
  }
  if(orthY >= -.001 && orthY <= .001)
  {
    orthY = 0.0;
  }

  printf("\nCoordinates or orthocenter: %.2lf, %.2lf", orthX, orthY);
  printf("\nInternal triangle angles: ");
  
  if(angleA <= angleB && angleA <= angleC) // A < B and A < C
  {
    printf("%.1lf, ", angleA);

    if(angleB <= angleC) //A < B < C
    {
      printf("%.1lf, %.1lf", angleB, angleC);
      maxAngle = angleC;
    }
    else // A < C < B
    {
      printf("%.1lf, %.1lf", angleC, angleB);
      maxAngle = angleB;
    }
  }
  else if (angleB <= angleA && angleB <= angleC) // B < A and B < C
  {
    printf("%.1lf, ", angleB);

    if(angleA <= angleC) // B < A < C
    {
      printf("%.1lf, %.1lf", angleA, angleC);
      maxAngle = angleC;
    }
    else // B < C < A
    {
      printf("%.1lf, %.1lf", angleC, angleA);
      maxAngle = angleA;
    }
  }
  else // C < A and C < b
  {
    printf("%.1lf, ", angleC);

    if(angleA <= angleB) // C < A < B
    {
      printf("%.1lf, %.1lf", angleA, angleB);
      maxAngle = angleB;
    }
    else // C < B < A
    {
      printf("%.1lf, %.1lf", angleB, angleA);
      maxAngle = angleA;
    }
  }

  printf("\nTriangle Type: ");

  switch(sideType(angleA, angleB, angleC))
  {
    case 1 : 
      printf("Equilateral ");
      break;
    case 2 :
      printf("Isosceles ");
      break;
    default :
      printf("Scalene ");
  }

  switch(angleType(maxAngle))
  {
    case 1 : 
      printf("acute");
      break;
    case 2 :
      printf("right");
      break;
    default :
      printf("obtuse");
  }
  printf("\n");
}
