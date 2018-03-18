#include <vector>
#include <cmath>
#include <random>

using namespace std;

/*
n: number of subintervals of [0,T]
a, k and sigma : parameter from the model
x : initial value; i.e. X at 0
*/
// As defined in pag 10
double psi(double k, double t);

double phi(double x, double t, double Dist, double k, double a, double sigma);

// Compute the threshold at a given time
// Notations used, page 11
double K(double t, double k, double a, double sigma);

//This is the potential second order scheme near cero when sigma*sigma - 4.0 * a > 0
double Z(double x, double t, double k, double a, double sigma);


// Returns a vector with a sample from the second order scheme
vector<double> cir2(int n, double x0, double T, double k, double a, double sigma, bool normal);

//Returns a path with n steps (returns a vector with n + 1 elements: n steps + the initial point). Takes a vector called "normal" of n independent samples of standard normal variable
vector<double> cir2_heston(int n, double x0, double T, double k, double a, double sigma, vector<double> normal);

double u_2func(double x, double t,double k, double a,double sigma);
double u_1func(double x, double t,double k, double a);
