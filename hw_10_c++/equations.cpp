#include <cmath>
#include <iostream>
#include <utility>
using std::pair;


pair<double, double> quadratic(double a, double b, double c) {
  pair<double,double> quad;
  quad.first = (-b + sqrt(b*b-4*a*c)) / (2*a);
  quad.second = (-b - sqrt(b*b-4*a*c)) / (2*a);
  return quad;
}


int main(int argc, char** argv) {
  if (argc != 4) {
    std::cout << "Usage: " << argv[0] << " a b c\n";
    return 1;
  }
  double a(std::atof(argv[1]));
  double b(std::atof(argv[2]));
  double c(std::atof(argv[3]));

  std::pair<double, double> result(quadratic(a, b, c));
  std::cout << "x1: " << result.first << "; x2: " << result.second << "\n";
  return 0;
}
