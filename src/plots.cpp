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
	vector <vector<double> > volatility_vector;




	double sigma = 0;

	/* TODO
	Figure out how to generate sigma with current CIR2 structure*/
	// Building the volatility path
	for (int i = 0; i < n; i++) {
		volatility_vector.push_back(cir2(nn, x, T, k, a, sigma, normal));
	}

	/* TODO
	Make sure that the a parameter corresponds to the drift*/
	// Building result_vector
	for (int i = 0; i < n; i++) {
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
