#include "cir2.hpp"
#include "schemes.h"

double Ecir2(int m, int n, double x, double T, double k, double a, double sigma, bool normal);

double Eexact(int m, int n, double x, double T, double k, double a, double sigma);

double Eb1(int m, int n, double x, double T, double k, double a, double sigma);

double Eb3(int m, int n, double x, double T, double k, double a, double sigma);

double error(int m, int n, double x, double T, double k, double a, double sigma, bool normal);

vector<double> E_exp_paper(int m, int n, double x, double T, double k, double a, double sigma, bool normal);
