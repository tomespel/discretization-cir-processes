#include "monte_carlo.hpp"


double E(int m, int n, double x, double T, double k, double a, double sigma, bool normal) { //m: number of paths, rest of parameters as in cir2
	double E = 0.0;                                                                         //This computes simple average of the process at T
	for (int j = 0; j < m; j++) {
		vector <double> v = cir2(n, x, T, k, a, sigma, normal);
		E += v.back()/(double)m;
	}

	return E;
}

double error(int m, int n, double x, double T, double k, double a, double sigma, bool normal) { //Pag 14
	double t = x*exp(-k*T) + a*(1 - exp(-k*T)) / k;
	return abs( E(m, n, x, T, k, a, sigma, normal) - t);
}
