#include <iostream>
#include <ctime>
using namespace std;

void vvod(int n, int mas[100]) //Ручной ввод массива
{
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
}

void randvvod(int n, int mas[100]) //Автоматический ввод массива
{
    for (int i = 0; i < n; i++) {
        mas[i] = rand() % 201 - 100;
    }
}

void out(int n, int mas[100]) //Вывод массива
{
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;
}


int main()
{
    srand(time(0));
    setlocale(LC_ALL, "rus");
    int n, mas[100], b[100], c[100], x;
    int ind_b = 0; int ind_c = 0;
    cout << "Введите количество элементов в массиве: " << endl;
    cin >> n;
    cout << "Введите 1 для ручного заполнения массива и 0 для автоматического: " << endl;
    cin >> x;
    if (x == 1) vvod(n, mas);
    else if (x == 0) randvvod(n, mas);
    else {
        cout << "Некорректные данные." << endl;
        return 0;
    }
    cout << "Полученный массив: " << endl;
    out(n, mas);
    cout << endl;


    for (int i = 0; i < n; i++) {
        if (mas[i] > 0) {
            b[ind_b] = mas[i];
            ind_b++;
        }
        else if (mas[i] < 0) {
            c[ind_c] = mas[i];
            ind_c++;
        }
    }
    cout << "Длина массива B: " << ind_b << ", сам массив: " << endl;
    out(ind_b, b);
    cout << "Длина массива C: " << ind_c << ", сам массив: " << endl;
    out(ind_c, c);
}
