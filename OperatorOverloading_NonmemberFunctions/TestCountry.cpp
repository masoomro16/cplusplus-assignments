#include <iostream>
#include "Country.h"

using namespace std;

int main(){
  Country usa("USA", 45, 34, 22);
  Country france("France", 23, 12, 10);
  Country uk("UK", 30, 15, 11);

  usa.Display();
  france.Display();
  uk.Display();
  cout << endl;

  (france + uk + usa).Display();
  cout << end;
  
  if (france == uk)
    cout << france.GetName() << " and " << uk.GetName() << " are equal in medals." << endl;
  else
    cout << france.GetName() << " and " << uk.GetName() << " are not equal in medals." << endl;


  return 0;
}
