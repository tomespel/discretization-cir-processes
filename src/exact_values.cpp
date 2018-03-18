#include "exact_values.h"

double cir_mean(double x0, double t, double k, double a, double sigma) {
	return x0*exp(-k*t) + (a/k) *(1.0 - exp(-k*t));
}

double cir_variance(double x0, double t, double k, double a, double sigma) {
	return (x0/k)*sigma*sigma*(exp(-k*t) - exp(-2.0*k*t)) + a*sigma*sigma*(1.0 - exp(-k*t))*(1.0 - exp(-k*t)) / (2.0*k*k);
}

double moment_gen_noncentral_chi(double t, double lambda, double v) {
	return exp(lambda*t / (1.0 - 2.0*t)) / pow((1.0 - 2.0*t), (v/2.0));
}

double moment_gen_cir2(double t, double x0, double T, double k, double a, double sigma) {
	double c = 2.0*k / ((1.0 - exp(-k*T))*sigma*sigma);
	double lambda = 2.0*c*x0*exp(-k*T);
	return moment_gen_noncentral_chi(t / (2.0*c), lambda, 4.0*a / (sigma*sigma));
}

double zero_coupon(double r, double T, double k, double a, double sigma) {
	double h = sqrt(k*k + 2.0*sigma*sigma);
	double d = 2.0*h + (h + k)*(exp(h*T) - 1);
	double A = pow((2.0*h*exp(((h + k)*T) / 2.0)) / d , 2.0*a/(sigma*sigma));
	double B = 2.0*(exp(h*T) - 1) / d;

	return A*exp(-r*B);
}