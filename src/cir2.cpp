#include "cir2.hpp"
#include "distributions.hpp"

using namespace std;

double psi(double k, double t) {
	if (k != 0) {
		return (1 - exp(-k*t)) / k;
	}
	return t;
}

double phi(double x, double t, double Dist, double k, double a, double sigma) {
	double P = pow(sigma, 2) - 4.0 * a;
	return exp(-k*t / 2.0)*pow((sqrt(-P*psi(k, t / 2.0) + exp(-k*t / 2.0) * x) + sigma*sqrt(t)*Dist / 2.0), 2) + -P*psi(k, t / 2.0); //Here formula (11) from the paper
}

double K(double t, double k, double a, double sigma){
	double psi_k = psi(k,t/2.0);
	double exp_kt_2 = exp(k*t/2.0);
	double v = sigma*sigma/4.0 - a;

	// Notations in the formula from p.11
	double w = sqrt(exp_kt_2*v*psi_k);
	double r = (w+sigma*0.5*sqrt(3.0*t))*(w+sigma*0.5*sqrt(3.0*t));
	double z = v*psi_k;
	return exp_kt_2*(r+z);
}

//This is the potential second order scheme near cero when sigma*sigma - 4.0 * a > 0
double Z(double x, double t, double k, double a, double sigma) {
	double u_1 = x*exp(-k*t) + a*psi(k, t);
	double u_2 = u_1*u_1 + sigma*sigma*psi(k, t)*(a*psi(k, t)/2.0 + x*exp(-k*t));
	double delta = 1 - u_1*u_1 / u_2;
	double pi = (1 - sqrt(delta)) / 2.0;

	random_device rd;
	default_random_engine gen(rd());
	uniform_real_distribution<double> u(0.0, 1.0);//U(0,1)

	if (u(gen) <= pi) { return u_1 / (2.0*pi); }
	
	else return u_1 / (2.0*(1 - pi));

}

vector<double> cir2(int n, double x, double T, double k, double a, double sigma, bool normal) { //If normal = true uses normal rv in P<=0 otherwise uses Y rv (We can use sampleY or any other rv that matches the first 5 moments af a N(0,1))
	vector<double> v;
	v.push_back(x);                   //First element is the initial value
	double delta = T / (double)n;     //This is the interval  step
	double P = sigma*sigma - 4.0 * a; //May be useful to define
	
	if (P <= 0.0) {//Here formula (11) from the paper, in this case we can sample from a normal dist, but we can also implement it using the random variable given at example 2.3.
		if (normal) {
			random_device rd;
			default_random_engine gen(rd());
			normal_distribution<double> d(0.0, 1.0);//N(0,1);
			for (int j = 1; j <= n; j++) { //Now t = delta*j, x = v.back(), Dist = d(gen) which is the last value and thus, the initial value for next step
				v.push_back(phi(v.back(), delta*j, d(gen), k, a, sigma));
			}
			return v;
		}
		else {
			for (int j = 1; j <= n; j++) { //Now t = delta*j, x = v.back(), Dist = sampleY() which is the last value and thus, the initial value for next step
				v.push_back(phi(v.back(), delta*j, sampleY(), k, a, sigma));
			}
			return v;
		}
	}

	else { //P > 0.0
		for (int j = 1; j <= n; j++) {
			double t = delta*j;
			double x = v.back();
			if (x < K(t, k, a, sigma)) {
				v.push_back(Z(x, t, k, a, sigma));
			}
			else v.push_back(phi(x, t, sampleY(), k, a, sigma));
		}
		return v;
	}
}
