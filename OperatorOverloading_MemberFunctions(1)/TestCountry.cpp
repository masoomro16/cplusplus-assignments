#include <iostream>
#include "Country.h"

using namespace std;

int main(){
  Country usa("USA", 45, 34, 22);
  Country france("France", 23, 12, 38);
  Country uk("UK", 30, 15, 11);

  usa.Display();
  france.Display();
  uk.Display();
  cout << endl;

  (france + uk + usa).Display();
  cout << endl;

  if (france == uk)
  cout << france.GetName() << " and " << uk.GetName() << " are equal in medals." << endl;
  else
    cout << france.GetName() << " and " << uk.GetName() << " are not equal in medals." << endl;
  cout << endl;

  if (usa != uk)
    cout << usa.GetName() << " and " << uk.GetName() << " are not equal in medals." << endl;
  else
    cout << usa.GetName() << " and " << uk.GetName() << " are equal in medals." << endl;
  cout << endl;
 
  if (france < uk)
    cout << france.GetName() << " has less medal value than " << uk.GetName() << "." << endl;
  else
    cout << france.GetName() << " does not have less medal value than " << uk.GetName() << "." << endl;
  cout << endl;

  if (usa > france)
    cout << usa.GetName() << " has more medal value than " << france.GetName() << "." << endl;
  else
    cout << usa.GetName() << " does not have less medal value than " << france.GetName() << "." << endl; 
  cout << endl;

  return 0;
}
