
Author: Junyan Xu  
Date:   Nov 1st, 2016  

# Heston Model Pricing Library Documentation v1.1


## 1. Module Introduction

The library is designed for three main functions:
    1. Fast Pricing
    2. Data Handling
    3. Calibration
The following content are brief introduction to the implementation of the corresponding modules and their usage

## 2. Pricing Module
The pricing module is implemented in C so it has faster computation speed than directly implementing in Python. To begin with you need to install GNU Scientific Library in your PC. After download latest [GSL](http://ftp://ftp.gnu.org/gnu/gsl/), extract the .tar.gz or .zip into a directory. Now we start to install this C library
    1. cd to the directory, type following command into terminal
```
./configure
```
    2. The type 
```
make
```
    3. After compliation finished, type
```
make install
```
Now the gsl has been installed into your computer and the headers are in **\usr\local\include** and libraries object files are in **\usr\local\lib**

    4. Switch to my Option directory. you will see setup.py there, type
```
sudo python setup.py build install
```

After installed Option module to your python. Open up your ipython console to try:
```python
import Option
S = 100
VolSquare = 0.09
K = 100
T = 1
r = 0
Chi = 1
Theta = 0.09
Ita = 1
Rho = 1
Up = 0.1
UpSigma = 0.1
Down = -0.1
DownSigma = 0.1
StepSize = 0.05
print(Option.HestonMixedGaussianCall(
        S, VolSquare, K, T, r, Chi, Theta, Ita, Rho, Up, UpSigma, Down, DownSigma, StepSize))
```

The interface of all functions in **Option** module are listed here:
```python
from Option import *
BSCall(S, K, T, Sigma, d, r)
BSPut(S, K, T, Sigma, d, r)
BSCallIV(C, S, K, T, d, r)
BSPutIV(P, S, K, T, d, r)
HestonModelCall(S, VolSquare, K, T, r, Chi, Theta, Ita, Rho, StepSize)
HestonModelPut(S, VolSquare, K, T, r, Chi, Theta, Ita, Rho, StepSize)
HestonMixedGaussianCall(S, VolSquare, K, T, r, Chi, Theta, Ita, Rho, Up, UpSigma, Down, DownSigma, StepSize)
HestonMixedGaussianPut(S, VolSquare, K, T, r, Chi, Theta, Ita, Rho, Up, UpSigma, Down, DownSigma, StepSize)
```

## 3. Data Handling Module 
The data handling module is mainly for extracting fitting data from data source. The interface are shown below
```python
from DataLib import *
data, Expirys, TimeStamps = ReadData(path)
OptionData = GetOptionData(data, expiry, kind, time=None)
OptionData = GetOptionDataForAllExpiry(data, expirys, kind, time=None)
```
The **ReadData** function will return the dataframe of the original data while list of different expirys and timestamps. If we want to get the fitting data for specfic expiry at some timestamp, we can use 
```python
data, Expirys, TimeStamps = ReadData(path)
OptionData = GetOptionData(data, Expirys[0], "CALL", TimeStamps[0])
```
Thus we can have fitting data for a vol curve or the whole surface at a specific timestamp

## 4. Calibration Module 
In the calibration module, you can customize your **HestonMixedGaussianApplyFunction** function to give a a judgement whether your parameter gives you an satisfying result of caliration. This function is recommended to use with lambda expression by `pandas.Dataframe.apply`
```python
def HestonMixedGaussianApplyFunction(
    x, VolSquare, Chi, Theta, Ita, Rho, Up, UpSigma, Down, DownSigma, StepSize
)
```

The MixedGaussianLoss for whole dataset could be calculated by calling **HestonMixedGaussianLossFunction** where you can customize your own optimizer to find the best parameter values.
```python
def HestonMixedGaussianLossFunction(
    data, VolSquare, Chi, Theta, Ita, Rho, Up,
    UpSigma, Down, DownSigma, StepSize
)
```

To make the whole process even easier, **CalibrateHestionMixedGaussianPlot** is provided here to give you plot when you want to test some parameters and plot.
```python
def CalibrateHestionMixedGaussianPlot(
    data, Expirys, timestamp, kind, VolSquare, Chi, Theta, Ita, Rho, Up,
    UpSigma, Down, DownSigma, StepSize)
```

Here is a brief example how to use Calibration module to get parameter fitting trial. Suppose we are trying to fitting the volatility surface for Linkedin data at given timestamps, we can write a breif piece of code to generate the plot
```python
import DataLib
import Option
import numpy
import pandas
import matplotlib.pyplot as plt
from Caliration import *
from scipy.optimize import minimize

data, Expirys, TimeStamps = DataLib.ReadData("data/LNKDVol20160203.csv")
x0 = [0.01, 1, 0.6, 0.5, -0.3, 0.07, 0.1, -0.1, 0.1]
finalres, CalibratedImpliedVol = CalibrateHestionMixedGaussianPlot(
    data, Expirys, TimeStamps[8], "CALL", *x0, 0.05)

```

![optional caption text](pictures/CurrentBest/Test.png)
