#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
  std::cout << "radi" << std::endl;
  std::cout << "radians |  sine | cosine" << std::endl;
  std::cout << "------------------------" << std::endl;
  for(double i = 0.0; i < 3.3; i+=0.1){
    std::cout << std::setprecision(2) << std::fixed;
    if(i <=  3.1){
      std::cout << "   " << i << " |  " << sin(i) << " |   " << cos(i) << std::endl;
    }
    else{
      std::cout << "   " << i << " | " << sin(i) << "  | " << cos(i) << std::endl;
    }
  }
  return 0;
}
