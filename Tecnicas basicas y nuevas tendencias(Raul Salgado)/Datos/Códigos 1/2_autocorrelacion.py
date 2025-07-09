import numpy as np
import matplotlib.pyplot as plt






## recuperamos la muestra de archivo
ruta = "/Users/raulsg/Desktop/"
X    = np.loadtxt(ruta + "datos_markov.txt",usecols=[0])

# definimos tamaño de muestra
#n    =  1000 
n    = len(X)

# parametros de autocorrelacion
L    = 1000
l    = 200

C = []
for k in range(l):
   std0 = np.std(X[0:n-L])
   std1 = np.std(X[k:n-L+k])
   
   suma = 0
   
   for j in range(0,n-L):
      m0    = np.mean(X[j:n-L+j])
      m1    = np.mean(X[j+k:n-L+k+j])
      suma += (X[j]-m0)*(X[j+k]-m1)
   
   suma = suma/(n-L)
   corr = suma/(std0*std1)
   
   C.append(corr)

plt.plot(C)
plt.show()
   
   
   
   
   