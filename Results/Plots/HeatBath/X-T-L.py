from pylab import plot,show,ylim, xlabel,ylabel,title,axis,legend
from numpy import loadtxt, linspace

title('Heat Bath: Magnetic Susceptability (X/N) vs Temperature (T)')


L5	=	loadtxt("8*8/X-T.dat",float)
L10	=	loadtxt("10*10/X-T.dat",float)
L16	=	loadtxt("16*16/X-T.dat",float)

# x = linspace(0,10,100)
plot(L5[:,1],L5[:,0],"gs", label="L=8")
plot(L5[:,1],L5[:,0],"g:")

plot(L10[:,1],L10[:,0],"b^",label="L=10")
plot(L10[:,1],L10[:,0],"b:")

plot(L16[:,1],L16[:,0],"r.", label="L=16")
plot(L16[:,1],L16[:,0],"r:")

xlabel("Temperature (T)")
ylabel("Magnetic Susceptability (X/N)")
legend(loc='upper left')

show()