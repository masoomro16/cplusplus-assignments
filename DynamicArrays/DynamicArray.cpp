//**************************************************************
// IMPLEMENTATION FILE (DynamicArray.cpp)
// This file gives the specification of the DynamicArray abstract 
// data type.
//*****************************************************************
 
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "DynamicArray.h"


using namespace std;

  DynamicArray::DynamicArray() {
    arrayPtr = new int[size];
    size = 1;
    rangeMin = 0; 
    rangeMax = 0; 

  }
  
  /* DynamicArray: sets the values for each parameter
   * parameters: int
   *             int
   *             int
   * return value: n/a
   */
DynamicArray::DynamicArray(int s, int min, int max) { 
    size = s; 
    arrayPtr = new int[size]; 
    rangeMin = min;
		      
    rangeMax = max;
    
    // srand(time(NULL));
    for (int i=0; i<size; i++)
      *(arrayPtr+i) = rand() % (rangeMax - rangeMin +1)+ rangeMin; 
  } 

  /* Display: displays all the data of the object
   * parameters: n/a
   * return value: n/a
   */ 
  void DynamicArray::Display(){ 
    for (int i=0; i<size; i++) { 
      cout << *(arrayPtr+i) << " "; 
    }

    cout << endl; 
  }

  /* Minimum: finds the minimum integer and its frequency 
   *          in the object's array
   * parameters: n/a
   * return value: n/a
   */ 
void DynamicArray::Minimum() { 
    
  int arrMin; 
  int count = 0; 

  // first loop to find minimum
  arrMin = *arrayPtr; // set first value to min 
    for (int i = 1; i<size; i++) { 
      if (arrMin > *(arrayPtr+i)) { // if first vaue is less than next value
	arrMin = *(arrayPtr+i); // set new value to min 
      }
    } 
    cout << "\nMinimum value in array = " << arrMin << endl; 
   
    // second loop to find frequency
    for (int j=0; j<size; j++) { 
      if (arrMin == *(arrayPtr+j)) // compare min with value
	count++; // increase count 
    } 
    cout << "Frequency of " << arrMin << " in array = " << count << endl; 
  } 
 
  /* Maximum: finds the maximum integer and its frequency in 
   * the object's array 
   * parameters: n/a
   * return value: n/a
   */ 
  void DynamicArray::Maximum(){ 
    int arrMax;
    int count = 0;

    // first loop to find minimum   
    arrMax = *arrayPtr;
    for (int i = 1; i<size; i++) {
      if (arrMax < *(arrayPtr+i)) {
        arrMax = *(arrayPtr+i);
      }
    }
    cout << "\nMaximum value in array = " << arrMax << endl;

    // second loop to find frequency
    for (int j=0; j<size; j++) {
      if (arrMax == *(arrayPtr+j))
        count++;
    }
    cout << "Frequency of " << arrMax << " in array = " << count << endl; 
  }  
  
  /* SwapElements: Swaps the ath and the bth elements of the
   *               object's array
   * parameters: int 
   *             int
   * return value: int
   */ 
  void DynamicArray::SwapElements(int a, int b){ 
    int temp; 
    a = a-1; 
    b = b-1; 
    // a-1 and b-1, because index starts at 0
    // e.g. to swap 2nd and 3rd elements in array,
    // index 1 and index 2 must be swapped
    temp = *(arrayPtr+a);
    *(arrayPtr+a) = *(arrayPtr+b); 
    *(arrayPtr+b) = temp; 
  } 
  
  /* SubArray: reduces the objects array to ony include the 
   *           elements from the ath element through the
   *           bth element.
   * parameters: int, int 
   * return value: n/a
   */
   
  void DynamicArray::SubArray(int a, int b){
    int nsize; 
    nsize = b - a; 
    int count = 0; 
    int *subArray = new int [nsize + 1];  // create new dynamic array 

    // a-1, b-1
    // copy ath through bth elements into new array
    a = a-1; 
    for (int i = 0; i<(nsize+1); i++) {  
      *(subArray+i) = *(arrayPtr+a);
      a++; 
    }
    
    // replace object's array with the new array 
    delete [] arrayPtr;
    arrayPtr = subArray;

    this->size = nsize+1;  // update size 

  } 
  
  /* Concatenate: takes a Dynamicarray object as an argument
   * and appends its array to the end of the object's array.
   * parameters: DynamicArray obj 
   * return value: n/a
   */
   
  void DynamicArray::Concatenate(DynamicArray obj) { 
    int nsize; 
    nsize = size + obj.size; 

    int *conArray = new int [nsize]; // create new array big enough for both arrays 
    int a=0; 

    // copy elements from both objects' arrays into new array 
    // first array
    for (int i = 0; i<size; i++) { 
      *(conArray+i) = *(arrayPtr+i);
    }

    // add the second
    for(int j = size; j<nsize; j++) { 
      *(conArray+j) = *(obj.arrayPtr+a);
      a++;  
    }

    delete[] arrayPtr; 

    // update array 
    arrayPtr = new int[nsize];

    arrayPtr = conArray;
    conArray = NULL;
    obj.arrayPtr = NULL;
		       
    this->size = nsize;
  }
