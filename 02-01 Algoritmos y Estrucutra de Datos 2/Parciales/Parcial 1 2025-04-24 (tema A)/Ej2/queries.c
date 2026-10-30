//*
 // @file queries.c
 // @brief Consultas sobre tablas de datos climáticos.


#include "queries.h"

/**
 * @brief Total de lluvias de un año dado.
 *
 * @param a Tabla de datos climáticos.
 * @param year Año, entre FST_YEAR (1980) y LST_YEAR (2016).
 */
int year_rainfall(WeatherTable a, int year) {
    unsigned int año = year -1980;
    unsigned int mes = 0;
    unsigned int dia = 0;
    unsigned int total_prec = 0;

    for(mes = 0; mes < 12; mes++)
    {
      for(dia = 0; dia < 28;dia++)
      {
         total_prec = total_prec + a[año][mes][dia]._rainfall;
      }
    }

    return total_prec;
}
