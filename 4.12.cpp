#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void vvod(int n, int m, int matr[][100]) //Ручной ввод массива
{
    cout << "Введите элементы матрицы: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matr[i][j];
        }
    }
}

void randvvod(int n, int m, int matr[][100]) //Автоматический ввод массива
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matr[i][j] = rand() % 201 - 100;
        }
    }
}

void out(int n, int m, int matr[][100]) //Вывод массива
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(3) << matr[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    srand(time(0));
    setlocale(LC_ALL, "rus");
    int n, m, x, matr[100][100], mas[100];
    cout << "Введите количество строк в матрице: " << endl;
    cin >> n;
    cout << "Введите количество столбцов в матрице: " << endl;
    cin >> m;
    cout << "Введите 1 для ручного заполнения матрицы и 0 для автоматического: " << endl;
    cin >> x;
    if (x == 1) vvod(n, m, matr);
    else if (x == 0) randvvod(n, m, matr);
    else {
        cout << "Некорректные данные." << endl;
        return 0;
    }
    cout << "Полученный массив: " << endl;
    out(n, m, matr);
    cout << endl;

    int ind_mas = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matr[i][j] != 0) {
                mas[ind_mas] = matr[i][j];
                ind_mas++;
            }
        }
    }
    cout << "Ненулевые элементы матрицы: ";
    for (int i = 0; i < ind_mas; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;
    cout << "Их количество: " << ind_mas << endl;
}