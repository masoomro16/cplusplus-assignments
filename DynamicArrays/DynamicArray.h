//**************************************************************
// SPECIFICATION FILE (DynamicArray.h)
// This file gives the specification of the DynamicArray abstract 
// data type.
//*****************************************************************
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
 
#include <iostream>
#include <string>
using namespace std;
/*
 * Dynamic Array: this is the base class, which includes
 * hotel name, destination, number of people, number of nights
 * and cost per night
 * Constructors: DynamicArray () 
 *               DynamicArray(string, string, int, int, double)
 * Private members: arrayPtr
 *                  size
 *                  rangeMin
 *                  rangeMax
 */

class DynamicArray
{
private:
    int *arrayPtr; 
    int size; 
    int rangeMin;
    int rangeMax;
 
 public:
  DynamicArray();
  // Default constructor
  // Post: dollars, cents have been set to blanks
  
  DynamicArray(int, int, int);
  // Parameterized constructor
  // Post: Data fields have been set to parameters

 
  void Display();
  // Post: Displays all the data of the object

  
  void Minimum();
  // Post: Finds the minimum integer and its frequency in the 
  // object's array 
  
  void Maximum(); 
  // Post: Return value is the number of people

  void SwapElements(int a, int b); 
  // Post: Return value is the number of nights

 
  void SubArray(int a, int b);
  // Post: Return value is the cost per night

  
  void Concatenate(DynamicArray obj); 
  // Post: return value is the total cost of the trip



};
 
#endif // DYNAMICARRAY_H
