#include "cir2.hpp"
using namespace std;


#include "plots.hpp"

int plot_paths_cir2(int n, int nn, double x, double T, double k, double a, double sigma, bool normal, string c) {
	vector <vector<double> > result_vector;
	for (int j = 0; j < n; j++) { result_vector.push_back(cir2(nn, x, T, k, a, sigma, normal)); }


	ofstream fout(c);
	if (!fout.is_open()) {
		cout << "Error opening the file output.txt for writing." << endl;
		return 1;
	}
	for (int j = 0; j <= nn; j++) {
		for (int i = 0; i < n - 1;i++) {
			fout << setprecision(5) << result_vector[i][j] << ",";
		}
		fout << setprecision(5) << result_vector[n - 1][j] << endl;
	}
	fout.close();

	return 0;
}

int plot_paths_cir2(int n, int nn, double x, double T, double k, double a, bool normal, string c) {

	vector <vector<double> > result_vector;
	<vector<double> > volatility_vector;




	double sigma = 0;

	/* TODO
	Figure out how to generate sigma with current CIR2 structure*/
	// Building the volatility path
	volatility_vector = cir2(nn, x, T, k, a, sigma, normal);

	/* TODO
	Make sure that the a parameter corresponds to the drift*/
	// Building result_vector
	for (int j = 0; j < n; j++) {
		result_vector.push_back(heston(a, volatility_vector[i], x, n));
	}


	ofstream fout(c);
	if (!fout.is_open()) {
		cout << "Error opening the file output.txt for writing." << endl;
		return 1;
	}
	for (int j = 0; j <= nn; j++) {
		for (int i = 0; i < n - 1;i++) {
			fout << setprecision(5) << result_vector[i][j] << ",";
		}
		fout << setprecision(5) << result_vector[n - 1][j] << endl;
	}
	fout.close();
	return 0;
}
