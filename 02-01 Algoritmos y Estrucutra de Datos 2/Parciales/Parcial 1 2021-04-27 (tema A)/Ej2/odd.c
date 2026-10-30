#include <stdbool.h>

#include "odd.h"

bool is_odd_sorted(int array[], unsigned int length) {
    int i = 0;
    bool resultado = true;
    for(i = 1;i+2<length;i+2)
    {
        if(array[i]> array[i+2])
        {
           resultado = false;
        }
    }
    return resultado;
}

