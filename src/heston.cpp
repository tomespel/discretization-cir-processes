#include "heston.hpp"

double heston_differential(double drift, double volatility, double St, double step, double normal){
  return St * exp((drift - 0.5*volatility)*step + std::sqrt(step*volatility)*normal);
}

vector<double> heston(double drift, vector<double> volatility, double S0, int size, vector<double> normal){

  vector<double> heston_values;
  volatility.size() == size ? true : size = volatility.size();
  double last_value = S0;
  double current_value;
  double step = 1/double(size);

  for (int i=0; i<size; i++){
    current_value = heston_differential(drift, volatility[i], last_value, step, normal[i]);
    heston_values.push_back(current_value);
    last_value = current_value;
  }
  return heston_values;
}
