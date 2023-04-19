import math as m
import numpy as np
from copy import deepcopy 
import matplotlib.pyplot as plt
N=40
dx=1/N;dy=1/N;x=[];y=[]
alpha=1
def transpose(u):
    uu=deepcopy(u)
    for i in range(N+1):
        for j in range(N+1):
            uu[j][i]=u[i][j]
    return uu
# Step-1: Fix initial condition
u=list(np.zeros((N+1,N+1)))
for i in range(N+1):
    x.append(i*dx);y.append(i*dy)
for i in range(int(N/3)):
    u[N][i]=1
for i in range(int(2*N/3),N+1):
    u[i][0]=1
# Create another array to use for boundary conditions for next results
used=deepcopy(u)
dt=0.003
iteration=0
while iteration<100:
    iteration=iteration+1
    next_time=deepcopy(used)
    for i in range(1,N):
        for j in range(1,N):
            next_time[i][j]=(u[i][j-1]+u[i][j+1]+u[i+1][j]+u[i-1][j])/4
    u=deepcopy(next_time)
    if iteration%10==0:
        fig,ax=plt.subplots(1,1)
        cp = ax.contourf(x,y,transpose(u))
        fig.colorbar(cp) # Add a colorbar to a plot
        ax.set_title('t = '+str(iteration*dt) + " N = "+str(N))
        ax.set_xlabel('x ')
        ax.set_ylabel('y ')
        plt.show()  
    
        

