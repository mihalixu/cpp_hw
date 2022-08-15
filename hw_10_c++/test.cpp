#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

double a(){
	//srand(time(NULL));
	return((double)rand() / ((double)RAND_MAX)); // rand() return number betwen 0 1, RAND_MAX returns max number from rand() 0-32677  //rand() return number betwen 0 1, RAND_MAX returns max number from rand() 0-32677
}

int main()
{
   	srand(time(NULL));
//   double sum = 0;
//   double calc;
//   for(int i = 0; i < 100000; i++){
// 	double x = ((double)rand() / ((double)RAND_MAX)); // rand() return number betwen 0 1, RAND_MAX returns max number from rand() 0-32677  //rand() return number betwen 0 1, RAND_MAX returns max number from rand() 0-32677
// 	double y = ((double)rand() / ((double)-RAND_MAX));
// 	calc = pow(x,2)+pow(y,2);	 
// 	if(calc <= 1) sum++;
//   }
//   cout << 4*(sum/100000);
	for(int i = 0; i < 10;i++){
		double anal = a();
		cout << anal << " ";
	}
return 0;
}
