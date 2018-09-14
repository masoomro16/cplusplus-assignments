/* 
 * Maira soomro, Section 1003, Assn 03
 * This program makes use of the concept of inheritance to 
 * create a program that calculates the total cost of a trip
 * depending on the number of nights, people and whether 
 * airfare is included or not. 
 * Input: trip destination, number of nights, people, hotel
 * name, airline and airfare
 * Output: calculated total cost of trip
 *
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "Vacation.h"
#include "VacationWithPlane.h" 
using namespace std;

int main () { 

  const int n = 20 ;    
    Vacation trip1("Las Vegas", "Mandalay Bay", 3, 6, 206.85); 
    VacationWithPlane trip2("Chicago", "Marriott", 2, 3, 199.99, "United Airlines", 274.13);     

    cout << "VACATION 1: " << endl
	 << "Vacation Type: " << "No Travel" <<  endl
	 << "Destination city: " << trip1.getDestination() << endl
	 << "Hotel name: " <<  trip1.getHotel()<< endl
	 << "Number of people: " << trip1.getPeople() << endl
	 << "Number of nights: " << trip1.getNights() << endl 
	 << "Price per night: " << "$"<< fixed << setprecision(2)<< trip1.getPerNight() << endl  
	 << "\nCost of vacation: "<< "$"  << trip1.totalCost() << endl
	 << "Cost per person: "<< "$" << trip1.perPersonCost() << endl; 
    
    cout << "\nVACATION 2: " << endl
	 << "Vacation Type: " << "With Plane" << endl
	 << "Destination city: " << trip2.getDestination() << endl
	 << "Hotel name: " << trip2.getHotel()<< endl
	 << "Number of people: " << trip2.getPeople() << endl
	 << "Number of nights: " << trip2.getNights() << endl
	 << "Price per night: " << "$" <<trip2.getPerNight() << endl
	 << "Airline: " << trip2.getAirline() << endl
	 << "Airfare: " << "$" << trip2.getAirfare() << endl
	 << "\nCost of Vacation: " << "$" << trip2.totalCost() <<  endl
	 << "Cost per person: " << "$" <<  trip2.perPersonCost() << endl;
    return 0; 
}
