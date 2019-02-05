#!bin/csh
@ inicio = 100
@ fin = 100000
@ incremento = 200
set ejecutable = OrdenacionBurbujaPeor
set salida = tiempos_burbuja_maximo.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end

