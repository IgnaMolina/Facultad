#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i, unsigned int length) {
    int value = a[i];
    unsigned int j = i;

    while (j > 0 && goes_before(value, a[j - 1])) {
        a[j] = a[j - 1];
        j = j - 1;
        array_dump(a, length);
    }

    a[j] = value;

    if (j != i) {
        array_dump(a, length);
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1; i < length; ++i) {
        insert(a, i, length);
    }
}
