#include <iostream>
#include <iomanip>
#include <string>
#include "stdio.h"

using namespace std;

struct stock {
    char name[15];
    int number_of_stock;
    float investment;
    float current_value;
    float ret;
};

void get_data(stock a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter stock " << i + 1 << " name: " << endl;
        cin >> a[i].name;

        cout << "Number of stocks: "; 
        cin >> a[i].number_of_stock;

        cout << "Invested stock price: ";
        cin >> a[i].investment;

        cout << "Current stock price: ";
        cin >> a[i].current_value;

        a[i].ret = (a[i].current_value - a[i].investment) / a[i].investment * 100;
    }
}

void display_data(stock a[], int n) {
    cout << left << setw(15) << "Stock" 
         << setw(15) << "Quantity" 
         << setw(15) << "Base Value" 
         << setw(20) << "Present Value" 
         << "Gain/Loss (%)" << endl;

    cout << string(80, '-') << endl;

    for (int j = 0; j < n; j++) {
        cout << left << setw(15) << a[j].name
             << setw(15) << a[j].number_of_stock
             << setw(15) << a[j].investment
             << setw(20) << a[j].current_value
             << fixed << setprecision(2) << a[j].ret << "%" << endl;
    }
}

int main() {
    float sum2 = 0;
    float sum1 = 0;
    int n;

    cout << "Enter number of companies whose stock you bought in your portfolio: ";
    cin >> n;

    stock a[n];
    get_data(a, n);

    cout << "\n\n" << endl;

    cout << string(150, '*') << endl;
    cout << endl;

    display_data(a, n);

    for (int i = 0; i < n; i++) {
        sum1 += a[i].number_of_stock * a[i].investment;
    }

    for (int i = 0; i < n; i++) {
        sum2 += a[i].number_of_stock * a[i].current_value;
    }

    cout << "\nTotal Portfolio Investment: " << fixed << setprecision(2) << sum1 << endl;
    cout << "Gain (%)                  : " << fixed << setprecision(2) << (sum2 - sum1) * 100 / sum1 << "%" << endl;

    cout << endl;
    cout << string(150, '*') << endl;

    return 0;
}
