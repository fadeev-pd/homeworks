#include <iostream>
#include <iomanip>
using namespace std;

// Функция для сравнения двух строк (начиная с характеристик, т.е. со 2-го элемента)
bool characteristics(int row1[], int row2[], int n) {
    // Сравниваем характеристики (элементы с индекса 1 до n-1)
    for (int j = 1; j < n; ++j) {
        if (row1[j] != row2[j]) {
            return false; // Характеристики не совпадают
        }
    }
    return true; // Характеристики совпадают
}

// Функция для удаления строки из матрицы
void del(int matr[][100], int& m, int n, int rowIndex) {
    // Сдвигаем все строки после удаляемой вверх
    for (int i = rowIndex; i < m - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            matr[i][j] = matr[i + 1][j];
        }
    }
    m--; // Уменьшаем количество строк
}

void out(int matr[][100], int m, int n) {
    cout << "Оставшаяся после резекции матрица:" << endl;;
    if (m == 0) {
        cout << "Матрица пуста" << endl;
        return;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matr[i][j]  << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int m, n;
    int matr[100][100];
    bool toDelete[100] = { false }; // Массив флагов для удаления элементов

    cout << "Введите количество строк m: ";
    cin >> m;
    cout << "Введите количество столбцов n (первый - шифр, остальные - характеристики): ";
    cin >> n;

    // Ввод матрицы
    cout << "Введите матрицу " << m << " x " << n << ":" << endl;
    cout << "(первый элемент каждой строки - шифр детали, остальные - характеристики)" << endl;
    for (int i = 0; i < m; ++i) {
        cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> matr[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int k = i + 1; k < m; ++k) {
            if (matr[i][0] == matr[k][0]) { // Если шифры совпадают
                if (!characteristics(matr[i], matr[k], n)) { // Проверяем характеристики
                    // Характеристики не совпадают -> обе строки подлежат удалению
                    toDelete[i] = true;
                    toDelete[k] = true;
                }
            }
        }
    }

    // Вывод номеров строк, подлежащих удалению
    cout << "Номера строк с совпадающими шифрами и несовпадающими характеристиками: ";
    bool found = false;
    for (int i = 0; i < m; ++i) {
        if (toDelete[i]) {
            cout << i + 1 << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "нет таких строк";
    }
    cout << endl;

    // Удаление помеченных строк
    for (int i = m - 1; i >= 0; --i) {
        if (toDelete[i]) {
            del(matr, m, n, i);
        }
    }

    out(matr, m, n);

    return 0;
}