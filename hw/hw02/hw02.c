/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. jferlazz@purdue.edu
*
*  Homework #: 2
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
*  The user enters the the mass of 2 gilders and airplane in kg and the
*  forward thrust produced by the propellers in N. This program then
*  calculates the resulting tension on the first and second cable
*  and the acceleration of the system
*
***************************************************************************/
#include <stdio.h>

int main(void) 
{
  //Local Declaration
  
  double airMass; //mass of the airplace in Kg
  double glider1Mass; //mass of the glider 1 in Kg
  double glider2Mass; //mass of the glider 2 in Kg
  double propForce; //Force produced by the propeller in N
  double cable1Tens; //The resulting tension force on cable 1 in N
  double cable2Tens; //The resulting tension force on cable 2 in N
  double acceleration; //The resulting acceleration of the glider in m/s^2

  //Executable Statements
  
  printf("Enter mass of airplane (kg) -> ");
  scanf("%lf", &airMass);
  printf("Enter mass of glider #1 (kg) -> ");
  scanf("%lf", &glider1Mass);
  printf("Enter mass of glider #2 (kg) -> ");
  scanf("%lf", &glider2Mass);
  printf("Enter force produced by propellers (N) -> ");
  scanf("%lf", &propForce);

  //Using Newtons second law Force = Mass * Acceleration the gliders
  //acceleration and the cables tension can be found
  acceleration = propForce / (airMass + glider1Mass + glider2Mass); //a = F / total mass
  cable2Tens = glider2Mass * acceleration; //F1 = mass of the glider * acceleration
  cable1Tens = (glider1Mass * acceleration) + cable2Tens; //F2 = (mass of the glider * acceleration) + Tension of the cable behind
  
  printf("\nAcceleration: %.2lf m/s^2\n", acceleration);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nResulting tension on cable #1:%11.2lf Newtons\n", cable1Tens);
  printf("Resulting tension on cable #2:%11.2lf Newtons\n", cable2Tens);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  
  return 0;
}
