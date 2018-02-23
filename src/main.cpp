/*
This is the main code file for the project.
*/
#import <iostream>
#import <cmath>

using namespace std;


/*
Utility functions
*/
double normal_cdf(double value){
    // erfc is a standard function used to generate normal cdf. It corresponds to the error fucntion.
    return 0.5 * erfc( - value / sqrt(2) );
}




int main(){
  cout << "Hello world" << endl;
  return 0;
}
