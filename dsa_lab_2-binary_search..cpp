#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            cout << "The value is: " << arr[mid] << endl;
            cout << "The index is: " << mid << endl;
            return mid;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << "Element not found" << endl;
    return -1;
}

int main() {
    int arr[7] = {3, 4, 5, 6, 7, 8, 9};
    int key;

    cout << "Enter the key value to search: ";
    cin >> key;

    int n = 7;
    binarySearch(arr, n, key);

    return 0;
}