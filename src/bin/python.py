import pandas as pd
import matplotlib.pyplot as plt

data1 = pd.read_csv('../output/paths_cir2_heston.csv')
plt.plot(data1); plt.show()
data2 = pd.read_csv('../output/paths_exact_heston.csv')
plt.plot(data2); plt.show()



data1.iloc[-1].mean()-data2.iloc[-1].mean()
