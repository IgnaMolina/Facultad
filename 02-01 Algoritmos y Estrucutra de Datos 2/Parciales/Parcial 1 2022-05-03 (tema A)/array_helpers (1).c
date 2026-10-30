/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

/**
* @brief returns true when reach last line in flight file
* @return True when is the last line of the file, False otherwise
*/
static bool is_last_line(unsigned int hour, unsigned int type) {
  return  hour == HOURS - 1u && type == TYPE - 1u;
}

void array_dump(DelayTable a) {
  for (unsigned int type = 0u; type < TYPE; ++type) {
    for (unsigned int hour = 0u; hour < HOURS; ++hour) {
      Flight f = a[type][hour];
      fprintf(stdout, "%c: %s flight with %u passengers arrived at %u:00, with %u delay",
        f.code,
        f.type == 0 ? "last_mile" : "layover",
        f.passengers_amount,
        f.hour - 1,
        f.delay
      );
      if (!is_last_line(hour, type))
      {
        fprintf(stdout, "\n");
      }
    }
  }
}

unsigned int compensation_cost (DelayTable a, unsigned int hour) {
double total_cost = 0.0;

    // Solo calculamos hasta la hora indicada (6 PM = 18)
    for (unsigned int type = 0; type < TYPE; ++type) {
        for (unsigned int h = 0; h < hour; ++h) {
            Flight f = a[type][h];
            unsigned int max_allowed = (f.type == last_mile) ? 
                                        MAX_LM_DELAY_ALLOWED : 
                                        MAX_LAYOVER_DELAY_ALLOWED;

            // Si la demora supera el límite, calculamos el excedente
            if (f.delay > max_allowed) {
                unsigned int extra_minutes = f.delay - max_allowed;
                total_cost += extra_minutes * f.passengers_amount * COMPENSATION_PER_MINUTE;
            }
        }
    }
    return (unsigned int)total_cost;
}


void array_from_file(DelayTable array, const char *filepath) {
  FILE *file = NULL;

  file = fopen(filepath, "r");
  if (file == NULL) {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }

  char code;
  int i = 0;
  while (!feof(file)) {
    /* COMPLETAR: lectura de cada vuelo */
    Flight last_mile_info = flight_from_file(file);
    Flight layover_info = flight_from_file(file);

    int res = fscanf(file, "| %c |", &code);
    if (res != 1) {
      fprintf(stderr, "Invalid file.\n");
      exit(EXIT_FAILURE);
    }

    /* Completar acá: completar y guardar ambos Flight en el array multidimensional*/
    last_mile_info.type = last_mile;
    last_mile_info.code = code;
    layover_info.type = layover;
    layover_info.code = code;

    array[last_mile_info.type][last_mile_info.hour-1] = last_mile_info;
    array[last_mile_info.type][last_mile_info.hour-1] = layover_info;

  }
  fclose(file);
}
