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

bool operator==(const Country& country1, const Country& country2){
  return ((country1.gold == country2.gold) && (country1.silver == country2.silver) && (country1.bronze == country2.bronze));
}

Country operator+(const Country& country1, const Country& country2){
  Country temp;
  temp.name = country1.name + " and " + country2.name;
  temp.gold = country1.gold + country2.gold;
  temp.silver = country1.silver + country2.silver;
  temp.bronze = country1.bronze + country2.bronze;
  return temp;
}
