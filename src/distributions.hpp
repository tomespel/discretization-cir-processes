#include <iostream>
#include <cmath>
#include <random>


// Define random engine generators
// Must be defined outside to change return values at every call
std::default_random_engine generator;

double normalCDF(double x, double mu, double stddev);
double sampleY(void);

//Here we can add functions that sample from different distributions
