#include "distributions.hpp"

double normalCDF(double x, double mu, double stddev) {
	return 0.5*(1 + erf((x - mu) / (stddev*sqrt(2))));
}
