#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void vvod(int n, int mas[][100]) {
	cout << "Введите элементы матрицы:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mas[i][j];
		}
	}
}

void randvvod(int n, int mas[][100]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mas[i][j] = rand() % 201 - 100;
		}
	}
}

void out(int n, int mas[][100]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(5) << mas[i][j];
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int mas[100][100];
	int n, t, x = 0, sum = 0;
	cout << "Введите количество строк/столбцов в квадратной матрице:" << endl;
	cin >> n;
	cout << "Введите 1 для ручного заполнения матрицы и 0 для рандомного:" << endl;
	cin >> t;
	if (t == 1) vvod(n, mas);
	else if (t == 0) randvvod(n, mas);
	else {
		cout << "Неверный ввод." << endl;
		return 0;
	}
	cout << "Итоговая матрица:" << endl;
	out(n, mas);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (mas[j][i] < 0) {
				sum += mas[j][i];
				x++;
			}
		}
	}
	cout << "Среднее арифметическое отрицательных чисел под главной диагональю: " << sum / x << endl;
}
