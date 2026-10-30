/*
  @file queries.c
  @brief Consultas sobre tablas de datos climáticos.
*/
#include <limits.h>
#include "queries.h"

/**
 * @brief Dado un año, calcula para cada mes de ese año la máxima precipitación
 * en un día.
 *
 * @param a Tabla de datos climáticos
 * @param year Año, entre FST_YEAR (1980) y LST_YEAR (2016)
 * @param output Arreglo de salida
 */
void max_daily_rainfall(WeatherTable a, int year, int output[MONTHS]) {

  for (int month = 0; month < MONTHS; month++){
    output[month] = 0;
  }

  int y = year - 1980;
  for(int month = 0; month < MONTHS; month++){
    int max_prec = 0;

    for(int day = 0; day < 28; day++){
      int current_prec = a[y][month][day]._rainfall;
      if (current_prec > max_prec)
      {
        max_prec = current_prec;
      }
      

    }
  }
  

}
