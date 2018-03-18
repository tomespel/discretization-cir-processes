/*
Created by tjespel on 13.03.18
*/

#include <cmath>
#include <vector>
#include <random>

using namespace std;

// Computes the local differential
double heston_differential(double drift, double volatility, double St, double step, double normal);

// Computes the integral
// The volatility is obtained with a CIR process
vector<double> heston(double drift, vector<double> volatility, double S0, int size, vector<double> normal);
