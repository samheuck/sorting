#include <stdlib.h>
#include <time.h>

int* randelem(int *head, int *tail) {
    srand(time(NULL));
    return &head[rand() % (tail - head)];
}

int* partition(int *l, int *r) {
    int pivot = *l,
        *a = l + 1,
        *b = l;

    while(++b <= r) {
        if (*b <= pivot) {
            swap(a, b);
            a++;
        }
    }

    swap(l, --a);

    return a;
}

void quicksort(int *head, int *tail) {
    int *pivot;

    while (head < tail) {
        swap(head, randelem(head, tail));
        pivot = partition(head, tail);
        quicksort(head, pivot - 1);
        head = pivot + 1;
    }
}
