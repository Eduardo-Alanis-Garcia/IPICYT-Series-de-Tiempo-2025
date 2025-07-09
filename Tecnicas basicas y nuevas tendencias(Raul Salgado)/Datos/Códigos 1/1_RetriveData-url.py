#!pip install gdown
import pandas      as pd
import yfinance    as yf
from   datetime    import datetime, timedelta
import requests
import gdown


###  Rango de fechas: últimos 5 años
end_date     = datetime.now()
start_date   = end_date - timedelta(days=5*365)
start_str    = start_date.strftime('%Y-%m-%d')
end_str      = end_date.strftime('%Y-%m-%d')

### 1. Datos climáticos de San Luis Potosí (NASA POWER)
nasa_url     = "https://power.larc.nasa.gov/api/temporal/daily/point"
nasa_params  = {
    'parameters': 'ALLSKY_SFC_SW_DWN,PRECTOTCORR,T2M',
    'community': 'AG',
    'latitude': 22.1565,
    'longitude': -100.9855,
    'start': start_date.strftime('%Y%m%d'),
    'end': end_date.strftime('%Y%m%d'),
    'format': 'JSON'
}

response     = requests.get(nasa_url, params=nasa_params)
data         = response.json()

### cargamos datos en un DataFrame:
nasa_df      = pd.DataFrame({
    'date': data['properties']['parameter']['T2M'].keys(),
    'Temperature (°C)': data['properties']['parameter']['T2M'].values(),
    'Radiation (MJ/m²)': data['properties']['parameter']['ALLSKY_SFC_SW_DWN'].values(),
    'Precipitation (mm)': data['properties']['parameter']['PRECTOTCORR'].values()
})
nasa_df['date'] = pd.to_datetime(nasa_df['date'])
nasa_df.head()



### 2. Datos de precios dolar/peso
usd_mxn_df = yf.download("USDMXN=X", start=start_str, end=end_str)
usd_mxn_df.head()



### URLs de datos
url1 = "https://drive.google.com/file/d/159Cbqt_iT839OVqX50xz-I6MwpNvrUA-/view?usp=drive_link"
url2 = 'https://drive.google.com/file/d/1cfePAAiXiYWWzi98OtEBaEr1_mDLmCfh/view?usp=drive_link'
url3 = "https://docs.google.com/spreadsheets/d/1Lg2awMjajw6PK2UcSpfmsxd1tkNZ-Ph0/edit?usp=drive_link&ouid=101231996969888165848&rtpof=true&sd=true"

### Descarga directa al disco usando gdown
gdown.download(url1, 'archivo.csv', quiet=False)








## ID de un archivo en Google Drive (configurado como acceso abierto)
file_id1     = '159Cbqt_iT839OVqX50xz-I6MwpNvrUA-'
file_id2     = '1cfePAAiXiYWWzi98OtEBaEr1_mDLmCfh'
file_id3     = '1Lg2awMjajw6PK2UcSpfmsxd1tkNZ-Ph0'

download_url = f'https://drive.google.com/uc?export=download&id={file_id1}'


TabData  = pd.read_csv(download_url, sep="\t")

"""
## Si queremos que evitar errores en el código::
try:
    # Lee el archivo CSV directamente en un DataFrame de pandas
    TabData  = pd.read_csv(download_url, sep="\t")
    print("Archivo CSV cargado exitosamente en un DataFrame de pandas:")
    print(df.head())
except Exception as e:
    print(f"Ocurrió un error al intentar cargar el archivo: {e}")
    print("Asegúrate de que el archivo sea público o compartible y que el file_id sea correcto.")
"""







