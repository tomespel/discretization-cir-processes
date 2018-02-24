#pragma once
#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "CIR2.h"

using namespace std;

void PlotPathsCIR2(int n, int nn, double x, double T, double k, double a, double sigma) { //This produces n paths from the CIR2 with nn nodes and returns a csv file that contains the paths (each column is a path)
	vector <vector<double>> M;
	for (int j = 0; j < n; j++) { M.push_back(CIR2(nn, x, T, k, a, sigma)); }

	ofstream fout("PathsCIR2.csv");
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
