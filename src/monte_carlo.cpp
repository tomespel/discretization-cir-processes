#include "monte_carlo.hpp"


double Ecir2(int m, int n, double x, double T, double k, double a, double sigma, bool normal) { //m: number of paths, rest of parameters as in cir2
	double E = 0.0;                                                                         //This computes simple average of the process at T
	for (int j = 0; j < m; j++) {
		vector <double> v = cir2(n, x, T, k, a, sigma, normal);
		E += v.back() / (double)m;
	}

	return E;
}

double Eexact(int m, int n, double x, double T, double k, double a, double sigma) { //m: number of paths, rest of parameters as in cir2
	double E = 0.0;                                                                         //This computes simple average of the process at T
	for (int j = 0; j < m; j++) {
		vector <double> v = exact(n, x, T, k, a, sigma);
		E += v.back() / (double)m;
	}

	return E;
}

double Eb1(int m, int n, double x, double T, double k, double a, double sigma) { //m: number of paths, rest of parameters as in cir2
	double E = 0.0;                                                                         //This computes simple average of the process at T
	for (int j = 0; j < m; j++) {
		vector <double> v = b1(n, x, T, k, a, sigma);
		E += v.back() / (double)m;
	}

	return E;
}

double Eb3(int m, int n, double x, double T, double k, double a, double sigma) { //m: number of paths, rest of parameters as in cir2
	double E = 0.0;                                                                         //This computes simple average of the process at T
	for (int j = 0; j < m; j++) {
		vector <double> v = b3(n, x, T, k, a, sigma);
		E += v.back() / (double)m;
	}

	return E;
}


vector<double> E_exp_paper(int m, int n, double x, double T, double k, double a, double sigma, bool normal) { //m: number of paths, rest of parameters as in cir2
	vector<double> E = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};                                                                         //This computes simple average of the process at T
	for (int j = 0; j < m; j++) {
		vector<vector<double>> V;
		V.push_back(cir2(n, x, T, k, a, sigma, normal));
		V.push_back(exact(n, x, T, k, a, sigma));
		V.push_back(cir2_K3(n, x, T, k, a, sigma));
		V.push_back(cir2_K4(n, x, T, k, a, sigma));
		V.push_back(b1(n, x, T, k, a, sigma));
		V.push_back(b3(n, x, T, k, a, sigma));
		for (int i = 0; i < 6;i++) {
			E[i] += exp(-V[i].back()) / (double)m;
		}
	}

	return E;
}

double error(int m, int n, double x, double T, double k, double a, double sigma, bool normal) { //Pag 14
	double t = x*exp(-k*T) + a*(1 - exp(-k*T)) / k;
	return abs( Ecir2(m, n, x, T, k, a, sigma, normal) - t);
}
