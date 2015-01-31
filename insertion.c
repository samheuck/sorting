void insertionsort(int *arr, int length) {
    for (int i = 1; i < length; i++) {
        int tmp = *(arr + i),
            j = i;

        while (j > 0 && *(arr + (j - 1)) > tmp) {
            *(arr + j) = *(arr + (j - 1));
            j--;
        }

        *(arr + j) = tmp;
    }
}
