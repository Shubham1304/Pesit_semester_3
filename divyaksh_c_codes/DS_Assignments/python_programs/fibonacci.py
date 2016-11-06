import numpy as np

maximum = 1000000
fiblist = np.zeros(maximum)
fiblist[1] = 1

for i in range(2,maximum):
    fiblist[i]=fiblist[i-1]+fiblist[i-2]
    print i,':',fiblist[i]

