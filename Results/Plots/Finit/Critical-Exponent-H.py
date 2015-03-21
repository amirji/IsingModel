from pylab import plot,show,xlabel,ylabel,legend, title
from numpy import linspace,sin,log,polyfit


title('Ln of Heat Capacity (C) vs Ln of Lattice size (ln L)')

xp = linspace(1,3,100)

x = [ log(5), log(10.0), log(16)]
y = [ log(0.945678 ), log(1.32423), log(1.68937)]


p = polyfit(x,y,1)

plot(xp,p[0]*xp+p[1],'b-', label="straight line fit")


plot(x,y,"co", label="data points of C")


print(p)
xlabel("Ln of Lattice size (ln L)")
ylabel("Ln of Heat Capacity (C)")
legend(loc='upper left')
show()