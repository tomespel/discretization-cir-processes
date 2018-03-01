#include "distributions.hpp"


// Set distribution generator


double normalCDF(double x, double mu, double stddev) {
	return 0.5*(1 + erf((x - mu) / (stddev*sqrt(2))));
}


double SampleY(void){
	// Samples Y, r.v such that first five moments equal to normal
	// Values: Y = -sqrt(3) (P = 1/6), +sqrt(3) (P = 1/6), O (P = 2/3)
	// We can generate them by summing two binomial r.v with parameters "p"
	// After computations, we find p  = (1/2 + 1/(2*sqrt(3)))
	double pBinomial = 0.5 + 0.5*(1/sqrt(3));
	std::binomial_distribution<int> Binomial(1,pBinomial);

	// Draw samples from the distribtions
	double UpDraw = Binomial(generator)*sqrt(3);
	double DownDraw = -Binomial(generator)*sqrt(3);

	// Return their sum, which follows Y's law

	return UpDraw + DownDraw;

}