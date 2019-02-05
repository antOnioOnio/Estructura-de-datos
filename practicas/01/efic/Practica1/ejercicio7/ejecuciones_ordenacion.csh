#!bin/csh
@ inicio = 1000
@ fin = 100000000
@ incremento = 10
set ejecutable = ejecutable
set salida = tiempos_multiplicacion.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end

