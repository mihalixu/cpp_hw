#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
#include <iostream>
using std::cout;

int main() {
  cout << "radians |  sine | cosine" << std::endl;
  cout << "------------------------" << std::endl;
  for(double i = 0.0; i < 3.2; i+=0.1){
    if(cos(i) > 0.0){
      cout << std::setprecision(1) << std::fixed;
      cout << "    " << i;
      cout << std::setprecision(2) << std::fixed;
      cout << " |  " << sin(i) << " |   " << cos(i)   << std::endl;
    }
    else{
      cout << std::setprecision(1) << std::fixed;
      cout << "    " << i;
      cout << std::setprecision(2) << std::fixed;
      cout << " |  " << sin(i) << " |  " << cos(i)   << std::endl; 
    }
  }
    cout << "   " << 3.14;
    cout << std::setprecision(2) << std::fixed;
    cout << " |  " << sin(3.14) << " |  " << cos(3.14)   << std::endl;

  return 0;
}
