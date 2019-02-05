#!bin/csh
@ inicio = 100
@ fin = 100000
@ incremento = 100
set ejecutable = descomposicion
set salida = tiempos_descomposicion.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end

