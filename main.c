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
    int range = 10;

    int *array = malloc(sizeof (int) * size);
    int *head = array;
    int *tail = &array[size - 1];

    float start, end;

    printf("%i integers, range 0..%i\n\n", size, range);

    if (size <= 100000) {
        intgen(size, 0, range, head);
        start = (float)clock()/CLOCKS_PER_SEC;
        selsort(head, size);
        end = (float)clock()/CLOCKS_PER_SEC;
        // printints(head, 10);
        printf("selection sort %10fs\n", end - start);
    }

    if (size <= 200000) {
        intgen(size, 0, range, head);
        start = (float)clock()/CLOCKS_PER_SEC;
        insertionsort(head, size);
        end = (float)clock()/CLOCKS_PER_SEC;
        // printints(head, 10);
        printf("insertion sort %10fs\n", end - start);
    }

    intgen(size, 0, range, head);
    start = (float)clock()/CLOCKS_PER_SEC;
    msort(head, size);
    end = (float)clock()/CLOCKS_PER_SEC;
    // printints(head, 10);
    printf("mergesort %15fs\n", end - start);

    intgen(size, 0, range, head);
    start = (float)clock()/CLOCKS_PER_SEC;
    quicksort(head, size);
    end = (float)clock()/CLOCKS_PER_SEC;
    // printints(head, 10);
    printf("quicksort %15fs\n", end - start);

    intgen(size, 0, range, head);
    start = (float)clock()/CLOCKS_PER_SEC;
    qsort(head, size, sizeof(*head), comp);
    end = (float)clock()/CLOCKS_PER_SEC;
    // printints(head, 10);
    printf("qsort %19fs\n", end - start);

    free(array);
}
