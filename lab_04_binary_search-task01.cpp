#include <iostream>
using namespace std;  // task no 01

// Function to perform binary search in ascending order
int binarySearchAsc(int arr[], int n, int key) {
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
    return -1; // Not found
}

// Function to perform binary search in descending order
int binarySearchDesc(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Not found
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int roll[n];
    cout << "Enter " << n << " roll numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> roll[i];
    }

    int searchRoll;
    cout << "\nEnter roll number to search: ";
    cin >> searchRoll;

    int pos;
    if (searchRoll % 2 == 0) {
        // Even roll number ? ascending order
        cout << "\nSearching in ascending order...\n";
        // Sort ascending (simple bubble sort)
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (roll[j] > roll[j + 1])
                    swap(roll[j], roll[j + 1]);

        pos = binarySearchAsc(roll, n, searchRoll);
    } else {
        // Odd roll number ? descending order
        cout << "\nSearching in descending order...\n";
        // Sort descending
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (roll[j] < roll[j + 1])
                    swap(roll[j], roll[j + 1]);

        pos = binarySearchDesc(roll, n, searchRoll);
    }

    if (pos != -1)
        cout << "\nRoll number found at position: " << pos + 1 << endl;
    else
        cout << "\nRoll number not found." << endl;

    return 0;
}
