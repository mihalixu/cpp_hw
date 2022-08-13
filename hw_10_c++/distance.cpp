#include <cmath>
#include <iomanip>
#include <iostream>
using std::cout;
using std::cin;


int main() {
  double x1,x2,y1,y2;
  cout << "First point's x-coordinate: ";
  cin >> x1;
  cout << "First point's y-coordinate: ";
  cin >> y1;
  cout << "Second point's x-coordinate: ";
  cin >> x2;
  cout << "Second point's y-coordinate: ";
  cin >> y2;
  cout << std::setprecision(4) << std::fixed;
  cout << "The euclidean distance between the two points is " << sqrt(pow(x2-x1,2)+pow(y2-y1,2)) << "."<< std::endl;
  return 0;
}
