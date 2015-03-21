from pylab import plot,show,xlabel,ylabel,legend,title
from numpy import linspace,sin,log,polyfit

title('Ln of Susceptibility (ln X) vs Ln of Lattice size (ln L)')


xp = linspace(1,3,100)

x = [ log(5), log(10.0), log(16)]
y = [ log(0.762153), log(2.77599), log(5.49745)]


p = polyfit(x,y,1)

plot(xp,p[0]*xp+p[1],'b-', label="straight line fit")


plot(x,y,"co", label="data points of X")


print(p)
xlabel("Ln of Lattice size (ln L)")
ylabel("Ln of Susceptibility (ln X)")
legend(loc='upper left')
show()