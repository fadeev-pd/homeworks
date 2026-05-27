#include <iostream>
#include <ctime>
using namespace std;

void vvod(int n, int mas[100]) //Ручной ввод массива
{
    cout << "Введите элементы массива: " << endl;
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

    // Поиск минимального и максимального элементов
    int mas_min = mas[0];
    int mas_max = mas[0];

    for (int i = 1; i < n; i++) {
        if (mas[i] < mas_min) {
            mas_min = mas[i];
        }
        if (mas[i] > mas_max) {
            mas_max = mas[i];
        }
    }

    // Вывод найденных значений
    cout << "Минимальный элемент: " << mas_min << endl;
    cout << "Максимальный элемент: " << mas_max << endl;

    // Создаем массив для отметки встреченных чисел
    // Размер массива = (mas_max - mas_min + 1)
    int range_size = mas_max - mas_min + 1;
    bool arr[1000];

    // Инициализация массива меток
    for (int i = 0; i < 1000; i++) {
        arr[i] = false;
    }

    // Отмечаем числа, которые встречаются в исходном массиве
    int shift = mas_min;
    for (int i = 0; i < n; i++) {
        int index = mas[i] - shift;
        if (index >= 0 and index < range_size) {
            arr[index] = true;
        }
    }

    // Вывод отсутствующих чисел из интервала (k_min, k_max)
    cout << "Целые числа из интервала от " << mas_min << " до " << mas_max << ", не встречающиеся в исходном массиве : " << endl;
    for (int num = mas_min + 1; num < mas_max; num++) {
        int index = num - shift;
        if (!arr[index]) {
            cout << num << " ";
        }
    }
    cout << endl;

    return 0;
}