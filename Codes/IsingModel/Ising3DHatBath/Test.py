from pylab import plot,ylim,xlabel,ylabel,show
from numpy import linspace,sin,cos
x = linspace(0,10,100)
y1 = data1
y2 = data2
y3 = (1- (sinh(2/T)**(-4)))**1/8
plot(x,y1,"ro")
# plot(x,y,"g--")
# (--,-,o,s)
# color(r,g,b,c,m,y,k,w)
ylim(-1.1,1.1)
xlabel("x axis")
ylabel("y = sin x")
show()