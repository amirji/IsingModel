from pylab import plot,show,ylim, xlabel,ylabel,title,axis,legend
from numpy import loadtxt, linspace

title('HeatBath: Energy per spin (E/N) vs Temperature (T)')


L8	=	loadtxt("8*8/E-T.dat",float)
L10	=	loadtxt("10*10/E-T.dat",float)
L16	=	loadtxt("16*16/E-T.dat",float)

# x = linspace(0,10,100)
plot(L8[:,1],L8[:,0],"cs", label="L=8")
plot(L8[:,1],L8[:,0],"c:")

plot(L10[:,1],L10[:,0],"b^",label="L=10")
plot(L10[:,1],L10[:,0],"b:")

plot(L16[:,1],L16[:,0],"r.", label="L=16")
plot(L16[:,1],L16[:,0],"r:")

xlabel("Temperature (T)")
ylabel("Energy per spin (E/N)")
legend(loc='upper left')

show()