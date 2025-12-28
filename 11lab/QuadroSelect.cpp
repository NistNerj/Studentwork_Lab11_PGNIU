#include <iostream>
using namespace std;

void quadraticAsc(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[m]) m = j;
        }
        if (m != i) {
            int temp = a[i];
            a[i] = a[m];
            a[m] = temp;
        }
    }
}


void quadraticDesc(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[m]) m = j;
        }
        if (m != i) {
            int temp = a[i];
            a[i] = a[m];
            a[m] = temp;
        }
    }
}
