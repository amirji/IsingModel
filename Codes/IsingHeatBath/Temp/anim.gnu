set terminal gif animate delay 10
set output 'foobar.gif'
stats 'spiral.txt' nooutput
set xrange [-0.5:1.5]
set yrange [-0.5:5.5]

do for [i=1:int(STATS_blocks)] {
    plot 'spiral.txt' with circles
}