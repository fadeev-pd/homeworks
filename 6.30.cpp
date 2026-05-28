#include <iostream>
using namespace std;

void vvod(int n, int arr[100]) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    } 
}

int main() {
    setlocale(LC_ALL, "rus");
    int n, x;
    int tickets[100];
    int sums[100];
    int myTickets[100];
    cout << "Введите количество выигрышных билетов:" << endl;
    cin >> n;
    cout << "Введите номера выигрышных билетов по возрастанию:" << endl;
    vvod(n, tickets);
    cout << "Введите суммы выигрышей билетов:" << endl;
    vvod(n, sums);
    cout << "Введите количество купленных билетов:" << endl;
    cin >> x;
    cout << "Введите номера купленных билетов:" << endl;
    vvod(x, myTickets);
    int win = 0;
    for (int i = 0; i < x; i++) {
        int prize = 0;
        int ticket = myTickets[i];
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (tickets[j] == ticket) {
                prize = sums[j];
                win += prize;
                found = true;
                break;
            }
        }
        if (found) {
            cout << "Билет номер " << ticket << " — выигрыш: " << prize << endl;
        }
        else {
            cout << "Билет номер " << ticket << " — не выигрышный" << endl;
        }
    }
    cout << "Суммарный выигрышъ: " << win;
}