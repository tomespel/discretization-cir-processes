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


vector<double> E_exp_paper(int m, int n, double x, double T, double k, double a, double sigma, bool cir2_normal) { //m: number of paths, rest of parameters as in cir2 
	random_device rd;
	default_random_engine gen(rd());
	normal_distribution<double> dist(0.0, 1.0);//N(0,1);

	if (cir2_normal) {
		vector<double> E = { 0.0, 0.0, 0.0, 0.0 };
		for (int j = 0; j < m; j++) {
			vector<double> Z;
			for (int j = 0; j < n; j++) { Z.push_back(dist(gen));  }
			vector<vector<double>> V;
			V.push_back(cir2_MC(n, x, T, k, a, sigma, cir2_normal, Z));
			V.push_back(exact_heston(n, x, T, k, a, sigma, Z));
			//V.push_back(cir2_K3(n, x, T, k, a, sigma));
			//V.push_back(cir2_K4(n, x, T, k, a, sigma));
			V.push_back(b1_MC(n, x, T, k, a, sigma, Z));
			V.push_back(b3_MC(n, x, T, k, a, sigma, Z));
			for (int i = 0; i < 4; i++) {
				E[i] += exp(-V[i].back()) / (double)m;
			}
		}

		return E;
	}

	else {
		vector<double> E = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
		for (int j = 0; j < m; j++) {
			vector<double> Y;
			vector<double> Z;
			for (int j = 0; j < n; j++) { Y.push_back(sampleY()); Z.push_back(dist(gen)); }
			vector<vector<double>> V;
			V.push_back(cir2_MC(n, x, T, k, a, sigma, cir2_normal, Y));
			V.push_back(exact_heston(n, x, T, k, a, sigma, Z));
			V.push_back(cir2_K3_MC(n, x, T, k, a, sigma, Y));
			V.push_back(cir2_K4_MC(n, x, T, k, a, sigma, Y));
			V.push_back(b1_MC(n, x, T, k, a, sigma, Z));
			V.push_back(b3_MC(n, x, T, k, a, sigma, Z));
			for (int i = 0; i < 6; i++) {
				E[i] += exp(-V[i].back()) / (double)m;
			}
		}

		return E;
	}
}

double error(int m, int n, double x, double T, double k, double a, double sigma, bool normal) { //Pag 14
	double t = x*exp(-k*T) + (a/k)*(1 - exp(-k*T));
	return abs( Ecir2(m, n, x, T, k, a, sigma, normal) - t);
}
