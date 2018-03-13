#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "cir2.hpp"
#include "heston.hpp"
#include "monte_carlo.hpp"
using namespace std;

int plot_paths_cir2(int n, int nn, double x, double T, double k, double a, double sigma, bool normal, string c);

void plot_average(int m, int N, double x, double T, double k, double a, double sigma, bool normal, string c);

void plot_order(int m, int N, double x, double T, double k, double a, double sigma, bool normal, string c);

int plot_paths_heston(int n, int nn, double x, double T, double k, double a, bool normal, string c);
