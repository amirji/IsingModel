plot "M-T.dat" using 2:1 w points pointtype 6 pointsize 1 lc 0
set terminal png
set output 'M-T.png'
replot

