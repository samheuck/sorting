#include <stdio.h>
#include <time.h>
#include "intgen.c"
#include "swap.c"
#include "quick.c"
#include "selection.c"
#include "insertion.c"

#define NELEMS(x) sizeof(x) / sizeof(x[0])

int main() {
    int
        array[100000],
        size = NELEMS(array),
        *head = &array[0],
        *tail = &array[size - 1];

    float
        start,
        end;

    intgen(size, -1000000, 1000000, head);
    start = (float)clock()/CLOCKS_PER_SEC;
    selsort(head, size);
    end = (float)clock()/CLOCKS_PER_SEC;
    printf("selection sort %10fs\n", end - start);

    intgen(size, -1000000, 1000000, head);
    start = (float)clock()/CLOCKS_PER_SEC;
    insertionsort(head, size);
    end = (float)clock()/CLOCKS_PER_SEC;
    printf("insertion sort %10fs\n", end - start);

    intgen(size, -1000000, 1000000, head);
    start = (float)clock()/CLOCKS_PER_SEC;
    quicksort(head, tail);
    end = (float)clock()/CLOCKS_PER_SEC;
    printf("quicksort %15fs\n", end - start);
}
