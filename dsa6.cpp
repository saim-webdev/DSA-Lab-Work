#include <iostream>
using namespace std;

// Function for Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;  // Element found
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;  // Element not found
}

int main() {
    int arr[7]={3,4,5,6,7,8,9};
    int key;
    
    cout << "Enter the key value to search: ";
    cin >> key;
int n=7;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "key found at index " << result << "." << endl;
    else
        cout << "key not found in the array." << endl;

    return 0;
}