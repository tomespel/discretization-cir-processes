#pragma once
#include <cmath>

using namespace std;

double normalCDF(double x, double mu, double stddev) {
	return 0.5*(1 + erf((x - mu) / (stddev*sqrt(2))));
}

//Here we can add functions that sample from different distributions