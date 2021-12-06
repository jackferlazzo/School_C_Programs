/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. jferlazz@purdue.edu
*
*  Homework #: 3
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Friday, 2:30pm, HAMP 3144
*
*  Program Description:
*
*  This program takes user input on the initial height, velocity, and angle
*  (to the horizontal) of a projectile being launched and calculates the
*  the time it takes to reach maximum height, time to hit the ground, and
*  total distance traveled then outputs desired values a outlined in the
*  homework
*
***************************************************************************/
#include <stdio.h>
#include <math.h>

double inputHeight(void); //User inputs height
double inputVelocity(void); //User inputs Velocity
double inputAngle(void); //User inputs angle to horizontal
double calculateTimeMax(double, double); //Calculates the time it take to reach maximum height using kinematics
double calculateMaxHeight(double, double, double, double); //Calculates the maximum height using kinematics
double calculateTimeGround(double, double, double); //Calculates the time it take to reach the ground using kinematics and quadratic formula
double calculateDistance(double, double, double); //Calculates the distance traveled using kinematics
void output(double, double, double, double); //Outputs desired values

int main(void) 
{
  //Local Declaration

  double initialHeight; //initial height of the projectile
  double initialVelocity; //initial velocity of the projectile
  double angle; //angle to the horizontal of the projectile
  double timeMax; //time it takes to reach maximum height
  double maxHeight; //The maximum height the projectile reaches
  double timeGround; //time it takes to hit the ground
  double distance; //total distance traveled

  //Executable statements

  initialHeight = inputHeight();
  initialVelocity = inputVelocity();
  angle = inputAngle();
  
  timeMax = calculateTimeMax(initialVelocity, angle);
  maxHeight = calculateMaxHeight(initialVelocity, angle, timeMax, initialHeight);
  timeGround = calculateTimeGround(initialHeight, initialVelocity, angle);
  distance = calculateDistance(initialVelocity, angle, timeGround);
  
  output(timeMax, maxHeight, timeGround, distance);
  
  return 0;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputHeight
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. NA
*
*  Function Description: This function takes input on initial height
*
***************************************************************************/

double inputHeight()
{
  double height; //user input for height
  printf("Enter height of launch [m] -> ");
  scanf("%lf", &height);
  return(height);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputVelocity
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. NA
*
*  Function Description: This function takes input on initial velocity
*
***************************************************************************/

double inputVelocity()
{
  double velocity; //user input for velocity
  printf("Enter initial Velocity [m/s] -> ");
  scanf("%lf", &velocity);
  return(velocity);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputAngle
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. NA
*
*  Function Description: This function takes input on the projectile's
*  lanuch angle from the horizontal
*
***************************************************************************/

double inputAngle()
{
  double angle; //user input for the angle to the horizontal
  printf("Enter angle to the horizontal [degrees] -> ");
  scanf("%lf", &angle);
  return(angle);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calculateTimeMax
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double initialVelocity The user inputed initial velocity
*    2. double angle the user inputed angle of the projectile to horizontal
*
*  Function Description: This function uses the kinematic formula
*  tmax = V0 * sin(angle) / g to find the time it takes to reach maximum 
*  height
*
***************************************************************************/

double calculateTimeMax(double initialVelocity, double angle)
{
  //tmax = V0 * sin(angle) / g
  return((initialVelocity * sin((angle * M_PI) / 180) / 9.8)); 
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calculateMaxHeight
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double initialVelocity The user inputed initial velocity
*    2. double angle the user inputed angle of the projectile to horizontal
*    3. double timeMax the calculated time it takes to reach maximum height
*
*  Function Description: This function uses the kinematic formula
*  h = V0 * sin(angle) * tMax - .5 * g * (tmax)^2 + h0 to find the maximum 
*  height of the projectile
*
***************************************************************************/

double calculateMaxHeight(double initialVelocity, double angle, double timeMax, double initialHeight)
{
  double val1; //placeholder value 1 to sentment calculation
  double val2; //placeholder value 2 to sentment calculation

  //val1 = V0 * sin(angle) * tMax
  val1 = initialVelocity * sin((angle * M_PI) / 180) * timeMax;
  
  //val2 = - .5 * g * (tmax)^2
  val2 = -.5 * 9.8 * (timeMax * timeMax);

  //h = V0 * sin(angle) * tMax - .5 * g * (tmax)^2 + h0
  return(val1 + val2 + initialHeight);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calculateTimeGround
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double initialHeight the user inputed initial height
*    2. double initialVelocity The user inputed initial velocity
*    3. double angle the user inputed angle of the projectile to horizontal
*
*  Function Description: This function uses the kinematic formula
*  0 = h + V0 * sin(angle) * tGround - .5 * g * (tGround)^2 and the 
*  quadratic formulat x = (-b +/- sqrt(b^2 - 4ac)) / 2a (the subtraction 
*  not addition is used in this case) to factor and solve for tGround
*
***************************************************************************/

double calculateTimeGround(double initialHeight, double initialVelocity, double angle)
{
  double radical; //The placeholder value for the radical part of the quadratic formula

  //sqrt(b^2 - 4ac)
  radical = sqrt(pow((initialVelocity * sin(angle * M_PI / 180)),2) + 2 * 9.8 * initialHeight);

  //x = (-b - sqrt(b^2 - 4ac)) / 2a
  return((initialVelocity * sin(angle * M_PI / 180) + radical) / 9.8);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calculateDistance
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    2. double initialVelocity The user inputed initial velocity
*    3. double angle the user inputed angle of the projectile to horizontal
*    3. double timeGround the calculated value that is the time the 
*    projectile takes to hit the ground
*
*  Function Description: This function uses the kinematic formula
*  distance = V0 * cos(angle) * tGround to solve for the distance the
*  projectile went in the horizontal direction
*
***************************************************************************/

double calculateDistance(double initialVelocity, double angle, double timeGround)
{
  //distance = V0 * cos(angle) * tGround
  return(initialVelocity * cos(angle * M_PI / 180) * timeGround);
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
*    1. double timeMax the calculated time it takes to reach maximum height
*    2. double maxHeight the calculated maximum height the projectile reaches
*    3. double timeGround the calculated value that is the time the 
*    projectile takes to hit the ground
*
*  Function Description: This function outputs the desired calculated values
*  as outlined in the assignment
*
***************************************************************************/

void output(double timeMax, double maxHeight, double timeGround, double distance)
{
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Time to max height:%20.2lf s\n", timeMax);
  printf("Maximum height reached:%16.2lf m\n", maxHeight);
  printf("Time to hit ground:%20.2lf s\n", timeGround);
  printf("Total distance traveled:%15.2lf m\n", distance);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}
