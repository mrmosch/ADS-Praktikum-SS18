reset
set term pdf
#set autoscale x
set autoscale y
set xlabel "n [-]"
set ylabel "t [s]"
set key top left
set key font ",12"
set xtics font ",10"

set out 'sorting_algorithm_results.pdf'
set xrange [1000:1000000]
plot \
"heapsort.txt" with linespoints title 'Heapsort',\
"quicksort.txt" with linespoints title 'Quicksort',\
"mergesort.txt" with linespoints title 'Mergesort',\
"shellsort.txt" with linespoints title 'Shellsort',\

pause -1

set out 'matrix_multiplication_results.pdf'
set xrange [1:1800]
plot \
"matrixmul_colmajor_singlethread.txt" with linespoints title 'matrixmul\_colmajor\_singlethread',\
"matrixmul_rowmajor_singlethread.txt" with linespoints title 'matrixmul\_rowmajor\_singlethread',\
"matrixmul_colmajor_maxthreads.txt" with linespoints title 'matrixmul\_colmajor\_maxthreads',\
"matrixmul_rowmajor_maxthreads.txt" with linespoints title 'matrixmul\_rowmajor\_maxthreads',\