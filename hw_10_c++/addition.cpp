#include <assert.h>
#include <iostream>


/**
 * Sum all numbers from 0 up to a given integer.
 */
unsigned int sum_to(int num) {
  assert(num >= 0);
  unsigned int sum = 0;
  for(int i = 0; i <= num; i++){
    if(i >= 0){ 
      sum+= i;
    }
  }
  return sum;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " num\n";
    return 1;
  }
  int num(std::atoi(argv[1]));
  std::cout << "sum: " << sum_to(num) << "\n";
  return 0;
}
