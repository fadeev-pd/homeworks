#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int k, l;
    int matr[100][100];

    cout << "Введите количество строк и столбцов: " << endl;
    cin >> k;
    cin >> l;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < l; j++) {
            // Используем формулу для распределения чисел 1,2,3,4
            // Чтобы соседи по горизонтали, вертикали и диагонали были разные
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    matr[i][j] = 1;
                }
                else {
                    matr[i][j] = 2;
                }
            }
            else {
                if (j % 2 == 0) {
                    matr[i][j] = 3;
                }
                else {
                    matr[i][j] = 4;
                }
            }
        }
    }

    // Вывод матрицы
    cout << "Заполненная матрица:" << endl;;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < l; j++) {
            cout << setw(3) << matr[i][j];
        }
        cout << endl;
    }

    return 0;
}