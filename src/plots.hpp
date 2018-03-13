#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "cir2.hpp"
#include "monte_carlo.h"

void plot_paths_cir2(int n, int nn, double x, double T, double k, double a, double sigma, bool normal, string c);

void plot_average(int m, int N, double x, double T, double k, double a, double sigma, bool normal, string c);

void plot_order(int m, int N, double x, double T, double k, double a, double sigma, bool normal, string c);
