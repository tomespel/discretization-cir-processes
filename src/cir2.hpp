#include <vector>
#include <cmath>
#include <random>

using namespace std;

/*
n: number of subintervals of [0,T]
a, k and sigma : parameter from the model
x : initial value; i.e. X at 0
*/
//As defined in pag 10
double psi(double k, double t);

double psi(double x, double t, double Dist, double k, double a, double sigma);

//Returns a vector with a sample from the second order scheme
vector<double> cir2(int n, double x, double T, double k, double a, double sigma);
