from pylab import plot,show,ylim, xlabel,ylabel,title,axis,legend
from numpy import loadtxt, linspace, sinh,power,errstate

title('Metropolis: Magnetisation (<M>/N) vs Temperature (T)')


x = linspace(0.2,5,1000000)
y = (1.0-(sinh(2.0/x)**(-4.0)))**(1.0/8.0)


L16	=	loadtxt("M-T-10.dat",float)


plot(x,y)


plot(L16[:,1],L16[:,0],"k:")
plot(L16[:,1],L16[:,0],"r.", label="L=16")


# plot(L16[:,1],L16[:,0],"r:")

xlabel("Temperature (T)")
ylabel("Magnetisation (<M>/N)")
legend(loc='upper right')
ylim(-1.1,1.1)

show()