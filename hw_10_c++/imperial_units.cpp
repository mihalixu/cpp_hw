#include <iostream>
#include <iomanip> 


const double inch_per_meter = 100 / 2.54;

int main() {
  double m; //meters
  std::cout << "Enter a distance in meters: ";
  std::cin >> m;
  std::cout << std::setprecision(2) << std::fixed;
  std::cout << m * 100 / 2.54 << " inch" << std::endl; // m to inch
  std::cout << m * 100 / 2.54 / 12 << " feet" << std::endl; // m to inch 
  std::cout << m * 100 / 2.54 / 12 / 3 << " yards" << std::endl; // m to inch 
  std::cout << m * 100 / 2.54 / 12 / 3 / 1760 << " miles" << std::endl; // m to inch 
  return 0;
}
