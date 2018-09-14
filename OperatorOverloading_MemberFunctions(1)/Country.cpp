#include <iostream>
#include <string>
#include "Country.h"

using namespace std;

Country::Country(string n, int g, int s, int b){
  name = n;
  gold = g;
  silver = s;
  bronze = b;
}

string Country::GetName() const{
  return name;
}

int Country::GetGold() const{
  return gold;
}

int Country::GetSilver() const{
  return silver;
}

int Country::GetBronze() const{
  return bronze;
}

void Country::Display() const{
  cout << name << " has " << gold << " gold, " << silver << " silver, and " << bronze << " bronze medals." << endl;
}

bool Country::operator==(const Country& country2) const{
  return ((gold * 3 + silver * 2 + bronze) == (country2.gold * 3 +  country2.silver * 2 + country2.bronze));
}

bool  Country::operator!=(const Country& country2) const{
  return !(*this == country2);
}
bool  Country::operator>(const Country& country2) const{
  return ((gold * 3 + silver * 2 + bronze) > (country2.gold * 3 +  country2.silver * 2 + country2.bronze));
}

bool  Country::operator<(const Country& country2) const{
  return (*this != country2) && !(*this > country2);  
}


Country Country::operator+(const Country& country2) const{
  Country temp;
  temp.name = name + " and " + country2.name;
  temp.gold = gold + country2.gold;
  temp.silver = silver + country2.silver;
  temp.bronze = bronze + country2.bronze;
  return temp;
}
