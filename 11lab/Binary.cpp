#include <iostream>
using namespace std;

void binaryAsc(int a[], int n) {
    for (int i = 1; i < n; ++i) {
        int k = a[i];
        int left = 0;
        int right = i - 1;

        // Бинарный поиск позиции
        while (left <= right) {
            int m = (left + right) / 2;
            if (a[m] > k) {
                left = m + 1;
            }
            else {
                right = m - 1;
            }
        }

        // Сдвиг элементов
        for (int j = i - 1; j >= left; --j) {
            a[j + 1] = a[j];
        }
        a[left] = k;
    }
}


void binaryDesc(int a[], int n) {
    for (int i = 1; i < n; ++i) {
        int k = a[i];
        int left = 0;
        int right = i - 1;

        // Бинарный поиск позиции (по убыванию)
        while (left <= right) {
            int m = (left + right) / 2;
            if (a[m] < k) {
                left = m + 1;
            }
            else {
                right = m - 1;
            }
        }

        // Сдвиг элементов
        for (int j = i - 1; j >= left; --j) {
            a[j + 1] = a[j];
        }
        a[left] = k;
    }
}

