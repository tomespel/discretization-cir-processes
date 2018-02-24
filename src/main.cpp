#include "plots.hpp"

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


	plot_paths_cir2(n, nn, x0, T, k, a, vol);
	
	return 0;
}
