#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <cmath>
using std::cout;

bool shoot();
double simulate_pi(int iterations);


// implement the missing functions


/**
 * Simulate the given number of iterations to retrieve a good approximation
 * of pi.
 */
double simulate_pi(int iterations) {
   double hit = 0;
   for(int i = 0; i < iterations; i++){
      if(shoot()){
        hit++;
      }
   }
   return 4*(hit/iterations);
}

/**
 * Shoot a dart at a 2x2 square and return true iif the dart hit inside the
 * inscribed circle.
 */
bool shoot() {
  	double x = ((double)rand() / ((double)RAND_MAX)); // rand() return number betwen 0 1, RAND_MAX returns max number from rand() 0-32677  //rand() return number betwen 0 1, RAND_MAX returns max number from rand() 0-32677
	  double y = ((double)rand() / ((double)-RAND_MAX)); 
    if((pow(x,2)+pow(y,2))<=1){
      return true;
    }
    else{
      return false;
    }
}


int main(int argc, char** argv) {
  //srand48(time((time_t*) NULL));  // initialize random number generator
  srand(time(NULL)); // generating random numbers,seed is time  
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " iterations\n";
    return 1;
  }
  int iterations(std::atoi(argv[1]));
  std::cout << "approximation of pi: " << simulate_pi(iterations) << "\n";
  return 0;
}
