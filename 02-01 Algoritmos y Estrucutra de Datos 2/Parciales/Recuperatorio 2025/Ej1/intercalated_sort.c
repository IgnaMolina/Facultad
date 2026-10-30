#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "intercalated_sort.h"

/**
 * @brief Ordena las posiciones pares del arreglo (0-based)
 * usando el algoritmo de ordenación por inserción.
 */
void intercalated_sort(int a[], int length) {
 int i;

    for (i = 2; i < length; i+=2){
     int j = i;

        while (j>= 2 && a[j]< a[j-2]){
            int temp = a[j];
            a[j] = a[j-2];
            a[j-2] = temp;
            j = j-2;
        }
        
    }
}
