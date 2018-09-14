#include <string>
class Country{
 public:
  bool operator==(const Country&) const;
  bool operator!=(const Country&) const;
  bool operator>(const Country&) const;
  bool operator<(const Country&) const;
  Country operator+(const Country&) const;
  Country(std::string = "", int = 0, int = 0, int = 0);
  std::string GetName() const;
  int GetGold() const;
  int GetSilver() const;
  int GetBronze() const;
  void Display() const;
 private:
  std::string name;
  int gold;
  int silver;
  int bronze;
};
