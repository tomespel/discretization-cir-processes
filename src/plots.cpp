#include "cir2.hpp"
using namespace std;

#include "plots.hpp"

void plot_paths_cir2(int n, int nn, double x, double T, double k, double a, double sigma) {
	vector <vector<double> > M;
	for (int j = 0; j < n; j++) { M.push_back(cir2(nn, x, T, k, a, sigma)); }

	ofstream fout("paths_cir2.csv");
	if (!fout.is_open()) {
		cout << "Error opening the file output.txt for writing." << endl;
		//return -1;
	}
	for (int j = 0; j <= nn; j++) {
		for (int i = 0; i < n - 1;i++) {
			fout << setprecision(5) << M[i][j] << ",";
		}
		fout << setprecision(5) << M[n - 1][j] << endl;
	}
	fout.close();
}
