import pandas                   as pd
import numpy                    as np
import matplotlib.pyplot        as plt
from   statsmodels.tsa.seasonal import seasonal_decompose

### Ejemplo: generamos datos con estacionalidad
#np.random.seed(42)

number_of_days  = 1000
date_range      = pd.date_range(start='2025-01-01', periods=number_of_days, freq='D')

trend           = np.linspace(10, 50, number_of_days)  # linear trend

seasonality     = 10*np.sin(2*np.pi*date_range.month/12)

noise           = np.random.normal(0, 2, number_of_days)

### Componemos la serie temporal
data            = trend + seasonality + noise


### graficamos
plt.plot(data,color="black",lw=1)
plt.show()

### Creamos la serie de tiempo en un DataFrame
ts = pd.Series(data, index=date_range)

### Descomponemos la serie con "seasonal_decompose" 
decomposition = seasonal_decompose(ts, model='additive', period=365,extrapolate_trend=1)


### Graficamos las componentes 
"""
decomposition.plot()
plt.tight_layout()
plt.show()
"""





