import math as m
import numpy as np
from copy import deepcopy 
import matplotlib.pyplot as plt
N=40
dx=1/N
dy=1/N
x=[]
y=[]
alpha=1
def transpose(u):
    uu=deepcopy(u)
    for i in range(N+1):
        for j in range(N+1):
            uu[j][i]=u[i][j]
    return uu
u=list(np.zeros((N+1,N+1)))
for i in range(N+1):
    x.append(i*dx);y.append(i*dy)
for i in range(int(N/3)):
    u[0][i]=1
for i in range(int(2*N/3),N+1):
    u[i][N]=1
bound=deepcopy(u)
dt=0.003
iter=0
while iter<100:
    iter=iter+1
    new=deepcopy(bound)
    jacobi=deepcopy(bound)
    for i in range(1,N):
        for j in range(1,N):
            new[i][j]=(u[i+1][j]+new[i-1][j]+u[i][j+1]+new[i][j-1])/4
    u=deepcopy(new)
    if iter%10==0:
        fig,ax=plt.subplots(1,1)
        cp = ax.contourf(x,y,transpose(u))
        fig.colorbar(cp) # Add a colorbar to a plot
        ax.set_title('Gauss-Seidal:  t = '+str(iter*dt) + " N = "+str(N))
        ax.set_xlabel('x ')
        ax.set_ylabel('y ')
        plt.show()  
    
        

