#include "cir2.hpp"

using namespace std;

double psi(double k, double t) {
	if (k != 0) {
		return (1 - exp(-k*t)) / k;
	}
	return t;
}

double psi(double x, double t, double Dist, double k, double a, double sigma) {
	double P = pow(sigma, 2) - 4.0 * a;
	return exp(-k*t / 2.0)*pow((sqrt(-P*psi(k, t / 2.0) + exp(-k*t / 2.0) * x) + sigma*sqrt(t)*Dist / 2.0), 2) + -P*psi(k, t / 2.0); //Here formula (11) from the paper
}

vector<double> cir2(int n, double x, double T, double k, double a, double sigma) {
	vector<double> v;
	v.push_back(x);                   //First element is the initial value
	double delta = T / (double)n;     //This is the interval  step
	double P = pow(sigma, 2) - 4.0 * a; //May be useful to define
	if (P <= 0.0) {//Here formula (11) from the paper, in this case we can sample from a normal dist, but we can also implement it using the random variable given at example 2.3.
		random_device rd;
		normal_distribution<double> d(0.0, 1.0);//N(0,1)
		default_random_engine gen(rd());
		for (int j = 1; j <= n; j++) { //Now t = delta*j x = v.back(), Dist = d(gen) which is the last value and thus, the initial value for next step
			v.push_back(psi(v.back(), delta*j, d(gen), k, a , sigma));
		}
		return v;
	}
	//Here we need to sample from Y and form a uniform(0,1), the scheme also depends on the threshold to be defined as in pag 11
	return v;
}
