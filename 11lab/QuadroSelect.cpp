#include <iostream>
using namespace std;

void quadraticAsc(int* A, int N) {
    // Вычисляем количество групп (квадратный корень из N)
    int groups = 1;
    while (groups * groups < N) {
        groups++;
    }

    // Создаем рабочий массив
    int** W = new int* [groups];
    int* sizes = new int[groups];

    // Делим исходный массив на группы
    int count = 0;
    for (int i = 0; i < groups; i++) {
        int n = N / groups;
        if (i < N % groups) {
            n++;
        }
        sizes[i] = n;
        W[i] = new int[n];
        for (int j = 0; j < n; j++) {
            W[i][j] = A[count + j];
        }
        count += n;
    }

    // Создаем вспомогательный массив для хранения текущих минимумов групп
    int* B = new int[groups];

    // Заполняем вспомогательный массив начальными минимумами из каждой группы
    for (int i = 0; i < groups; i++) {
        // Находим индекс минимального элемента в группе i
        int minIndex = 0;
        int minVal = W[i][0];
        for (int j = 1; j < sizes[i]; j++) {
            if (minVal > W[i][j]) {
                minVal = W[i][j];
                minIndex = j;
            }
        }
        // Сохраняем минимум и заменяем его на максимальное значение
        B[i] = minVal;
        W[i][minIndex] = 2147483647;
    }

    // Основной цикл сортировки
    for (int i = 0; i < N; i++) {
        // Находим индекс минимального элемента во вспомогательном массиве B
        int minIndexB = 0;
        int minValB = B[0];
        for (int j = 1; j < groups; j++) {
            if (minValB > B[j]) {
                minValB = B[j];
                minIndexB = j;
            }
        }

        // Записываем найденный минимум в исходный массив
        A[i] = B[minIndexB];

        // Находим следующий минимальный элемент в соответствующей группе
        int groupIndex = minIndexB;
        int minIndexW = 0;
        int minValW = W[groupIndex][0];
        for (int j = 1; j < sizes[groupIndex]; j++) {
            if (minValW > W[groupIndex][j]) {
                minValW = W[groupIndex][j];
                minIndexW = j;
            }
        }

        // Обновляем значение во вспомогательном массиве
        B[minIndexB] = minValW;
        W[groupIndex][minIndexW] = 2147483647;
    }

    // Освобождаем память
    delete[] B;
    delete[] sizes;
    for (int i = 0; i < groups; i++) {
        delete[] W[i];
    }
    delete[] W;
}


void quadraticDesc(int* A, int N) {
    // Вычисляем количество групп (квадратный корень из N)
    int groups = 1;
    while (groups * groups < N) {
        groups++;
    }

    // Создаем рабочий массив
    int** W = new int*[groups];
    int* sizes = new int[groups];

    // Делим исходный массив на группы
    int count = 0;
    for (int i = 0; i < groups; i++) {
        int n = N / groups;
        if (i < N % groups) {
            n++;
        }
        sizes[i] = n;
        W[i] = new int[n];
        for (int j = 0; j < n; j++) {
            W[i][j] = A[count + j];
        }
        count += n;
    }

    // Создаем вспомогательный массив для хранения текущих максимумов групп
    int* B = new int[groups];

    // Заполняем вспомогательный массив начальными максимумами из каждой группы
    for (int i = 0; i < groups; i++) {
        // Находим индекс максимального элемента в группе i
        int maxIndex = 0;
        int maxVal = W[i][0];
        for (int j = 1; j < sizes[i]; j++) {
            if (maxVal < W[i][j]) {  // Изменено на поиск максимума
                maxVal = W[i][j];
                maxIndex = j;
            }
        }
        // Сохраняем максимум и заменяем его на минимальное значение
        B[i] = maxVal;
        W[i][maxIndex] = -2147483648;  // Минимальное значение для int
    }

    // Основной цикл сортировки по убыванию
    for (int i = 0; i < N; i++) {
        // Находим индекс максимального элемента во вспомогательном массиве B
        int maxIndexB = 0;
        int maxValB = B[0];
        for (int j = 1; j < groups; j++) {
            if (maxValB < B[j]) {  // Изменено на поиск максимума
                maxValB = B[j];
                maxIndexB = j;
            }
        }

        // Записываем найденный максимум в исходный массив
        A[i] = B[maxIndexB];

        // Находим следующий максимальный элемент в соответствующей группе
        int groupIndex = maxIndexB;
        int maxIndexW = 0;
        int maxValW = W[groupIndex][0];
        for (int j = 1; j < sizes[groupIndex]; j++) {
            if (maxValW < W[groupIndex][j]) {  // Изменено на поиск максимума
                maxValW = W[groupIndex][j];
                maxIndexW = j;
            }
        }

        // Обновляем значение во вспомогательном массиве
        B[maxIndexB] = maxValW;
        W[groupIndex][maxIndexW] = -2147483648;  // Минимальное значение для int
    }

    // Освобождаем память
    delete[] B;
    delete[] sizes;
    for (int i = 0; i < groups; i++) {
        delete[] W[i];
    }
    delete[] W;
}
