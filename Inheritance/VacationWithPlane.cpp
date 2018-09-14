//*****************************************************************
// IMPLEMENTATION FILE (VacationWithPlane.cpp)
// This file implements the VacationWithPlane member functions
//*****************************************************************
#include <iostream>
#include <string>
#include "Vacation.h"
#include "VacationWithPlane.h" 
using namespace std;


  VacationWithPlane::VacationWithPlane() {
      airline = "" ; 
      airfare = 0; 
  }
  
  /* VacationWithPlane: sets the values for each parameter
   * parameters: string
   *             string
   *             int
   *             int
   *             double
   *             string
   *             double
   * return value: n/a
   */
  
VacationWithPlane::VacationWithPlane(string d, string h, int np, int nn, double pn, string aline, double afair) : Vacation (d, h, np, nn, pn) {     
      airline = aline; 
      airfare = afair;
  }
  
  /* getAirline: returns airline string
   * parameters: n/a
   * return value: string airline
   */
  string VacationWithPlane::getAirline() { 
      return airline; 
  }

  /* getAirfare: returns airfare value
   * parameters: n/a
   * return value: double airfare
   */
  double VacationWithPlane::getAirfare() { 
      return airfare; 
  }
  
  /* totalCost: returns total cost of trip
   * with airfare
   * parameters: n/a
   * return value: double total cost
   */
 double VacationWithPlane::totalCost() {
   return (getNights() * getPerNight()) + (getAirfare() * getPeople());    
  }
  
  /* perPersonCost: returns cost per person
   * parameters: n/a
   * return value: double per person cost
   */
  double VacationWithPlane::perPersonCost() { 
    return (totalCost()/getPeople()); 
  }
