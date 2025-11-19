#include <iostream>
using namespace std;   // task no 02

// Function for Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // return index if found
        }
    }
    return -1; // not found
}

// Function for Binary Search (for sorted arrays)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1; 
    }

    return -1; // not found
}

int main() {
    int n, key, choice;

    cout << "\n University Student Record Search System " << endl;
	cout <<"\n";
    cout << "Enter number of student roll numbers: ";
    cin >> n;

    int rollNumbers[n];

    cout << "Enter " << n << " student roll numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> rollNumbers[i];
    }

    cout << "\n Enter roll number to search: ";
    cin >> key;

    cout << "\nSelect Search Type:" << endl;
    cout << "1. Linear Search (Unsorted Records)" << endl;
    cout << "2. Binary Search (Sorted Records)" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    int index = -1;

    if (choice == 1) {
        index = linearSearch(rollNumbers, n, key);
    } 
    else if (choice == 2) {
        index = binarySearch(rollNumbers, n, key);
    } 
    else {
        cout << "Invalid choice! Please restart the program." << endl;
        return 0;
    }

    cout << "\n" << endl;
    if (index != -1)
        cout << "? Roll number " << key << " found at index " << index << "." << endl;
    else
        cout << "? Roll number " << key << " not found in the records." << endl;
    cout << "\n" << endl;

    return 0;
}
