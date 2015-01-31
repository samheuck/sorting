int *findmin(int *arr, int len) {
  int *min = arr;

  for (int i = 0; i < len; i++) {
    if (*arr < *min) {
      min = arr;
    }

    arr++;
  }

  return min;
}

void selsort(int *arr, int len) {
  if (0 == len) {
    return;
  }

  swap(arr, findmin(arr, len));
  selsort(++arr, len-1);
}
