#include <iostream>
#include "sorts.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Ââåäèòå ðàçìåð ìàññèâà: ";
    cin >> n;

    int* a = new int[n];

    cout << "Ââåäèòå ýëåìåíòû ìàññèâà:";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int selected, direction;

    cout << endl;
    cout << "ÌÅÍÞ:" << endl;
    cout << "1. Áèíàðíûå âñòàâêè" << endl;
    cout << "2. Ïðîñòîé ïîäñ÷åò" << endl;;
    cout << "3. Ïóçûðüêîâàÿ ñîðòèðîâêà" << endl;
    cout << "4. Öåíòðèðîâàííûå âñòàâêè" << endl;
    cout << "5. Êâàäðàòè÷íûé âûáîð" << endl;;
    cout << "6. Áûñòðàÿ ñîðòèðîâêà" << endl;
    cout << "0. Îòìåíà" << endl;
    cout << "Âûáåðèòå òèï: ";
    cin >> selected;

    cout << "1. Ïî âîçðàñòàíèþ" << endl;
    cout << "2. Ïî óáûâàíèþ" << endl;
    cout << "Âûáåðèòå ïîðÿäîê: ";
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

    else cout << "Error: value(s) out of range!" << endl;
    
    return 0;
}

