import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

plt.style.use('ggplot')

df = pd.read_csv('results.csv')

x = df['position']
y = df['momentum']

fig = plt.figure(figsize=(6,6), dpi=200)
plt.title('Phase portrait of Simple Harmonic Oscillator')
plt.xlabel('x')
plt.ylabel('p')
plot_lims = np.arange(-1.5, 2, 0.5)
plt.xticks(plot_lims)
plt.yticks(plot_lims)
plt.xlim(-2, 2)
plt.ylim(-2, 2)

plt.plot(x, y, color='black')

plt.show()