#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <ctime>
using std::cout;
using std::vector;
using std::fill;
using std::endl;
using std::cin;

class rolling_die{
private:
    int last_die;
public:
    vector<int>stats = {0,0,0,0,0,0};
    int result = 0;
    // reset all stats to 0
    void reset(){
        fill(stats.begin(), stats.end()+1, 0);
    }

    // create a random integer 1..6, store it as private property and return it
    int roll(){
        last_die = 1+(rand() % 6);
        result += last_die;
        if(last_die == 1) {
            stats[0]++;
        }
        else if(last_die == 2){
            stats[1]++;
        }
        else if(last_die == 3){
            stats[2]++;
        }
        else if(last_die == 4){
            stats[3]++;
        }
        else if(last_die == 5){
            stats[4]++;
        }
        else if(last_die == 6){
            stats[5]++;
        }
        return last_die;
    }

    /* print the stats, one per line (eg.
    1: 45
    2: 53
    ...
    */
    void print_stats(){
        cout << "1: " << stats[0] << endl;
        cout << "2: " << stats[1] << endl;
        cout << "3: " << stats[2] << endl;
        cout << "4: " << stats[3] << endl;
        cout << "5: " << stats[4] << endl;
        cout << "6: " << stats[5] << endl;
    }

    // return the stored integer result from the last toss
    int value(){
        return result;
    }
};

int main(){
    srand(time(NULL));
    rolling_die die1;
    for(int i = 0; i < 10000; i++){
        die1.roll();
    }
    die1.print_stats();
    cout << die1.value() << endl;
    return 0;
}


