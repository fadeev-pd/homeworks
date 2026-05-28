#include <iostream>
#include <ctime>
using namespace std;

void vvod(int n, int mas[100]) //Ручной ввод массива
{
    cout << "Введите элементы массива" << endl;
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
    int n, mas[100], x;
    cout << "Введите количество элементов в массиве: " << endl;
    cin >> n;
    if (n < 3) {
        cout << "Слишком маленький массив." << endl;
        return 0;
    }
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

    cout << "Номера локальных максимумов: " << endl;
    for (int i = 1; i < n - 1; i++) {
        if (mas[i] > mas[i - 1] and mas[i] > mas[i + 1]) cout << i + 1 << " ";
    }
}