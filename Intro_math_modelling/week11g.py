import math as m
from copy import deepcopy 
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np
def f(x,y):
    return m.sin(x)*m.sin(3*y)
N=100
dx=3.14/N;dy=3.14/N;dt=0.0001;c=3;epsilon=0.00001
def transpose(u):
    uu=deepcopy(u)
    for i in range(N+1):
        for j in range(N+1):
            uu[j][i]=u[i][j]
    return uu
# Step-1: Fix initial condition and boundary cond
u=[];x=[];y=[];used=[]
all_u=[]
for i in range(N+1):
    x.append(i*dx);y.append(i*dy)
    uu=[]
    uub=[]
    for j in range(N+1):
        uu.append(f(dx*i,dy*j))
        uub.append(0)
    u.append(uu)
    used.append(uub)
all_u.append(u)
u1=deepcopy(u)
for i in range(N+1):
    for j in range(N+1):
        u1[i][j]=u[i][j]+dt*2*m.sin(dx*i*2)*m.sin(dy*j*5)
all_u.append(u1)
for i in range(N+1):
    print(u[i])
    print()
# Create another array to use for boundary conditions for next results
iteration=1
while True:
    iteration=iteration+1
    next_time=deepcopy(used)
    for i in range(1,N):
        for j in range(1,N):
            next_time[i][j]=2*all_u[-1][i][j]-all_u[-2][i][j]+(dt*dt*c*c)*((all_u[-1][i+1][j]-2*all_u[-1][i][j]+all_u[-1][i-1][j])/(dx*dx)+(all_u[-1][i][j+1]-2*all_u[-1][i][j]+all_u[-1][i][j-1])/(dy*dy))
    u=deepcopy(next_time)
    all_u.append(u)
    finished=True
    for i in range(N+1):
        for j in range(N+1):
            if abs(all_u[-1][i][j]-all_u[-2][i][j])>epsilon:
                finished=False
                break
        if finished==False:
            break
    if iteration%100==0 or finished==True:
        fig,ax=plt.subplots()
        fig1=plt.figure(figsize=(3.14, 3.14))
        ax1 = fig1.add_subplot()
        xnp=np.array(x);ynp=np.array(y);unp=np.array(transpose(u))
        ax1.plot(xnp,ynp,unp)
        print(len(x),len(y),len(u),len(u[100]))
        cp = ax.contourf(x,y,transpose(u))
        fig.colorbar(cp) # Add a colorbar to a plot
        ax.set_title('t = '+str(iteration*dt) + " N = "+str(N))
        plt.show()    
        if finished==True:
            break
