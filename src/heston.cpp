#include "heston.hpp"

double heston_differential(double drift, double volatility, double St, double normal){
  return drift * St * step + std::sqrt(volatility)*St*normal;
}

vector<double> heston(double drift, vector<double> volatility, double S0, int size){

  std::default_random_engine generator;
  std::normal_distribution<double> normal(0.0,1.0);

  vector<double> heston_values;
  volatility.size() == size ? true : size = volatility.size();
  double last_value = S0;
  double current_value;
  double step = 1/double(size);

  for (int i=0; i<size; i++){
    current_value = heston_differential(drift, volatility[i], last_value, step, normal(generator));
    heston_values.push_back(current_value);
    last_value = current_value;
  }
  return heston_values;
}
