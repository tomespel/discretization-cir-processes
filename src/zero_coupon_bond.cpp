#include "zero_coupon_bond.hpp"

double P(double r, double T, double k, double a, double sigma) {
	double h = sqrt(k*k + 2.0*sigma*sigma);
	double d = 2.0*h + (h + k)*(exp(h*T) - 1);
	double A = pow((2.0*h*exp(((h + k)*T) / 2.0)) / d , 2.0*a/(sigma*sigma));
	double B = 2.0*(exp(h*T) - 1) / d;

	return A*exp(-r*B);
}
