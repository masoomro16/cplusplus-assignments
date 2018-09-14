/* 
 * Maira Soomro, CS 202, Assn 04
 * This program will implement a dynamic array class and
 * will be able to swap elements in an array, break an array
 * into a subarray and concatenate two arrays. This program
 * can also find the minimum and maxumum values in an array
 *
 */

#include <iostream>
#include <string>
#include "DynamicArray.h"
using namespace std;
 
int main () { 

   DynamicArray array1(3, 5, 15); 
   DynamicArray array2(5, 10, 20);
   DynamicArray array3(20, 25, 40); 
   DynamicArray array4(10, 10, 30);

   cout << " /**** ARRAY 1 ****/ ";
   cout << "\nArray 1 = "; 
   array1.Display(); 

   cout << "\n /**** ARRAY 3 ****/ "; 
   cout << "\nArray 3 = "; 
   array3.Display(); 
   array3.Minimum(); 
   array3.Maximum();

   cout << "\nAppend array 1 to array 3: " << endl;
   array3.Concatenate(array1);
   array3.Display(); 

   cout << "\nSwap elements 2 and 22: " << endl; 
   array3.SwapElements(2,22); 
   array3.Display(); 

   cout << "\nCut array to only 11th to 21st elements: " << endl; 
   array3.SubArray(11,21);
   array3.Display();

   cout << "\n /*** ARRAY 2 ***/ "; 
   cout << "\nArray 2 = " ; 
   array2.Display(); 

   cout << "Swap 2nd and 3rd elements of array = "; 
   array2.SwapElements(2,3);
   array2.Display();

   array2.Minimum();
   array2.Maximum(); 

   cout << "\nCut array to only 2nd through 4th elements = "; 
   array2.SubArray(2,4);
   array2.Display();

   cout << "\n /**** ARRAY 4 ****/";
   cout << "\nArray 4 = "; 
   array4.Display();
   array4.Minimum();
   array4.Maximum();


   cout << "\nAppend Array 4 to Array 2 = "; 
   array2.Concatenate(array4);
   array2.Display();

   cout << endl; 
    return 0; 
}
