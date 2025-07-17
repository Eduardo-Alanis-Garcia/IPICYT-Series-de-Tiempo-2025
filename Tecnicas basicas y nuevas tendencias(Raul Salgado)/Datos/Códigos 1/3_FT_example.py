import matplotlib.pyplot    as plt
import numpy                as np
from   matplotlib.gridspec  import GridSpec

freq1 = 2
freq2 = 3
def onda1(t):
	return( np.sin(2*np.pi*freq1*t) )

def onda2(t):
	return(  np.cos(2*np.pi*freq2*t) )

## sampling rate
sr = 200

# sampling interval
ts = 1.0/sr

# time span 
t  = np.arange(0,100,ts)

print(len(t))
#x  = np.linspace(0,100,10000)
y  = 3*onda1(t) + 4*onda2(t)



X  = np.fft.fft(y)
N  = len(X)
n  = np.arange(N)
T  = N/sr
freq = n/T 




"""
fig, ax = plt.subplots(3)

ax[0].plot(freq, np.abs(X), color="black")
ax[0].set_xlabel('Freq (Hz)')
ax[0].set_ylabel('FFT Amplitude |X(freq)|')
ax[0].set_xlim(0, 5)

ax[1].plot(freq,X.real , color="black")
ax[1].set_xlabel('Freq (Hz)')
ax[1].set_ylabel('FFT Real part Re[X(freq)]')
ax[1].set_xlim(0, 5)

ax[2].plot(freq, X.imag, color="black")
ax[2].set_xlabel('Freq (Hz)')
ax[2].set_ylabel('FFT Imaginary part Re[X(freq)]')
ax[2].set_xlim(0, 5)
"""


"""
fig, ax = plt.subplots(2)
ax[0].plot(t[0:1000], onda1(t[0:1000]), color="black")
ax[0].set_xlabel('tiempo')
ax[0].set_ylabel('Onda 1')
ax[0].set_xlim(0, 5)

ax[1].plot(t[0:1000], onda2(t[0:1000]), color="black")
ax[1].set_xlabel('tiempo')
ax[1].set_ylabel('Onda 2')
ax[1].set_xlim(0, 5)

"""

ig, ax = plt.subplots()
ax.plot(t[0:1000], y[0:1000], color="black")
ax.set_xlabel('tiempo')
ax.set_ylabel('función')
ax.set_xlim(0, 5)


"""
plt.figure(figsize = (12, 6))
plt.subplot(121)

plt.stem(freq, np.abs(X), 'b', markerfmt=" ", basefmt="-b")

#plt.stem(freq, X.imag, 'b', markerfmt=" ", basefmt="-b")
      
plt.xlabel('Freq (Hz)')
plt.ylabel('FFT Amplitude |X(freq)|')
plt.xlim(0, 10)

plt.subplot(122)
plt.plot(t, y, 'r')

#plt.plot(t, np.fft.ifft(X), 'r')
plt.xlabel('Time (s)')
plt.ylabel('Amplitude')
plt.tight_layout()
"""
plt.show()

