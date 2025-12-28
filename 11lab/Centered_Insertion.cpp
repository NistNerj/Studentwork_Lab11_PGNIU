#include <iostream>
using namespace std;


void centeredAsc(int a[], int n) {
    int cen = n / 2;

    for (int i = cen; i > 0; i--) {
        int j = i - 1;
        while (j < n - 1 && a[j] > a[j + 1]) {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            j++;
        }
    }

    for (int i = cen; i < n - 1; i++) {
        int j = i;
        while (j > 0 && a[j] < a[j - 1]) {
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }
}

void centeredDesc(int a[], int n) {
    int cen = n / 2;

    for (int i = cen; i > 0; i--) {
        int j = i - 1;
        while (j < n - 1 && a[j] < a[j + 1]) {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            j++;
        }
    }

    for (int i = cen; i < n - 1; i++) {
        int j = i;
        while (j > 0 && a[j] > a[j - 1]) {
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }
}
