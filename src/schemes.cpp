#include "schemes.h"

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
			double N = poisson(lambda / 2.0);
			double x = chi_square(d + 2.0*N);
			v.push_back(c*x);
		}
	}

	return v;
}

vector<double> b1(int n, double x0, double T, double k, double a, double sigma) {
	double beta = a / k; //To preserve notations of the paper 2.

	vector<double> v;
	v.push_back(x0);                   //First element is the initial value

	random_device rd;
	default_random_engine gen(rd());
	normal_distribution<double> d(0.0, 1.0);//N(0,1);
	for (int j = 1; j <= n; j++) { 
		v.push_back(v.back() + (k / n)*(beta - v.back()) + (sigma / sqrt(n))*sqrt(max(0.0, v.back()))*d(gen));
	}
	return v;
}

vector<double> b3(int n, double x0, double T, double k, double a, double sigma) {
	double beta = a / k; //To preserve notations of the paper 2.

	vector<double> v;
	v.push_back(x0);                   //First element is the initial value


	random_device rd;
	default_random_engine gen(rd());
	normal_distribution<double> d(0.0, 1.0);//N(0,1);
	for (int j = 1; j <= n; j++) { 
		v.push_back(abs(v.back() + (k / n)*(beta - v.back()) + (sigma / sqrt(n))*sqrt(v.back())*d(gen)));
	}
	return v;
}

vector<double> cir2_K3(int n, double x0, double T, double k, double a, double sigma) { 
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

double phi_K4(double x, double t, double Dist, double k, double a, double sigma) {
	double p = a - sigma*sigma / 4.0;
	double phi_k = psi(k, t / 2.0);
	double e = exp(-k*t / 2.0);
	double r = sqrt(max(p*phi_k + e*x, 0.0));
	double s = (r + (sigma*sqrt(t)*Dist / 2.0))*(r + (sigma*sqrt(t)*Dist / 2.0));

	return e*s + p*phi_k;
	//Here formula (11) from the paper with pos parts
}

vector<double> cir2_K4(int n, double x0, double T, double k, double a, double sigma) { 
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
		else v.push_back(phi_K4(x, t, sampleY(), k, a, sigma));
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
			double N = poisson(lambda / 2.0);
			double x = chi_square(d + 2.0*N);
			v.push_back(c*x);
		}
	}

	return v;
}

vector<double> b1_MC(int n, double x0, double T, double k, double a, double sigma, vector<double> sample) {
	double beta = a / k; //To preserve notations of the paper 2.

	vector<double> v;
	v.push_back(x0);                   //First element is the initial value

	for (int j = 1; j <= n; j++) {
		v.push_back(v.back() + (k / n)*(beta - v.back()) + (sigma / sqrt(n))*sqrt(max(0.0, v.back()))*sample[j - 1]);
	}
	return v;
}

vector<double> b3_MC(int n, double x0, double T, double k, double a, double sigma, vector<double> sample) {
	double beta = a / k; //To preserve notations of the paper 2.

	vector<double> v;
	v.push_back(x0);                   //First element is the initial value

	for (int j = 1; j <= n; j++) {
		v.push_back(abs(v.back() + (k / n)*(beta - v.back()) + (sigma / sqrt(n))*sqrt(v.back())*sample[j - 1]));
	}
	return v;
}

vector<double> cir2_K3_MC(int n, double x0, double T, double k, double a, double sigma, vector<double> sample) {
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
		else v.push_back(phi(x, t, sample[j-1], k, a, sigma));
	}

	return v;
}

vector<double> cir2_K4_MC(int n, double x0, double T, double k, double a, double sigma, vector<double> sample) {
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
		else v.push_back(phi_K4(x, t, sample[j-1], k, a, sigma));
	}

	return v;
}