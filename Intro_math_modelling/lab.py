import math as m
from copy import deepcopy 
import matplotlib.pyplot as plt
N=40
dx=1/N;dy=1/N
alpha=1
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
            u.append(uu)
        else:
            for j in range(N+1):
                uu.append(0)
            u.append(uu)
for i in range(N+1):
    print(u[i])
    print()
# Create another array to use for boundary conditions for next results
used=deepcopy(u)
dt=0.00032
iteration=0
while True:
    iteration=iteration+1
    next_u_first_half=deepcopy(used)
    next_u=deepcopy(used)
    # 1-st formulation to get u_1/2
    for j in range(1,N): # Метод прогонки для каждого j
        alpha=[0];betta=[u[0][j]]
        a=-1/(2*dx*dx);b=1/dt+1/(dx*dx)
        c=a
        for i in range(1,N): # betta[1 (2)]=u[1]
            d=u[i][j]/dt+(-a)*(u[i+1][j]-2*u[i][j]+u[i-1][j])+(1/(dy*dy))*(u[i][j+1]-2*u[i][j]+u[i][j-1])
            alpha.append((-a)/(b+alpha[i-1]*c));betta.append((d-c*betta[i-1])/(b+alpha[i-1]*c))
        for i in range(N-1,0,-1):
            next_u_first_half[i][j]=alpha[i]*next_u_first_half[i+1][j]+betta[i]
    # 2-nd formulation to get u_n+1
    for i in range(1,N): # Метод прогонки для каждого i
        alpha=[0];betta=[u[i][0]]
        a=-1/(2*dy*dy);b=1/dt+1/(dy*dy)
        c=a
        for j in range(1,N):
            d=next_u_first_half[i][j]/dt+(-a)*(u[i][j+1]-2*u[i][j]+u[i][j-1])
            alpha.append((-a)/(b+alpha[j-1]*c));betta.append((d-c*betta[j-1])/(b+alpha[j-1]*c))
        for j in range(N-1,0,-1):
            next_u[i][j]=alpha[j]*next_u[i][j+1]+betta[j]
    u=deepcopy(next_u)
    if iteration%10==0:
        fig,ax=plt.subplots(1,1)
        cp = ax.contourf(x,y,u)
        fig.colorbar(cp) # Add a colorbar to a plot
        ax.set_title('t = '+str(iteration*dt) + " N = "+str(N))
        ax.set_xlabel('x ')
        ax.set_ylabel('y ')
        plt.show()  
    
        
