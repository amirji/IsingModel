from pylab import plot,show,ylim, xlabel,ylabel,title,axis,legend
from numpy import loadtxt, linspace

title('Wolff: Heat Capacity (C/N) vs Temperature (T)')


L5	=	loadtxt("5*5/Cv-T.dat",float)
L8	=	loadtxt("8*8/Cv-T.dat",float)
L10	=	loadtxt("10*10/Cv-T.dat",float)

# x = linspace(0,10,100)
plot(L5[:,1],L5[:,0],"cs", label="L=5")
plot(L5[:,1],L5[:,0],"c:")

plot(L8[:,1],L8[:,0],"b^",label="L=8")
plot(L8[:,1],L8[:,0],"b:")

plot(L10[:,1],L10[:,0],"r.", label="L=10")
plot(L10[:,1],L10[:,0],"r:")

xlabel("Temperature (T)")
ylabel("Heat Capacity (C/N)")
legend(loc='upper left')

show()