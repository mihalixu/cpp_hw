#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
#include <iostream>

double surface_cylinder(double radius, double height){
   return 2*M_PI*radius*height+2*M_PI*pow(radius,2);
}

double volume_cylinder(double radius, double height){
   return M_PI*radius*radius*height;
}

double surface_cone(double radius, double height){
   return M_PI*radius*(radius+sqrt(pow(height,2)+pow(radius,2)));
}

double volume_cone(double radius, double height){
   return M_PI*pow(radius,2)*(height/3);
}


int main(int argc, char** argv) {
  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " radius height\n";
    return 1;
  }
  double radius(std::atof(argv[1]));
  double height(std::atof(argv[2]));
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "surface_cylinder(" << radius << ", " << height << "): ";
  std::cout << surface_cylinder(radius, height) << "\n";
  std::cout << "volume_cylinder(" << radius << ", " << height << "): ";
  std::cout << volume_cylinder(radius, height) << "\n";
  std::cout << "surface_cone(" << radius << ", " << height << "): ";
  std::cout << surface_cone(radius, height) << "\n";
  std::cout << "volume_cone(" << radius << ", " << height << "): ";
  std::cout << volume_cone(radius, height) << "\n";
  return 0;
}
