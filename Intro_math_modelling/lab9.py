import matplotlib.pyplot as plt
from copy import deepcopy
import math as m
pi=m.pi
def initial_condition(x):
    return m.sin(x)
l=2*pi # 6.28 
dx=0.2;
dt=0.01
c=2
N=int(l//dx) # 31
print(N);
x=[]
u1=[];
u2=[];
u3=[];
next_bound=[]
for i in range(N+1):
    x.append(i*dx)
    u1.append(initial_condition(i*dx)) # INITIAL CONDITION
    next_bound.append(0)
u2=deepcopy(u1);
u3=deepcopy(u1) 
time=0
plt.plot(x,u1,color='r',label="u1, time = "+str(time))
plt.plot(x,u2,color='g',label="u2")
plt.plot(x,u3,color='b',label="u3")
plt.legend()
plt.show()
iter=0
while time<0.1:
    iter=iter+1
    next_u1=deepcopy(next_bound)
    next_u2=deepcopy(next_bound)
    next_u3=deepcopy(next_bound)
    for i in range(1,N):
        next_u1[i]=u1[i]+(c*dt/(dx*dx))*(u1[i+1]-2*u1[i]+u1[i-1])
        boolean11=(i==N-1)
        boolean22=(i==N-2)
        if boolean11:
            next_u2[i]=u2[i]+(c*dt/(dx*dx))*(u2[i+1]-2*u2[i]+u2[i-1])
            next_u3[i]=u3[i]+(c*dt/(dx*dx))*(u3[i+1]-2*u3[i]+u3[i-1])
        if boolean22:
            next_u2[i]=u2[i]+(c*dt)/(dx*dx)*(u2[i]-2*u2[i+1]+u2[i+2])
            next_u3[i]=u3[i]+(c*dt/(dx*dx))*(u3[i+1]-2*u3[i]+u3[i-1])
        if boolean22!=True and boolean11!=True:
            next_u3[i]=u3[i]+(c*dt)/(dx*dx)*(-u3[i+3]+4*u3[i+2]-5*u3[i+1]+2*u3[i])
            next_u2[i]=u2[i]+(c*dt)/(dx*dx)*(u2[i]-2*u2[i+1]+u2[i+2])
    plt.plot(x,next_u1,color='r',label="u1, time = "+str(iter*dt))
    plt.plot(x,next_u2,color='g',label="u2")
    plt.plot(x,next_u3,color='b',label="u3")
    u1=deepcopy(next_u1)
    u2=deepcopy(next_u2)
    u3=deepcopy(next_u3)
    plt.legend()
    plt.show()