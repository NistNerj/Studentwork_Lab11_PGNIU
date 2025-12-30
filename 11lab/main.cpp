#include <iostream>
#include "sorts.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* a = new int[n];

    cout << "Введите элементы массива:";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int selected, direction;

    cout << endl;
    cout << "МЕНЮ:" << endl;
    cout << "1. Бинарные вставки" << endl;
    cout << "2. Простой подсчет" << endl;;
    cout << "3. Пузырьковая сортировка" << endl;
    cout << "4. Центрированные вставки" << endl;
    cout << "5. Квадратичный выбор" << endl;;
    cout << "6. Быстрая сортировка" << endl;
    cout << "0. Отмена" << endl;
    cout << "Выберите тип: ";
    cin >> selected;

    cout << "1. По возрастанию" << endl;
    cout << "2. По убыванию" << endl;
    cout << "Выберите порядок: ";
    cin >> direction;

    if (selected >= 0 && selected <= 6) {

    // Выполняем сортировку

        switch (selected) {
        case 1:
            if (direction == 1) binaryDesc(a, n);
            else  binaryAsc(a, n);
            break;
        case 2:
            if (direction == 1) countingDesc(a, n);
            else  countingAsc(a, n);
            break;
        case 3:
            if (direction == 1) bubbleDesc(a, n);
            else  bubbleAsc(a, n);
            break;
        case 4:
            if (direction == 1) centeredDesc(a, n);
            else  centeredAsc(a, n);
            break;
        case 5:
            if (direction == 1) quadraticDesc(a, n);
            else  quadraticAsc(a, n);
            break;
        case 6:
            if (direction == 1) quickDesc(a, n);
            else  quickAsc(a, n);
            break;
        case 0:
            cout << "Ничего" << endl;
        }
        // Выводим результат
        cout << "Результат: ";
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }

    else cout << "Error: value(s) out of range. Pls try again!" << endl;
    
    return 0;
}


