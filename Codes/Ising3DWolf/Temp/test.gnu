$map3 << EOD
,Apple,Bacon,Cream,Donut,Eclair
Row 1, 5, 4, 3, 1, 0
Row 2, 2, 2, 0, 0, 1
Row 3, 0, 0, 0, 1, 0
Row 4, 0, 0, 0, 2, 3
Row 5, 0, 1, 2, 4, 3
EOD

set datafile separator comma
plot '$map3' matrix rowheaders columnheaders using 1:2:3 with image
set datafile separator