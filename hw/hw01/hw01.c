
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. jferlazz@purdue.edu
*
*  Homework #: 1
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Friday, 2:30pm, HAMP 3144
*
*  Program Description:
*  
*  The user enters the the mass of a gilder and airplane in kg and the
*  forward thrust produced by the propellers in N. This program then 
*  calculates the resulting tension on the cable conneting the two aircraft
*  and the acceleration of the glider
*
***************************************************************************/
#include <stdio.h>

int main(void) 
{
  //Local Declaration
  double airMass; //mass of the airplace in Kg
  double gliderMass; //mass of the glider in Kg
  double propForce; //Force produced by the propeller in N
  double cableTens; //The resulting tension force on the cable in N
  double accGlider; //The resulting acceleration of the glider in m/s^2
  
  //Executable Statements
  printf("Enter mass of airplane (kg) -> ");
  scanf("%lf", &airMass);
  printf("Enter mass of glider (kg) -> ");
  scanf("%lf", &gliderMass);
  printf("Enter the force produced by propellers (N) -> ");
  scanf("%lf", &propForce);
  //Using Newtons second law Force = Mass * Acceleration the gliders
  //acceleration and the cables tension can be found
  accGlider = propForce / (airMass + gliderMass); //a = F / total mass
  cableTens = gliderMass * accGlider; //F = mass of the glider * acceleration
  printf("\nResulting tension: %.2lf Newtons\n", cableTens);
  printf("Acceleration of glider: %.2lf m/s^2\n", accGlider);
  
  return 0;
}

