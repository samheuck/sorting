#include <string.h>

void msort(int *head, int n);
void divide(int *head, int *tmp, int l, int r);
void merge();

void msort(int *head, int n) {
    int *tmp;

    if (!n || !(tmp = malloc (sizeof (int) * n))) {
        return;
    }

    divide(head, tmp, 0, n - 1);
    free(tmp);
}

void divide(int *head, int *tmp, int l, int r) {
    if (l >= r) {
        return;
    }

    int mid = l + ((r - l) / 2);
    divide(head, tmp, l, mid);
    divide(head, tmp, mid + 1, r);
    merge(head, tmp, l, mid, r);
}

void merge(int *head, int *tmp, int l, int mid, int r) {
    register int i, j = l, k = mid + 1;

    for (i = 0;  j <= mid && k <= r; i++) {
        tmp[i] = (head[j] <= head[k]) ? head[j++] : head[k++];
    }

    while (j <= mid) {
        tmp[i++] = head[j++];
    }

    while (k <= r) {
        tmp[i++] = head[k++];
    }

    memcpy(head + l, tmp, sizeof (int) * i);
}