import math as m
from copy import deepcopy 
import matplotlib.pyplot as plt
def f(x,y):
    
N=40
dx=1/N;dy=1/N
alpha=1
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
    if i==0:
        for j in range(N+1):
                uu.append(f(dx*i,dy*j))
                uub.append(1)
        u.append(uu)
        used.append(uub)
    else:
        for j in range(N+1):
            uu.append(f(dx*i,dy*j))
            uub.append(0)
        u.append(uu)
        used.append(uub)
all_u.append(u)
all_u.append(u)
for i in range(N+1):
    print(u[i])
    print()
# Create another array to use for boundary conditions for next results
dt=0.003
iteration=1
epsilon=0.0001
while True:
    iteration=iteration+1
    next_time=deepcopy(used)
    for i in range(1,N):
        for j in range(1,N):
            next_time[i][j]=2*all_u[-1][i][j]-all_u[-2][i][j]+(dt*dt)*((all_u[-1][i+1][j]-2*all_u[-1][i][j]+all_u[-1][i-1][j])/(dx*dx)+(all_u[-1][i][j+1]-2*all_u[-1][i][j]+all_u[-1][i][j-1])/(dy*dy))
    u=deepcopy(next_time)
    all_u.append(u)
    fig,ax=plt.subplots(1,1)
    cp = ax.contourf(x,y,transpose(u))
    fig.colorbar(cp) # Add a colorbar to a plot
    ax.set_title('t = '+str(iteration*dt) + " N = "+str(N))
    ax.set_xlabel('x ')
    ax.set_ylabel('y ')
    plt.show()  
    
        

