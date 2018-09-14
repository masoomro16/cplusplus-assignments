
//**************************************************************
// IMPLEMENTATION FILE (Vacation.cpp)
// This file gives the specification of the Vacation abstract 
// data type.
//*****************************************************************
 
#include <iostream>
#include <string>
#include "Vacation.h"

using namespace std;

  Vacation::Vacation() {
    destination = ""; 
    hotel = "";
    numPeople = 0; 
    numNights = 0; 
    perNight = 0; 
  }
  
  /* Vacation: sets the values for each parameter
   * parameters: string
   *             string
   *             int
   *             int
   *             double
   * return value: n/a
   */
  Vacation::Vacation(string d, string h, int np, int nn, double pn) { 
    destination = d; 
    hotel = h; 
    numPeople = np; 
    numNights = nn; 
    perNight = pn;   
  }

  /* getDestination: returns destination name
   * parameters: n/a
   * return value: string destination
   */
  string Vacation::getDestination(){ 
      return destination; 
  }

  /* getHotel: returns hotel name
   * parameters: n/a
   * return value: string hotel
   */
string Vacation::getHotel() { 
      return hotel; 
  }
 
  /* getPeople: returns number of people
   * parameters: n/a
   * return value: int
   */  
  int Vacation::getPeople(){ 
      return numPeople;
  } 
  
    /* getNights: returns number of nights
   * parameters: n/a
   * return value: int
   */
  int Vacation::getNights(){ 
      return numNights; 
  }
  
  /* getPerNight: returns nightly rate
   * parameters: n/a
   * return value: double
   */
  double Vacation::getPerNight(){ 
      return perNight;
  }
  
  /* totalCost: returns total cost of trip
   * parameters: n/a
   * return value: double
   */
  double Vacation::totalCost() { 
    return  numNights * perNight; 
  } 
  
  /* perPersonCost: returns cost per person
   * parameters: n/a
   * return value: double
   */  
double Vacation::perPersonCost()  { 
  return (numNights * perNight) / numPeople; 
}

