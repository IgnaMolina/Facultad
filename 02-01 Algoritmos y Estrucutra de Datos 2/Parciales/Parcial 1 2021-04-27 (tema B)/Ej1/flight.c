/*
  @file layover.c
  @brief Implements flight structure and methods
*/
#include <stdlib.h>
#include "flight.h"

static const int AMOUNT_OF_FLIGHT_VARS = 2;

Flight flight_from_file(FILE* file, char code, item_t type)
{
    Flight flight;
    flight.code = code;
    flight.type = type;
    
    unsigned int hora;
    unsigned int items;

    int res = fscanf(file, "%u %u", &hora, &items);

    if(res != 2)
    {
       fprintf(stderr, "Error: carga de archivos incompleta .\n");
       exit(1);
    }

    flight.hour = hora-1;
    flight.items_amount = items;
    

    return flight;
}
