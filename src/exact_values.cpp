#include "exact_values.hpp"

double cir_mean(double x0, double t, double k, double a, double sigma) {
	return x0*exp(-k*t) + (a/k) *(1.0 - exp(-k*t));
}

double cir_variance(double x0, double t, double k, double a, double sigma) {
	return x0*sigma*sigma*(exp(-k*t) - exp(-2.0*k*t)) / k + a*sigma*sigma*(1.0 - exp(-k*t))*(1.0 - exp(-k*t)) / (2.0*k*k);
}

double moment_gen_noncentral_chi(double t, double lambda, double v) {
	return exp(lambda*t / (1.0 - 2.0*t)) / pow((1.0 - 2.0*t), (v/2.0));
}

double zero_coupon(double r, double T, double k, double a, double sigma) {
	double h = sqrt(k*k + 2.0*sigma*sigma);
	double d = 2.0*h + (h + k)*(exp(h*T) - 1);
	double A = pow((2.0*h*exp(((h + k)*T) / 2.0)) / d , 2.0*a/(sigma*sigma));
	double B = 2.0*(exp(h*T) - 1) / d;

	return A*exp(-r*B);
}
