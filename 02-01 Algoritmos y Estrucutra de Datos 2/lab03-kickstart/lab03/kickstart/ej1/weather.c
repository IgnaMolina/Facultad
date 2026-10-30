/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

Weather weather_from_file(FILE* file)
{
    Weather weather;
    int res;
    // weather es el nombre del struct, el punto "." es el comando de acceso, &weather. es entra al struct y busca en la direccion _max_temp
    res = fscanf(file,"%d %d %d %u %u %u", &weather._average_temp, &weather._max_temp, &weather._min_temp, &weather._pressure, &weather._moisture, &weather._rainfall);

    if (res != 6){
      //stderr se usa para imprimir error sin que el usario vea el error, es otra forma de hacerlo
      fprintf(stderr, "error");
      //exit es una funcion que termina el programa sin importar donde estas, exit_failure es una constante definida en stdlib.h que avisa que el sistema termino (se puede hacer exit(1) para error y exit(0) para succes)
      exit(EXIT_FAILURE);
      // usamos fscan o fprint pq estamos buscando en un archivo no estamos  pidiendo al suario
    }
    return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, "%d %d %d %u %u %u", weather._average_temp,
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
