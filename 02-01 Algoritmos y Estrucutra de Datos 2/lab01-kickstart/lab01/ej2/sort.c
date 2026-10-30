#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {

    unsigned int ppiv = a[0];

    if(izq < der){
       int pivote = partition (a,izq,der);

        if (pivote > izq) {
            quick_sort_rec (a, izq, pivote - 1);
        }

        quick_sort_rec (a, pivote + 1, der);
     }
}



void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

