from pylab import plot,show,ylim, xlabel,ylabel,title,axis,legend
from numpy import loadtxt, linspace

title('Comparing: Specific Heat Capacity (C/N) vs Temperature (T) of Metropolis, Heat Bath')


H	=	loadtxt("Cv-T-H.dat",float)
M	=	loadtxt("Cv-T-M.dat",float)
W	=	loadtxt("Cv-T-W.dat",float)

# x = linspace(0,10,100)
plot(H[:,1],H[:,0],"gs", label="Heat Bath")
plot(H[:,1],H[:,0],"g:")

plot(M[:,1],M[:,0],"m^",label="Metropolis")
plot(M[:,1],M[:,0],"m:")

# plot(W[:,1],W[:,0],"r.", label="Wolff")
# plot(W[:,1],W[:,0],"r:")

xlabel("Temperature (T)")
ylabel("Specific Heat Capacity (C/N)")
legend(loc='upper left')

show()