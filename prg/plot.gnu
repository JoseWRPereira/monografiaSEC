reset
#set title "Grafico de resposta LPA2v"
set xlabel "Iteracoes"
set ylabel "Variavel controlada"
set yrange [0:5]
set grid
set style data linespoints
plot "grafparacontrol.txt" using 1:3 with lines t"Setpoint"
rep "grafparacontrol.txt" using 1:2 with lines t"Sensor"
replot
# Salvar .eps colorido
set term postscript eps enhanced color
set output "plot.eps"
replot
