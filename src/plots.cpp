#include "cir2.hpp"
using namespace std;

//<<<<<<< HEAD:src/Plots.h
//void PlotPathsCIR2(int n, int nn, double x, double T, double k, double a, double sigma) { //This produces n paths from the CIR2 with nn nodes and returns a csv file that contains the paths (each column is a path)
//	vector <vector<double>> M;
//	for (int j = 0; j < n; j++) { M.push_back(CIR2(nn, x, T, k, a, sigma)); }
//=======
#include "plots.hpp"

void plot_paths_cir2(int n, int nn, double x, double T, double k, double a, double sigma, bool normal, string c) {
	vector <vector<double> > M;
	for (int j = 0; j < n; j++) { M.push_back(cir2(nn, x, T, k, a, sigma, normal)); }
//>>>>>>> master:src/plots.cpp

	ofstream fout(c);
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


void plot_average(int m, int N, double x, double T, double k, double a, double sigma, bool normal, string c) { //For fixed m computes E and write them in a csv file running n from 1 to N
	vector<double> values;
	for (int j = 1; j <= N; j++) {
		values.push_back(E(m, j, x, T, k, a, sigma, normal));
	}

	reverse(values.begin(), values.end());

	ofstream fout(c);
	if (!fout.is_open()) {
		cout << "Error opening the file output.txt for writing." << endl;
		//return -1;
	}
	for (int j = 0; j < values.size(); j++) {
		fout << setprecision(5) << values[j] << endl;
	}
	fout.close();
}

void plot_order(int m, int N, double x, double T, double k, double a, double sigma, bool normal, string c) { //For fixed m computes log(error) and write them in a csv file running n from 1 to N
	vector<double> values;
	for (int j = 1; j <= N; j++) {
		values.push_back(log(error(m, j, x, T, k, a, sigma, normal)));
	}

	reverse(values.begin(), values.end());

	ofstream fout(c);
	if (!fout.is_open()) {
		cout << "Error opening the file output.txt for writing." << endl;
		//return -1;
	}
	for (int j = 0; j < values.size(); j++) {
		fout << setprecision(5) << values[j] << endl;
	}
	fout.close();
}