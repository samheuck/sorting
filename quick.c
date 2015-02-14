#include <stdlib.h>
#include <time.h>

void quicksort(int *a, int size);
void qs(int *a, int lo, int hi);
int* select_pivot(int *head, int hi);

void quicksort(int *a, int n) {
    qs(a, 0, n - 1);
}

void qs(int *a, int l, int r) {
    int len = r - l + 1;

    if (len <= 1024) {
        insertionsort(&a[l], len);
        return;
    }

    int i = l - 1;
    int j = r;
    int p = l - 1;
    int q = r;
    int pivot = a[r];

    for (;;) {
        // scan ltr, stop when greater than pivot
        while (a[++i] < pivot);

        // scan rtl, stop when less than pivot
        while (a[--j] > pivot) {
            if (j == l) break;
        }

        // stop if pointers cross
        if (i >= j) break;

        swap(&a[i], &a[j]);

        if (a[i] == pivot) {
            p++;
            swap(&a[p], &a[i]);
        }

        if (a[j] == pivot) {
            q--;
            swap(&a[j], &a[q]);
        }
    }

    // move initial pivot back to the middle
    swap(&a[r], &a[i]);
    j = i - 1;
    i++;

    // move left pivots to middle
    for (int k = l; k < p; k++, j--) {
        swap(&a[k], &a[j]);
    }

    // move right pivots to middle
    for (int k = r - 1; k > q; k--, i++) {
        swap(&a[i], &a[k]);
    }

    qs(a, l, j);
    qs(a, i, r);
}
