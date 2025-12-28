#include <iostream>
using namespace std;

void countingAsc(int a[], int n) {
    if (n <= 0) return;

    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max) max = a[i];

    int count[100] = { 0 }; // ограничим максимальное значение 99
    for (int i = 0; i < n; i++) count[a[i]]++;

    int ind = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            a[ind++] = i;
            count[i]--;
        }
    }
}

void countingDesc(int a[], int n) {
    if (n <= 0) return;

    int max = a[0];
    for (int i = 1; i < n; i++) if (a[i] > max) max = a[i];

    int count[100] = { 0 };
    for (int i = 0; i < n; i++) count[a[i]]++;

    int ind = 0;
    for (int i = max; i >= 0; i--) {
        while (count[i] > 0) {
            a[ind++] = i;
            count[i]--;
        }
    }
}

