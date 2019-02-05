#!bin/csh
@ inicio = 100
@ fin = 10000000
@ incremento = 200
set ejecutable = OrdenacionBurbujaMejor
set salida = tiempos_burbuja_minimo.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end

