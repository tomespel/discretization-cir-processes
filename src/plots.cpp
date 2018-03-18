#include "plots.hpp"

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



int plot_paths_cir2_heston(int n, int nn, double x, double T, double k, double a, string c) {

	vector <vector<double> > result_vector;
	vector <vector<double> > volatility_vector;


	// Add the random generation parameters

	std::default_random_engine generator;
	std::normal_distribution<double> normal(0.0,1.0);

	vector<double> Z1;
	vector<double> Z2;

	double rau = 1; // TODO change it
	for (int i=0; i<Z2.size(); i++){
		Z2[i] = rau * rau * Z2[i] + (1 - rau * rau ) * Z1[i];
	}


	double sigma = 0;

	/* TODO
	Figure out how to generate sigma with current CIR2 structure*/
	// Building the volatility path
	for (int i = 0; i < n; i++) {
		volatility_vector.push_back(cir2_heston(nn, x, T, k, a, sigma, Z1));
	}

	/* TODO
	Make sure that the a parameter corresponds to the drift*/
	// Building result_vector
	for (int i = 0; i < n; i++) {
		result_vector.push_back(heston(a, volatility_vector[i], x, n, Z2));
	}
}


void plot_paths_exact(int n, int nn, double x, double T, double k, double a, double sigma, bool normal, string c) {
	vector <vector<double> > M;
	for (int j = 0; j < n; j++) { M.push_back(exact(nn, x, T, k, a, sigma)); }

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
	vector<double> values_cir2;
	vector<double> values_exact;
	vector<double> values_b1;
	vector<double> values_b3;
	for (int j = 1; j <= N; j++) {
		values_cir2.push_back(Ecir2(m, j, x, T, k, a, sigma, normal));
		values_exact.push_back(Eexact(m, j, x, T, k, a, sigma));
		values_b1.push_back(Eb1(m, j, x, T, k, a, sigma));
		values_b3.push_back(Eb3(m, j, x, T, k, a, sigma));
	}

	reverse(values_cir2.begin(), values_cir2.end());   //First the value with N nodes
	reverse(values_exact.begin(), values_exact.end());
	reverse(values_b1.begin(), values_b1.end());
	reverse(values_b3.begin(), values_b3.end());

	ofstream fout(c);
	if (!fout.is_open()) {
		cout << "Error opening the file output.txt for writing." << endl;
		//return -1;
	}
	for (int j = 0; j < values_cir2.size(); j++) {
		fout << setprecision(5) << values_cir2[j] << "," << values_exact[j] << "," << values_b1[j] << "," << values_b3[j] << endl;
	}
	fout.close();
}

void plot_order(int m, int N, double x, double T, double k, double a, double sigma, bool normal, string c) { //For fixed m computes log(error) and write them in a csv file running n from 1 to N
	vector<double> values;
	for (int j = 100; j <= N; j+=100) {
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

void plot_paper(int m, int N, double x, double T, double k, double a, double sigma, bool normal, string c) { //For fixed m computes E and write them in a csv file running n from 1 to N
	vector<double> values_cir2;
	vector<double> values_exact;
	vector<double> values_K3;
	vector<double> values_K4;
	vector<double> values_b1;
	vector<double> values_b3;
	for (int j = 1; j <= N; j++) {
		vector<double> E = E_exp_paper(m, j, x, T, k, a, sigma, normal);
		values_cir2.push_back(E[0]);
		values_exact.push_back(E[1]);
		values_K3.push_back(E[2]);
		values_K4.push_back(E[3]);
		values_b1.push_back(E[4]);
		values_b3.push_back(E[5]);
	}

	ofstream fout(c);
	if (!fout.is_open()) {
		cout << "Error opening the file output.txt for writing." << endl;
		//return -1;
	}
	for (int j = 0; j < values_cir2.size(); j++) {
		fout << setprecision(5) << values_cir2[j] << "," << values_exact[j] << "," << values_K3[j] << ","<< values_K4[j] << "," << values_b1[j] << "," << values_b3[j] << endl;
	}
	fout.close();
}
