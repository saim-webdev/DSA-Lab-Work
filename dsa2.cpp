#include <iostream>
#include <iomanip> // for formatting output
using namespace std;

int main() {
    const int SIZE = 30;
    int rollNo[SIZE];
    int PF[SIZE], OOP[SIZE], DSA[SIZE];
    int key, total;
    float percentage;
    bool found = false;

    cout << "Enter data for " << SIZE << " students:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nEnter Roll Number for student " << i + 1 << ": ";
        cin >> rollNo[i];

        cout << "Enter marks in Programming Fundamentals (PF): ";
        cin >> PF[i];
        cout << "Enter marks in Object Oriented Programming (OOP): ";
        cin >> OOP[i];
        cout << "Enter marks in Data Structures & Algorithms (DSA): ";
        cin >> DSA[i];
    }

    cout << "\nEnter Roll Number to search: ";
    cin >> key;

    // Linear Search
    for (int i = 0; i < SIZE; i++) {
        if (rollNo[i] == key) {
            total = PF[i] + OOP[i] + DSA[i];
            percentage = (total / 300.0f) * 100;

            cout << "\nRecord Found!\n";
            cout << "--------------------------------------\n";
            cout << "Roll Number : " << rollNo[i] << endl;
            cout << "PF Marks     : " << PF[i] << endl;
            cout << "OOP Marks    : " << OOP[i] << endl;
            cout << "DSA Marks    : " << DSA[i] << endl;
            cout << "Total Marks  : " << total << " / 300" << endl;
            cout << fixed << setprecision(2);
            cout << "Percentage   : " << percentage << "%" << endl;
            cout << "--------------------------------------\n";

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nRecord Not Found!" << endl;
    }

    return 0;
}
