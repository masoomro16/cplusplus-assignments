//**************************************************************
// SPECIFICATION FILE (Vacation.h)
// This file gives the specification of the Vacation abstract 
// data type.
//*****************************************************************
#ifndef VACATION_H
#define VACATION_H
 
#include <iostream>
#include <string>
using namespace std;
/*
 * VacationWithPlane: this is the base class, which includes
 * hotel name, destination, number of people, number of nights
 * and cost per night
 * Constructors: Vacation () 
 *               Vacation(string, string, int, int, double)
 * Protected members: destination
 *                    hotel
 *                    numPeople
 *                    numNights
 *                    perNight
 */

class Vacation
{
protected:
    string destination; 
    string hotel; 
    int numPeople;
    int numNights;
    double perNight;
 
 public:
  Vacation();
  // Default constructor
  // Post: dollars, cents have been set to blanks
  Vacation(string, string, int, int, double);
  // Parameterized constructor
  // Post: Data fields have been set to parameters

  string getDestination();
  // Post: Return value is the city name

  string getHotel();
  // Post: Return value is the hotel name
  
  int getPeople(); 
  // Post: Return value is the number of people

  int getNights(); 
  // Post: Return value is the number of nights

  double getPerNight();
  // Post: Return value is the cost per night

  double totalCost(); 
  // Post: return value is the total cost of the trip
  
  double perPersonCost();
  // Post: return value is the cost per person
};

#endif // VACATION_H
