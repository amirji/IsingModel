from pylab import plot,show,ylim, xlabel,ylabel,title,axis,legend, errorbar
from numpy import loadtxt, linspace

title('Metropolice: Energy per spin (E/N) vs Temperature (T)')


data =	loadtxt("5*5/E-T.dat",float)

# x = linspace(0,10,100)
plot(data[:,1],data[:,0],"cs", label="L = 100")
plot(data[:,1],data[:,0],"c:")
errorbar(data[:,1], data[:,0], yerr=data[:,2], fmt='o')


xlabel("Temperature (T)")
ylabel("Energy per spin (E/N)")
legend(loc='upper left')

show()