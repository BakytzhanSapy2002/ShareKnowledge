import math as m
import numpy as np
from copy import deepcopy
import matplotlib.pyplot as plt
def init(x):
    return x*(x*x-3)
N=40;l=1;dt=0.0001;t=1;pi=m.pi
dx=l/N
M=int(t/dt)
X=[];T=[]
for i in range(N+1):
    X.append(i*dx)
for i in range(M):
    T.append(dt*i)
print(M)
ua=list(np.zeros((M,N+1)))
un=deepcopy(ua)
# Step 1: Initial condition
for i in range(N+1):
    un[0][i]=init(dx*i)
print(un[0])
for n in range(M):
    tt=n*dt
    a=-1/(2*dx*dx);b=(1/(dx*dx)+1/dt)
    c=a
    for i in range(N+1):
        xx=i*dx
        mm=100
        sum=0
        for k in range(1,mm): # Analytical solution
                sqrt_lamb=-pi/2+pi*k
                ak=2*((m.sin(sqrt_lamb)*(-2))/(sqrt_lamb**2)-2*m.sin(sqrt_lamb)/((sqrt_lamb)**2))
                sum=sum+ak*m.sin(sqrt_lamb*xx)*m.exp(-1*(sqrt_lamb**2)*tt)
        ua[n][i]=sum
    if n==0:
        plt.plot(X,un[n],color='r',label='t = '+str(n*dt))
        plt.plot(X,ua[n],color='g')
        plt.legend()
        plt.show()
        continue
    # Numerical solution Crank-Nickelson
    alpha=[0];betta=[0] # alpha[1]
    for i in range(1,N):
        d=un[n-1][i]/dt+(un[n-1][i+1]-2*un[n-1][i]+un[n-1][i-1])/(2*dx*dx) # alpha[2] <==when d[1]
        betta.append((d-betta[-1])/(alpha[-1]*c+b))
        alpha.append((-a)/(alpha[-1]*c+b))
    un[n][N-1]=betta[N-1]/(1-alpha[N-1])
    un[n][N]=deepcopy(un[n][N-1])
    for i in range(N-2,0,-1):
        un[n][i]=alpha[i]*un[n][i+1]+betta[i]
    plt.plot(X,un[n],color='r',label='t = '+str(n*dt))
    plt.plot(X,ua[n],color='g')
    plt.legend()
    plt.show()