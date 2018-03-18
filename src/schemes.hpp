#include <vector>
#include <cmath>
#include <random>
#include <algorithm>

#include "distributions.hpp"
#include "cir2.hpp"

using namespace std;

vector<double> exact(int n, double x0, double T, double k, double a, double sigma);

vector<double> b1(int n, double x0, double T, double k, double beta, double sigma);

vector<double> b3(int n, double x0, double T, double k, double beta, double sigma);

vector<double> cir2_K3(int n, double x0, double T, double k, double a, double sigma);

vector<double> cir2_K4(int n, double x0, double T, double k, double a, double sigma);

//Returns a path with n steps (returns a vector with n + 1 elements: n steps + the initial point). Takes a vector called "normal" of n independent samples of standard normal variable
vector<double> exact_heston(int n, double x0, double T, double k, double a, double sigma, vector<double> normal);

vector<double> b1_MC(int n, double x0, double T, double k, double a, double sigma, vector<double> sample);

vector<double> b3_MC(int n, double x0, double T, double k, double a, double sigma, vector<double> sample);

vector<double> cir2_K3_MC(int n, double x0, double T, double k, double a, double sigma, vector<double> sample);

vector<double> cir2_K4_MC(int n, double x0, double T, double k, double a, double sigma, vector<double> sample);
