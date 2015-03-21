from pylab import plot,show,ylim, xlabel,ylabel,title,axis,legend
from numpy import loadtxt, linspace

title('Heat Bath: Magnetisation (<M>/N) vs Temperature (T)')


# L5	=	loadtxt("5*5/M-T.dat",float)
# L10	=	loadtxt("10*10/M-T.dat",float)
L16	=	loadtxt("16*16/M-T.dat",float)

# x = linspace(0,10,100)
# plot(L5[:,1],L5[:,0],"cs", label="L=5")
# plot(L5[:,1],L5[:,0],"c:")

# plot(L10[:,1],L10[:,0],"b^",label="L=10")
# plot(L10[:,1],L10[:,0],"b:")

plot(L16[:,1],L16[:,0],"k:")
plot(L16[:,1],L16[:,0],"r.", label="L=16")

# plot(L16[:,1],L16[:,0],"r:")

xlabel("Temperature (T)")
ylabel("Magnetisation (<M>/N)")
legend(loc='upper center')
ylim(-1.1,1.1)

show()