import pandas as pd
import matplotlib.pyplot as plt

plt.rcParams['figure.figsize']=[7,4]
paths = pd.read_csv('output/paths_cir2.csv')

paths.head()

plt.plot(paths); plt.show()
