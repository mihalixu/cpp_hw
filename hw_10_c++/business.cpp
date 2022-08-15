#include <cmath>
#include <cstdlib>
#include <iostream>
#include <math.h>

double interest(double capital, double rate, int years=1, double tax=0){
  return capital*pow((1+rate*(1-tax)),years)-capital;
}

double terminal_value(double capital, double rate, int years=1, double tax=0){
  return capital*pow((1+rate*(1-tax)),years);
}


int main(int argc, char** argv) {
  int years(1);
  double tax(0.0);
  if (argc < 3) {
    std::cout << "Usage: " << argv[0] << " capital rate [years=1 [tax=0.0]]\n";
    return 1;
  }
  double capital(std::atof(argv[1]));
  double rate(std::atof(argv[2]));
  switch (argc) {
  case 5:
    tax = std::atof(argv[4]);
    [[fallthrough]];
  case 4:
    years = std::atoi(argv[3]);
  }
  std::cout << "interest: " << interest(capital, rate, years, tax) << "\n";
  std::cout << "terminal value: ";
  std::cout << terminal_value(capital, rate, years, tax) << "\n";
  return 0;
}
