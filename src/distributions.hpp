#include <iostream>
#include <cmath>
#include <random>


// Define random engine generators
// Must be defined outside to change return values at every call
//std::default_random_engine generator;

double normalCDF(double x, double mu, double stddev);
double sampleY();
int poisson(double theta);
double gamma(double a);
double chi_square(double v);

//Here we can add functions that sample from different distributions
