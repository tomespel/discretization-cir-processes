#include "schemes.hpp"

vector<double> exact(int n, double x0, double T, double k, double a, double sigma) { //following pag 124 Glasserman
	double alpha = k;//This is to preserve the notation used at glasserman using the parameters given at the paper.
	double b = a / k;
	double d = 4.0*b*alpha / (sigma*sigma);

	random_device rd;
	default_random_engine gen(rd());
	normal_distribution<double> dist(0.0, 1.0);//N(0,1);

	vector<double> v;
	v.push_back(x0);
	double delta = T / (double)n;

	if (d > 1.0) {
		for (int j = 0; j < n; j++) {
			double c = sigma*sigma*(1.0 - exp(-alpha*delta)) / (4.0*alpha);
			double lambda = v.back()*exp(-alpha*delta) / c;
			double z = dist(gen);
			double x = chi_square(d - 1.0);
			v.push_back(c*((z + sqrt(lambda))*(z + sqrt(lambda)) +x));
		}
	}
	else {
		for (int j = 0; j < n; j++) {
			double c = sigma*sigma*(1.0 - exp(-alpha*delta)) / (4.0*alpha);
			double lambda = v.back()*exp(-alpha*delta) / c;
			int N = poisson(lambda / 2.0);
			double x = chi_square(d + 2.0*(double)N);
			v.push_back(c*x);
		}
	}

	return v;
}

vector<double> b1(int n, double x0, double T, double k, double a, double sigma) {
	double beta = a / k; //To preserve notations of the paper 2.

	vector<double> v;
	v.push_back(x0);                   //First element is the initial value
	double delta = T / (double)n;

	random_device rd;
	default_random_engine gen(rd());
	normal_distribution<double> d(0.0, 1.0);//N(0,1);
	for (int j = 1; j <= n; j++) { //Now t = delta*j, x = v.back() which is the last value and thus, the initial value for next step
		v.push_back(v.back() + k*(beta - v.back())/n + sigma*sqrt(max(0.0, v.back()))*d(gen)/(sqrt(n)));
	}
	return v;
}

vector<double> b3(int n, double x0, double T, double k, double a, double sigma) {
	double beta = a / k; //To preserve notations of the paper 2.

	vector<double> v;
	v.push_back(x0);                   //First element is the initial value
	double delta = T / (double)n;

	random_device rd;
	default_random_engine gen(rd());
	normal_distribution<double> d(0.0, 1.0);//N(0,1);
	for (int j = 1; j <= n; j++) { //Now t = delta*j, x = v.back() which is the last value and thus, the initial value for next step
		v.push_back(abs(v.back() + k*(beta - v.back()) / n + sigma*sqrt(v.back())*d(gen) / (sqrt(n))));
	}
	return v;
}

vector<double> cir2_K3(int n, double x0, double T, double k, double a, double sigma) { //If normal = true uses normal rv in P<=0 otherwise uses Y rv (We can use sampleY or any other rv that matches the first 5 moments af a N(0,1))
	vector<double> v;
	v.push_back(x0);                   //First element is the initial value
	double delta = T / (double)n;     //This is the interval  step
	double P = sigma*sigma - 4.0 * a; //May be useful to define

	//P > 0.0
	for (int j = 1; j <= n; j++) {
		double t = delta;
		double x = v.back();
		if (x < (3.0 / 2.0)*K(t, k, a, sigma)) {
			v.push_back(Z(x, t, k, a, sigma));
		}
		else v.push_back(phi(x, t, sampleY(), k, a, sigma));
	}

	return v;
}

vector<double> cir2_K4(int n, double x0, double T, double k, double a, double sigma) { //If normal = true uses normal rv in P<=0 otherwise uses Y rv (We can use sampleY or any other rv that matches the first 5 moments af a N(0,1))
	vector<double> v;
	v.push_back(x0);                   //First element is the initial value
	double delta = T / (double)n;     //This is the interval  step
	double P = sigma*sigma - 4.0 * a; //May be useful to define

									  //P > 0.0
	for (int j = 1; j <= n; j++) {
		double t = delta;
		double x = v.back();
		if (x < (1.0 / 2.0)*K(t, k, a, sigma)) {
			v.push_back(Z(x, t, k, a, sigma));
		}
		else v.push_back(phi(x, t, sampleY(), k, a, sigma));
	}

	return v;
}


vector<double> exact_heston(int n, double x0, double T, double k, double a, double sigma, vector<double> normal) { //following pag 124 Glasserman
	double alpha = k;//This is to preserve the notation used at glasserman using the parameters given at the paper.
	double b = a / k;
	double d = 4.0*b*alpha / (sigma*sigma);

	vector<double> v;
	v.push_back(x0);
	double delta = T / (double)n;

	if (d > 1.0) {
		for (int j = 0; j < n; j++) {
			double c = sigma*sigma*(1.0 - exp(-alpha*delta)) / (4.0*alpha);
			double lambda = v.back()*exp(-alpha*delta) / c;
			double z = normal[j];
			double x = chi_square(d - 1.0);
			v.push_back(c*((z + sqrt(lambda))*(z + sqrt(lambda)) + x));
		}
	}
	else {
		for (int j = 0; j < n; j++) {
			double c = sigma*sigma*(1.0 - exp(-alpha*delta)) / (4.0*alpha);
			double lambda = v.back()*exp(-alpha*delta) / c;
			int N = poisson(lambda / 2.0);
			double x = chi_square(d + 2.0*(double)N);
			v.push_back(c*x);
		}
	}

	return v;
}
