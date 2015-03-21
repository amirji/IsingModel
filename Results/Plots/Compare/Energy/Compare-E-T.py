from pylab import plot,show,ylim, xlabel,ylabel,title,axis,legend
from numpy import loadtxt, linspace

title('Comparing: Energy per spin (E/N) vs Temperature (T) of Metropolis, Heat Bath')


H	=	loadtxt("E-T-H.dat",float)
M	=	loadtxt("E-T-M.dat",float)
W	=	loadtxt("E-T-W.dat",float)

# x = linspace(0,10,100)
plot(H[:,1],H[:,0],"gs", label="Heat Bath")
plot(H[:,1],H[:,0],"g:")

plot(M[:,1],M[:,0],"m^",label="Metropolis")
plot(M[:,1],M[:,0],"m:")

# plot(W[:,1],W[:,0],"r.", label="Wolff")
# plot(W[:,1],W[:,0],"r:")

xlabel("Temperature (T)")
ylabel("Energy per spin (E/N)")
legend(loc='upper left')
# ylim(-2.1,1.0)


show()