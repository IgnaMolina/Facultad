#include <stdbool.h>

#include "pivot.h"

bool is_pivot(int array[], unsigned int length, unsigned int piv) {
    int i;
    bool resultado = true;

    for (i = 0; i<piv;i++)
    {
      if(array[i] > array[piv])
      {
         resultado = false;
      }
    }
    for(i=piv+1; i <length; i++)
    {
        if(array[piv] > array[i])
        {
            resultado = false;
        }
    }

    return resultado;
}
