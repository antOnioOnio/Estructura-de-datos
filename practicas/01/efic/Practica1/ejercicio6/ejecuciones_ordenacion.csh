#!bin/csh
@ inicio = 100
@ fin = 100000
@ incremento = 100
set ejecutable = ordenacion_optimizado
set salida = tiempos_ordenacion_optimizado.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end

