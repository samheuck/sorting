#include <stdlib.h>
#include <time.h>

void quicksort(int *head, int *tail);
int* select_pivot(int *head, int *tail);
int* partition(int *l, int *r);

void quicksort(int *head, int *tail) {
    if (head < tail) {
        if (tail - head <= 1024) {
            insertionsort(head, (tail - head) + 1);
        } else {
            swap(head, select_pivot(head, tail));
            int *pivot = partition(head, tail);
            quicksort(head, pivot - 1);
            quicksort(pivot + 1, tail);
        }
    }
}

int* select_pivot(int *head, int *tail) {
    srand(time(NULL));
    int range = (tail - head);
    int *a = head;
    int *b = head + (rand() % range);
    int *c = tail;
    int *median;

    if ((*a - *b) * (*c - *a) >= 0) {
        median = a;
    } else if ((*b - *a) * (*c - *b) >= 0) {
        median = b;
    } else {
        median = c;
    }

    return median;
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
