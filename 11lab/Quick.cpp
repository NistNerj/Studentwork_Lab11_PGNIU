int ppasc(int a[], int low, int high) {
    int p = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= p) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickAsc(int a[], int low, int high) {
    if (low < high) {
        int pi = ppasc(a, low, high);
        quickAsc(a, low, pi - 1);
        quickAsc(a, pi + 1, high);
    }
}

void quickAsc(int a[], int n) {
    quickAsc(a, 0, n - 1);
}

int ppaDesc(int a[], int low, int high) {
    int p = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] >= p) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickDesc(int a[], int low, int high) {
    if (low < high) {
        int pi = ppaDesc(a, low, high);
        quickDesc(a, low, pi - 1);
        quickDesc(a, pi + 1, high);
    }
}

void quickDesc(int a[], int n) {
    quickDesc(a, 0, n - 1);
}

