import math as m
from copy import deepcopy 
import matplotlib.pyplot as plt
N=40
dx=1/N;dy=1/N
alpha=1
def transpose(u):
    uu=deepcopy(u)
    for i in range(N+1):
        for j in range(N+1):
            uu[j][i]=u[i][j]
    return uu
# Step-1: Fix initial condition
u=[];x=[];y=[]
for i in range(N+1):
    x.append(i*dx);y.append(i*dy)
    uu=[]
    if i==0:
        for j in range(N+1):
            if (j>=1/3*N and j<=2/3*N) or j==N:
                uu.append(1)
            else:
                uu.append(0)
        u.append(uu)
    else:
        if i<=1/3*N:
            for j in range(N+1):
                if j==N:
                    uu.append(1)
                else:
                    uu.append(0)
        else:
            for j in range(N+1):
                uu.append(0)
        u.append(uu)
for i in range(N+1):
    print(u[i])
    print()
# Create another array to use for boundary conditions for next results
used=deepcopy(u)
dt=0.003
epsilon=0.0001
iteration=0
while iteration<1000:
    iteration=iteration+1
    next_time=deepcopy(used)
    for i in range(1,N):
        for j in range(1,N):
            next_time[i][j]=(u[i][j-1]+u[i][j+1]+u[i+1][j]+u[i-1][j])/4
    finished=True
    for i in range(0,N+1):
        for j in range(0,N+1):
            if abs(next_time[i][j]-u[i][j])>epsilon:
                finished=False
                break
        if finished==False:
            break
    if iteration%100==0:
        fig,ax=plt.subplots(1,1)
        cp = ax.contourf(x,y,transpose(u))
        fig.colorbar(cp) # Add a colorbar to a plot
        ax.set_title('Iteration = '+str(iteration) + " N = "+str(N))
        ax.set_xlabel('x ')
        ax.set_ylabel('y ')
        plt.show()  
    u=deepcopy(next_time)
    
        

# if finished==True:
#         fig,ax=plt.subplots(1,1)
#         cp = ax.contourf(x,y,transpose(u))
#         fig.colorbar(cp) # Add a colorbar to a plot
#         ax.set_title('t = '+str(iteration*dt) + " N = "+str(N))
#         ax.set_xlabel('x ')
#         ax.set_ylabel('y ')
#         plt.show()  
#         break