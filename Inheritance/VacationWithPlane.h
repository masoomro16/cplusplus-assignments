//**************************************************************
// SPECIFICATION FILE (VacationWithPlane.h)
// This file gives the specification of the Vacation abstract 
// data type.
//*****************************************************************
#ifndef VACATIONWITHPLANE_H
#define VACATIONWITHPLANE_H 

#include <iostream>
#include <string>
#include "Vacation.h"
using namespace std;

/*
 * VacationWithPlane: this is the derived class, which includes
 * the name of the airline and the airfare as well as calculates
 * the total cost of the trip with airfare
 * Constructors: VacationWithPlane () 
 *               VacationWithPlane(string, string, int, int
 *               double, string, double)
 * Private members: airline
 *                  airfare
 */
class VacationWithPlane : public Vacation
{
private:
    string airline; 
    double airfare;
    
public:
  VacationWithPlane();
  // Default constructor
  // Post: destination, hotel, number of people, number
  // of nights, cost per night are initialized
 VacationWithPlane(string, string, int, int, double, string, double);
  // Parameterized constructor
  // Post: Data fields have been set to parameters

  string getAirline();
  // Post: Return value is the airline name

  double getAirfare();
  // Post: Return value is this airfare amount
  
  double totalCost(); 
  // Post: Return value is the total cost of the
  // whole trip
  
  double perPersonCost(); 
  // Post: Return value is the total cost of the 
  // trip divided by the number of people on the
  // trip

};

#endif // VACATIONWITHPLANE_H
