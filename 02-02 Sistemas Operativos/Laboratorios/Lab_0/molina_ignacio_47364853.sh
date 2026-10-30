#!/bin/bash

#EJERCICIO 1: Modelo del procesador
grep "model name" /proc/cpuinfo | head -n 1 | awk -F ':' '{print $2}'
#EJERCICIO 2: Número de unidades de ejecución (cores)​
grep "model name" /proc/cpuinfo | wc -l
#EJERCICIO 3: Lista de nombres de usuarios para red social de​ superhéroes​
tail -n +2 datos/heroes.csv | cut -d ';' -f 2 | grep -v "^$" | tr ' ' '_' | tr 'A-Z' 'a-z' > datos/superheroes_usuarios.txt
#EJERCICIO 4A: Día de máxima temperatura en Córdoba​
grep "$(awk -F ' ' '{print $5}' datos/weather_cordoba.in | sort -n | tail -n 1)" datos/weather_cordoba.in | awk '{print $1, $2, $3}'
#EJERCICIO 4B: Día de mínima temperatura en Córdoba​
grep -e "$(awk -F ' ' '{print $6}' datos/weather_cordoba.in | sort -n | head -n 1)" datos/weather_cordoba.in | awk '{print $1,$2,$3}'
#EJERCICIO 5: Ordenar jugadores de tenis por ranking​
sort -k3 -n datos/wtaplayers.in
#EJERCICIO 6: Ordenar tabla de la Liga Profesional por puntos y​ diferencia de goles​
awk '{ difgol = $7 - $8; print $1, $2, difgol }' datos/lpf.in | sort -k2,2nr -k3,3nr
#EJERCICIO 7: MAC address de la interfaz de red del equipo​
ip link show | grep "link/ether" | awk -F ' ' '{print $2}' | head -n 1
#EJERCICIO 8A: Crear la carpeta serie_prueba con los 10 archivos​ de ​subtítulos​
mkdir -p datos/serie_prueba && for i in {01..10}; do touch "datos/serie_prueba/fma_S01E${i}_es.srt"; done
#EJERCICIO 8B: Renombrar los archivos sacando el sufijo _es​
for archivo in datos/serie_prueba/*; do mv "$archivo" "${archivo/_es/}"; done
