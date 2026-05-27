#include <iostream>
#include<ctime>
#include<iomanip>
using namespace std;


void vvod(int m, int matr[][100]) //Ручной ввод массива
{
    cout << "Введите элементы матрицы: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matr[i][j];
        }
    }
}

void randvvod(int m, int matr[][100]) //Автоматический ввод массива
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matr[i][j] = rand() % 2;
        }
    }
}

void out(int m, int matr[][100]) //Вывод массива
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(3) << matr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int m, x, matr[100][100];
    cout << "Введите количество строк/столбцов в матрице: " << endl;
    cin >> m;
    cout << "Введите 1 для ручного заполнения матрицы и 0 для автоматического: " << endl;
    cin >> x;
    if (x == 1) vvod(m, matr);
    else if (x == 0) randvvod(m, matr);
    else {
        cout << "Некорректные данные." << endl;
        return 0;
    }
    cout << "Полученный массив: " << endl;
    out(m, matr);
    cout << endl;

    bool found = false;

    // Поиск строки без единиц
    for (int i = 0; i < m; i++) {
        bool flag = false;
        for (int j = 0; j < m; j++) {
            if (matr[i][j] == 1) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "Строка " << i + 1 << " не содержит единиц" << endl;
            found = true;
        }
    }

    // Если строка не найдена, ищем столбец без единиц
    if (!found) {
        for (int j = 0; j < m; j++) {
            bool flag = false;
            for (int i = 0; i < m; i++) {
                if (matr[i][j] == 1) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                cout << "Столбец " << j + 1 << " не содержит единиц" << endl;
                found = true;
            }
        }
    }

    // Если ничего не найдено
    if (!found) {
        cout << "Нет ни строки, ни столбца, полностью состоящих из нулей" << endl;
    }
}