#include "plots.hpp"
#include "distributions.hpp"

/*
This is the main code file for the project.
*/

int main(){
	//Checking with parameters given by pag 24
	double x0 = 3.0 / 2.0;
	double k = 1.0 / 2.0;
	double a = 1.0 / 2.0;
	double vol = 0.8;
	double T = 1.0;
	int nn = 100;        //number of nodes per path
	int n = 5;          //number of paths we want to plot

	//  P = sigma*sigma - 4.0 * a >= 0
	plot_paths_cir2(n, nn, x0, T, k, a, vol, true, "output/paths_cir2.csv"); //Using N(0,1)

	plot_paths_cir2(n, nn, x0, T, k, a, vol, false, "output/paths_cir2_Y.csv"); //Using Y


	//Let's say that P = sigma*sigma - 4.0 * a > 0 is the case B
	double x0_b = 0.3;
	double k_b = 0.1;
	double a_b = 0.04;
	double vol_b = 2.0;

	plot_paths_cir2(n, nn, x0_b, T, k_b, a_b, vol_b, false, "output/paths_cir2_B.csv");

	return 0;
}
