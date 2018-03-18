#include "plots.hpp"
#include "distributions.hpp"
#include "exact_values.h"
#include "cir2.hpp"

/*
This is the main code file for the project.
*/

int main(){
	/*
	//Some plots
	plot_paths_cir2(7, 400, 0.0165, 10.0, 0.4, 0.02, 0.04, true, "output/paths_cir2.csv"); //Using N(0,1)
	plot_paths_exact(7, 400, 0.0165, 10.0, 0.4, 0.02, 0.04, true, "output/paths_exact.csv"); //Using N(0,1)

	plot_paths_cir2(7, 400, 0.0165, 10.0, 0.4, 0.02, 0.04, true, "output/paths_cir2_mr.csv"); //Checking mean reverting property

	plot_paths_cir2(7, 400, 0.0165, 10.0, 0.4, 0.02, 0.04, false, "output/paths_cir2_Y.csv"); //Using Y

	plot_mean_var_cir2(400, 0.0165, 10.0, 0.4, 0.02, 0.04, "output/mean_var_cir2.csv");
	*/

	//  P = sigma*sigma - 4.0 * a >= 0
	double x0 = 3.0 / 2.0;
	double k = 1.0 / 2.0;
	double a = 1.0 / 2.0;
	double vol = 0.8;
	double T = 1.0;


	//Let's say that P = sigma*sigma - 4.0 * a > 0 is the case B
	double x0_b = 0.3;
	double k_b = 0.1;
	double a_b = 0.04;
	double vol_b = 2.0;

	/*
	plot_paths_cir2(7, 400, x0_b, T, k_b, a_b, vol_b, false, "output/paths_cir2_B.csv");
	plot_paths_cir2(7, 400, x0_b, T, k_b, 1.0, 3.0, false, "output/paths_cir2_C.csv");
	*/

	//Some theoretical values for the paper plots
	double mean = cir_mean(x0, T, k, a, vol);
	double moment = moment_gen_cir2(-1.0, x0, T, k, a, vol);
	cout << setprecision(5) << mean << " " << moment << endl;

	double mean_b = cir_mean(x0_b, T, k_b, a_b, vol_b);
	double moment_b = moment_gen_cir2(-1.0, x0_b, T, k_b, a_b, vol_b);
	cout << setprecision(5) << mean_b << " " << moment_b << endl;



	//Checking order of scheme
	//plot_order(10000, 1000, x0, T, k, a, vol, true, "output/order.csv");

	//Plot Paper
	//plot_paper(100000, 100, x0, T, k, a, vol, true, "output/plot_paper.csv");

	plot_paper(100000, 70, 0.3, 1.0, 0.1, 0.04, 2.0, false, "output/plot_paper_B.csv");


	system("pause");

	return 0;
}
