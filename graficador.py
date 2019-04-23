import numpy as np
import matplotlib.pyplot as plt

x=np.loadtxt("datos1.dat", usecols=0)
y=np.loadtxt("datos1.dat", usecols=2)
z=np.loadtxt("datos1.dat", usecols=1)

plt.figure(figsize=(30,10))
plt.subplot(1,3,1)
plt.plot(x,y)
plt.xlabel("x")
plt.ylabel("y")
plt.subplot(1,3,2)
plt.plot(x,z)
plt.xlabel("x")
plt.ylabel("dy/dx")
plt.subplot(1,3,3)
plt.plot(y,z)
plt.xlabel("y")
plt.ylabel("dy/dx")

plt.savefig("SegundaDerivada.png")