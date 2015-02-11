#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "intgen.c"
#include "swap.c"
#include "selection.c"
#include "insertion.c"
#include "merge.c"
#include "quick.c"

#define NELEMS(x) sizeof(x) / sizeof(x[0])

int comp(const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int main() {
    int size = 100000;
    int *array = malloc(sizeof (int) * size);
    int *head = array;
    int *tail = &array[size - 1];

    float start, end;

    intgen(size, -1000000, 1000000, head);
    start = (float)clock()/CLOCKS_PER_SEC;
    selsort(head, size);
    end = (float)clock()/CLOCKS_PER_SEC;
    printf("selection sort %10fs\n", end - start);

    intgen(size, -100, 100, head);
    start = (float)clock()/CLOCKS_PER_SEC;
    insertionsort(head, size);
    end = (float)clock()/CLOCKS_PER_SEC;
    printf("insertion sort %10fs\n", end - start);

    intgen(size, -100, 100, head);
    start = (float)clock()/CLOCKS_PER_SEC;
    msort(head, size);
    end = (float)clock()/CLOCKS_PER_SEC;
    printf("mergesort %15fs\n", end - start);

    intgen(size, -100, 100, head);
    start = (float)clock()/CLOCKS_PER_SEC;
    // qsort(head, size, sizeof(*head), comp);
    quicksort(head, tail);
    end = (float)clock()/CLOCKS_PER_SEC;
    printf("quicksort %15fs\n", end - start);
}
