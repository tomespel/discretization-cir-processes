import pandas as pd
import matplotlib.pyplot as plt


paths = pd.read_csv('output/paths_cir2.csv')

paths.head()

plt.plot(paths); plt.show()
