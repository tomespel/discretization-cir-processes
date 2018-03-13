#include "heston.hpp"

<<<<<<< HEAD
double heston_differential(double drift, double volatility, double St, double step, double normal){
=======
double heston_differential(double drift, double volatility, double St, double normal){
>>>>>>> 0db4cbf2ba4e27e3a332400478734b903e6018b3
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

<<<<<<< HEAD
  for (int i=0; i<size; i++){x
=======
  for (int i=0; i<size; i++){
>>>>>>> 0db4cbf2ba4e27e3a332400478734b903e6018b3
    current_value = heston_differential(drift, volatility[i], last_value, step, normal(generator));
    heston_values.push_back(current_value);
    last_value = current_value;
  }
  return heston_values;
}
