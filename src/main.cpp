#include "plots.hpp"
#include "distributions.hpp"
#include "exact_values.hpp"
#include "cir2.hpp"

/*
This is the main code file for the project.
*/

int main(){
	/*
	//Checking with parameters given by pag 24
	*/

	/*
	double x0 = 0.0165;
	double k = 0.4;
	double a = 0.02;
	double vol = 0.04;
	double T = 10.0;
	*/

	double x0 = 3.0/2.0;
	double k = 1.0/2.0;
	double a = 1.0/2.0;
	double vol = 0.8;
	double T = 1.0;
	int nn = 200;        //number of nodes per path
	int n = 5;          //number of paths we want to plot

	//  P = sigma*sigma - 4.0 * a >= 0
	//plot_paths_cir2(n, nn, x0, T, k, a, vol, true, "output/paths_cir2.csv"); //Using N(0,1)
	//plot_paths_exact(n, nn, x0, T, k, a, vol, true, "output/paths_exact.csv"); //Using N(0,1)

	//plot_paths_cir2(n, 200, 10.0, 10.0, k, a, vol, true, "output/paths_cir2_mr.csv"); //Checking mean reverting property

	//plot_paths_cir2(n, nn, x0, T, k, a, vol, false, "output/paths_cir2_Y.csv"); //Using Y


	//Let's say that P = sigma*sigma - 4.0 * a > 0 is the case B
	double x0_b = 0.3;
	double k_b = 0.1;
	double a_b = 0.04;
	double vol_b = 2.0;

	//plot_paths_cir2(n, nn, x0_b, T, k_b, a_b, vol_b, false, "output/paths_cir2_B.csv");
	//plot_paths_cir2(n, nn, x0_b, T, k_b, 1.0, 3.0, false, "output/paths_cir2_C.csv");

	//plot_paths_cir2(n, 600, x0_b, 60.0, 0.05, 0.25, vol_b, false, "output/paths_cir2_D.csv");

	double mean = cir_mean(x0, T, k, a, vol);
	double moment = moment_gen_noncentral_chi(-1.0, mean);
	cout << setprecision(5) << mean << " " << moment << endl;

	/*
	for (int j = 1; j <25; j++) {
		cout << j << " " << Ecir2(20000, j, x0, T, k, a, vol, true) << endl;
	}
	*/



	/*
	vector<vector<double>> M;
	for (int j = 0; j < 100000; j++) {
		M.push_back(cir2(1000, x0, T, k, a, vol, true));
	}

	for (int j = 0; j < 1000; j++) {
		double E = 0.0;
		for (int i = 0; i < 100000; i++) {
			E += M[i][j] / (double)100000;
		}
		cout << E << endl;
	}
	*/



	//plot_average(15000, 15, x0, T, k, a, vol, true, "output/fig1.csv");

	//plot_exp_average(5000, 15, x0, T, k, a, vol, true, "output/fig2.csv");

	//Checking order of scheme
	//plot_order(10000, 1000, x0, T, k, a, vol, true, "output/order.csv");

	//Plot Paper
	plot_paper(100000, 25, x0, T, k, a, vol, true, "output/plot_paper.csv");

	plot_paper(100000, 25, 0.3, 1.0, 0.1, 0.04, 2.0, false, "output/plot_paper_B.csv");


	system("pause");

	return 0;
}
