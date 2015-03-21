from pylab import plot,show,xlabel,ylabel,legend,title
from numpy import linspace,sin,log,polyfit

title('Ln of Absolute Magnetization (ln |M|) vs Ln of Lattice size (ln L)')


xp = linspace(1,3,100)

x = [ log(5), log(10.0), log(16)]
y = [ log(0.0132212), log(0.047873), log(0.198331)]


p = polyfit(x,y,1)

plot(xp,p[0]*xp+p[1],'b-', label="straight line fit")


plot(x,y,"co", label="data points of |M|")


print(p)
xlabel("Ln of Absolute Magnetization (ln |M|)")
ylabel("Ln of Lattice size (ln L)")
legend(loc='upper left')
show()