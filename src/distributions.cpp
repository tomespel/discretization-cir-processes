#include "distributions.hpp"


// Set distribution generator


double normalCDF(double x, double mu, double stddev) {
	return 0.5*(1 + erf((x - mu) / (stddev*sqrt(2))));
}


double sampleY(){
	// Samples Y, r.v such that first five moments equal to normal
	// Values: Y = -sqrt(3) (P = 1/6), +sqrt(3) (P = 1/6), O (P = 2/3)
	// We can generate them by summing two binomial r.v with parameters "p"
	// After computations, we find p  = (1/2 + 1/(2*sqrt(3)))
	double pBinomial = 0.5 + 0.5*(1/sqrt(3));
	std::random_device rd;
	std::default_random_engine gen(rd());
	std::binomial_distribution<int> Binomial(1, pBinomial);

	// Draw samples from the distribtions
	double UpDraw = Binomial(gen)*sqrt(3);
	double DownDraw = -Binomial(gen)*sqrt(3);

	// Return their sum, which follows Y's law

	return UpDraw + DownDraw;

}

int poisson(double theta) {
	double p = exp(-theta);
	double F = p;
	int N = 0;
	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_real_distribution<double> u(0.0, 1.0);

	while (u(gen) > F) {
		N = N + 1;
		p = p*theta / (double)N;
		F = F + p;
	}

	return N;
}

double gamma(double a) { //This generates gamma (a, 1)
	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_real_distribution<double> u(0.0, 1.0);
	if (a > 1) {
		double a_bar = a - 1.0;
		double b = (a - (1.0 / (6 * a))) / a_bar;
		double m = 2.0 / a_bar;
		double d = m + 2.0;
		double v = 1.0;
		int accept = -1;

		while (accept < 0) {
			double u1 = u(gen);
			double u2 = u(gen);
			v = b*u2 / u1;
			if (m*u1 - d + v + (1 / v) <= 0.0) { accept = 1; }
			else if (m*log(u1) - log(v) + v - 1.0 <= 0.0) { accept = 1; }
		}

		return a_bar*v;;
	}

	else {
		double b = (a + exp(1.0)) / exp(1.0);
		int accept = -1;
		double z = 1.0;
		while (accept < 0) {
			double u1 = u(gen);
			double u2 = u(gen);
			double y = b*u1;
			if (y <= 1.0) { 
				z = pow(y, 1.0 / a);
				if (u2 <= exp(-z)) { accept = 1; }
			}
			else {
				z = -log((b - y) / a);
				if (u2 <= pow(z, a - 1.0)) { accept = 1; }
			}
		}

		return z;
	}
}

double chi_square(double v) {
	double a = v /2.0 ;
	double beta = 2.0;

	double x = gamma(a);

	return beta*x;
}