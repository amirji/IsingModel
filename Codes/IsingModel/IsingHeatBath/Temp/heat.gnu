set pm3d map
set pm3d interpolate 4,4
splot 'heatF.dat' matrix

# Color runs from white to green
set palette rgbformula 7,5,15
set cbrange [0:5]
set cblabel "Score"
unset cbtics

show palette fit2rgbformulae
set terminal png
set output 'heatF.png'
replot